# mimalloc — research notes (web-sourced, for aligning our port)

Sources: microsoft/mimalloc (readme, src/alloc.c, src/page.c, src/free.c,
src/segment.c, include/mimalloc/atomic.h, include/mimalloc-internal.h),
MSR-TR-2019-18 "Mimalloc: Free List Sharding in Action", Microsoft
Research blog. Versions: v2 = stable (thread-local segments), v3 = dev
(first-class heaps, lock-free simplification). We target v2 semantics.

## 1. Architecture

```
thread → theap (thread-local heap) → pages (one per size class)
       → segments (reserved from OS/arena) → blocks
```

- **Segment** (v2): 32 MiB on 64-bit, aligned to a boundary so the
  segment containing pointer `p` is found by masking low bits
  (`p & ~(MI_SEGMENT_SIZE-1)`). Memory committed on demand. Segment
  starts with metadata (segment + page structs), then page data.
  Segments are per-thread; when a thread ends its live segments are
  **abandoned** (`thread_id = 0`) and reclaimed by other threads
  (work-stealing style).
- **Page** kinds: small 64 KiB (blocks < 8 KiB), medium 512 KiB,
  large 4 MiB (one page per segment), huge = one page per segment of
  arbitrary size (> 512 KiB or alignment > max). Every segment/page
  combo exists so `free` has a uniform code path with no special cases.
- **Size classes** ("bins"): 8-byte steps up to 128, then 16, 24, 32…
  through 10240, 12288, 14336, 16384. Our `_miBlockSize` table already
  matches the real bin tail.
- **theap** has a direct array of pointers `small_pages[index]` where
  `index = (size + sizeof(void*))/sizeof(void*)` — constant-time page
  lookup. Pointers are never null (empty-page sentinels with
  `free == NULL`) so the fast path needs no null checks.

## 2. The three free lists per page (the big idea)

Every page has **three** lists:

| list | owner | operation |
|---|---|---|
| `free` | page (thread-local) | allocation pops head — no atomics |
| `local_free` | owning thread | same-thread `free` pushes here — no atomics |
| `thread_free` (xthread_free) | any thread | cross-thread `free` pushes with **one CAS** |

Fast malloc (release build ~7 instructions):

```c
block = page->free;
if (block == NULL) return malloc_generic(heap, size);  // slow path
page->free = block->next;   // encoded next
page->used++;
return block;
```

Fast free:

```c
page = ptr_page(p);
if (page->thread_id == thread_id()) {   // local
    block->next = page->local_free;
    page->local_free = block;
    if (--page->used == 0) page_free(page);
} else {                                // cross-thread: one CAS
    do { block->next = page->thread_free; }
    while (!cas(&page->thread_free, block->next, block));
    atomic_inc(&page->thread_freed);
}
```

**Collection cadence:** when `free` is empty the generic path promotes
lists: `thread_free` is atomically swapped to NULL and appended to
`local_free`; `local_free` becomes `free` when `free` is empty. This
guarantees the generic path is taken after a bounded number of
allocations — amortizing page extend/retire, delayed-free processing,
and cross-thread collection with a single check in the fast path.

## 3. Cross-thread delayed free (v2 details)

- First cross-thread free on a full page sets the **delayed flag** in
  the packed `xthread_free` word (`MI_USE_DELAYED_FREE` →
  `MI_DELAYED_FREEING`) and pushes the block onto the **heap's**
  `thread_delayed_free` list (also CAS), then resets the flag.
  Subsequent frees go straight onto the page's `thread_free` list.
- The owning thread processes `thread_delayed_free` in
  `_mi_heap_delayed_free_partial` (atomic take-over of the list) and
  `_mi_free_delayed_block` (collect page lists, then local free).
- Abandoned segments: a free on `segment->thread_id == 0` first tries
  `_mi_segment_attempt_reclaim` and then re-frees locally.

## 4. Free-list pointer encoding (security)

Per-page random keys `k1, k2`; `NULL` is encoded through a separate
sentinel (`null` argument) so `(k2<<<k1)+k1` never appears as a real
sentinel:

```c
set:  block->next = (rotl(next ^ k2, k1)) + k1;      // next==NULL → sentinel
get:  b = rotr(block->next - k1, k1) ^ k2;           // b==sentinel → NULL
```

Decode must also verify `b` lies in the same page (corruption → fatal).
Keys are unique per page. Double-free detection walks the three lists
and reports (then ignores). Our port has `_miFreeBlockEncode/Decode` —
verify it matches this formula exactly (it is NOT plain `p ^ k1`).

## 5. Locks and atomics (include/mimalloc/atomic.h)

`mi_lock_t` is **never a plain non-atomic spin**. Choices, in order:
Win32 `SRWLOCK`, pthreads `pthread_mutex_t`, C++ `std::mutex`, and the
fallback:

```c
// _Atomic(uintptr_t) mutex
try_acquire:  expected = 0; cas_strong_acq_rel(&mutex, &expected, 1)
acquire:      for (i = 0; i < 10000; i++) { if (try_acquire()) return;
                                            _mi_prim_thread_yield(); }
              error "lock cannot be acquired"
release:      store_release(&mutex, 0)
```

Locks are used only for arena reservation and the abandoned list —
the allocation fast path is lock-free.

Atomic primitives used throughout: `cas_weak/cas_strong` (release /
acq_rel / relaxed), `exchange`, `fetch_add/sub`, `load_acquire`,
`store_release`, `thread_fence`. Memory-order rules that matter:
- cross-thread list push: CAS **release** (or acq_rel on the collect
  side: `cas_weak_acq_rel` when taking over `thread_free`/delayed list)
- local counters: relaxed
- publishing heap/page ownership: acquire loads of `xheap`/`thread_id`.

Our codebase's equivalent: `lib_old/std/concurrent/thread.crl` defines
`AtomicU64` with `flag (ARCH)` dispatch and inline asm
(x86_64 `lock cmpxchg` / `lock xadd` / `stlr`+`ldar` on arm64, etc.):
`load()`, `store(v)`, `fetchAdd(delta)`, plus a CAS method. concurrent
is not yet ported, so until it is, mimalloc may carry a private copy of
these helpers (modeled on that file) and yield via a local
`extern("C") i32 sched_yield();`.

## 6. Page lifecycle (src/page.c)

- `mi_page_init`: block_size, page_start, `reserved = page_size /
  block_size` (u16), per-page random keys, `block_size_shift` for
  power-of-two sizes, initial `mi_page_extend_free`.
- `mi_page_extend_free`: bounded — `max_extend = MI_MAX_EXTEND_SIZE /
  bsize` (with `MI_MIN_EXTEND` floor), so worst-case work is bounded;
  only the touched prefix of the page is committed (lean RSS).
  Sequential extend: `mi_page_free_list_extend` chains blocks and
  prepends to `free` (secure mode: random slice threading).
- `_mi_page_free_collect`: CAS-swap `thread_free` → walk to tail →
  append to `local_free`; then `local_free` → `free` when `free` is
  empty (append only on forced/shutdown collect). Updates `used`.
- Retire: generic path linearly walks the size-class queue, frees
  pages with no used blocks (bounded count kept cached), stops at first
  page with room and rotates the queue. Abandon: page released to
  segment, thread_id → 0.

## 7. Allocation flow (src/alloc.c)

```
mi_malloc(size):
  if size <= MI_SMALL_SIZE_MAX:               // fast
      page = theap->small_pages[(size+ptr)/ptr]
      return page_malloc_zero(heap, page, size)  // pop free list
  else: return _mi_heap_malloc_generic(...)      // slow: extend/collect
```

`_mi_page_malloc_zero`: pop `page->free`; if null →
`_mi_malloc_generic` (collect local/thread lists, extend, retire);
`used++`; optional zeroing (`free_is_zero` short-circuit); padding
canary (`mi_ptr_encode_canary`) when MI_PADDING.

## 8. What "real mimalloc" means for our port (acceptance list)

1. Lock = CAS+bounded retry+yield (per §5), never `while(locked){} locked=1;`.
2. All shared-state accesses (thread_free list head, used/thread_freed
   counters, delayed flags, segment thread_id) go through atomics with
   the memory orders from §5.
3. Exactly three lists per page with promotion in the generic path
   (§2); fast paths match the pseudocode.
4. Cross-thread free follows §3 (delayed-flag dance + heap delayed
   list), not a naive shared mutex around everything.
5. Encoding matches §4 (rotate-add-xor, two per-page keys, sentinel,
   same-page validation on decode).
6. Bounded extend + retire per §6 (no unbounded loops, no full-page
   zeroing up front — commit on demand).
7. Double-free detected and ignored; stats counters kept.
8. Thread yield on lock contention; arena/abandoned-list are the only
   lock users.

Not in scope: guard pages / MI_SECURE padding, valgrind/TSAN hooks,
commit/purge masks, v3 first-class heaps, CPython heap-walk support.
