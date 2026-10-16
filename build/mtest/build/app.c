#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

extern int memcmp(const void*, const void*, size_t);

#undef INT8_MIN
#undef INT8_MAX
#undef INT16_MIN
#undef INT16_MAX
#undef INT32_MIN
#undef INT32_MAX
#undef INT64_MIN
#undef INT64_MAX

typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;
static bool _coral_streq(_coral_str a, _coral_str b) { return a.len == b.len && memcmp(a.ptr, b.ptr, a.len) == 0; }
static bool _coral_strtruth(_coral_str s) { return s.len > 0; }
typedef struct crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock;
typedef struct crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf;
typedef struct crl__lib__std__x86_64__linux__memory__mman___HeapBlock crl__lib__std__x86_64__linux__memory__mman___HeapBlock;
typedef struct crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator;
typedef struct crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator;
typedef struct crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator;
typedef struct crl__lib__std__x86_64__linux__memory__mman__PoolAllocator crl__lib__std__x86_64__linux__memory__mman__PoolAllocator;
typedef struct crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc;
typedef struct crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator;
typedef struct crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String;
typedef struct crl__lib__std__x86_64__linux__io__ios___Buf crl__lib__std__x86_64__linux__io__ios___Buf;
typedef struct crl__lib__std__x86_64__linux__io__ios__Spaces crl__lib__std__x86_64__linux__io__ios__Spaces;
typedef struct crl__lib__std__x86_64__linux__io__ios__Repeat crl__lib__std__x86_64__linux__io__ios__Repeat;
typedef struct crl__lib__std__x86_64__linux__io__ios__Hex crl__lib__std__x86_64__linux__io__ios__Hex;
typedef struct crl__lib__std__x86_64__linux__io__ios__Bin crl__lib__std__x86_64__linux__io__ios__Bin;
typedef struct crl__lib__std__x86_64__linux__io__ios__Fixed crl__lib__std__x86_64__linux__io__ios__Fixed;
typedef struct crl__loc__m1__m1__A crl__loc__m1__m1__A;
typedef struct Vec__coral_str Vec__coral_str;
typedef void* (*FnP_voidp_voidp_size_t)(void*, size_t);
typedef void (*FnP_void_voidp_voidp)(void*, void*);
typedef void* (*FnP_voidp_voidp_voidp_size_t)(void*, void*, size_t);
typedef void (*FnP_void_int32_t)(int32_t);
typedef void (*FnP_void)();
typedef void* (*FnP_voidp_voidp)(void*);
typedef struct _coral_tuple_uint32_t_uint32_t {
    uint32_t _1;
    uint32_t _2;
} _coral_tuple_uint32_t_uint32_t;
typedef _Bool (*FnP__Bool__coral_str__coral_str)(_coral_str, _coral_str);
typedef int32_t (*FnP_int32_t__coral_str__coral_str)(_coral_str, _coral_str);
typedef uint8_t crl__lib__core__cchar__cchar;
struct crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator {
    void* ctx;
    FnP_voidp_voidp_size_t alloc;
    FnP_void_voidp_voidp free;
    FnP_voidp_voidp_voidp_size_t realloc;
};
struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next;
};
struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry {
    uint8_t* pageBase;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry* next;
};
struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry* buckets[64];
};
struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* next;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* prev;
    uint32_t sizeClass;
    size_t blockSize;
    size_t capacity;
    uint32_t used;
    uint32_t freeCount;
    size_t reserved;
    uint8_t* base;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* free;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* localFree;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* xthreadFree;
    uint64_t xthreadFreeCount;
    _Bool inFull;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* segment;
    uint32_t pageIdx;
    _Bool retired;
    uint32_t retireCount;
    uint64_t key1;
    uint64_t key2;
};
struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* next;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* prev;
    uint8_t* base;
    size_t size;
    uint32_t pageCount;
    uint32_t usedCount;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* pages;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* arena;
    uint64_t threadId;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* owner;
};
struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* next;
    uint8_t* base;
    size_t size;
    uint64_t* bitmap;
    size_t bitmapWords;
    uint32_t sliceCount;
    uint32_t usedSlices;
};
struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* pages[44];
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* freePages[44];
    uint32_t pageCounts[44];
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* arenas;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* segments;
    size_t totalAllocated;
    size_t totalFreed;
    size_t mapped;
    uint32_t pageSize[44];
    uint64_t threadId;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* delayedFree;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* fullPages;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* hugePages;
};
struct crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap heap;
};
struct crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader {
    size_t sizeAndFlags;
};
struct crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock {
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader header;
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* prev;
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* next;
};
struct crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf {
    void* heapStart;
    void* heapEnd;
    size_t heapSize;
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* freeLists[32][32];
    uint32_t fliBitmap;
    uint32_t sliBitmap[32];
};
struct crl__lib__std__x86_64__linux__memory__mman___HeapBlock {
    size_t sizeAndFlags;
    size_t prevPhysSize;
};
struct crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator {
    uint8_t* buffer;
    size_t cap;
    size_t used;
};
struct crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator {
    crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator fba;
    crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* fallback;
    uint8_t stackBuf[1024];
};
struct crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator {
    crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* backing;
    uint8_t* base;
    size_t cap;
    size_t used;
};
struct crl__lib__std__x86_64__linux__memory__mman__PoolAllocator {
    void* freeList;
    size_t blockSize;
    size_t blockCount;
    uint8_t* backing;
    crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* source;
};
struct crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc {
    crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* backing;
    void** ptrs;
    size_t* sizes;
    size_t len;
    size_t cap;
};
struct crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator {
    crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* parent;
    size_t totalAlloced;
    size_t totalFreed;
    size_t currentUsed;
    size_t allocCount;
    size_t freeCount;
    void** trackPtrs;
    size_t* trackSizes;
    size_t trackLen;
    size_t trackCap;
};
struct crl__lib__std__x86_64__linux__text__string__String {
    uint8_t* ptr;
    size_t len;
    size_t cap;
};
struct crl__lib__std__x86_64__linux__io__ios___Buf {
    int32_t fd;
    uint8_t* data;
    size_t len;
};
struct crl__lib__std__x86_64__linux__io__ios__Spaces {
    uint64_t count;
};
struct crl__lib__std__x86_64__linux__io__ios__Repeat {
    uint8_t ch;
    uint64_t count;
};
struct crl__lib__std__x86_64__linux__io__ios__Hex {
    uint64_t value;
};
struct crl__lib__std__x86_64__linux__io__ios__Bin {
    uint64_t value;
};
struct crl__lib__std__x86_64__linux__io__ios__Fixed {
    double value;
    uint64_t precision;
};
struct crl__loc__m1__m1__A {
    int32_t x;
};
struct Vec__coral_str {
    _coral_str* data;
    size_t len;
    size_t cap;
};

int32_t* __errno_location(void);
int64_t read(int32_t fd, char* buf, uint64_t count);
int64_t write(int32_t fd, char* const buf, uint64_t count);
int32_t getcchar(void);
int32_t putcchar(int32_t c);
int32_t fflush(void* stream);
uint64_t strlen(char* const s);
int32_t strcmp(char* const a, char* const b);
char* strcpy(char* dst, char* const src);
void* malloc(uint64_t size);
void free(void* ptr);
void* realloc(void* ptr, uint64_t newSize);
int32_t memcmp(const void* a, const void* b, uint64_t n);
int32_t snprintf(char* buf, uint64_t size, char* const fmt, ...);
int32_t printf(char* const fmt, ...);
int32_t puts(char* const s);
void* mmap(void* addr, uint64_t length, int32_t prot, int32_t flags, int32_t fd, int64_t offset);
int32_t open(char* const path, int32_t flags, int32_t mode);
int32_t close(int32_t fd);
int32_t stat(char* const path, void* buf);
int32_t mkdir(char* const path, int32_t mode);
int32_t chdir(char* const path);
int32_t rmdir(char* const path);
int32_t unlink(char* const path);
int32_t rename(char* const old, char* const newName);
int32_t access(char* const path, int32_t mode);
void* opendir(char* const path);
void* readdir(void* dir);
int32_t closedir(void* dir);
int32_t getchar(void);
double strtod(char* const nptr, char** endptr);
int32_t vsnprintf(char* buf, uint64_t size, char* const fmt, ...);
void* fopen(char* const path, char* const mode);
int32_t fclose(void* stream);
uint64_t fread(void* ptr, uint64_t size, uint64_t count, void* stream);
uint64_t fwrite(const void* ptr, uint64_t size, uint64_t count, void* stream);
int32_t feof(void* stream);
int32_t ferror(void* stream);
int64_t lseek(int32_t fd, int64_t offset, int32_t whence);
int32_t mkstemp(char* templateStr);
char* mkdtemp(char* templateStr);
int32_t regcomp(void* preg, char* const pattern, int32_t cflags);
int32_t regexec(const void* preg, char* const string, uint64_t nmatch, void* pmatch, int32_t eflags);
void regfree(void* preg);
uint64_t regerror(int32_t errcode, const void* preg, char* errbuf, uint64_t errbufSize);
int32_t fork(void);
int32_t execvp(char* const file, char** const argv);
int32_t waitpid(int32_t pid, int32_t* status, int32_t options);
int32_t poll(void* fds, uint64_t nfds, int32_t timeout);
void _exit(int32_t code);
int32_t pipe(int32_t* fds);
int32_t dup2(int32_t oldfd, int32_t newfd);
int32_t execvpe(char* const file, char** const argv, char** const envp);
FnP_void_int32_t signal(int32_t signum, FnP_void_int32_t handler);
int32_t kill(int32_t pid, int32_t sig);
int32_t raise(int32_t sig);
char* getenv(char* const name);
int32_t setenv(char* const name, char* const value, int32_t overwrite);
int32_t unsetenv(char* const name);
int64_t readlink(char* const path, char* buf, uint64_t bufsize);
int32_t gettimeofday(void* tv, void* tz);
uint64_t time(void* t);
int64_t clock_gettime(int32_t clockId, void* tp);
int32_t nanosleep(const void* req, void* rem);
int32_t getcontext(void* uc);
void makecontext(void* uc, FnP_void fn, int32_t argc);
int32_t swapcontext(void* ocp, void* ucp);
int32_t isatty(int32_t fd);
int32_t pthread_create(void** thread, const void* attr, FnP_voidp_voidp start, void* arg);
int32_t pthread_join(void* thread, void** retval);
void pthread_exit(void* retval);
void* pthread_self(void);
int32_t pthread_mutex_init(void* mutex, const void* attr);
int32_t pthread_mutex_destroy(void* mutex);
int32_t pthread_mutex_lock(void* mutex);
int32_t pthread_mutex_unlock(void* mutex);
int32_t pthread_mutex_trylock(void* mutex);
int32_t pthread_mutexattr_init(void* attr);
int32_t pthread_mutexattr_destroy(void* attr);
int32_t pthread_mutexattr_settype(void* attr, int32_t type);
int32_t pthread_cond_init(void* cond, const void* attr);
int32_t pthread_cond_destroy(void* cond);
int32_t pthread_cond_wait(void* cond, void* mutex);
int32_t pthread_cond_signal(void* cond);
int32_t pthread_cond_broadcast(void* cond);
int32_t pthread_cond_timedwait(void* cond, void* mutex, void* abstime);
int32_t pthread_rwlock_init(void* lock, const void* attr);
int32_t pthread_rwlock_destroy(void* lock);
int32_t pthread_rwlock_rdlock(void* lock);
int32_t pthread_rwlock_wrlock(void* lock);
int32_t pthread_rwlock_unlock(void* lock);
int32_t pthread_rwlock_tryrdlock(void* lock);
int32_t pthread_rwlock_trywrlock(void* lock);
int32_t sem_init(void* sem, int32_t pshared, uint32_t value);
int32_t sem_destroy(void* sem);
int32_t sem_wait(void* sem);
int32_t sem_trywait(void* sem);
int32_t sem_post(void* sem);
int32_t sem_getvalue(void* sem, int32_t* sval);
int32_t socket(int32_t domain, int32_t type, int32_t protocol);
int32_t connect(int32_t fd, const void* addr, int32_t addrlen);
int32_t bind(int32_t fd, const void* addr, int32_t addrlen);
int32_t listen(int32_t fd, int32_t backlog);
int32_t accept(int32_t fd, void* addr, int32_t* addrlen);
int32_t setsockopt(int32_t fd, int32_t level, int32_t optname, uint8_t* const optval, int32_t optlen);
int64_t send(int32_t fd, uint8_t* const buf, uint64_t len, int32_t flags);
int64_t recv(int32_t fd, uint8_t* buf, uint64_t len, int32_t flags);
int64_t sendto(int32_t fd, uint8_t* const buf, uint64_t len, int32_t flags, const void* dstAddr, int32_t addrLen);
int64_t recvfrom(int32_t fd, uint8_t* buf, uint64_t len, int32_t flags, void* srcAddr, int32_t* addrLen);
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
_Bool crl__lib__core__char_util__isDigit(uint8_t c);
_Bool crl__lib__core__char_util__isAlpha(uint8_t c);
_Bool crl__lib__core__char_util__isAlnum(uint8_t c);
_Bool crl__lib__core__char_util__isLower(uint8_t c);
_Bool crl__lib__core__char_util__isUpper(uint8_t c);
uint8_t crl__lib__core__char_util__toLower(uint8_t c);
uint8_t crl__lib__core__char_util__toUpper(uint8_t c);
_Bool crl__lib__core__char_util__isSpace(uint8_t c);
_Bool crl__lib__core__char_util__isPrint(uint8_t c);
_Bool crl__lib__core__char_util__isControl(uint8_t c);
_Bool crl__lib__core__char_util__isHexDigit(uint8_t c);
uint8_t crl__lib__core__char_util__digitValue(uint8_t c);
_Bool crl__lib__core__char_util__isAscii(uint8_t c);
_Bool crl__lib__core__char_util__isWhitespace(uint8_t c);
_Bool crl__lib__core__char_util__isNewline(uint8_t c);
_Bool crl__lib__core__char_util__isPunctuation(uint8_t c);
_Bool crl__lib__core__char_util__isSymbol(uint8_t c);
uint32_t crl__lib__core__char_util__utf8Width(uint32_t c);
uint32_t crl__lib__core__char_util__encodeUtf8(uint32_t c, uint8_t* buf);
_coral_tuple_uint32_t_uint32_t crl__lib__core__char_util__decodeUtf8(uint8_t* const buf);
uint32_t crl__lib__core__char_util__toUtf8(uint32_t c, uint8_t* buf);
uint32_t crl__lib__core__char_util__fromUtf8(uint8_t* const buf);
uint8_t crl__lib__core__char_util__toAscii(uint8_t c);
_Bool crl__lib__core__char_util__u8Eq(uint8_t a, uint8_t b);
_Bool crl__lib__core__char_util__u8EqLower(uint8_t a, uint8_t b);
int32_t crl__lib__core__char_util__u8Cmp(uint8_t a, uint8_t b);
uint32_t crl__lib__core__char_util__toStr(uint8_t c, uint8_t* buf);
_coral_str crl__lib__core__str___coral_str_fromCstr(char* const cstr);
_coral_str crl__lib__core__str___coral_str_fromParts(uint8_t* const ptr, size_t len);
_coral_str crl__lib__core__str___coral_str_empty(void);
uint8_t* const crl__lib__core__str___coral_str_asU8(_coral_str* self);
uint8_t crl__lib__core__str___coral_str_at(_coral_str* self, size_t idx);
_Bool crl__lib__core__str___coral_str_isEmpty(_coral_str* self);
_Bool crl__lib__core__str___coral_str_equals(_coral_str* self, _coral_str other);
int32_t crl__lib__core__str___coral_str_compare(_coral_str* self, _coral_str other);
_Bool crl__lib__core__str___coral_str_startsWith(_coral_str* self, _coral_str prefix);
_Bool crl__lib__core__str___coral_str_endsWith(_coral_str* self, _coral_str suffix);
_Bool crl__lib__core__str___coral_str_containsView(_coral_str* self, _coral_str needle);
_Bool crl__lib__core__str___coral_str_containsByte(_coral_str* self, uint8_t c);
size_t crl__lib__core__str___coral_str_findByte(_coral_str* self, uint8_t c);
size_t crl__lib__core__str___coral_str_rfindByte(_coral_str* self, uint8_t c);
size_t crl__lib__core__str___coral_str_findView(_coral_str* self, _coral_str needle);
_coral_str crl__lib__core__str___coral_str_slice(_coral_str* self, size_t start, size_t end);
_coral_str crl__lib__core__str___coral_str_trimStart(_coral_str* self);
_coral_str crl__lib__core__str___coral_str_trimEnd(_coral_str* self);
_coral_str crl__lib__core__str___coral_str_trim(_coral_str* self);
_Bool crl__lib__core__str___coral_str_isAsciiDigit(_coral_str* self);
_Bool crl__lib__core__str___coral_str_isAsciiAlpha(_coral_str* self);
_Bool crl__lib__core__str___coral_str_isAsciiAlnum(_coral_str* self);
void memmove(void* dst, const void* src, size_t n);
void memcpy(void* dst, const void* src, size_t n);
void* crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(void* addr, size_t length, int32_t prot, int32_t flags, int32_t fd, int64_t offset);
void crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(void* addr, size_t length);
void memset(void* dst, uint8_t val, size_t n);
int32_t memcmp(const void* a, const void* b, size_t n);
int32_t sched_yield(void);
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSizeClass(size_t size);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(uint32_t sc);
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlocksPerPage(uint32_t sc);
uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miRandomU64(void);
uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(uint64_t* p);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicStore(uint64_t* p, uint64_t v);
_Bool crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicCAS(uint64_t* p, uint64_t* expected, uint64_t desired);
uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicExchange(uint64_t* p, uint64_t v);
uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicFetchAdd(uint64_t* p, uint64_t delta);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miLockAcquire(uint64_t* p);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miLockRelease(uint64_t* p);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockEncode(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page);
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page);
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapHash(uint8_t* addr);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapInsertChain(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint32_t idx, uint8_t* pageBase, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapRemoveChain(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint32_t idx, uint8_t* pageBase);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapInsert(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint8_t* pageBase, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapRemove(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint8_t* pageBase, size_t size);
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapLookup(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint8_t* addr);
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaAlloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, size_t minSize);
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaSliceAlloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* arena, uint32_t count);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaSliceFree(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* arena, void* ptr, uint32_t count);
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentAlloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, uint32_t pageCount);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentFree(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* seg);
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageAlloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, uint32_t sc);
_Bool crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageExtend(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageFree(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, uint32_t sc);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMaybeRetire(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, uint32_t sc);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveToFull(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, uint32_t sc);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveFromFull(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, uint32_t sc);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageCollect(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page);
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAllocFast(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, uint32_t sc);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeFast(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, void* ptr);
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageFind(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, void* ptr);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miProcessDelayedFree(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_init(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, size_t reserveSize);
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_alloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, size_t size);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_free(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, void* ptr);
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_realloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, void* ptr, size_t newSize);
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_calloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, size_t count, size_t size);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getAllocated(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getFreed(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getUsed(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getMapped(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self);
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_allocator(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self);
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapRealloc(void* ctx, void* ptr, size_t newSize);
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc__miStatsPrint(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* alloc);
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_init(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* heap, size_t size);
uint32_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__fls(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, uint32_t x);
uint32_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__lsbIndex(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, uint32_t x);
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__getIndex(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, size_t size, uint32_t* fli, uint32_t* sli);
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* const block);
crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockFromPtr(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* ptr);
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__memcpy(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* dst, const void* src, size_t n);
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__ptrFromBlock(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block);
crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__nextBlock(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block);
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block);
crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__prevBlock(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block);
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__removeFree(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* block);
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__insertFree(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block);
crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__findSuitableBlock(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, size_t size, uint32_t* outFli, uint32_t* outSli);
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_alloc(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, size_t size);
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_free(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* ptr);
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_realloc(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* ptr, size_t newSize);
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_getHeapSize(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self);
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_getFreeSize(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self);
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_allocator(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self);
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapRealloc(void* ctx, void* ptr, size_t newSize);
void crl__lib__std__x86_64__linux__memory__mman__deinitDefaultAllocator(void);
void* crl__lib__std__x86_64__linux__memory__mman___libcAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___libcFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___libcRealloc(void* ctx, void* ptr, size_t newSize);
void* crl__lib__std__x86_64__linux__memory__mman___miStdAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___miStdFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___miStdRealloc(void* ctx, void* ptr, size_t newSize);
void crl__lib__std__x86_64__linux__memory__mman__ensureDefaultAllocator(void);
void crl__lib__std__x86_64__linux__memory__mman__initDefaultAllocator(void);
void* crl__lib__std__x86_64__linux__memory__mman___tlsfAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___tlsfFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___tlsfRealloc(void* ctx, void* ptr, size_t newSize);
size_t crl__lib__std__x86_64__linux__memory__mman___hbSize(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b);
_Bool crl__lib__std__x86_64__linux__memory__mman___hbIsFree(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b);
size_t crl__lib__std__x86_64__linux__memory__mman___hbAlign(size_t v);
crl__lib__std__x86_64__linux__memory__mman___HeapBlock* crl__lib__std__x86_64__linux__memory__mman___hbNext(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b);
void crl__lib__std__x86_64__linux__memory__mman___heapPushFree(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b);
void crl__lib__std__x86_64__linux__memory__mman___heapUnlink(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b);
void* crl__lib__std__x86_64__linux__memory__mman___heapAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___heapFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___heapRealloc(void* ctx, void* ptr, size_t newSize);
void* crl__lib__std__x86_64__linux__memory__mman___pageAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___pageFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___pageRealloc(void* ctx, void* ptr, size_t newSize);
void crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_init(crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* self, uint8_t* buffer, size_t size);
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* self);
void crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_reset(crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* self);
size_t crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_remaining(crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* self);
void* crl__lib__std__x86_64__linux__memory__mman___fbaAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___fbaFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___fbaRealloc(void* ctx, void* ptr, size_t newSize);
void crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator_init(crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* fallback);
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator* self);
void* crl__lib__std__x86_64__linux__memory__mman___sfaAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___sfaFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___sfaRealloc(void* ctx, void* ptr, size_t newSize);
void crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_init(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* backing, size_t initialCap);
void crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_deinit(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self);
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self);
void* crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_push(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self, size_t size);
void crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_reset(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self);
size_t crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_remaining(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self);
void* crl__lib__std__x86_64__linux__memory__mman___arenaAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___arenaFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___arenaRealloc(void* ctx, void* ptr, size_t newSize);
void crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_init(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* source, size_t blockSize, size_t blockCount);
void crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_deinit(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self);
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self);
void* crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_allocBlock(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self);
void crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_freeBlock(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self, void* block);
void* crl__lib__std__x86_64__linux__memory__mman___poolAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___poolFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___poolRealloc(void* ctx, void* ptr, size_t newSize);
void crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_init(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* backing, size_t cap);
void crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc__grow(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self);
void* crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_alloc(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self, size_t size);
void crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_freeAll(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self);
void crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_deinit(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self);
size_t crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_bytesUsed(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self);
void crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator_init(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* parent);
void crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__trackGrow(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self);
void crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__track(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self, void* ptr, size_t size);
size_t crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__untrack(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self, void* ptr);
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self);
void crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator_printStats(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self);
void* crl__lib__std__x86_64__linux__memory__mman___logAlloc(void* ctx, size_t size);
void crl__lib__std__x86_64__linux__memory__mman___logFree(void* ctx, void* ptr);
void* crl__lib__std__x86_64__linux__memory__mman___logRealloc(void* ctx, void* ptr, size_t newSize);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_new(void);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_withCap(size_t cap);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_from(_coral_str sv);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_fromCstr(char* const cstr);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_clone(crl__lib__std__x86_64__linux__text__string__String* self);
void crl__lib__std__x86_64__linux__text__string__String_free(crl__lib__std__x86_64__linux__text__string__String* self);
void crl__lib__std__x86_64__linux__text__string__String__ensure(crl__lib__std__x86_64__linux__text__string__String* self, size_t extra);
_coral_str crl__lib__std__x86_64__linux__text__string__String_asView(crl__lib__std__x86_64__linux__text__string__String* self);
char* crl__lib__std__x86_64__linux__text__string__String_asCstr(crl__lib__std__x86_64__linux__text__string__String* self);
uint8_t* crl__lib__std__x86_64__linux__text__string__String_asU8(crl__lib__std__x86_64__linux__text__string__String* self);
void crl__lib__std__x86_64__linux__text__string__String_pushChar(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c);
void crl__lib__std__x86_64__linux__text__string__String_pushByte(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t b);
void crl__lib__std__x86_64__linux__text__string__String_appendView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str sv);
void crl__lib__std__x86_64__linux__text__string__String_pushView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str sv);
void crl__lib__std__x86_64__linux__text__string__String_pushStr(crl__lib__std__x86_64__linux__text__string__String* self, crl__lib__std__x86_64__linux__text__string__String* const other);
void crl__lib__std__x86_64__linux__text__string__String_pushCstr(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t* const cstr);
void crl__lib__std__x86_64__linux__text__string__String_pushRepeat(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c, size_t n);
void crl__lib__std__x86_64__linux__text__string__String_clear(crl__lib__std__x86_64__linux__text__string__String* self);
void crl__lib__std__x86_64__linux__text__string__String_shrinkToFit(crl__lib__std__x86_64__linux__text__string__String* self);
void crl__lib__std__x86_64__linux__text__string__String_truncate(crl__lib__std__x86_64__linux__text__string__String* self, size_t newLen);
void crl__lib__std__x86_64__linux__text__string__String_insertView(crl__lib__std__x86_64__linux__text__string__String* self, size_t idx, _coral_str sv);
void crl__lib__std__x86_64__linux__text__string__String_removeRange(crl__lib__std__x86_64__linux__text__string__String* self, size_t start, size_t end);
void crl__lib__std__x86_64__linux__text__string__String_replaceAll(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str needle, _coral_str replacement);
void crl__lib__std__x86_64__linux__text__string__String_toUpper(crl__lib__std__x86_64__linux__text__string__String* self);
void crl__lib__std__x86_64__linux__text__string__String_toLower(crl__lib__std__x86_64__linux__text__string__String* self);
void crl__lib__std__x86_64__linux__text__string__String_reverse(crl__lib__std__x86_64__linux__text__string__String* self);
uint8_t crl__lib__std__x86_64__linux__text__string__String_at(crl__lib__std__x86_64__linux__text__string__String* self, size_t idx);
void crl__lib__std__x86_64__linux__text__string__String_atApply(crl__lib__std__x86_64__linux__text__string__String* self, size_t idx, uint8_t c);
_Bool crl__lib__std__x86_64__linux__text__string__String_isEmpty(crl__lib__std__x86_64__linux__text__string__String* self);
_Bool crl__lib__std__x86_64__linux__text__string__String_equals(crl__lib__std__x86_64__linux__text__string__String* self, crl__lib__std__x86_64__linux__text__string__String* const other);
_Bool crl__lib__std__x86_64__linux__text__string__String_equalsView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str sv);
int32_t crl__lib__std__x86_64__linux__text__string__String_compare(crl__lib__std__x86_64__linux__text__string__String* self, crl__lib__std__x86_64__linux__text__string__String* const other);
size_t crl__lib__std__x86_64__linux__text__string__String_findChar(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c);
size_t crl__lib__std__x86_64__linux__text__string__String_rfindChar(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c);
size_t crl__lib__std__x86_64__linux__text__string__String_findView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str needle);
_Bool crl__lib__std__x86_64__linux__text__string__String_startsWith(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str prefix);
_Bool crl__lib__std__x86_64__linux__text__string__String_endsWith(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str suffix);
_Bool crl__lib__std__x86_64__linux__text__string__String_containsView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str needle);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_trim(crl__lib__std__x86_64__linux__text__string__String* self);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_trimStart(crl__lib__std__x86_64__linux__text__string__String* self);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_trimEnd(crl__lib__std__x86_64__linux__text__string__String* self);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_substr(crl__lib__std__x86_64__linux__text__string__String* self, size_t start, size_t end);
Vec__coral_str crl__lib__std__x86_64__linux__text__string__String_splitByte(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t delim);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_repeat(crl__lib__std__x86_64__linux__text__string__String* self, size_t n);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_join(_coral_str sep, Vec__coral_str* const parts);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_padLeft(crl__lib__std__x86_64__linux__text__string__String* self, size_t totalLen, uint8_t padChar);
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_padRight(crl__lib__std__x86_64__linux__text__string__String* self, size_t totalLen, uint8_t padChar);
size_t crl__lib__std__x86_64__linux__text__string__String_countChar(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c);
void crl__lib__std__x86_64__linux__text__string__String_drop(crl__lib__std__x86_64__linux__text__string__String* self);
void crl__lib__std__x86_64__linux__io__ios___writeStr(int32_t fd, _coral_str s);
void crl__lib__std__x86_64__linux__io__ios___pflush(crl__lib__std__x86_64__linux__io__ios___Buf* out);
void crl__lib__std__x86_64__linux__io__ios___pbyte(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint8_t c);
void crl__lib__std__x86_64__linux__io__ios___pbytes(crl__lib__std__x86_64__linux__io__ios___Buf* out, char* const s, size_t n);
size_t crl__lib__std__x86_64__linux__io__ios___itoa(uint8_t* dst, uint64_t val, uint32_t base, _Bool neg);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintSigned(crl__lib__std__x86_64__linux__io__ios___Buf* out, int64_t v, uint32_t base);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint64_t v, uint32_t base, _Bool prefix);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintI8(crl__lib__std__x86_64__linux__io__ios___Buf* out, int8_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintI16(crl__lib__std__x86_64__linux__io__ios___Buf* out, int16_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintI32(crl__lib__std__x86_64__linux__io__ios___Buf* out, int32_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintI64(crl__lib__std__x86_64__linux__io__ios___Buf* out, int64_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintU8(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint8_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintU16(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint16_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintU32(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint32_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintU64(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint64_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintF32(crl__lib__std__x86_64__linux__io__ios___Buf* out, float v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintF64(crl__lib__std__x86_64__linux__io__ios___Buf* out, double v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintBool(crl__lib__std__x86_64__linux__io__ios___Buf* out, _Bool v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintChar(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint8_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintPtr(crl__lib__std__x86_64__linux__io__ios___Buf* out, const void* v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintCstr(crl__lib__std__x86_64__linux__io__ios___Buf* out, char* const s);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintBytes(crl__lib__std__x86_64__linux__io__ios___Buf* out, char* const ptr, size_t len);
void crl__lib__std__x86_64__linux__io__ios___fprintNewline(crl__lib__std__x86_64__linux__io__ios___Buf* out);
void crl__lib__std__x86_64__linux__io__ios___fprintFlush(int32_t fd);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintHex(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint64_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintBin(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint64_t v);
int32_t crl__lib__std__x86_64__linux__io__ios___fprintFixed(crl__lib__std__x86_64__linux__io__ios___Buf* out, double value, uint64_t precision);
int32_t crl__lib__std__x86_64__linux__io__ios___sysReadByte(void);
size_t crl__lib__std__x86_64__linux__io__ios___sysReadLine(uint8_t* buf, size_t maxBytes);
void crl__lib__std__x86_64__linux__io__ios__vaprint(...);
crl__lib__std__x86_64__linux__io__ios__Spaces crl__lib__std__x86_64__linux__io__ios__spaces(uint64_t count);
crl__lib__std__x86_64__linux__io__ios__Repeat crl__lib__std__x86_64__linux__io__ios__repeat(uint8_t ch, uint64_t count);
crl__lib__std__x86_64__linux__io__ios__Hex crl__lib__std__x86_64__linux__io__ios__hex(uint64_t value);
crl__lib__std__x86_64__linux__io__ios__Bin crl__lib__std__x86_64__linux__io__ios__bin(uint64_t value);
crl__lib__std__x86_64__linux__io__ios__Fixed crl__lib__std__x86_64__linux__io__ios__fixed(double value, uint64_t precision);
void crl__lib__std__x86_64__linux__io__ios__flush(void);
int64_t crl__lib__std__x86_64__linux__io__ios___readI64(void);
uint64_t crl__lib__std__x86_64__linux__io__ios___readU64(void);
double crl__lib__std__x86_64__linux__io__ios___readF64(void);
_Bool crl__lib__std__x86_64__linux__io__ios___readBool(void);
int64_t crl__lib__std__x86_64__linux__io__ios__parseI64(_coral_str sv, _Bool* ok);
uint64_t crl__lib__std__x86_64__linux__io__ios__parseU64(_coral_str sv, _Bool* ok);
double crl__lib__std__x86_64__linux__io__ios__parseF64(_coral_str sv, _Bool* ok);
uint8_t crl__lib__std__x86_64__linux__io__ios__readChar(void);
_Bool crl__lib__std__x86_64__linux__io__ios__readLine(crl__lib__std__x86_64__linux__text__string__String* out);
int32_t crl__loc__m1__m1__ga(void);
int32_t main(void);
void crl__lib__std__x86_64__linux__memory__mman__copy_voidp(void** dst, void** src, size_t count);
void crl__lib__std__x86_64__linux__memory__mman__copy_size_t(size_t* dst, size_t* src, size_t count);
uint8_t* crl__lib__std__x86_64__linux__memory__mman__alloc_uint8_t(size_t count);
void crl__lib__std__x86_64__linux__memory__mman__dealloc_uint8_t(uint8_t* ptr);
uint8_t* crl__lib__std__x86_64__linux__memory__mman__realloc_uint8_t(uint8_t* ptr, size_t newCount);
Vec__coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_new(void);
Vec__coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_withCap(size_t capacity);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_reserve(Vec__coral_str* self, size_t newCap);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_push(Vec__coral_str* self, _coral_str val);
_coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_pop(Vec__coral_str* self);
size_t crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_count(Vec__coral_str* self);
_coral_str* crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_atPtr(Vec__coral_str* self, size_t i);
_coral_str* const crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_atConst(Vec__coral_str* self, size_t i);
_coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_at(Vec__coral_str* self, size_t i);
_coral_str* crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_ptr(Vec__coral_str* self);
_Bool crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_isEmpty(Vec__coral_str* self);
_coral_str* const crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_constPtr(Vec__coral_str* self);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_set(Vec__coral_str* self, size_t i, _coral_str val);
_coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_front(Vec__coral_str* self);
_coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_back(Vec__coral_str* self);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_insert(Vec__coral_str* self, size_t i, _coral_str val);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_removeAt(Vec__coral_str* self, size_t i);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_removeRange(Vec__coral_str* self, size_t start, size_t end);
_Bool crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_contains(Vec__coral_str* self, _coral_str val);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_fill(Vec__coral_str* self, _coral_str val);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_reserveExact(Vec__coral_str* self, size_t newCap);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_shrinkToFit(Vec__coral_str* self);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_clear(Vec__coral_str* self);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_reverse(Vec__coral_str* self);
_Bool crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_isSortedBy(Vec__coral_str* self, FnP__Bool__coral_str__coral_str less);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_sortBy(Vec__coral_str* self, FnP__Bool__coral_str__coral_str less);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str__sortByRange(Vec__coral_str* self, size_t lo, size_t hi, FnP__Bool__coral_str__coral_str less);
size_t crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str__partitionBy(Vec__coral_str* self, size_t lo, size_t hi, FnP__Bool__coral_str__coral_str less);
int64_t crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_binarySearchBy(Vec__coral_str* self, _coral_str key, FnP_int32_t__coral_str__coral_str cmp);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_dispose(Vec__coral_str* self);
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_drop(Vec__coral_str* self);
void crl__lib__std__x86_64__linux__memory__mman__copy_uint8_t(uint8_t* dst, uint8_t* src, size_t count);
void crl__lib__std__x86_64__linux__io__ios__println__coral_str_v6189685f387084b6(_coral_str fmt, int32_t _varg0);
_coral_str* crl__lib__std__x86_64__linux__memory__mman__alloc__coral_str(size_t count);
_coral_str* crl__lib__std__x86_64__linux__memory__mman__realloc__coral_str(_coral_str* ptr, size_t newCount);
void crl__lib__std__x86_64__linux__memory__mman__dealloc__coral_str(_coral_str* ptr);extern char** environ;
uint8_t crl__lib__core__char_util__newline = (uint32_t)10;
uint8_t crl__lib__core__char_util__tab = (uint32_t)9;
uint8_t crl__lib__core__char_util__space = ' ';
uint8_t crl__lib__core__char_util__nullu8 = (uint32_t)0;
uint8_t crl__lib__core__char_util__carriageReturn = (uint32_t)13;
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_ARENA_SIZE = ((64*1024)*1024);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SEGMENT_SIZE = ((4*1024)*1024);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_PAGE_SIZE = (64*1024);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE = (64*1024);
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_ALIGN = 16;
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_MAX_BLOCK_SIZE = (512*1024);
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SMALL_PAGE_MAX = (64*1024);
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_MEDIUM_PAGE_MAX = (512*1024);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_HUGE_THRESHOLD = (128*1024);
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_INITIAL_CAPACITY = 4;
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SEGMENT_MAP_SIZE = 64;
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SIZE_CLASS_COUNT = 44;
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_BLOCK_SIZES[44] = {8, 16, 24, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384, 448, 512, 640, 768, 896, 1024, 1280, 1536, 1792, 2048, 2560, 3072, 3584, 4096, 5120, 6144, 7168, 8192, 10240, 12288, 14336, 16384, 20480, 24576, 28672, 32768};
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_PAGE_SIZES[44] = {4096, 4096, 4096, 4096, 4096, 4096, 4096, 4096, 8192, 8192, 8192, 8192, 16384, 16384, 16384, 16384, 32768, 32768, 32768, 32768, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536, 65536};
uint8_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SIZE_CLASS_SMALL[129] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11};
static crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miGlobalPages;
static uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapLockWord = 0;
uint32_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__FLI_COUNT = 32;
uint32_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__SLI_COUNT = 32;
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__MIN_BLOCK_SIZE = 32;
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_ALIGN = 8;
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_USED = 1;
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED = 2;
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* crl__lib__std__x86_64__linux__memory__mman__defaultAllocator;
void* crl__lib__std__x86_64__linux__memory__mman___defaultAllocHeap;
size_t crl__lib__std__x86_64__linux__memory__mman___defaultAllocHeapSize;
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__libcAllocator = (crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = 0, .alloc = crl__lib__std__x86_64__linux__memory__mman___libcAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___libcFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___libcRealloc};
static crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc crl__lib__std__x86_64__linux__memory__mman___miAllocInstance;
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__miAllocator = (crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = 0, .alloc = crl__lib__std__x86_64__linux__memory__mman___miStdAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___miStdFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___miStdRealloc};
size_t crl__lib__std__x86_64__linux__memory__mman___HB_ALIGN = 16;
size_t crl__lib__std__x86_64__linux__memory__mman___HB_HDR = 16;
size_t crl__lib__std__x86_64__linux__memory__mman___HB_FREE = 1;
crl__lib__std__x86_64__linux__memory__mman___HeapBlock* crl__lib__std__x86_64__linux__memory__mman___heapFreeHead;
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__cAllocator = (crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = 0, .alloc = crl__lib__std__x86_64__linux__memory__mman___heapAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___heapFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___heapRealloc};
size_t crl__lib__std__x86_64__linux__memory__mman__pageSize = 4096;
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__pageAllocator = (crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = 0, .alloc = crl__lib__std__x86_64__linux__memory__mman___pageAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___pageFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___pageRealloc};
int64_t crl__lib__core__limits__INT64_MIN = -(9223372036854775808);
int64_t crl__lib__core__limits__INT64_MAX = 9223372036854775807;
int32_t crl__lib__core__limits__INT32_MIN = -(2147483648);
int32_t crl__lib__core__limits__INT32_MAX = 2147483647;
int32_t crl__lib__core__limits__INT16_MIN = -(32768);
int32_t crl__lib__core__limits__INT16_MAX = 32767;
int32_t crl__lib__core__limits__INT8_MIN = -(128);
int32_t crl__lib__core__limits__INT8_MAX = 127;
uint64_t crl__lib__core__limits__U64_MAX = 18446744073709551615;
uint32_t crl__lib__core__limits__U32_MAX = 4294967295;
uint32_t crl__lib__core__limits__U16_MAX = 65535;
uint32_t crl__lib__core__limits__U8_MAX = 255;
double crl__lib__core__limits__F64_MAX = 1.7976931348623157e+308;
double crl__lib__core__limits__F64_MIN = 2.2250738585072014e-308;
double crl__lib__core__limits__F32_MAX = 3.40282347e+38;
double crl__lib__core__limits__F32_MIN = 1.17549435e-38;

_Bool crl__lib__core__char_util__isDigit(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((v >= ((uint16_t)('0'))))) && (((v <= ((uint16_t)('9'))))));
}
_Bool crl__lib__core__char_util__isAlpha(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((((v >= ((uint16_t)('a'))))) && (((v <= ((uint16_t)('z'))))))) || (((((v >= ((uint16_t)('A'))))) && (((v <= ((uint16_t)('Z'))))))));
}
_Bool crl__lib__core__char_util__isAlnum(uint8_t c) {
    return ((crl__lib__core__char_util__isDigit(c)) || (crl__lib__core__char_util__isAlpha(c)));
}
_Bool crl__lib__core__char_util__isLower(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((v >= ((uint16_t)('a'))))) && (((v <= ((uint16_t)('z'))))));
}
_Bool crl__lib__core__char_util__isUpper(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((v >= ((uint16_t)('A'))))) && (((v <= ((uint16_t)('Z'))))));
}
uint8_t crl__lib__core__char_util__toLower(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    if (((((v >= ((uint16_t)('A'))))) && (((v <= ((uint16_t)('Z')))))))
    {
        return ((uint8_t)(((v + 32))));
    }
    return c;
}
uint8_t crl__lib__core__char_util__toUpper(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    if (((((v >= ((uint16_t)('a'))))) && (((v <= ((uint16_t)('z')))))))
    {
        return ((uint8_t)(((v - 32))));
    }
    return c;
}
_Bool crl__lib__core__char_util__isSpace(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((((((((((v == ((uint16_t)(' '))))) || (((v == ((uint16_t)((uint32_t)9))))))) || (((v == ((uint16_t)((uint32_t)10))))))) || (((v == ((uint16_t)((uint32_t)13))))))) || (((v == ((uint16_t)((uint32_t)12))))))) || (((v == ((uint16_t)((uint32_t)11))))));
}
_Bool crl__lib__core__char_util__isPrint(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((v >= 32))) && (((v <= 126))));
}
_Bool crl__lib__core__char_util__isControl(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((v < 32))) || (((v == 127))));
}
_Bool crl__lib__core__char_util__isHexDigit(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((((((v >= ((uint16_t)('0'))))) && (((v <= ((uint16_t)('9'))))))) || (((((v >= ((uint16_t)('a'))))) && (((v <= ((uint16_t)('f'))))))))) || (((((v >= ((uint16_t)('A'))))) && (((v <= ((uint16_t)('F'))))))));
}
uint8_t crl__lib__core__char_util__digitValue(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    if (((((v >= ((uint16_t)('0'))))) && (((v <= ((uint16_t)('9')))))))
    {
        return ((uint8_t)(((v - ((uint16_t)('0'))))));
    }
    if (((((v >= ((uint16_t)('a'))))) && (((v <= ((uint16_t)('f')))))))
    {
        return ((uint8_t)(((((v - ((uint16_t)('a')))) + 10))));
    }
    if (((((v >= ((uint16_t)('A'))))) && (((v <= ((uint16_t)('F')))))))
    {
        return ((uint8_t)(((((v - ((uint16_t)('A')))) + 10))));
    }
    return ((uint8_t)(0));
}
_Bool crl__lib__core__char_util__isAscii(uint8_t c) {
    return ((((uint16_t)(c)) <= 127));
}
_Bool crl__lib__core__char_util__isWhitespace(uint8_t c) {
    return crl__lib__core__char_util__isSpace(c);
}
_Bool crl__lib__core__char_util__isNewline(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((v == ((uint16_t)((uint32_t)10))))) || (((v == ((uint16_t)((uint32_t)13))))));
}
_Bool crl__lib__core__char_util__isPunctuation(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((((((((v >= 33))) && (((v <= 47))))) || (((((v >= 58))) && (((v <= 64))))))) || (((((v >= 91))) && (((v <= 96))))))) || (((((v >= 123))) && (((v <= 126))))));
}
_Bool crl__lib__core__char_util__isSymbol(uint8_t c) {
    uint16_t v = ((uint16_t)(c));
    return ((((((((((((((((((((((((((((((v == ((uint16_t)('+'))))) || (((v == ((uint16_t)('-'))))))) || (((v == ((uint16_t)('*'))))))) || (((v == ((uint16_t)('/'))))))) || (((v == ((uint16_t)('='))))))) || (((v == ((uint16_t)('<'))))))) || (((v == ((uint16_t)('>'))))))) || (((v == ((uint16_t)('!'))))))) || (((v == ((uint16_t)('&'))))))) || (((v == ((uint16_t)('|'))))))) || (((v == ((uint16_t)('^'))))))) || (((v == ((uint16_t)('~'))))))) || (((v == ((uint16_t)('%'))))))) || (((v == ((uint16_t)('?'))))))) || (((v == ((uint16_t)('@'))))));
}
uint32_t crl__lib__core__char_util__utf8Width(uint32_t c) {
    if (((c <= 127)))
    {
        return 1;
    }
    if (((c <= 2047)))
    {
        return 2;
    }
    if (((c <= 65535)))
    {
        return 3;
    }
    return 4;
}
uint32_t crl__lib__core__char_util__encodeUtf8(uint32_t c, uint8_t* buf) {
    if (((c <= 127)))
    {
        ((buf[0] = ((uint8_t)(c))));
        return 1;
    }
    if (((c <= 2047)))
    {
        ((buf[0] = ((uint8_t)(((192 | ((c >> 6))))))));
        ((buf[1] = ((uint8_t)(((128 | ((c & 63))))))));
        return 2;
    }
    if (((c <= 65535)))
    {
        ((buf[0] = ((uint8_t)(((224 | ((c >> 12))))))));
        ((buf[1] = ((uint8_t)(((128 | ((((c >> 6)) & 63))))))));
        ((buf[2] = ((uint8_t)(((128 | ((c & 63))))))));
        return 3;
    }
    ((buf[0] = ((uint8_t)(((240 | ((c >> 18))))))));
    ((buf[1] = ((uint8_t)(((128 | ((((c >> 12)) & 63))))))));
    ((buf[2] = ((uint8_t)(((128 | ((((c >> 6)) & 63))))))));
    ((buf[3] = ((uint8_t)(((128 | ((c & 63))))))));
    return 4;
}
_coral_tuple_uint32_t_uint32_t crl__lib__core__char_util__decodeUtf8(uint8_t* const buf) {
    uint8_t b0 = buf[0];
    if (((b0 <= 127)))
    {
        return ((_coral_tuple_uint32_t_uint32_t){((uint32_t)(b0)), 1});
    }
    if (((((b0 & 224)) == 192)))
    {
        return ((_coral_tuple_uint32_t_uint32_t){((((((uint32_t)(((b0 & 31)))) << 6)) | ((uint32_t)(((buf[1] & 63)))))), 2});
    }
    if (((((b0 & 240)) == 224)))
    {
        return ((_coral_tuple_uint32_t_uint32_t){((((((((uint32_t)(((b0 & 15)))) << 12)) | ((((uint32_t)(((buf[1] & 63)))) << 6)))) | ((uint32_t)(((buf[2] & 63)))))), 3});
    }
    return ((_coral_tuple_uint32_t_uint32_t){((((((((((uint32_t)(((b0 & 7)))) << 18)) | ((((uint32_t)(((buf[1] & 63)))) << 12)))) | ((((uint32_t)(((buf[2] & 63)))) << 6)))) | ((uint32_t)(((buf[3] & 63)))))), 4});
}
uint32_t crl__lib__core__char_util__toUtf8(uint32_t c, uint8_t* buf) {
    return crl__lib__core__char_util__encodeUtf8(c, buf);
}
uint32_t crl__lib__core__char_util__fromUtf8(uint8_t* const buf) {
    _coral_tuple_uint32_t_uint32_t r = crl__lib__core__char_util__decodeUtf8(buf);
    return r._1;
}
uint8_t crl__lib__core__char_util__toAscii(uint8_t c) {
    return ((c & 127));
}
_Bool crl__lib__core__char_util__u8Eq(uint8_t a, uint8_t b) {
    return ((a == b));
}
_Bool crl__lib__core__char_util__u8EqLower(uint8_t a, uint8_t b) {
    return ((crl__lib__core__char_util__toLower(a) == crl__lib__core__char_util__toLower(b)));
}
int32_t crl__lib__core__char_util__u8Cmp(uint8_t a, uint8_t b) {
    uint16_t av = ((uint16_t)(a));
    uint16_t bv = ((uint16_t)(b));
    if (((av < bv)))
    {
        return (-(1));
    }
    if (((av > bv)))
    {
        return 1;
    }
    return 0;
}
uint32_t crl__lib__core__char_util__toStr(uint8_t c, uint8_t* buf) {
    return crl__lib__core__char_util__encodeUtf8(((uint32_t)(c)), buf);
}
_coral_str crl__lib__core__str___coral_str_fromCstr(char* const cstr) {
    return ((_coral_str){.ptr = ((uint8_t* const)(cstr)), .len = ((size_t)(strlen(cstr)))});
}
_coral_str crl__lib__core__str___coral_str_fromParts(uint8_t* const ptr, size_t len) {
    return ((_coral_str){.ptr = ptr, .len = len});
}
_coral_str crl__lib__core__str___coral_str_empty(void) {
    return (_coral_str){ (const uint8_t*)"", 0 };
}
uint8_t* const crl__lib__core__str___coral_str_asU8(_coral_str* self) {
    return self->ptr;
}
uint8_t crl__lib__core__str___coral_str_at(_coral_str* self, size_t idx) {
    assert(((idx < self->len)));
    0;
    return self->ptr[idx];
}
_Bool crl__lib__core__str___coral_str_isEmpty(_coral_str* self) {
    return ((self->len == 0));
}
_Bool crl__lib__core__str___coral_str_equals(_coral_str* self, _coral_str other) {
    if (((self->len != other.len)))
    {
        return 0;
    }
    return ((memcmp(((void* const)(self->ptr)), ((void* const)(other.ptr)), ((uint64_t)(self->len))) == 0));
}
int32_t crl__lib__core__str___coral_str_compare(_coral_str* self, _coral_str other) {
    size_t minLen = ((((self->len < other.len))) ? (self->len) : (other.len));
    int32_t r = memcmp(((void* const)(self->ptr)), ((void* const)(other.ptr)), ((uint64_t)(minLen)));
    if (((r != 0)))
    {
        return r;
    }
    if (((self->len < other.len)))
    {
        return (-(1));
    }
    if (((self->len > other.len)))
    {
        return 1;
    }
    return 0;
}
_Bool crl__lib__core__str___coral_str_startsWith(_coral_str* self, _coral_str prefix) {
    if (((prefix.len > self->len)))
    {
        return 0;
    }
    return ((memcmp(((void* const)(self->ptr)), ((void* const)(prefix.ptr)), ((uint64_t)(prefix.len))) == 0));
}
_Bool crl__lib__core__str___coral_str_endsWith(_coral_str* self, _coral_str suffix) {
    if (((suffix.len > self->len)))
    {
        return 0;
    }
    return ((memcmp(((void* const)(((self->ptr + ((self->len - suffix.len)))))), ((void* const)(suffix.ptr)), ((uint64_t)(suffix.len))) == 0));
}
_Bool crl__lib__core__str___coral_str_containsView(_coral_str* self, _coral_str needle) {
    return ((crl__lib__core__str___coral_str_findView(self, needle) < self->len));
}
_Bool crl__lib__core__str___coral_str_containsByte(_coral_str* self, uint8_t c) {
    return ((crl__lib__core__str___coral_str_findByte(self, c) < self->len));
}
size_t crl__lib__core__str___coral_str_findByte(_coral_str* self, uint8_t c) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        if (((self->ptr[i] == c)))
        {
            return i;
        }
    }
    return self->len;
}
size_t crl__lib__core__str___coral_str_rfindByte(_coral_str* self, uint8_t c) {
    size_t i = self->len;
    while (((i > 0)))
    {
        ((i)--);
        if (((self->ptr[i] == c)))
        {
            return i;
        }
    }
    return self->len;
}
size_t crl__lib__core__str___coral_str_findView(_coral_str* self, _coral_str needle) {
    if (((needle.len == 0)))
    {
        return 0;
    }
    if (((needle.len > self->len)))
    {
        return self->len;
    }
    for (
    size_t i = 0;((i <= ((self->len - needle.len))));((i)++))
    {
        if (((memcmp(((void* const)(((self->ptr + i)))), ((void* const)(needle.ptr)), ((uint64_t)(needle.len))) == 0)))
        {
            return i;
        }
    }
    return self->len;
}
_coral_str crl__lib__core__str___coral_str_slice(_coral_str* self, size_t start, size_t end) {
    assert(((start <= end)));
    0;
    assert(((end <= self->len)));
    0;
    return crl__lib__core__str___coral_str_fromParts(((self->ptr + start)), ((end - start)));
}
_coral_str crl__lib__core__str___coral_str_trimStart(_coral_str* self) {
    size_t i = 0;
    while (((((i < self->len))) && (((((((((self->ptr[i] == ((uint8_t)(' '))))) || (((self->ptr[i] == ((uint8_t)((uint32_t)9))))))) || (((self->ptr[i] == ((uint8_t)((uint32_t)10))))))) || (((self->ptr[i] == ((uint8_t)((uint32_t)13)))))))))
    {
        ((i)++);
    }
    return crl__lib__core__str___coral_str_fromParts(((self->ptr + i)), ((self->len - i)));
}
_coral_str crl__lib__core__str___coral_str_trimEnd(_coral_str* self) {
    size_t e = self->len;
    while (((((e > 0))) && (((((((((self->ptr[((e - 1))] == ((uint8_t)(' '))))) || (((self->ptr[((e - 1))] == ((uint8_t)((uint32_t)9))))))) || (((self->ptr[((e - 1))] == ((uint8_t)((uint32_t)10))))))) || (((self->ptr[((e - 1))] == ((uint8_t)((uint32_t)13)))))))))
    {
        ((e)--);
    }
    return crl__lib__core__str___coral_str_fromParts(self->ptr, e);
}
_coral_str crl__lib__core__str___coral_str_trim(_coral_str* self) {
    _coral_str t = crl__lib__core__str___coral_str_trimStart(self);
    return crl__lib__core__str___coral_str_trimEnd((&(t)));
}
_Bool crl__lib__core__str___coral_str_isAsciiDigit(_coral_str* self) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        uint8_t c = self->ptr[i];
        if ((!(crl__lib__core__char_util__isDigit(c))))
        {
            return 0;
        }
    }
    return ((self->len > 0));
}
_Bool crl__lib__core__str___coral_str_isAsciiAlpha(_coral_str* self) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        uint8_t c = self->ptr[i];
        if ((!(crl__lib__core__char_util__isAlpha(c))))
        {
            return 0;
        }
    }
    return ((self->len > 0));
}
_Bool crl__lib__core__str___coral_str_isAsciiAlnum(_coral_str* self) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        uint8_t c = self->ptr[i];
        if ((!(crl__lib__core__char_util__isAlnum(c))))
        {
            return 0;
        }
    }
    return ((self->len > 0));
}
void memmove(void* dst, const void* src, size_t n) {
    if (((n == 0)))
    {
        return;
    }
    uint8_t* d = ((uint8_t*)(dst));
    uint8_t* s = ((uint8_t* const)(src));
    if (((d == s)))
    {
        return;
    }
    if (((d < s)))
    {
        memcpy(dst, src, n);
        return;
    }
    size_t i = n;
    while (((i > 0)))
    {
        ((i)--);
        ((d[i] = s[i]));
    }
}
void memcpy(void* dst, const void* src, size_t n) {
    if (((n == 0)))
    {
        return;
    }
    uint8_t* d = ((uint8_t*)(dst));
    uint8_t* s = ((uint8_t* const)(src));
    size_t i = 0;
    while (((((i + 8)) <= n)))
    {
        (((*(((size_t*)(((d + i)))))) = (*(((size_t* const)(((s + i))))))));
        ((i += 8));
    }
    while (((i < n)))
    {
        ((d[i] = s[i]));
        ((i)++);
    }
}
void* crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(void* addr, size_t length, int32_t prot, int32_t flags, int32_t fd, int64_t offset) {
    size_t ret;
    __asm__ volatile ("movq %2, %%rdi\n\tmovq %3, %%rsi\n\tmovq %4, %%rdx\n\tmovq %5, %%r10\n\tmovq %6, %%r8\n\tmovq %7, %%r9\n\tsyscall\n\tmovq %%rax, %0" : "=a"(ret) : "0"(9), "D"(((size_t)(addr))), "S"(length), "d"(((size_t)(prot))), "r"(((size_t)(flags))), "r"(((size_t)(fd))), "r"(((size_t)(offset))) : "rcx", "r8", "r9", "r10", "r11", "memory");
    if (((((((int64_t)(ret)) < 0))) && (((((int64_t)(ret)) >= (-(4095)))))))
    {
        return 0;
    }
    return ((void*)(ret));
}
void crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(void* addr, size_t length) {
    size_t ret;
    __asm__ volatile ("syscall\n\tmovq %%rax, %0" : "=a"(ret) : "0"(11), "D"(((size_t)(addr))), "S"(length) : "rcx", "r11", "memory");
}
void memset(void* dst, uint8_t val, size_t n) {
    uint8_t* d = ((uint8_t*)(dst));
    for (
    size_t i = 0;((i < n));((i)++))
    {
        ((d[i] = val));
    }
}
int32_t memcmp(const void* a, const void* b, size_t n) {
    uint8_t* pa = ((uint8_t* const)(a));
    uint8_t* pb = ((uint8_t* const)(b));
    for (
    size_t i = 0;((i < n));((i)++))
    {
        if (((pa[i] < pb[i])))
        {
            return (-(1));
        }
        if (((pa[i] > pb[i])))
        {
            return 1;
        }
    }
    return 0;
}
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSizeClass(size_t size) {
    if (((size == 0)))
    {
        return 0;
    }
    if (((size <= 128)))
    {
        return ((uint32_t)(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SIZE_CLASS_SMALL[size]));
    }
    if (((size <= 1024)))
    {
        return ((8 + ((uint32_t)(((((size - 129)) / 16))))));
    }
    for (
    uint32_t i = 0;((i < crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SIZE_CLASS_COUNT));((i)++))
    {
        if (((size <= ((size_t)(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_BLOCK_SIZES[i])))))
        {
            return i;
        }
    }
    return ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SIZE_CLASS_COUNT - 1));
}
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(uint32_t sc) {
    return ((size_t)(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_BLOCK_SIZES[sc]));
}
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlocksPerPage(uint32_t sc) {
    size_t blockSize = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(sc);
    size_t pageSize = ((size_t)(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_PAGE_SIZES[sc]));
    size_t metaSize = ((((sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage) + 255)) & (~(((size_t)(255))))));
    size_t usable = ((pageSize - metaSize));
    return ((uint32_t)(((usable / blockSize))));
}
uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miRandomU64(void) {
    static uint64_t state = 1311768467463790320;
    ((state = ((((state * 6364136223846793005)) + 1442695040888963407))));
    return state;
}
uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(uint64_t* p) {
    uint64_t v;
    __asm__ volatile ("movq %1, %0" : "=r"(v) : "m"((*(p))) : "memory");
    return v;
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicStore(uint64_t* p, uint64_t v) {
    __asm__ volatile ("movq %1, %0" : "=m"((*(p))) : "r"(v) : "memory");
}
_Bool crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicCAS(uint64_t* p, uint64_t* expected, uint64_t desired) {
    uint8_t ok;
    __asm__ volatile ("lock cmpxchgq %3, %1\n\tsete %0" : "=q"(ok), "+m"((*(p))), "+a"((*(expected))) : "r"(desired) : "cc", "memory");
    return ((ok != 0));
}
uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicExchange(uint64_t* p, uint64_t v) {
    uint64_t old = v;
    __asm__ volatile ("xchgq %0, %1" : "+r"(old), "+m"((*(p))) :  : "memory");
    return old;
}
uint64_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicFetchAdd(uint64_t* p, uint64_t delta) {
    uint64_t result;
    __asm__ volatile ("lock xaddq %0, %1" : "=r"(result), "=m"((*(p))) : "0"(delta), "m"((*(p))) : "memory");
    return result;
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miLockAcquire(uint64_t* p) {
    for (
    uint32_t i = 0;((i < 10000));((i)++))
    {
        uint64_t expected = 0;
        if (crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicCAS(p, (&(expected)), 1))
        {
            return;
        }
        sched_yield();
    }
    printf(((char* const)("mimalloc: internal error: lock cannot be acquired\n")));
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miLockRelease(uint64_t* p) {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicStore(p, 0);
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockEncode(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page) {
    uint64_t raw = ((uint64_t)(next));
    uint64_t rot = ((((((raw ^ page->key2)) << page->key1)) | ((((raw ^ page->key2)) >> ((64 - page->key1))))));
    ((block->next = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(((rot + page->key1))))));
}
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page) {
    uint64_t encoded = ((uint64_t)(block->next));
    uint64_t raw = ((((((encoded - page->key1)) >> page->key1)) | ((((encoded - page->key1)) << ((64 - page->key1))))));
    ((raw = ((raw ^ page->key2))));
    if (((raw == 0)))
    {
        return 0;
    }
    uint8_t* p = ((uint8_t*)(raw));
    uint8_t* end = ((page->base + ((page->capacity * page->blockSize))));
    if (((((((p < page->base))) || (((p >= end))))) || (((((((size_t)(((p - page->base)))) % page->blockSize)) != 0)))))
    {
        printf(((char* const)("mimalloc: corrupted free list entry\n")));
        return 0;
    }
    return ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(raw));
}
uint32_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapHash(uint8_t* addr) {
    uint64_t val = ((((uint64_t)(addr)) >> 22));
    ((val = ((val ^ ((val >> 16))))));
    return ((uint32_t)(((val % ((uint64_t)(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SEGMENT_MAP_SIZE))))));
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapInsertChain(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint32_t idx, uint8_t* pageBase, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page) {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry* entry = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry*)(crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(0, sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry), 3, 34, (-(1)), 0)));
    if (((entry == 0)))
    {
        return;
    }
    ((entry->pageBase = pageBase));
    ((entry->page = page));
    ((entry->next = map->buckets[idx]));
    ((map->buckets[idx] = entry));
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapRemoveChain(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint32_t idx, uint8_t* pageBase) {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry* prev = 0;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry* entry = map->buckets[idx];
    while (((entry != 0)))
    {
        if (((entry->pageBase == pageBase)))
        {
            if (((prev != 0)))
            {
                ((prev->next = entry->next));
            }
            else
            {
                ((map->buckets[idx] = entry->next));
            }
            crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(((void*)(entry)), sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry));
            return;
        }
        ((prev = entry));
        ((entry = entry->next));
    }
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapInsert(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint8_t* pageBase, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page) {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miLockAcquire((&(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapLockWord)));
    size_t size = ((page->capacity * page->blockSize));
    if (((size == 0)))
    {
        ((size = 1));
    }
    uint64_t start = ((((uint64_t)(pageBase)) & (~(((uint64_t)(4194303))))));
    uint64_t end = ((((((((uint64_t)(pageBase)) + ((uint64_t)(size)))) - 1)) & (~(((uint64_t)(4194303))))));
    for (
    uint64_t w = start;((w <= end));((w += ((uint64_t)(4194304)))))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapInsertChain(map, crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapHash(((uint8_t*)(w))), pageBase, page);
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miLockRelease((&(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapLockWord)));
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapRemove(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint8_t* pageBase, size_t size) {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miLockAcquire((&(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapLockWord)));
    if (((size == 0)))
    {
        ((size = 1));
    }
    uint64_t start = ((((uint64_t)(pageBase)) & (~(((uint64_t)(4194303))))));
    uint64_t end = ((((((((uint64_t)(pageBase)) + ((uint64_t)(size)))) - 1)) & (~(((uint64_t)(4194303))))));
    for (
    uint64_t w = start;((w <= end));((w += ((uint64_t)(4194304)))))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapRemoveChain(map, crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapHash(((uint8_t*)(w))), pageBase);
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miLockRelease((&(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miMapLockWord)));
}
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapLookup(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMap* map, uint8_t* addr) {
    uint32_t idx = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapHash(addr);
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry* entry = map->buckets[idx];
    while (((entry != 0)))
    {
        if (((entry->pageBase == addr)))
        {
            return entry->page;
        }
        ((entry = entry->next));
    }
    return 0;
}
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaAlloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, size_t minSize) {
    size_t arenaSize = crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_ARENA_SIZE;
    if (((arenaSize < minSize)))
    {
        ((arenaSize = minSize));
    }
    uint8_t* mem = ((uint8_t*)(crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(0, arenaSize, 3, 34, (-(1)), 0)));
    if (((mem == 0)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* arena = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena*)(mem));
    ((arena->base = mem));
    ((arena->size = arenaSize));
    ((arena->sliceCount = ((uint32_t)(((arenaSize / crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE))))));
    ((arena->bitmapWords = ((((((size_t)(arena->sliceCount)) + 63)) / 64))));
    ((arena->bitmap = ((uint64_t*)(((mem + sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena)))))));
    ((arena->usedSlices = 0));
    ((arena->next = heap->arenas));
    for (
    size_t i = 0;((i < arena->bitmapWords));((i)++))
    {
        ((arena->bitmap[i] = 0));
    }
    size_t headerSlices = ((((((((sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena) + ((arena->bitmapWords * 8)))) + crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE)) - 1)) / crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE));
    for (
    uint32_t i = 0;((((i < ((uint32_t)(headerSlices))))) && (((i < arena->sliceCount))));((i)++))
    {
        ((arena->bitmap[((i / 64))] |= ((1 << ((i % 64))))));
    }
    ((arena->usedSlices = ((uint32_t)(headerSlices))));
    ((heap->arenas = arena));
    ((heap->mapped += arenaSize));
    return arena;
}
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaSliceAlloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* arena, uint32_t count) {
    for (
    uint32_t i = 0;((((i + count)) <= arena->sliceCount));((i)++))
    {
        _Bool found = 1;
        for (
        size_t j = 0;((j < ((size_t)(count))));((j)++))
        {
            if (((arena->bitmap[((((((size_t)(i)) + j)) / 64))] & ((((uint64_t)(1)) << ((uint64_t)(((((((size_t)(i)) + j)) % 64)))))))))
            {
                ((found = 0));
                break;
            }
        }
        if (found)
        {
            for (
            size_t j = 0;((j < ((size_t)(count))));((j)++))
            {
                ((arena->bitmap[((((((size_t)(i)) + j)) / 64))] |= ((((uint64_t)(1)) << ((uint64_t)(((((((size_t)(i)) + j)) % 64))))))));
            }
            ((arena->usedSlices += count));
            return ((arena->base + ((((size_t)(i)) * crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE))));
        }
    }
    return 0;
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaSliceFree(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* arena, void* ptr, uint32_t count) {
    uint8_t* p = ((uint8_t*)(ptr));
    uint32_t startIdx = ((uint32_t)(((((p - arena->base)) / crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE))));
    for (
    uint32_t j = 0;((j < count));((j)++))
    {
        ((arena->bitmap[((((startIdx + j)) / 64))] &= (~(((1 << ((((startIdx + j)) % 64))))))));
    }
    ((arena->usedSlices -= count));
}
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentAlloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, uint32_t pageCount) {
    size_t segSize = ((((size_t)(pageCount)) * crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_PAGE_SIZE));
    if (((segSize < crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SEGMENT_SIZE)))
    {
        ((segSize = crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SEGMENT_SIZE));
    }
    uint32_t slicesNeeded = ((uint32_t)(((((((segSize + crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE)) - 1)) / crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE))));
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiArena* arena = heap->arenas;
    while (((arena != 0)))
    {
        void* mem = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaSliceAlloc(arena, slicesNeeded);
        if (((mem != 0)))
        {
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* seg = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment*)(mem));
            ((seg->base = ((uint8_t*)(mem))));
            ((seg->size = segSize));
            ((seg->pageCount = pageCount));
            ((seg->usedCount = 0));
            ((seg->arena = arena));
            ((seg->threadId = heap->threadId));
            ((seg->owner = heap));
            ((seg->pages = 0));
            ((seg->next = heap->segments));
            ((seg->prev = 0));
            if (((heap->segments != 0)))
            {
                ((heap->segments->prev = seg));
            }
            ((heap->segments = seg));
            return seg;
        }
        ((arena = arena->next));
    }
    uint8_t* mem = ((uint8_t*)(crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(0, segSize, 3, 34, (-(1)), 0)));
    if (((mem == 0)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* seg = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment*)(mem));
    ((seg->base = mem));
    ((seg->size = segSize));
    ((seg->pageCount = pageCount));
    ((seg->usedCount = 0));
    ((seg->arena = 0));
    ((seg->threadId = heap->threadId));
    ((seg->owner = heap));
    ((seg->pages = 0));
    ((seg->next = heap->segments));
    ((seg->prev = 0));
    if (((heap->segments != 0)))
    {
        ((heap->segments->prev = seg));
    }
    ((heap->segments = seg));
    ((heap->mapped += segSize));
    return seg;
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentFree(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* seg) {
    if (((seg->prev != 0)))
    {
        ((seg->prev->next = seg->next));
    }
    else
    {
        ((heap->segments = seg->next));
    }
    if (((seg->next != 0)))
    {
        ((seg->next->prev = seg->prev));
    }
    if (((seg->arena != 0)))
    {
        uint32_t slices = ((uint32_t)(((((((seg->size + crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE)) - 1)) / crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SLICE_SIZE))));
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaSliceFree(seg->arena, seg->base, slices);
    }
    else
    {
        crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(((void*)(seg)), seg->size);
        ((heap->mapped -= seg->size));
    }
}
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageAlloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, uint32_t sc) {
    size_t pageSize = ((size_t)(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_PAGE_SIZES[sc]));
    uint32_t pageCount = 1;
    if (((pageSize < crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SEGMENT_SIZE)))
    {
        ((pageCount = ((uint32_t)(((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SEGMENT_SIZE / pageSize))))));
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* seg = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentAlloc(heap, pageCount);
    if (((seg == 0)))
    {
        return 0;
    }
    size_t blockSize = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(sc);
    size_t blocksPerPage = ((size_t)(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlocksPerPage(sc)));
    size_t metaSize = ((((((sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment) + sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage))) + 255)) & (~(((size_t)(255))))));
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage*)(((seg->base + sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment)))));
    ((page->next = 0));
    ((page->prev = 0));
    ((page->sizeClass = sc));
    ((page->blockSize = blockSize));
    ((page->capacity = crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_INITIAL_CAPACITY));
    ((page->used = 0));
    ((page->freeCount = ((uint32_t)(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_INITIAL_CAPACITY))));
    ((page->reserved = blocksPerPage));
    ((page->base = ((seg->base + metaSize))));
    ((page->free = 0));
    ((page->localFree = 0));
    ((page->xthreadFree = 0));
    ((page->xthreadFreeCount = 0));
    ((page->inFull = 0));
    ((page->segment = seg));
    ((page->pageIdx = 0));
    ((page->retired = 0));
    ((page->retireCount = 0));
    ((page->key1 = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miRandomU64() % 64))));
    ((page->key2 = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miRandomU64()));
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* head = 0;
    for (
    size_t i = 0;((i < crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_INITIAL_CAPACITY));((i)++))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(((page->base + ((i * blockSize))))));
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockEncode(block, head, page);
        ((head = block));
    }
    ((page->free = head));
    ((seg->usedCount = 1));
    ((page->next = heap->pages[sc]));
    if (((heap->pages[sc] != 0)))
    {
        ((heap->pages[sc]->prev = page));
    }
    ((heap->pages[sc] = page));
    ((heap->pageCounts[sc])++);
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapInsert((&(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miGlobalPages)), page->base, page);
    return page;
}
_Bool crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageExtend(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page) {
    size_t newCap = ((page->capacity * 2));
    if (((newCap > page->reserved)))
    {
        ((newCap = page->reserved));
    }
    if (((newCap <= page->capacity)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* head = page->free;
    for (
    size_t i = page->capacity;((i < newCap));((i)++))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(((page->base + ((i * page->blockSize))))));
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockEncode(block, head, page);
        ((head = block));
    }
    ((page->free = head));
    ((page->freeCount += ((uint32_t)(((newCap - page->capacity))))));
    ((page->capacity = newCap));
    return 1;
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageFree(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, uint32_t sc) {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapRemove((&(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miGlobalPages)), page->base, ((page->capacity * page->blockSize)));
    if (((page->prev != 0)))
    {
        ((page->prev->next = page->next));
    }
    else
    {
        ((heap->pages[sc] = page->next));
    }
    if (((page->next != 0)))
    {
        ((page->next->prev = page->prev));
    }
    ((heap->pageCounts[sc])--);
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegment* seg = page->segment;
    if (((((seg != 0))) && (((seg->usedCount <= 1)))))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentFree(heap, seg);
    }
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMaybeRetire(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, uint32_t sc) {
    if (((((page->used > 0))) || (page->inFull)))
    {
        ((page->retireCount = 0));
        return;
    }
    uint32_t freePages = 0;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* p = heap->pages[sc];
    while (((p != 0)))
    {
        if (((((p->free != 0))) || (((p->localFree != 0)))))
        {
            ((freePages)++);
        }
        ((p = p->next));
    }
    if (((freePages <= 1)))
    {
        return;
    }
    ((page->retireCount)++);
    if (((page->retireCount < 16)))
    {
        return;
    }
    if (((page->prev != 0)))
    {
        ((page->prev->next = page->next));
    }
    else
    {
        ((heap->pages[sc] = page->next));
    }
    if (((page->next != 0)))
    {
        ((page->next->prev = page->prev));
    }
    ((heap->pageCounts[sc])--);
    ((page->next = heap->freePages[sc]));
    ((heap->freePages[sc] = page));
    ((page->retired = 1));
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveToFull(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, uint32_t sc) {
    uint64_t raw = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(page->xthreadFree)))));
    while ((!(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicCAS(((uint64_t*)((&(page->xthreadFree)))), (&(raw)), ((raw | ((uint64_t)(1))))))))
    {
        ((raw = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(page->xthreadFree)))))));
    }
    if (((page->prev != 0)))
    {
        ((page->prev->next = page->next));
    }
    else
    {
        ((heap->pages[sc] = page->next));
    }
    if (((page->next != 0)))
    {
        ((page->next->prev = page->prev));
    }
    ((heap->pageCounts[sc])--);
    ((page->inFull = 1));
    ((page->next = heap->fullPages));
    ((page->prev = 0));
    if (((heap->fullPages != 0)))
    {
        ((heap->fullPages->prev = page));
    }
    ((heap->fullPages = page));
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveFromFull(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, uint32_t sc) {
    if (((page->prev != 0)))
    {
        ((page->prev->next = page->next));
    }
    else
    {
        ((heap->fullPages = page->next));
    }
    if (((page->next != 0)))
    {
        ((page->next->prev = page->prev));
    }
    ((page->inFull = 0));
    ((page->next = heap->pages[sc]));
    ((page->prev = 0));
    if (((heap->pages[sc] != 0)))
    {
        ((heap->pages[sc]->prev = page));
    }
    ((heap->pages[sc] = page));
    ((heap->pageCounts[sc])++);
    uint64_t raw = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(page->xthreadFree)))));
    while ((!(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicCAS(((uint64_t*)((&(page->xthreadFree)))), (&(raw)), ((raw & (~(((uint64_t)(1))))))))))
    {
        ((raw = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(page->xthreadFree)))))));
    }
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageCollect(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page) {
    uint64_t raw = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(page->xthreadFree)))));
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* head = 0;
    while (1)
    {
        if (((((raw & (~(((uint64_t)(1)))))) == 0)))
        {
            return;
        }
        uint64_t next = ((raw & (~(((uint64_t)(1))))));
        if (crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicCAS(((uint64_t*)((&(page->xthreadFree)))), (&(raw)), ((raw & ((uint64_t)(1))))))
        {
            ((head = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(next))));
            break;
        }
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* current = head;
    uint32_t count = 0;
    while (((current != 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* decoded = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(current, page);
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockEncode(current, page->localFree, page);
        ((page->localFree = current));
        ((page->used)--);
        ((page->freeCount)++);
        ((heap->totalFreed += page->blockSize));
        ((count)++);
        if (((((size_t)(count)) > page->capacity)))
        {
            printf(((char* const)("mimalloc: corrupted thread-free list\n")));
            return;
        }
        ((current = decoded));
    }
    if (((((count > 0))) && (page->inFull)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveFromFull(heap, page, page->sizeClass);
    }
}
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAllocFast(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, uint32_t sc) {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page = heap->pages[sc];
    if (((((page != 0))) && (((page->free != 0)))))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = page->free;
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(block, page);
        ((page->free = next));
        ((page->used)++);
        ((page->freeCount)--);
        ((heap->totalAllocated += crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(sc)));
        if (((page->freeCount == 0)))
        {
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveToFull(heap, page, sc);
        }
        return ((void*)(block));
    }
    if (((page != 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageCollect(heap, page);
        if (((((page->free == 0))) && (((page->localFree != 0)))))
        {
            ((page->free = page->localFree));
            ((page->localFree = 0));
        }
        if (((page->free != 0)))
        {
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = page->free;
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(block, page);
            ((page->free = next));
            ((page->used)++);
            ((page->freeCount)--);
            ((heap->totalAllocated += crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(sc)));
            if (((page->freeCount == 0)))
            {
                crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveToFull(heap, page, sc);
            }
            return ((void*)(block));
        }
    }
    return 0;
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeFast(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page, void* ptr) {
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(ptr));
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* owner = heap;
    if (((((page->segment != 0))) && (((page->segment->threadId != heap->threadId)))))
    {
        ((owner = page->segment->owner));
        if (((owner == 0)))
        {
            ((owner = heap));
        }
        uint64_t raw = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(page->xthreadFree)))));
        if (((((raw & ((uint64_t)(1)))) != 0)))
        {
            uint64_t head = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(owner->delayedFree)))));
            while (1)
            {
                ((block->next = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(head))));
                if (crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicCAS(((uint64_t*)((&(owner->delayedFree)))), (&(head)), ((uint64_t)(block))))
                {
                    break;
                }
                ((head = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(owner->delayedFree)))))));
            }
            return;
        }
        while (1)
        {
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockEncode(block, ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(((raw & (~(((uint64_t)(1)))))))), page);
            if (crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicCAS(((uint64_t*)((&(page->xthreadFree)))), (&(raw)), ((((uint64_t)(block)) | ((raw & ((uint64_t)(1))))))))
            {
                break;
            }
            ((raw = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(page->xthreadFree)))))));
        }
        return;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockEncode(block, page->localFree, page);
    ((page->localFree = block));
    ((page->used)--);
    ((page->freeCount)++);
    ((heap->totalFreed += page->blockSize));
    if (page->inFull)
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveFromFull(heap, page, page->sizeClass);
    }
    if (((page->used == 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMaybeRetire(heap, page, page->sizeClass);
    }
}
crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageFind(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap, void* ptr) {
    uint8_t* p = ((uint8_t*)(ptr));
    uint32_t idx = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapHash(p);
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiSegmentMapEntry* entry = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miGlobalPages.buckets[idx];
    while (((entry != 0)))
    {
        uint8_t* pageEnd = ((entry->page->base + ((entry->page->capacity * entry->page->blockSize))));
        if (((((p >= entry->page->base))) && (((p < pageEnd)))))
        {
            size_t offset = ((size_t)(((p - entry->page->base))));
            if (((((offset % entry->page->blockSize)) == 0)))
            {
                return entry->page;
            }
        }
        ((entry = entry->next));
    }
    return 0;
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miProcessDelayedFree(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiHeap* heap) {
    uint64_t head = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicExchange(((uint64_t*)((&(heap->delayedFree)))), 0);
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* current = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock*)(head));
    while (((current != 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next = current->next;
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageFind(heap, current);
        if (((page != 0)))
        {
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockEncode(current, page->localFree, page);
            ((page->localFree = current));
            ((page->used)--);
            ((page->freeCount)++);
            ((heap->totalFreed += page->blockSize));
            if (page->inFull)
            {
                crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveFromFull(heap, page, page->sizeClass);
            }
            if (((page->used == 0)))
            {
                crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMaybeRetire(heap, page, page->sizeClass);
            }
        }
        ((current = next));
    }
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_init(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, size_t reserveSize) {
    ((self->heap.totalAllocated = 0));
    ((self->heap.totalFreed = 0));
    ((self->heap.mapped = 0));
    ((self->heap.arenas = 0));
    ((self->heap.segments = 0));
    ((self->heap.threadId = ((uint64_t)(pthread_self()))));
    ((self->heap.delayedFree = 0));
    ((self->heap.fullPages = 0));
    ((self->heap.hugePages = 0));
    for (
    uint32_t i = 0;((i < crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_SIZE_CLASS_COUNT));((i)++))
    {
        ((self->heap.pages[i] = 0));
        ((self->heap.freePages[i] = 0));
        ((self->heap.pageCounts[i] = 0));
        ((self->heap.pageSize[i] = crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_PAGE_SIZES[i]));
    }
    if (((reserveSize > 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miArenaAlloc((&(self->heap)), reserveSize);
    }
}
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_alloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, size_t size) {
    if (((size == 0)))
    {
        return 0;
    }
    if (((crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAtomicLoad(((uint64_t*)((&(self->heap.delayedFree))))) != 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miProcessDelayedFree((&(self->heap)));
    }
    uint32_t sc = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSizeClass(size);
    if (((size >= crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_HUGE_THRESHOLD)))
    {
        size_t allocSize = ((((size + 255)) & (~(((size_t)(255))))));
        uint8_t* mem = ((uint8_t*)(crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(0, allocSize, 3, 34, (-(1)), 0)));
        if (((mem == 0)))
        {
            return 0;
        }
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage*)(crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(0, sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage), 3, 34, (-(1)), 0)));
        if (((page == 0)))
        {
            crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(((void*)(mem)), allocSize);
            return 0;
        }
        ((page->next = 0));
        ((page->prev = 0));
        ((page->sizeClass = sc));
        ((page->blockSize = allocSize));
        ((page->capacity = 1));
        ((page->used = 1));
        ((page->freeCount = 0));
        ((page->reserved = 1));
        ((page->base = mem));
        ((page->free = 0));
        ((page->localFree = 0));
        ((page->xthreadFree = 0));
        ((page->xthreadFreeCount = 0));
        ((page->segment = 0));
        ((page->pageIdx = 0));
        ((page->retired = 0));
        ((page->retireCount = 0));
        ((page->key1 = ((crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miRandomU64() % 64))));
        ((page->key2 = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miRandomU64()));
        ((page->inFull = 0));
        ((page->next = self->heap.hugePages));
        ((self->heap.hugePages = page));
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapInsert((&(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miGlobalPages)), page->base, page);
        ((self->heap.totalAllocated += allocSize));
        return ((void*)(mem));
    }
    void* ptr = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miAllocFast((&(self->heap)), sc);
    if (((ptr != 0)))
    {
        return ptr;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* full = self->heap.fullPages;
    while (((full != 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* nextFull = full->next;
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageCollect((&(self->heap)), full);
        ((full = nextFull));
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page = self->heap.pages[sc];
    while (((((page != 0))) && (((page->free == 0)))))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageCollect((&(self->heap)), page);
        if (((((page->free == 0))) && (((page->localFree != 0)))))
        {
            ((page->free = page->localFree));
            ((page->localFree = 0));
        }
        if (((page->free != 0)))
        {
            break;
        }
        ((page = page->next));
    }
    if (((((page != 0))) && (((page->free != 0)))))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = page->free;
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(block, page);
        ((page->free = next));
        ((page->used)++);
        ((page->freeCount)--);
        ((self->heap.totalAllocated += crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(sc)));
        if (((page->freeCount == 0)))
        {
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageMoveToFull((&(self->heap)), page, sc);
        }
        return ((void*)(block));
    }
    ((page = self->heap.pages[sc]));
    while (((page != 0)))
    {
        if (((page->capacity < page->reserved)))
        {
            if (crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageExtend((&(self->heap)), page))
            {
                crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = page->free;
                crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(block, page);
                ((page->free = next));
                ((page->used)++);
                ((page->freeCount)--);
                ((self->heap.totalAllocated += crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(sc)));
                return ((void*)(block));
            }
        }
        ((page = page->next));
    }
    ((page = self->heap.freePages[sc]));
    if (((page != 0)))
    {
        ((self->heap.freePages[sc] = page->next));
        ((page->next = 0));
        ((page->retired = 0));
        if (((page->localFree != 0)))
        {
            ((page->free = page->localFree));
            ((page->localFree = 0));
        }
        ((page->next = self->heap.pages[sc]));
        if (((self->heap.pages[sc] != 0)))
        {
            ((self->heap.pages[sc]->prev = page));
        }
        ((self->heap.pages[sc] = page));
        ((self->heap.pageCounts[sc])++);
        if (((page->free != 0)))
        {
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = page->free;
            crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(block, page);
            ((page->free = next));
            ((page->used)++);
            ((page->freeCount)--);
            ((self->heap.totalAllocated += crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(sc)));
            return ((void*)(block));
        }
    }
    ((page = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageAlloc((&(self->heap)), sc)));
    if (((page == 0)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* block = page->free;
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiBlock* next = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeBlockDecode(block, page);
    ((page->free = next));
    ((page->used)++);
    ((page->freeCount)--);
    ((self->heap.totalAllocated += crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miBlockSize(sc)));
    return ((void*)(block));
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_free(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, void* ptr) {
    if (((ptr == 0)))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageFind((&(self->heap)), ptr);
    if (((page == 0)))
    {
        return;
    }
    if (((((page->capacity == 1))) && (((page->blockSize >= crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MI_HUGE_THRESHOLD)))))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage** pp = (&(self->heap.hugePages));
        while ((((*(pp)) != 0)))
        {
            if ((((*(pp)) == page)))
            {
                (((*(pp)) = page->next));
                break;
            }
            ((pp = (&((*(pp))->next))));
        }
        size_t allocSize = ((size_t)(page->blockSize));
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSegmentMapRemove((&(crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miGlobalPages)), page->base, allocSize);
        crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(((void*)(page)), sizeof(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage));
        crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(ptr, allocSize);
        ((self->heap.totalFreed += allocSize));
        return;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miFreeFast((&(self->heap)), page, ptr);
}
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_realloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, void* ptr, size_t newSize) {
    if (((ptr == 0)))
    {
        return crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_alloc(self, newSize);
    }
    if (((newSize == 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_free(self, ptr);
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiPage* page = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miPageFind((&(self->heap)), ptr);
    if (((page == 0)))
    {
        return 0;
    }
    uint32_t oldSc = page->sizeClass;
    uint32_t newSc = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miSizeClass(newSize);
    if (((oldSc == newSc)))
    {
        return ptr;
    }
    void* newPtr = crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_alloc(self, newSize);
    if (((newPtr == 0)))
    {
        return 0;
    }
    size_t copyLen = ((((((size_t)(page->blockSize)) < newSize))) ? (((size_t)(page->blockSize))) : (newSize));
    memcpy(newPtr, ptr, copyLen);
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_free(self, ptr);
    return newPtr;
}
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_calloc(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self, size_t count, size_t size) {
    if (((((count != 0))) && (((size > ((18446744073709551615 / count)))))))
    {
        return 0;
    }
    size_t total = ((count * size));
    void* ptr = crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_alloc(self, total);
    if (((ptr != 0)))
    {
        uint8_t* p = ((uint8_t*)(ptr));
        for (
        size_t i = 0;((i < total));((i)++))
        {
            ((p[i] = 0));
        }
    }
    return ptr;
}
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getAllocated(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self) {
    return self->heap.totalAllocated;
}
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getFreed(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self) {
    return self->heap.totalFreed;
}
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getUsed(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self) {
    return ((self->heap.totalAllocated - self->heap.totalFreed));
}
size_t crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getMapped(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self) {
    return self->heap.mapped;
}
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_allocator(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* self) {
    return ((crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = ((void*)(self)), .alloc = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapAlloc, .free = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapFree, .realloc = crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapRealloc});
}
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapAlloc(void* ctx, size_t size) {
    if ((!(ctx)))
    {
        return 0;
    }
    return crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_alloc(((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc*)(ctx)), size);
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapFree(void* ctx, void* ptr) {
    if ((((!(ctx))) || ((!(ptr)))))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_free(((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc*)(ctx)), ptr);
}
void* crl__lib__std__x86_64__linux__memory__allocators__mimalloc___miWrapRealloc(void* ctx, void* ptr, size_t newSize) {
    if ((!(ctx)))
    {
        return 0;
    }
    return crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_realloc(((crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc*)(ctx)), ptr, newSize);
}
void crl__lib__std__x86_64__linux__memory__allocators__mimalloc__miStatsPrint(crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc* alloc) {
    printf(((char* const)("mimalloc stats:\n")));
    printf(((char* const)("  allocated: %llu\n")), crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getAllocated(alloc));
    printf(((char* const)("  freed:     %llu\n")), crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getFreed(alloc));
    printf(((char* const)("  in use:    %llu\n")), crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getUsed(alloc));
    printf(((char* const)("  mapped:    %llu\n")), crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_getMapped(alloc));
}
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_init(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* heap, size_t size) {
    ((self->heapStart = heap));
    ((self->heapEnd = ((((uint8_t*)(heap)) + size))));
    ((self->heapSize = size));
    for (
    uint32_t fli = 0;((fli < crl__lib__std__x86_64__linux__memory__allocators__tlsf__FLI_COUNT));((fli)++))
    {
        ((self->sliBitmap[fli] = 0));
        for (
        uint32_t sli = 0;((sli < crl__lib__std__x86_64__linux__memory__allocators__tlsf__SLI_COUNT));((sli)++))
        {
            ((self->freeLists[fli][sli] = 0));
        }
    }
    ((self->fliBitmap = 0));
    size_t aligned = ((((size - sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader))) & (~(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_ALIGN - 1))))));
    uint8_t* start = ((((uint8_t*)(heap)) + sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader)));
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* first = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(start));
    ((first->sizeAndFlags = ((aligned | crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))));
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, first);
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__insertFree(self, first);
}
uint32_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__fls(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, uint32_t x) {
    if (((x == 0)))
    {
        return 0;
    }
    uint32_t r = 0;
    if (((x >= 65536)))
    {
        ((r += 16));
        ((x >>= 16));
    }
    if (((x >= 256)))
    {
        ((r += 8));
        ((x >>= 8));
    }
    if (((x >= 16)))
    {
        ((r += 4));
        ((x >>= 4));
    }
    if (((x >= 4)))
    {
        ((r += 2));
        ((x >>= 2));
    }
    if (((x >= 2)))
    {
        ((r += 1));
    }
    return r;
}
uint32_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__lsbIndex(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, uint32_t x) {
    uint32_t isolated = ((x & ((uint32_t)((-(((int32_t)(x))))))));
    uint32_t pos = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__fls(self, isolated);
    return pos;
}
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__getIndex(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, size_t size, uint32_t* fli, uint32_t* sli) {
    uint32_t bucket;
    if (((size < 16)))
    {
        ((bucket = 1));
    }
    else
    {
        if (((size < 4294967296)))
        {
            ((bucket = ((uint32_t)(((size >> 4))))));
        }
        else
        {
            ((bucket = 4294967295));
        }
    }
    (((*(fli)) = ((bucket >> 5))));
    (((*(sli)) = ((bucket & ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__SLI_COUNT - 1))))));
    if ((((*(fli)) >= crl__lib__std__x86_64__linux__memory__allocators__tlsf__FLI_COUNT)))
    {
        (((*(fli)) = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__FLI_COUNT - 1))));
    }
}
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* const block) {
    return ((block->sizeAndFlags & (~(((size_t)(3))))));
}
crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockFromPtr(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* ptr) {
    return ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(((((uint8_t*)(ptr)) - sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader)))));
}
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__memcpy(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* dst, const void* src, size_t n) {
    uint8_t* d = ((uint8_t*)(dst));
    uint8_t* s = ((uint8_t* const)(src));
    size_t i = 0;
    while (((((i + 8)) <= n)))
    {
        (((*(((size_t*)(((d + i)))))) = (*(((size_t* const)(((s + i))))))));
        ((i += 8));
    }
    while (((i < n)))
    {
        ((d[i] = s[i]));
        ((i)++);
    }
}
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__ptrFromBlock(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block) {
    return ((void*)(((((uint8_t*)(block)) + sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader)))));
}
crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__nextBlock(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block) {
    uint8_t* next = ((((uint8_t*)(block)) + crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, block)));
    return ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(next));
}
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block) {
    size_t sz = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, block);
    (((*(((size_t*)(((((((uint8_t*)(block)) + sz)) - 8)))))) = sz));
}
crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__prevBlock(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block) {
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* prev = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(((((uint8_t*)(block)) - ((block[(-(1))].sizeAndFlags & (~(((size_t)(3))))))))));
    return prev;
}
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__removeFree(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* block) {
    uint32_t fli;
    uint32_t sli;
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__getIndex(self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, (&(block->header))), (&(fli)), (&(sli)));
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* prev = block->prev;
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* next = block->next;
    if (((prev != 0)))
    {
        ((prev->next = next));
    }
    else
    {
        ((self->freeLists[fli][sli] = next));
    }
    if (((next != 0)))
    {
        ((next->prev = prev));
    }
    if (((self->freeLists[fli][sli] == 0)))
    {
        ((self->sliBitmap[fli] &= (~(((1 << sli))))));
        if (((self->sliBitmap[fli] == 0)))
        {
            ((self->fliBitmap &= (~(((1 << fli))))));
        }
    }
}
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__insertFree(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block) {
    uint32_t fli;
    uint32_t sli;
    size_t blockSize = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, block);
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__getIndex(self, blockSize, (&(fli)), (&(sli)));
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* fb = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock*)(block));
    ((fb->prev = 0));
    ((fb->next = self->freeLists[fli][sli]));
    if (((fb->next != 0)))
    {
        ((fb->next->prev = fb));
    }
    ((self->freeLists[fli][sli] = fb));
    ((self->sliBitmap[fli] |= ((1 << sli))));
    ((self->fliBitmap |= ((1 << fli))));
}
crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__findSuitableBlock(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, size_t size, uint32_t* outFli, uint32_t* outSli) {
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__getIndex(self, size, outFli, outSli);
    uint32_t fli = (*(outFli));
    uint32_t sli = (*(outSli));
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* fb = self->freeLists[fli][sli];
    if (((fb != 0)))
    {
        while (((((fb != 0))) && (((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, (&(fb->header))) < size)))))
        {
            ((fb = fb->next));
        }
        if (((fb != 0)))
        {
            return ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(fb));
        }
    }
    uint32_t sliMap = ((self->sliBitmap[fli] & (((~(0)) << sli))));
    ((sliMap &= (~(((1 << sli))))));
    while (((sliMap != 0)))
    {
        uint32_t candSli = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__lsbIndex(self, sliMap);
        ((fb = self->freeLists[fli][candSli]));
        while (((((fb != 0))) && (((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, (&(fb->header))) < size)))))
        {
            ((fb = fb->next));
        }
        if (((fb != 0)))
        {
            (((*(outFli)) = fli));
            (((*(outSli)) = candSli));
            return ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(fb));
        }
        ((sliMap &= (~(((1 << candSli))))));
    }
    uint32_t fliMap = ((self->fliBitmap & (((~(0)) << ((fli + 1))))));
    while (((fliMap != 0)))
    {
        uint32_t candFli = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__lsbIndex(self, fliMap);
        uint32_t candSliMap = self->sliBitmap[candFli];
        while (((candSliMap != 0)))
        {
            uint32_t candSli = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__lsbIndex(self, candSliMap);
            ((fb = self->freeLists[candFli][candSli]));
            while (((((fb != 0))) && (((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, (&(fb->header))) < size)))))
            {
                ((fb = fb->next));
            }
            if (((fb != 0)))
            {
                (((*(outFli)) = candFli));
                (((*(outSli)) = candSli));
                return ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(fb));
            }
            ((candSliMap &= (~(((1 << candSli))))));
        }
        ((fliMap &= (~(((1 << candFli))))));
    }
    return 0;
}
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_alloc(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, size_t size) {
    if (((size == 0)))
    {
        return 0;
    }
    size_t aligned = ((((((size + crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_ALIGN)) - 1)) & (~(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_ALIGN - 1))))));
    if (((aligned < crl__lib__std__x86_64__linux__memory__allocators__tlsf__MIN_BLOCK_SIZE)))
    {
        ((aligned = crl__lib__std__x86_64__linux__memory__allocators__tlsf__MIN_BLOCK_SIZE));
    }
    size_t needSize = ((aligned + sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader)));
    if (((needSize < aligned)))
    {
        return 0;
    }
    uint32_t fli;
    uint32_t sli;
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__findSuitableBlock(self, needSize, (&(fli)), (&(sli)));
    if (((block == 0)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__removeFree(self, ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock*)(block)));
    size_t blockSize = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, block);
    if (((blockSize < needSize)))
    {
        return 0;
    }
    size_t remaining = ((blockSize - needSize));
    if (((remaining >= ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__MIN_BLOCK_SIZE + sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader))))))
    {
        ((block->sizeAndFlags = ((((needSize | crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_USED)) | ((block->sizeAndFlags & crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))))));
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, block);
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* next = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(((((uint8_t*)(block)) + needSize))));
        ((next->sizeAndFlags = ((remaining | crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))));
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, next);
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__insertFree(self, next);
    }
    else
    {
        ((block->sizeAndFlags = ((((blockSize | crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_USED)) | ((block->sizeAndFlags & crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))))));
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, block);
    }
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* nextBlock = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__nextBlock(self, block);
    if (((((uint8_t*)(nextBlock)) < ((uint8_t*)(self->heapEnd)))))
    {
        ((nextBlock->sizeAndFlags |= crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED));
    }
    return crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__ptrFromBlock(self, block);
}
void crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_free(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* ptr) {
    if (((ptr == 0)))
    {
        return;
    }
    if (((((ptr < self->heapStart))) || (((ptr >= self->heapEnd)))))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockFromPtr(self, ptr);
    ((block->sizeAndFlags &= (~(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_USED))));
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* prev = 0;
    if (((((block->sizeAndFlags & crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED)) == 0)))
    {
        ((prev = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__prevBlock(self, block)));
        if (((((prev != 0))) && (((((prev->sizeAndFlags & crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_USED)) == 0)))))
        {
            crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__removeFree(self, ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock*)(prev)));
            size_t combined = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, prev) + crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, block)));
            ((prev->sizeAndFlags = ((combined | ((prev->sizeAndFlags & crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))))));
            crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, prev);
            ((block = prev));
        }
    }
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* next = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__nextBlock(self, block);
    if (((((((uint8_t*)(next)) < ((uint8_t*)(self->heapEnd))))) && (((((next->sizeAndFlags & crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_USED)) == 0)))))
    {
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__removeFree(self, ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock*)(next)));
        size_t combined = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, block) + crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, next)));
        ((block->sizeAndFlags = ((combined | ((block->sizeAndFlags & crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))))));
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, block);
        ((next = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__nextBlock(self, block)));
    }
    if (((((uint8_t*)(next)) < ((uint8_t*)(self->heapEnd)))))
    {
        ((next->sizeAndFlags &= (~(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))));
    }
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, block);
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__insertFree(self, block);
}
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_realloc(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self, void* ptr, size_t newSize) {
    if (((ptr == 0)))
    {
        return crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_alloc(self, newSize);
    }
    if (((newSize == 0)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_free(self, ptr);
        return 0;
    }
    if (((((ptr < self->heapStart))) || (((ptr >= self->heapEnd)))))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* block = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockFromPtr(self, ptr);
    size_t oldSize = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, block) - sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader)));
    if (((oldSize >= newSize)))
    {
        size_t alignedNew = ((((((newSize + crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_ALIGN)) - 1)) & (~(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_ALIGN - 1))))));
        if (((alignedNew < crl__lib__std__x86_64__linux__memory__allocators__tlsf__MIN_BLOCK_SIZE)))
        {
            ((alignedNew = crl__lib__std__x86_64__linux__memory__allocators__tlsf__MIN_BLOCK_SIZE));
        }
        size_t excess = ((oldSize - alignedNew));
        if (((excess >= ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__MIN_BLOCK_SIZE + sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader))))))
        {
            ((block->sizeAndFlags = ((((((alignedNew + sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader))) | crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_USED)) | ((block->sizeAndFlags & crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))))));
            crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, block);
            uint8_t* splitAt = ((((((uint8_t*)(block)) + alignedNew)) + sizeof(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader)));
            crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader* split = ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__BlockHeader*)(splitAt));
            ((split->sizeAndFlags = ((excess | crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))));
            crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__writeFooter(self, split);
            crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__insertFree(self, split);
            ((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__nextBlock(self, split)->sizeAndFlags &= (~(crl__lib__std__x86_64__linux__memory__allocators__tlsf__BLOCK_PREV_USED))));
        }
        return ptr;
    }
    void* newPtr = crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_alloc(self, newSize);
    if (((newPtr == 0)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__memcpy(self, newPtr, ptr, oldSize);
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_free(self, ptr);
    return newPtr;
}
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_getHeapSize(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self) {
    return self->heapSize;
}
size_t crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_getFreeSize(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self) {
    size_t total = 0;
    for (
    uint32_t fli = 0;((fli < crl__lib__std__x86_64__linux__memory__allocators__tlsf__FLI_COUNT));((fli)++))
    {
        if (((self->sliBitmap[fli] == 0)))
        {
            continue;
        }
        for (
        uint32_t sli = 0;((sli < crl__lib__std__x86_64__linux__memory__allocators__tlsf__SLI_COUNT));((sli)++))
        {
            crl__lib__std__x86_64__linux__memory__allocators__tlsf__FreeBlock* fb = self->freeLists[fli][sli];
            while (((fb != 0)))
            {
                ((total += crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf__blockSize(self, (&(fb->header)))));
                ((fb = fb->next));
            }
        }
    }
    return total;
}
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_allocator(crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf* self) {
    return ((crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = ((void*)(self)), .alloc = crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapAlloc, .free = crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapFree, .realloc = crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapRealloc});
}
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapAlloc(void* ctx, size_t size) {
    if ((!(ctx)))
    {
        return 0;
    }
    return crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_alloc(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf*)(ctx)), size);
}
void crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapFree(void* ctx, void* ptr) {
    if ((((!(ctx))) || ((!(ptr)))))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_free(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf*)(ctx)), ptr);
}
void* crl__lib__std__x86_64__linux__memory__allocators__tlsf___tlsfWrapRealloc(void* ctx, void* ptr, size_t newSize) {
    if ((!(ctx)))
    {
        return 0;
    }
    return crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_realloc(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf*)(ctx)), ptr, newSize);
}
void crl__lib__std__x86_64__linux__memory__mman__deinitDefaultAllocator(void) {
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator == 0)))
    {
        return;
    }
    ((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator = 0));
    if (((crl__lib__std__x86_64__linux__memory__mman___defaultAllocHeap != 0)))
    {
        crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(crl__lib__std__x86_64__linux__memory__mman___defaultAllocHeap, crl__lib__std__x86_64__linux__memory__mman___defaultAllocHeapSize);
        ((crl__lib__std__x86_64__linux__memory__mman___defaultAllocHeap = 0));
        ((crl__lib__std__x86_64__linux__memory__mman___defaultAllocHeapSize = 0));
    }
}
void* crl__lib__std__x86_64__linux__memory__mman___libcAlloc(void* ctx, size_t size) {
    ((void)(ctx));
    return malloc(size);
}
void crl__lib__std__x86_64__linux__memory__mman___libcFree(void* ctx, void* ptr) {
    ((void)(ctx));
    if (ptr)
    {
        free(ptr);
    }
}
void* crl__lib__std__x86_64__linux__memory__mman___libcRealloc(void* ctx, void* ptr, size_t newSize) {
    ((void)(ctx));
    return realloc(ptr, newSize);
}
void* crl__lib__std__x86_64__linux__memory__mman___miStdAlloc(void* ctx, size_t size) {
    ((void)(ctx));
    return crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_alloc((&(crl__lib__std__x86_64__linux__memory__mman___miAllocInstance)), size);
}
void crl__lib__std__x86_64__linux__memory__mman___miStdFree(void* ctx, void* ptr) {
    ((void)(ctx));
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_free((&(crl__lib__std__x86_64__linux__memory__mman___miAllocInstance)), ptr);
}
void* crl__lib__std__x86_64__linux__memory__mman___miStdRealloc(void* ctx, void* ptr, size_t newSize) {
    ((void)(ctx));
    return crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_realloc((&(crl__lib__std__x86_64__linux__memory__mman___miAllocInstance)), ptr, newSize);
}
void crl__lib__std__x86_64__linux__memory__mman__ensureDefaultAllocator(void) {
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator == 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman__initDefaultAllocator();
    }
}
void crl__lib__std__x86_64__linux__memory__mman__initDefaultAllocator(void) {
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator != 0)))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__allocators__mimalloc__MiAlloc_init((&(crl__lib__std__x86_64__linux__memory__mman___miAllocInstance)), ((((64 * 1024)) * 1024)));
    ((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator = (&(crl__lib__std__x86_64__linux__memory__mman__miAllocator))));
}
void* crl__lib__std__x86_64__linux__memory__mman___tlsfAlloc(void* ctx, size_t size) {
    return crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_alloc(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf*)(ctx)), size);
}
void crl__lib__std__x86_64__linux__memory__mman___tlsfFree(void* ctx, void* ptr) {
    if (((ctx) && (ptr)))
    {
        crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_free(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf*)(ctx)), ptr);
    }
}
void* crl__lib__std__x86_64__linux__memory__mman___tlsfRealloc(void* ctx, void* ptr, size_t newSize) {
    return crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf_realloc(((crl__lib__std__x86_64__linux__memory__allocators__tlsf__Tlsf*)(ctx)), ptr, newSize);
}
size_t crl__lib__std__x86_64__linux__memory__mman___hbSize(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b) {
    return ((b->sizeAndFlags & (~(((size_t)(crl__lib__std__x86_64__linux__memory__mman___HB_FREE))))));
}
_Bool crl__lib__std__x86_64__linux__memory__mman___hbIsFree(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b) {
    return ((((b->sizeAndFlags & crl__lib__std__x86_64__linux__memory__mman___HB_FREE)) != 0));
}
size_t crl__lib__std__x86_64__linux__memory__mman___hbAlign(size_t v) {
    return ((((((v + crl__lib__std__x86_64__linux__memory__mman___HB_ALIGN)) - 1)) & (~(((crl__lib__std__x86_64__linux__memory__mman___HB_ALIGN - 1))))));
}
crl__lib__std__x86_64__linux__memory__mman___HeapBlock* crl__lib__std__x86_64__linux__memory__mman___hbNext(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b) {
    return ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(((((uint8_t*)(b)) + crl__lib__std__x86_64__linux__memory__mman___hbSize(b)))));
}
void crl__lib__std__x86_64__linux__memory__mman___heapPushFree(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b) {
    (((*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(b)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR)))))) = crl__lib__std__x86_64__linux__memory__mman___heapFreeHead));
    ((crl__lib__std__x86_64__linux__memory__mman___heapFreeHead = b));
}
void crl__lib__std__x86_64__linux__memory__mman___heapUnlink(crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b) {
    crl__lib__std__x86_64__linux__memory__mman___HeapBlock* prev = 0;
    crl__lib__std__x86_64__linux__memory__mman___HeapBlock* cur = crl__lib__std__x86_64__linux__memory__mman___heapFreeHead;
    while (((((cur != 0))) && (((cur != b)))))
    {
        ((prev = cur));
        ((cur = (*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(cur)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR))))))));
    }
    if (((cur == 0)))
    {
        return;
    }
    if (((prev != 0)))
    {
        (((*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(prev)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR)))))) = (*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(cur)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR))))))));
    }
    else
    {
        ((crl__lib__std__x86_64__linux__memory__mman___heapFreeHead = (*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(cur)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR))))))));
    }
}
void* crl__lib__std__x86_64__linux__memory__mman___heapAlloc(void* ctx, size_t size) {
    ((void)(ctx));
    if (((size == 0)))
    {
        return 0;
    }
    size_t need = ((crl__lib__std__x86_64__linux__memory__mman___hbAlign(size) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR));
    while (1)
    {
        crl__lib__std__x86_64__linux__memory__mman___HeapBlock* prev = 0;
        crl__lib__std__x86_64__linux__memory__mman___HeapBlock* cur = crl__lib__std__x86_64__linux__memory__mman___heapFreeHead;
        while (((cur != 0)))
        {
            size_t curSize = crl__lib__std__x86_64__linux__memory__mman___hbSize(cur);
            if (((curSize >= need)))
            {
                if (((prev != 0)))
                {
                    (((*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(prev)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR)))))) = (*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(cur)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR))))))));
                }
                else
                {
                    ((crl__lib__std__x86_64__linux__memory__mman___heapFreeHead = (*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(cur)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR))))))));
                }
                size_t rem = ((curSize - need));
                if (((rem >= ((crl__lib__std__x86_64__linux__memory__mman___HB_HDR + crl__lib__std__x86_64__linux__memory__mman___HB_ALIGN)))))
                {
                    crl__lib__std__x86_64__linux__memory__mman___HeapBlock* tail = ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(((((uint8_t*)(cur)) + need))));
                    ((tail->sizeAndFlags = ((rem | crl__lib__std__x86_64__linux__memory__mman___HB_FREE))));
                    ((tail->prevPhysSize = need));
                    ((cur->sizeAndFlags = need));
                    crl__lib__std__x86_64__linux__memory__mman___HeapBlock* nn = crl__lib__std__x86_64__linux__memory__mman___hbNext(tail);
                    ((nn->prevPhysSize = rem));
                    crl__lib__std__x86_64__linux__memory__mman___heapPushFree(tail);
                }
                else
                {
                    ((cur->sizeAndFlags = curSize));
                }
                return ((void*)(((((uint8_t*)(cur)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR))));
            }
            ((prev = cur));
            ((cur = (*(((crl__lib__std__x86_64__linux__memory__mman___HeapBlock**)(((((uint8_t*)(cur)) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR))))))));
        }
        size_t reg = crl__lib__std__x86_64__linux__memory__mman___hbAlign(((((need + crl__lib__std__x86_64__linux__memory__mman___HB_HDR)) + crl__lib__std__x86_64__linux__memory__mman___HB_ALIGN)));
        if (((reg < 4096)))
        {
            ((reg = 4096));
        }
        uint8_t* mem = ((uint8_t*)(crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(0, reg, 3, 34, (-(1)), 0)));
        if (((mem == 0)))
        {
            return 0;
        }
        crl__lib__std__x86_64__linux__memory__mman___HeapBlock* big = ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(mem));
        ((big->sizeAndFlags = ((((reg - crl__lib__std__x86_64__linux__memory__mman___HB_HDR)) | crl__lib__std__x86_64__linux__memory__mman___HB_FREE))));
        ((big->prevPhysSize = 0));
        crl__lib__std__x86_64__linux__memory__mman___HeapBlock* sent = ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(((((mem + reg)) - crl__lib__std__x86_64__linux__memory__mman___HB_HDR))));
        ((sent->sizeAndFlags = crl__lib__std__x86_64__linux__memory__mman___HB_HDR));
        ((sent->prevPhysSize = ((reg - crl__lib__std__x86_64__linux__memory__mman___HB_HDR))));
        crl__lib__std__x86_64__linux__memory__mman___heapPushFree(big);
    }
}
void crl__lib__std__x86_64__linux__memory__mman___heapFree(void* ctx, void* ptr) {
    ((void)(ctx));
    if (((ptr == 0)))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b = ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(((((uint8_t*)(ptr)) - crl__lib__std__x86_64__linux__memory__mman___HB_HDR))));
    crl__lib__std__x86_64__linux__memory__mman___HeapBlock* next = crl__lib__std__x86_64__linux__memory__mman___hbNext(b);
    if (crl__lib__std__x86_64__linux__memory__mman___hbIsFree(next))
    {
        crl__lib__std__x86_64__linux__memory__mman___heapUnlink(next);
        size_t sz = ((crl__lib__std__x86_64__linux__memory__mman___hbSize(b) + crl__lib__std__x86_64__linux__memory__mman___hbSize(next)));
        ((b->sizeAndFlags = ((sz | crl__lib__std__x86_64__linux__memory__mman___HB_FREE))));
        crl__lib__std__x86_64__linux__memory__mman___HeapBlock* nn = crl__lib__std__x86_64__linux__memory__mman___hbNext(next);
        ((nn->prevPhysSize = sz));
    }
    else
    {
        ((b->sizeAndFlags = ((crl__lib__std__x86_64__linux__memory__mman___hbSize(b) | crl__lib__std__x86_64__linux__memory__mman___HB_FREE))));
    }
    if (((b->prevPhysSize != 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman___HeapBlock* prev = ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(((((uint8_t*)(b)) - b->prevPhysSize))));
        if (crl__lib__std__x86_64__linux__memory__mman___hbIsFree(prev))
        {
            crl__lib__std__x86_64__linux__memory__mman___heapUnlink(prev);
            size_t sz = ((crl__lib__std__x86_64__linux__memory__mman___hbSize(prev) + crl__lib__std__x86_64__linux__memory__mman___hbSize(b)));
            ((prev->sizeAndFlags = ((sz | crl__lib__std__x86_64__linux__memory__mman___HB_FREE))));
            crl__lib__std__x86_64__linux__memory__mman___HeapBlock* nn = crl__lib__std__x86_64__linux__memory__mman___hbNext(b);
            ((nn->prevPhysSize = sz));
            ((b = prev));
        }
    }
    crl__lib__std__x86_64__linux__memory__mman___heapPushFree(b);
}
void* crl__lib__std__x86_64__linux__memory__mman___heapRealloc(void* ctx, void* ptr, size_t newSize) {
    ((void)(ctx));
    if (((ptr == 0)))
    {
        return crl__lib__std__x86_64__linux__memory__mman___heapAlloc(0, newSize);
    }
    if (((newSize == 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman___heapFree(0, ptr);
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman___HeapBlock* b = ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(((((uint8_t*)(ptr)) - crl__lib__std__x86_64__linux__memory__mman___HB_HDR))));
    size_t curSize = crl__lib__std__x86_64__linux__memory__mman___hbSize(b);
    size_t need = ((crl__lib__std__x86_64__linux__memory__mman___hbAlign(newSize) + crl__lib__std__x86_64__linux__memory__mman___HB_HDR));
    if (((need <= curSize)))
    {
        size_t rem = ((curSize - need));
        if (((rem >= ((crl__lib__std__x86_64__linux__memory__mman___HB_HDR + crl__lib__std__x86_64__linux__memory__mman___HB_ALIGN)))))
        {
            crl__lib__std__x86_64__linux__memory__mman___HeapBlock* tail = ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(((((uint8_t*)(b)) + need))));
            ((tail->sizeAndFlags = ((rem | crl__lib__std__x86_64__linux__memory__mman___HB_FREE))));
            ((tail->prevPhysSize = need));
            ((b->sizeAndFlags = need));
            crl__lib__std__x86_64__linux__memory__mman___HeapBlock* nn = crl__lib__std__x86_64__linux__memory__mman___hbNext(tail);
            ((nn->prevPhysSize = rem));
            crl__lib__std__x86_64__linux__memory__mman___heapPushFree(tail);
        }
        return ptr;
    }
    crl__lib__std__x86_64__linux__memory__mman___HeapBlock* next = crl__lib__std__x86_64__linux__memory__mman___hbNext(b);
    if (((crl__lib__std__x86_64__linux__memory__mman___hbIsFree(next)) && (((((curSize + crl__lib__std__x86_64__linux__memory__mman___hbSize(next))) >= need)))))
    {
        crl__lib__std__x86_64__linux__memory__mman___heapUnlink(next);
        size_t total = ((curSize + crl__lib__std__x86_64__linux__memory__mman___hbSize(next)));
        size_t rem = ((total - need));
        if (((rem >= ((crl__lib__std__x86_64__linux__memory__mman___HB_HDR + crl__lib__std__x86_64__linux__memory__mman___HB_ALIGN)))))
        {
            crl__lib__std__x86_64__linux__memory__mman___HeapBlock* tail = ((crl__lib__std__x86_64__linux__memory__mman___HeapBlock*)(((((uint8_t*)(b)) + need))));
            ((tail->sizeAndFlags = ((rem | crl__lib__std__x86_64__linux__memory__mman___HB_FREE))));
            ((tail->prevPhysSize = need));
            ((b->sizeAndFlags = need));
            crl__lib__std__x86_64__linux__memory__mman___HeapBlock* nn = crl__lib__std__x86_64__linux__memory__mman___hbNext(tail);
            ((nn->prevPhysSize = rem));
            crl__lib__std__x86_64__linux__memory__mman___heapPushFree(tail);
        }
        else
        {
            ((b->sizeAndFlags = total));
            crl__lib__std__x86_64__linux__memory__mman___HeapBlock* nn = crl__lib__std__x86_64__linux__memory__mman___hbNext(b);
            ((nn->prevPhysSize = total));
        }
        return ptr;
    }
    void* np = crl__lib__std__x86_64__linux__memory__mman___heapAlloc(0, newSize);
    if (((np == 0)))
    {
        return 0;
    }
    size_t copyLen = ((((((curSize - crl__lib__std__x86_64__linux__memory__mman___HB_HDR)) < newSize))) ? (((curSize - crl__lib__std__x86_64__linux__memory__mman___HB_HDR))) : (newSize));
    memcpy(np, ptr, copyLen);
    crl__lib__std__x86_64__linux__memory__mman___heapFree(0, ptr);
    return np;
}
void* crl__lib__std__x86_64__linux__memory__mman___pageAlloc(void* ctx, size_t size) {
    ((void)(ctx));
    if (((size == 0)))
    {
        return 0;
    }
    size_t aligned = ((((((size + crl__lib__std__x86_64__linux__memory__mman__pageSize)) - 1)) & (~(((crl__lib__std__x86_64__linux__memory__mman__pageSize - 1))))));
    void* region = crl__lib__std__x86_64__linux__memory__intrinsics__memory__mmap(0, ((aligned + crl__lib__std__x86_64__linux__memory__mman__pageSize)), 3, 34, (-(1)), 0);
    if (((region == 0)))
    {
        return 0;
    }
    (((*(((size_t*)(region)))) = aligned));
    return ((void*)(((((uint8_t*)(region)) + crl__lib__std__x86_64__linux__memory__mman__pageSize))));
}
void crl__lib__std__x86_64__linux__memory__mman___pageFree(void* ctx, void* ptr) {
    ((void)(ctx));
    if ((!(ptr)))
    {
        return;
    }
    uint8_t* region = ((((uint8_t*)(ptr)) - crl__lib__std__x86_64__linux__memory__mman__pageSize));
    size_t size = (*(((size_t*)(region))));
    crl__lib__std__x86_64__linux__memory__intrinsics__memory__munmap(region, ((size + crl__lib__std__x86_64__linux__memory__mman__pageSize)));
}
void* crl__lib__std__x86_64__linux__memory__mman___pageRealloc(void* ctx, void* ptr, size_t newSize) {
    ((void)(ctx));
    if (((newSize == 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman___pageFree(0, ptr);
        return 0;
    }
    void* newPtr = crl__lib__std__x86_64__linux__memory__mman___pageAlloc(0, newSize);
    if (((newPtr == 0)))
    {
        return 0;
    }
    if (((ptr != 0)))
    {
        size_t oldAligned = (*(((size_t*)(((((uint8_t*)(ptr)) - crl__lib__std__x86_64__linux__memory__mman__pageSize))))));
        size_t newAligned = (*(((size_t*)(((((uint8_t*)(newPtr)) - crl__lib__std__x86_64__linux__memory__mman__pageSize))))));
        size_t copyLen = ((((oldAligned < newAligned))) ? (oldAligned) : (newAligned));
        memcpy(newPtr, ptr, copyLen);
        crl__lib__std__x86_64__linux__memory__mman___pageFree(0, ptr);
    }
    return newPtr;
}
void crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_init(crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* self, uint8_t* buffer, size_t size) {
    ((self->buffer = buffer));
    ((self->cap = size));
    ((self->used = 0));
}
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* self) {
    return ((crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = ((void*)(self)), .alloc = crl__lib__std__x86_64__linux__memory__mman___fbaAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___fbaFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___fbaRealloc});
}
void crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_reset(crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* self) {
    ((self->used = 0));
}
size_t crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_remaining(crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* self) {
    return ((self->cap - self->used));
}
void* crl__lib__std__x86_64__linux__memory__mman___fbaAlloc(void* ctx, size_t size) {
    if ((((!(ctx))) || (((size == 0)))))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator*)(ctx));
    size_t aligned = ((((size + 7)) & (~(((size_t)(7))))));
    if (((((((alloc->used + 8)) + aligned)) > alloc->cap)))
    {
        return 0;
    }
    (((*(((size_t*)(((alloc->buffer + alloc->used)))))) = aligned));
    void* ptr = ((void*)(((((alloc->buffer + alloc->used)) + 8))));
    ((alloc->used += ((8 + aligned))));
    return ptr;
}
void crl__lib__std__x86_64__linux__memory__mman___fbaFree(void* ctx, void* ptr) {
    ((void)(ctx));
    ((void)(ptr));
}
void* crl__lib__std__x86_64__linux__memory__mman___fbaRealloc(void* ctx, void* ptr, size_t newSize) {
    if ((!(ctx)))
    {
        return 0;
    }
    if (((newSize == 0)))
    {
        return 0;
    }
    size_t oldAligned = ((((ptr != 0))) ? ((*(((size_t*)(((((uint8_t*)(ptr)) - 8))))))) : (0));
    void* newPtr = crl__lib__std__x86_64__linux__memory__mman___fbaAlloc(ctx, newSize);
    if (((newPtr == 0)))
    {
        return 0;
    }
    size_t copyLen = ((((oldAligned < newSize))) ? (oldAligned) : (newSize));
    if (((((ptr != 0))) && (((copyLen > 0)))))
    {
        memcpy(newPtr, ptr, copyLen);
    }
    return newPtr;
}
void crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator_init(crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* fallback) {
    crl__lib__std__x86_64__linux__memory__mman__FixedBufferAllocator_init((&(self->fba)), self->stackBuf, 1024);
    ((self->fallback = fallback));
}
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator* self) {
    return ((crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = ((void*)(self)), .alloc = crl__lib__std__x86_64__linux__memory__mman___sfaAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___sfaFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___sfaRealloc});
}
void* crl__lib__std__x86_64__linux__memory__mman___sfaAlloc(void* ctx, size_t size) {
    if ((!(ctx)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator*)(ctx));
    void* ptr = crl__lib__std__x86_64__linux__memory__mman___fbaAlloc(((void*)((&(alloc->fba)))), size);
    if (((ptr != 0)))
    {
        return ptr;
    }
    if ((!(alloc->fallback)))
    {
        return 0;
    }
    return (alloc->fallback->alloc)(alloc->fallback->ctx, size);
}
void crl__lib__std__x86_64__linux__memory__mman___sfaFree(void* ctx, void* ptr) {
    if ((((!(ctx))) || ((!(ptr)))))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator*)(ctx));
    uint8_t* p = ((uint8_t*)(ptr));
    if (((((p >= alloc->stackBuf))) && (((p < ((alloc->stackBuf + 1024)))))))
    {
        return;
    }
    if (alloc->fallback)
    {
        (alloc->fallback->free)(alloc->fallback->ctx, ptr);
    }
}
void* crl__lib__std__x86_64__linux__memory__mman___sfaRealloc(void* ctx, void* ptr, size_t newSize) {
    if ((!(ctx)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__StackFallbackAllocator*)(ctx));
    if (((newSize == 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman___sfaFree(ctx, ptr);
        return 0;
    }
    uint8_t* p = ((uint8_t*)(ptr));
    _Bool inStack = ((((p >= alloc->stackBuf))) && (((p < ((alloc->stackBuf + 1024))))));
    size_t oldAligned = ((inStack) ? ((*(((size_t*)(((p - 8))))))) : (0));
    void* newPtr = crl__lib__std__x86_64__linux__memory__mman___sfaAlloc(ctx, newSize);
    if (((newPtr == 0)))
    {
        return 0;
    }
    size_t copyLen = ((((oldAligned < newSize))) ? (oldAligned) : (newSize));
    if (((((ptr != 0))) && (((copyLen > 0)))))
    {
        memcpy(newPtr, ptr, copyLen);
    }
    if ((((!(inStack))) && (alloc->fallback)))
    {
        (alloc->fallback->free)(alloc->fallback->ctx, ptr);
    }
    return newPtr;
}
void crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_init(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* backing, size_t initialCap) {
    ((self->backing = backing));
    ((self->base = ((uint8_t*)((backing->alloc)(backing->ctx, initialCap)))));
    ((self->cap = initialCap));
    ((self->used = 0));
}
void crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_deinit(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self) {
    (self->backing->free)(self->backing->ctx, ((void*)(self->base)));
    ((self->base = 0));
    ((self->cap = 0));
    ((self->used = 0));
}
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self) {
    return ((crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = ((void*)(self)), .alloc = crl__lib__std__x86_64__linux__memory__mman___arenaAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___arenaFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___arenaRealloc});
}
void* crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_push(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self, size_t size) {
    return crl__lib__std__x86_64__linux__memory__mman___arenaAlloc(((void*)(self)), size);
}
void crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_reset(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self) {
    ((self->used = 0));
}
size_t crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator_remaining(crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* self) {
    return ((self->cap - self->used));
}
void* crl__lib__std__x86_64__linux__memory__mman___arenaAlloc(void* ctx, size_t size) {
    if ((((!(ctx))) || (((size == 0)))))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator*)(ctx));
    if ((!(alloc->backing)))
    {
        return 0;
    }
    size_t aligned = ((((size + 7)) & (~(((size_t)(7))))));
    if (((((((alloc->used + 8)) + aligned)) > alloc->cap)))
    {
        size_t newCap = ((alloc->cap * 2));
        size_t need = ((((alloc->used + 8)) + aligned));
        if (((newCap < need)))
        {
            ((newCap = need));
        }
        uint8_t* newBase = ((uint8_t*)((alloc->backing->realloc)(alloc->backing->ctx, ((void*)(alloc->base)), newCap)));
        if (((newBase == 0)))
        {
            return 0;
        }
        ((alloc->base = newBase));
        ((alloc->cap = newCap));
    }
    (((*(((size_t*)(((alloc->base + alloc->used)))))) = aligned));
    void* ptr = ((void*)(((((alloc->base + alloc->used)) + 8))));
    ((alloc->used += ((8 + aligned))));
    return ptr;
}
void crl__lib__std__x86_64__linux__memory__mman___arenaFree(void* ctx, void* ptr) {
    ((void)(ctx));
    ((void)(ptr));
}
void* crl__lib__std__x86_64__linux__memory__mman___arenaRealloc(void* ctx, void* ptr, size_t newSize) {
    if ((!(ctx)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__ArenaAllocator*)(ctx));
    if (((newSize == 0)))
    {
        return 0;
    }
    size_t oldAligned = 0;
    size_t off = 0;
    if (((ptr != 0)))
    {
        ((oldAligned = (*(((size_t*)(((((uint8_t*)(ptr)) - 8))))))));
        ((off = ((size_t)(((((uint8_t*)(ptr)) - ((uint8_t*)(alloc->base))))))));
    }
    void* newPtr = crl__lib__std__x86_64__linux__memory__mman___arenaAlloc(ctx, newSize);
    if (((newPtr == 0)))
    {
        return 0;
    }
    size_t copyLen = ((((oldAligned < newSize))) ? (oldAligned) : (newSize));
    if (((((ptr != 0))) && (((copyLen > 0)))))
    {
        memcpy(newPtr, ((((uint8_t*)(alloc->base)) + off)), copyLen);
    }
    return newPtr;
}
void crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_init(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* source, size_t blockSize, size_t blockCount) {
    ((self->source = source));
    ((self->blockSize = ((((blockSize > sizeof(void*)))) ? (blockSize) : (sizeof(void*)))));
    ((self->blockCount = 0));
    ((self->backing = ((((source != 0))) ? (((uint8_t*)((source->alloc)(source->ctx, ((self->blockSize * blockCount)))))) : (0))));
    ((self->freeList = 0));
    if (((self->backing == 0)))
    {
        return;
    }
    ((self->blockCount = blockCount));
    for (
    size_t i = 0;((i < blockCount));((i)++))
    {
        void* block = ((void*)(((self->backing + ((i * self->blockSize))))));
        (((*(((void**)(block)))) = self->freeList));
        ((self->freeList = block));
    }
}
void crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_deinit(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self) {
    if (((((self->source != 0))) && (((self->backing != 0)))))
    {
        (self->source->free)(self->source->ctx, ((void*)(self->backing)));
    }
    ((self->backing = 0));
    ((self->freeList = 0));
    ((self->blockSize = 0));
    ((self->blockCount = 0));
}
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self) {
    return ((crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = ((void*)(self)), .alloc = crl__lib__std__x86_64__linux__memory__mman___poolAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___poolFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___poolRealloc});
}
void* crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_allocBlock(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self) {
    return crl__lib__std__x86_64__linux__memory__mman___poolAlloc(((void*)(self)), self->blockSize);
}
void crl__lib__std__x86_64__linux__memory__mman__PoolAllocator_freeBlock(crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* self, void* block) {
    crl__lib__std__x86_64__linux__memory__mman___poolFree(((void*)(self)), block);
}
void* crl__lib__std__x86_64__linux__memory__mman___poolAlloc(void* ctx, size_t size) {
    if ((!(ctx)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__PoolAllocator*)(ctx));
    if (((size > alloc->blockSize)))
    {
        return 0;
    }
    if (((alloc->freeList == 0)))
    {
        return 0;
    }
    void* block = alloc->freeList;
    ((alloc->freeList = (*(((void**)(block))))));
    return block;
}
void crl__lib__std__x86_64__linux__memory__mman___poolFree(void* ctx, void* ptr) {
    if ((((!(ctx))) || ((!(ptr)))))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__PoolAllocator*)(ctx));
    (((*(((void**)(ptr)))) = alloc->freeList));
    ((alloc->freeList = ptr));
}
void* crl__lib__std__x86_64__linux__memory__mman___poolRealloc(void* ctx, void* ptr, size_t newSize) {
    if ((!(ctx)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__PoolAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__PoolAllocator*)(ctx));
    if (((newSize > alloc->blockSize)))
    {
        return 0;
    }
    return ptr;
}
void crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_init(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* backing, size_t cap) {
    ((self->backing = backing));
    ((self->ptrs = ((((backing != 0))) ? (((void**)((backing->alloc)(backing->ctx, ((cap * sizeof(void*))))))) : (0))));
    ((self->sizes = ((((backing != 0))) ? (((size_t*)((backing->alloc)(backing->ctx, ((cap * sizeof(size_t))))))) : (0))));
    ((self->len = 0));
    if (((((self->ptrs == 0))) || (((self->sizes == 0)))))
    {
        if (((self->ptrs != 0)))
        {
            (backing->free)(backing->ctx, ((void*)(self->ptrs)));
        }
        if (((self->sizes != 0)))
        {
            (backing->free)(backing->ctx, ((void*)(self->sizes)));
        }
        ((self->ptrs = 0));
        ((self->sizes = 0));
        ((cap = 0));
    }
    ((self->cap = cap));
}
void crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc__grow(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self) {
    size_t newCap = ((((self->cap > 0))) ? (((self->cap * 2))) : (64));
    void** newPtrs = ((void**)((self->backing->alloc)(self->backing->ctx, ((newCap * sizeof(void*))))));
    if (((newPtrs == 0)))
    {
        return;
    }
    size_t* newSizes = ((size_t*)((self->backing->alloc)(self->backing->ctx, ((newCap * sizeof(size_t))))));
    if (((newSizes == 0)))
    {
        (self->backing->free)(self->backing->ctx, ((void*)(newPtrs)));
        return;
    }
    if (((self->len > 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman__copy_voidp(newPtrs, self->ptrs, self->len);
        crl__lib__std__x86_64__linux__memory__mman__copy_size_t(newSizes, self->sizes, self->len);
    }
    if (((self->ptrs != 0)))
    {
        (self->backing->free)(self->backing->ctx, ((void*)(self->ptrs)));
    }
    if (((self->sizes != 0)))
    {
        (self->backing->free)(self->backing->ctx, ((void*)(self->sizes)));
    }
    ((self->ptrs = newPtrs));
    ((self->sizes = newSizes));
    ((self->cap = newCap));
}
void* crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_alloc(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self, size_t size) {
    if (((self->backing == 0)))
    {
        return 0;
    }
    if (((((self->ptrs == 0))) || (((self->len >= self->cap)))))
    {
        crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc__grow(self);
    }
    if (((((self->ptrs == 0))) || (((self->len >= self->cap)))))
    {
        return 0;
    }
    void* ptr = (self->backing->alloc)(self->backing->ctx, size);
    if (((ptr != 0)))
    {
        ((self->ptrs[self->len] = ptr));
        ((self->sizes[self->len] = size));
        ((self->len)++);
    }
    return ptr;
}
void crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_freeAll(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        (self->backing->free)(self->backing->ctx, self->ptrs[i]);
    }
    ((self->len = 0));
}
void crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_deinit(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self) {
    crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_freeAll(self);
    (self->backing->free)(self->backing->ctx, ((void*)(self->ptrs)));
    (self->backing->free)(self->backing->ctx, ((void*)(self->sizes)));
    ((self->ptrs = 0));
    ((self->sizes = 0));
    ((self->cap = 0));
}
size_t crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc_bytesUsed(crl__lib__std__x86_64__linux__memory__mman__ScopeAlloc* self) {
    size_t total = 0;
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        ((total += self->sizes[i]));
    }
    return total;
}
void crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator_init(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self, crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator* parent) {
    ((self->parent = parent));
    ((self->totalAlloced = 0));
    ((self->totalFreed = 0));
    ((self->currentUsed = 0));
    ((self->allocCount = 0));
    ((self->freeCount = 0));
    ((self->trackPtrs = ((((parent != 0))) ? (((void**)((parent->alloc)(parent->ctx, ((64 * sizeof(void*))))))) : (0))));
    ((self->trackSizes = ((((parent != 0))) ? (((size_t*)((parent->alloc)(parent->ctx, ((64 * sizeof(size_t))))))) : (0))));
    ((self->trackLen = 0));
    if (((((self->trackPtrs == 0))) || (((self->trackSizes == 0)))))
    {
        if (((((self->trackPtrs != 0))) && (((parent != 0)))))
        {
            (parent->free)(parent->ctx, ((void*)(self->trackPtrs)));
        }
        if (((((self->trackSizes != 0))) && (((parent != 0)))))
        {
            (parent->free)(parent->ctx, ((void*)(self->trackSizes)));
        }
        ((self->trackPtrs = 0));
        ((self->trackSizes = 0));
        ((self->trackCap = 0));
    }
    else
    {
        ((self->trackCap = 64));
    }
}
void crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__trackGrow(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self) {
    size_t newCap = ((((self->trackCap > 0))) ? (((self->trackCap * 2))) : (64));
    void** newPtrs = ((void**)((self->parent->alloc)(self->parent->ctx, ((newCap * sizeof(void*))))));
    if (((newPtrs == 0)))
    {
        return;
    }
    size_t* newSizes = ((size_t*)((self->parent->alloc)(self->parent->ctx, ((newCap * sizeof(size_t))))));
    if (((newSizes == 0)))
    {
        (self->parent->free)(self->parent->ctx, ((void*)(newPtrs)));
        return;
    }
    if (((self->trackLen > 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman__copy_voidp(newPtrs, self->trackPtrs, self->trackLen);
        crl__lib__std__x86_64__linux__memory__mman__copy_size_t(newSizes, self->trackSizes, self->trackLen);
    }
    if (((self->trackPtrs != 0)))
    {
        (self->parent->free)(self->parent->ctx, ((void*)(self->trackPtrs)));
    }
    if (((self->trackSizes != 0)))
    {
        (self->parent->free)(self->parent->ctx, ((void*)(self->trackSizes)));
    }
    ((self->trackPtrs = newPtrs));
    ((self->trackSizes = newSizes));
    ((self->trackCap = newCap));
}
void crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__track(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self, void* ptr, size_t size) {
    if (((((self->trackPtrs == 0))) || (((self->trackLen >= self->trackCap)))))
    {
        crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__trackGrow(self);
    }
    if (((((self->trackPtrs == 0))) || (((self->trackLen >= self->trackCap)))))
    {
        return;
    }
    ((self->trackPtrs[self->trackLen] = ptr));
    ((self->trackSizes[self->trackLen] = size));
    ((self->trackLen)++);
}
size_t crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__untrack(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self, void* ptr) {
    for (
    size_t i = 0;((i < self->trackLen));((i)++))
    {
        if (((self->trackPtrs[i] == ptr)))
        {
            size_t size = self->trackSizes[i];
            ((self->trackLen)--);
            ((self->trackPtrs[i] = self->trackPtrs[self->trackLen]));
            ((self->trackSizes[i] = self->trackSizes[self->trackLen]));
            return size;
        }
    }
    return 0;
}
crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator_allocator(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self) {
    return ((crl__lib__std__x86_64__linux__memory__allocators__allocator__Allocator){.ctx = ((void*)(self)), .alloc = crl__lib__std__x86_64__linux__memory__mman___logAlloc, .free = crl__lib__std__x86_64__linux__memory__mman___logFree, .realloc = crl__lib__std__x86_64__linux__memory__mman___logRealloc});
}
void crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator_printStats(crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* self) {
}
void* crl__lib__std__x86_64__linux__memory__mman___logAlloc(void* ctx, size_t size) {
    if ((((!(ctx))) || (((size == 0)))))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator*)(ctx));
    if ((!(alloc->parent)))
    {
        return 0;
    }
    void* ptr = (alloc->parent->alloc)(alloc->parent->ctx, size);
    if (((ptr != 0)))
    {
        ((alloc->totalAlloced += size));
        ((alloc->currentUsed += size));
        ((alloc->allocCount)++);
        crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__track(alloc, ptr, size);
    }
    return ptr;
}
void crl__lib__std__x86_64__linux__memory__mman___logFree(void* ctx, void* ptr) {
    if ((((!(ctx))) || ((!(ptr)))))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator*)(ctx));
    if (((ptr == 0)))
    {
        return;
    }
    ((alloc->freeCount)++);
    size_t size = crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__untrack(alloc, ptr);
    if (((size > alloc->currentUsed)))
    {
        ((size = alloc->currentUsed));
    }
    ((alloc->totalFreed += size));
    ((alloc->currentUsed -= size));
    if (alloc->parent)
    {
        (alloc->parent->free)(alloc->parent->ctx, ptr);
    }
}
void* crl__lib__std__x86_64__linux__memory__mman___logRealloc(void* ctx, void* ptr, size_t newSize) {
    if ((((!(ctx))) || (((newSize == 0)))))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator* alloc = ((crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator*)(ctx));
    if ((!(alloc->parent)))
    {
        return 0;
    }
    size_t oldSize = ((((ptr != 0))) ? (crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__untrack(alloc, ptr)) : (0));
    void* newPtr = (alloc->parent->realloc)(alloc->parent->ctx, ptr, newSize);
    if (((newPtr == 0)))
    {
        if (((oldSize > 0)))
        {
            crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__track(alloc, ptr, oldSize);
        }
        return 0;
    }
    if (((newSize > oldSize)))
    {
        ((alloc->totalAlloced += ((newSize - oldSize))));
    }
    else
    {
        ((alloc->totalFreed += ((oldSize - newSize))));
    }
    if (((newSize > oldSize)))
    {
        ((alloc->currentUsed += ((newSize - oldSize))));
    }
    else
    {
        ((alloc->currentUsed -= ((oldSize - newSize))));
    }
    if (((ptr == 0)))
    {
        ((alloc->allocCount)++);
    }
    crl__lib__std__x86_64__linux__memory__mman__LoggingAllocator__track(alloc, newPtr, newSize);
    return newPtr;
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_new(void) {
    crl__lib__std__x86_64__linux__text__string__String s = ((crl__lib__std__x86_64__linux__text__string__String){.ptr = crl__lib__std__x86_64__linux__memory__mman__alloc_uint8_t(((16 + 1))), .len = 0, .cap = 16});
    ((s.ptr[0] = 0));
    return s;
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_withCap(size_t cap) {
    size_t c = ((((cap > 7))) ? (cap) : (7));
    crl__lib__std__x86_64__linux__text__string__String s = ((crl__lib__std__x86_64__linux__text__string__String){.ptr = crl__lib__std__x86_64__linux__memory__mman__alloc_uint8_t(((c + 1))), .len = 0, .cap = c});
    ((s.ptr[0] = 0));
    return s;
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_from(_coral_str sv) {
    crl__lib__std__x86_64__linux__text__string__String s = crl__lib__std__x86_64__linux__text__string__String_withCap(sv.len);
    memcpy(((void*)(s.ptr)), ((const void*)(sv.ptr)), sv.len);
    ((s.ptr[sv.len] = 0));
    ((s.len = sv.len));
    return s;
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_fromCstr(char* const cstr) {
    return crl__lib__std__x86_64__linux__text__string__String_from(crl__lib__core__str___coral_str_fromCstr(cstr));
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_clone(crl__lib__std__x86_64__linux__text__string__String* self) {
    return crl__lib__std__x86_64__linux__text__string__String_from(crl__lib__std__x86_64__linux__text__string__String_asView(self));
}
void crl__lib__std__x86_64__linux__text__string__String_free(crl__lib__std__x86_64__linux__text__string__String* self) {
    crl__lib__std__x86_64__linux__memory__mman__dealloc_uint8_t(self->ptr);
    ((self->ptr = 0));
    ((self->len = 0));
    ((self->cap = 0));
}
void crl__lib__std__x86_64__linux__text__string__String__ensure(crl__lib__std__x86_64__linux__text__string__String* self, size_t extra) {
    if (((((self->len + extra)) <= self->cap)))
    {
        return;
    }
    size_t nc = ((self->cap * 2));
    if (((nc < ((self->len + extra)))))
    {
        ((nc = ((self->len + extra))));
    }
    ((self->ptr = crl__lib__std__x86_64__linux__memory__mman__realloc_uint8_t(self->ptr, ((nc + 1)))));
    ((self->cap = nc));
}
_coral_str crl__lib__std__x86_64__linux__text__string__String_asView(crl__lib__std__x86_64__linux__text__string__String* self) {
    return crl__lib__core__str___coral_str_fromParts(self->ptr, self->len);
}
char* crl__lib__std__x86_64__linux__text__string__String_asCstr(crl__lib__std__x86_64__linux__text__string__String* self) {
    return ((char*)(self->ptr));
}
uint8_t* crl__lib__std__x86_64__linux__text__string__String_asU8(crl__lib__std__x86_64__linux__text__string__String* self) {
    return self->ptr;
}
void crl__lib__std__x86_64__linux__text__string__String_pushChar(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c) {
    crl__lib__std__x86_64__linux__text__string__String__ensure(self, 1);
    ((self->ptr[((self->len)++)] = c));
    ((self->ptr[self->len] = 0));
}
void crl__lib__std__x86_64__linux__text__string__String_pushByte(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t b) {
    crl__lib__std__x86_64__linux__text__string__String__ensure(self, 1);
    ((self->ptr[((self->len)++)] = b));
    ((self->ptr[self->len] = 0));
}
void crl__lib__std__x86_64__linux__text__string__String_appendView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str sv) {
    crl__lib__std__x86_64__linux__text__string__String_pushView(self, sv);
}
void crl__lib__std__x86_64__linux__text__string__String_pushView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str sv) {
    _Bool selfRef = ((((sv.ptr >= self->ptr))) && (((((size_t)(((sv.ptr - self->ptr)))) < self->len))));
    size_t off = 0;
    if (selfRef)
    {
        ((off = ((size_t)(((sv.ptr - self->ptr))))));
    }
    crl__lib__std__x86_64__linux__text__string__String__ensure(self, sv.len);
    if (selfRef)
    {
        memmove(((void*)(((self->ptr + self->len)))), ((const void*)(((self->ptr + off)))), sv.len);
    }
    else
    {
        memcpy(((void*)(((self->ptr + self->len)))), ((const void*)(sv.ptr)), sv.len);
    }
    ((self->len += sv.len));
    ((self->ptr[self->len] = 0));
}
void crl__lib__std__x86_64__linux__text__string__String_pushStr(crl__lib__std__x86_64__linux__text__string__String* self, crl__lib__std__x86_64__linux__text__string__String* const other) {
    crl__lib__std__x86_64__linux__text__string__String_pushView(self, crl__lib__std__x86_64__linux__text__string__String_asView(other));
}
void crl__lib__std__x86_64__linux__text__string__String_pushCstr(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t* const cstr) {
    crl__lib__std__x86_64__linux__text__string__String_pushView(self, crl__lib__core__str___coral_str_fromCstr(cstr));
}
void crl__lib__std__x86_64__linux__text__string__String_pushRepeat(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c, size_t n) {
    crl__lib__std__x86_64__linux__text__string__String__ensure(self, n);
    memset(((void*)(((self->ptr + self->len)))), ((uint8_t)(c)), n);
    ((self->len += n));
    ((self->ptr[self->len] = 0));
}
void crl__lib__std__x86_64__linux__text__string__String_clear(crl__lib__std__x86_64__linux__text__string__String* self) {
    ((self->len = 0));
    ((self->ptr[0] = 0));
}
void crl__lib__std__x86_64__linux__text__string__String_shrinkToFit(crl__lib__std__x86_64__linux__text__string__String* self) {
    ((self->ptr = crl__lib__std__x86_64__linux__memory__mman__realloc_uint8_t(self->ptr, ((self->len + 1)))));
    ((self->cap = self->len));
}
void crl__lib__std__x86_64__linux__text__string__String_truncate(crl__lib__std__x86_64__linux__text__string__String* self, size_t newLen) {
    if (((newLen >= self->len)))
    {
        return;
    }
    ((self->len = newLen));
    ((self->ptr[self->len] = 0));
}
void crl__lib__std__x86_64__linux__text__string__String_insertView(crl__lib__std__x86_64__linux__text__string__String* self, size_t idx, _coral_str sv) {
    assert(((idx <= self->len)));
    0;
    _Bool selfRef = ((((sv.ptr >= self->ptr))) && (((((size_t)(((sv.ptr - self->ptr)))) < self->len))));
    size_t off = 0;
    if (selfRef)
    {
        ((off = ((size_t)(((sv.ptr - self->ptr))))));
    }
    crl__lib__std__x86_64__linux__text__string__String__ensure(self, sv.len);
    memmove(((void*)(((((self->ptr + idx)) + sv.len)))), ((const void*)(((self->ptr + idx)))), ((((self->len - idx)) + 1)));
    if (selfRef)
    {
        uint8_t* src = ((self->ptr + off));
        if (((off >= idx)))
        {
            ((src = ((((self->ptr + off)) + sv.len))));
        }
        memmove(((void*)(((self->ptr + idx)))), ((const void*)(src)), sv.len);
    }
    else
    {
        memcpy(((void*)(((self->ptr + idx)))), ((const void*)(sv.ptr)), sv.len);
    }
    ((self->len += sv.len));
}
void crl__lib__std__x86_64__linux__text__string__String_removeRange(crl__lib__std__x86_64__linux__text__string__String* self, size_t start, size_t end) {
    assert(((start <= end)));
    0;
    assert(((end <= self->len)));
    0;
    size_t tail = ((self->len - end));
    memmove(((void*)(((self->ptr + start)))), ((const void*)(((self->ptr + end)))), ((tail + 1)));
    ((self->len -= ((end - start))));
}
void crl__lib__std__x86_64__linux__text__string__String_replaceAll(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str needle, _coral_str replacement) {
    if (((needle.len == 0)))
    {
        return;
    }
    crl__lib__std__x86_64__linux__text__string__String result = crl__lib__std__x86_64__linux__text__string__String_new();
    size_t i = 0;
    while (((i <= self->len)))
    {
        _coral_str rest = crl__lib__core__str___coral_str_fromParts(((self->ptr + i)), ((self->len - i)));
        size_t pos = crl__lib__core__str___coral_str_findView((&(rest)), needle);
        if (((pos == rest.len)))
        {
            crl__lib__std__x86_64__linux__text__string__String_pushView((&(result)), rest);
            break;
        }
        crl__lib__std__x86_64__linux__text__string__String_pushView((&(result)), crl__lib__core__str___coral_str_fromParts(rest.ptr, pos));
        crl__lib__std__x86_64__linux__text__string__String_pushView((&(result)), replacement);
        ((i += ((pos + needle.len))));
    }
    crl__lib__std__x86_64__linux__text__string__String_free(self);
    (((*(self)) = result));
}
void crl__lib__std__x86_64__linux__text__string__String_toUpper(crl__lib__std__x86_64__linux__text__string__String* self) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        ((self->ptr[i] = crl__lib__core__char_util__toUpper(self->ptr[i])));
    }
}
void crl__lib__std__x86_64__linux__text__string__String_toLower(crl__lib__std__x86_64__linux__text__string__String* self) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        ((self->ptr[i] = crl__lib__core__char_util__toLower(self->ptr[i])));
    }
}
void crl__lib__std__x86_64__linux__text__string__String_reverse(crl__lib__std__x86_64__linux__text__string__String* self) {
    size_t lo = 0;
    size_t hi = self->len;
    while (((lo < hi)))
    {
        ((hi)--);
        uint8_t t = self->ptr[lo];
        ((self->ptr[((lo)++)] = self->ptr[hi]));
        ((self->ptr[hi] = t));
    }
}
uint8_t crl__lib__std__x86_64__linux__text__string__String_at(crl__lib__std__x86_64__linux__text__string__String* self, size_t idx) {
    assert(((idx < self->len)));
    0;
    return self->ptr[idx];
}
void crl__lib__std__x86_64__linux__text__string__String_atApply(crl__lib__std__x86_64__linux__text__string__String* self, size_t idx, uint8_t c) {
    assert(((idx < self->len)));
    0;
    ((self->ptr[idx] = c));
}
_Bool crl__lib__std__x86_64__linux__text__string__String_isEmpty(crl__lib__std__x86_64__linux__text__string__String* self) {
    return ((self->len == 0));
}
_Bool crl__lib__std__x86_64__linux__text__string__String_equals(crl__lib__std__x86_64__linux__text__string__String* self, crl__lib__std__x86_64__linux__text__string__String* const other) {
    _coral_str sv = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_equals((&(sv)), crl__lib__std__x86_64__linux__text__string__String_asView(other));
}
_Bool crl__lib__std__x86_64__linux__text__string__String_equalsView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str sv) {
    _coral_str __t0;
    __t0 = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_equals((&(__t0)), sv);
}
int32_t crl__lib__std__x86_64__linux__text__string__String_compare(crl__lib__std__x86_64__linux__text__string__String* self, crl__lib__std__x86_64__linux__text__string__String* const other) {
    _coral_str sv = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_compare((&(sv)), crl__lib__std__x86_64__linux__text__string__String_asView(other));
}
size_t crl__lib__std__x86_64__linux__text__string__String_findChar(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c) {
    _coral_str __t0;
    __t0 = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_findByte((&(__t0)), c);
}
size_t crl__lib__std__x86_64__linux__text__string__String_rfindChar(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c) {
    _coral_str __t0;
    __t0 = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_rfindByte((&(__t0)), c);
}
size_t crl__lib__std__x86_64__linux__text__string__String_findView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str needle) {
    _coral_str __t0;
    __t0 = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_findView((&(__t0)), needle);
}
_Bool crl__lib__std__x86_64__linux__text__string__String_startsWith(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str prefix) {
    _coral_str __t0;
    __t0 = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_startsWith((&(__t0)), prefix);
}
_Bool crl__lib__std__x86_64__linux__text__string__String_endsWith(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str suffix) {
    _coral_str __t0;
    __t0 = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_endsWith((&(__t0)), suffix);
}
_Bool crl__lib__std__x86_64__linux__text__string__String_containsView(crl__lib__std__x86_64__linux__text__string__String* self, _coral_str needle) {
    _coral_str __t0;
    __t0 = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__core__str___coral_str_containsView((&(__t0)), needle);
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_trim(crl__lib__std__x86_64__linux__text__string__String* self) {
    _coral_str tv = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__std__x86_64__linux__text__string__String_from(crl__lib__core__str___coral_str_trim((&(tv))));
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_trimStart(crl__lib__std__x86_64__linux__text__string__String* self) {
    _coral_str tv = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__std__x86_64__linux__text__string__String_from(crl__lib__core__str___coral_str_trimStart((&(tv))));
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_trimEnd(crl__lib__std__x86_64__linux__text__string__String* self) {
    _coral_str tv = crl__lib__std__x86_64__linux__text__string__String_asView(self);
    return crl__lib__std__x86_64__linux__text__string__String_from(crl__lib__core__str___coral_str_trimEnd((&(tv))));
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_substr(crl__lib__std__x86_64__linux__text__string__String* self, size_t start, size_t end) {
    assert(((start <= end)));
    0;
    assert(((end <= self->len)));
    0;
    return crl__lib__std__x86_64__linux__text__string__String_from(crl__lib__core__str___coral_str_fromParts(((self->ptr + start)), ((end - start))));
}
Vec__coral_str crl__lib__std__x86_64__linux__text__string__String_splitByte(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t delim) {
    Vec__coral_str parts = crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_new();
    size_t start = 0;
    for (
    size_t i = 0;((i <= self->len));((i)++))
    {
        if (((((i == self->len))) || (((self->ptr[i] == delim)))))
        {
            crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_push((&(parts)), crl__lib__core__str___coral_str_fromParts(((self->ptr + start)), ((i - start))));
            ((start = ((i + 1))));
        }
    }
    return parts;
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_repeat(crl__lib__std__x86_64__linux__text__string__String* self, size_t n) {
    crl__lib__std__x86_64__linux__text__string__String r = crl__lib__std__x86_64__linux__text__string__String_withCap(((self->len * n)));
    for (
    size_t i = 0;((i < n));((i)++))
    {
        crl__lib__std__x86_64__linux__text__string__String_pushStr((&(r)), self);
    }
    return r;
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_join(_coral_str sep, Vec__coral_str* const parts) {
    crl__lib__std__x86_64__linux__text__string__String r = crl__lib__std__x86_64__linux__text__string__String_new();
    for (
    size_t i = 0;((i < parts->len));((i)++))
    {
        if (((i > 0)))
        {
            crl__lib__std__x86_64__linux__text__string__String_pushView((&(r)), sep);
        }
        crl__lib__std__x86_64__linux__text__string__String_pushView((&(r)), (*(crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_atConst(parts, i))));
    }
    return r;
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_padLeft(crl__lib__std__x86_64__linux__text__string__String* self, size_t totalLen, uint8_t padChar) {
    if (((self->len >= totalLen)))
    {
        return crl__lib__std__x86_64__linux__text__string__String_clone(self);
    }
    size_t pad = ((totalLen - self->len));
    crl__lib__std__x86_64__linux__text__string__String r = crl__lib__std__x86_64__linux__text__string__String_withCap(totalLen);
    crl__lib__std__x86_64__linux__text__string__String_pushRepeat((&(r)), padChar, pad);
    crl__lib__std__x86_64__linux__text__string__String_pushStr((&(r)), self);
    return r;
}
crl__lib__std__x86_64__linux__text__string__String crl__lib__std__x86_64__linux__text__string__String_padRight(crl__lib__std__x86_64__linux__text__string__String* self, size_t totalLen, uint8_t padChar) {
    if (((self->len >= totalLen)))
    {
        return crl__lib__std__x86_64__linux__text__string__String_clone(self);
    }
    crl__lib__std__x86_64__linux__text__string__String r = crl__lib__std__x86_64__linux__text__string__String_clone(self);
    crl__lib__std__x86_64__linux__text__string__String_pushRepeat((&(r)), padChar, ((totalLen - self->len)));
    return r;
}
size_t crl__lib__std__x86_64__linux__text__string__String_countChar(crl__lib__std__x86_64__linux__text__string__String* self, uint8_t c) {
    size_t n = 0;
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        if (((self->ptr[i] == c)))
        {
            ((n)++);
        }
    }
    return n;
}
void crl__lib__std__x86_64__linux__text__string__String_drop(crl__lib__std__x86_64__linux__text__string__String* self) {
    crl__lib__std__x86_64__linux__text__string__String_free(self);
}
void crl__lib__std__x86_64__linux__io__ios___writeStr(int32_t fd, _coral_str s) {
    if (((s.len > 0)))
    {
        write(fd, s.ptr, s.len);
    }
}
void crl__lib__std__x86_64__linux__io__ios___pflush(crl__lib__std__x86_64__linux__io__ios___Buf* out) {
    if (((out->len > 0)))
    {
        write(out->fd, out->data, out->len);
        ((out->len = 0));
    }
}
void crl__lib__std__x86_64__linux__io__ios___pbyte(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint8_t c) {
    if (((out->len >= 1024)))
    {
        crl__lib__std__x86_64__linux__io__ios___pflush(out);
    }
    ((out->data[out->len] = c));
    ((out->len)++);
}
void crl__lib__std__x86_64__linux__io__ios___pbytes(crl__lib__std__x86_64__linux__io__ios___Buf* out, char* const s, size_t n) {
    if (((n == 0)))
    {
        return;
    }
    if (((n >= 1024)))
    {
        crl__lib__std__x86_64__linux__io__ios___pflush(out);
        crl__lib__std__x86_64__linux__io__ios___writeStr(out->fd, crl__lib__core__str___coral_str_fromParts(((uint8_t*)(s)), n));
        return;
    }
    if (((((out->len + n)) > 1024)))
    {
        crl__lib__std__x86_64__linux__io__ios___pflush(out);
    }
    for (
    size_t i = 0;((i < n));((i)++))
    {
        ((out->data[((out->len + i))] = s[i]));
    }
    ((out->len += n));
}
size_t crl__lib__std__x86_64__linux__io__ios___itoa(uint8_t* dst, uint64_t val, uint32_t base, _Bool neg) {
    uint8_t tmp[72] = {0};
    size_t n = 0;
    if (((val == 0)))
    {
        ((tmp[0] = '0'));
        ((n = 1));
    }
    else
    {
        while (((val != 0)))
        {
            uint64_t digit = ((val % ((uint64_t)(base))));
            ((val /= ((uint64_t)(base))));
            ((tmp[n] = ((((digit < 10))) ? (((uint8_t)((('0' + digit))))) : (((uint8_t)((((('a' + digit)) - 10))))))));
            ((n)++);
        }
        if (neg)
        {
            ((tmp[n] = '-'));
            ((n)++);
        }
    }
    for (
    size_t i = 0;((i < n));((i)++))
    {
        ((dst[i] = tmp[((((n - 1)) - i))]));
    }
    return n;
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintSigned(crl__lib__std__x86_64__linux__io__ios___Buf* out, int64_t v, uint32_t base) {
    uint8_t numBuf[72] = {0};
    _Bool neg = ((v < 0));
    uint64_t mag = ((neg) ? (((((uint64_t)((-(((v + 1)))))) + 1))) : (((uint64_t)(v))));
    size_t n = crl__lib__std__x86_64__linux__io__ios___itoa(numBuf, mag, base, neg);
    crl__lib__std__x86_64__linux__io__ios___pbytes(out, numBuf, n);
    return ((int32_t)(n));
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint64_t v, uint32_t base, _Bool prefix) {
    uint8_t numBuf[72] = {0};
    size_t n = 0;
    if (prefix)
    {
        if (((base == 16)))
        {
            ((numBuf[0] = '0'));
            ((numBuf[1] = 'x'));
            ((n = 2));
        }
        else
        {
            if (((base == 2)))
            {
                ((numBuf[0] = '0'));
                ((numBuf[1] = 'b'));
                ((n = 2));
            }
        }
    }
    ((n += crl__lib__std__x86_64__linux__io__ios___itoa(((numBuf + n)), v, base, 0)));
    crl__lib__std__x86_64__linux__io__ios___pbytes(out, numBuf, n);
    return ((int32_t)(n));
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintI8(crl__lib__std__x86_64__linux__io__ios___Buf* out, int8_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintSigned(out, ((int64_t)(v)), 10);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintI16(crl__lib__std__x86_64__linux__io__ios___Buf* out, int16_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintSigned(out, ((int64_t)(v)), 10);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintI32(crl__lib__std__x86_64__linux__io__ios___Buf* out, int32_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintSigned(out, ((int64_t)(v)), 10);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintI64(crl__lib__std__x86_64__linux__io__ios___Buf* out, int64_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintSigned(out, v, 10);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintU8(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint8_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(out, ((uint64_t)(v)), 10, 0);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintU16(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint16_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(out, ((uint64_t)(v)), 10, 0);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintU32(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint32_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(out, ((uint64_t)(v)), 10, 0);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintU64(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint64_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(out, v, 10, 0);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintF32(crl__lib__std__x86_64__linux__io__ios___Buf* out, float v) {
    uint8_t buf[64] = {0};
    int32_t len = snprintf(buf, 64, "%.6g", v);
    if (((len > 0)))
    {
        if (((len > 63)))
        {
            ((len = 63));
        }
        crl__lib__std__x86_64__linux__io__ios___pbytes(out, buf, ((size_t)(len)));
    }
    return len;
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintF64(crl__lib__std__x86_64__linux__io__ios___Buf* out, double v) {
    uint8_t buf[64] = {0};
    int32_t len = snprintf(buf, 64, "%.15g", v);
    if (((len > 0)))
    {
        if (((len > 63)))
        {
            ((len = 63));
        }
        crl__lib__std__x86_64__linux__io__ios___pbytes(out, buf, ((size_t)(len)));
    }
    return len;
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintBool(crl__lib__std__x86_64__linux__io__ios___Buf* out, _Bool v) {
    if (v)
    {
        crl__lib__std__x86_64__linux__io__ios___pbytes(out, "true", 4);
        return 4;
    }
    else
    {
        crl__lib__std__x86_64__linux__io__ios___pbytes(out, "false", 5);
        return 5;
    }
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintChar(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint8_t v) {
    crl__lib__std__x86_64__linux__io__ios___pbyte(out, v);
    return 1;
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintPtr(crl__lib__std__x86_64__linux__io__ios___Buf* out, const void* v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(out, ((uint64_t)(v)), 16, 1);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintCstr(crl__lib__std__x86_64__linux__io__ios___Buf* out, char* const s) {
    size_t len = strlen(s);
    if (((len > 0)))
    {
        crl__lib__std__x86_64__linux__io__ios___pbytes(out, s, len);
    }
    return ((int32_t)(len));
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintBytes(crl__lib__std__x86_64__linux__io__ios___Buf* out, char* const ptr, size_t len) {
    if (((ptr) && (((len > 0)))))
    {
        crl__lib__std__x86_64__linux__io__ios___pbytes(out, ptr, len);
    }
    return ((int32_t)(len));
}
void crl__lib__std__x86_64__linux__io__ios___fprintNewline(crl__lib__std__x86_64__linux__io__ios___Buf* out) {
    crl__lib__std__x86_64__linux__io__ios___pbyte(out, (uint32_t)10);
}
void crl__lib__std__x86_64__linux__io__ios___fprintFlush(int32_t fd) {
    ((void)(fd));
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintHex(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint64_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(out, v, 16, 1);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintBin(crl__lib__std__x86_64__linux__io__ios___Buf* out, uint64_t v) {
    return crl__lib__std__x86_64__linux__io__ios___fprintUnsigned(out, v, 2, 1);
}
int32_t crl__lib__std__x86_64__linux__io__ios___fprintFixed(crl__lib__std__x86_64__linux__io__ios___Buf* out, double value, uint64_t precision) {
    if (((precision > 1000)))
    {
        ((precision = 1000));
    }
    uint8_t buf[1344] = {0};
    int32_t len = snprintf(buf, 1344, "%.*f", ((int32_t)(precision)), value);
    if (((len > 0)))
    {
        if (((len > 1343)))
        {
            ((len = 1343));
        }
        crl__lib__std__x86_64__linux__io__ios___pbytes(out, buf, ((size_t)(len)));
    }
    return len;
}
int32_t crl__lib__std__x86_64__linux__io__ios___sysReadByte(void) {
    return getchar();
}
size_t crl__lib__std__x86_64__linux__io__ios___sysReadLine(uint8_t* buf, size_t maxBytes) {
    if (((maxBytes == 0)))
    {
        return 0;
    }
    size_t i = 0;
    while (((i < ((maxBytes - 1)))))
    {
        int32_t c = getchar();
        if (((((c < 0))) || (((c == (uint32_t)10)))))
        {
            break;
        }
        if (((c != (uint32_t)13)))
        {
            ((buf[i] = ((uint8_t)(c))));
            ((++i));
        }
    }
    ((buf[i] = 0));
    return i;
}
void crl__lib__std__x86_64__linux__io__ios__vaprint(...) {
    uint8_t outBuf[1024] = {0};
    crl__lib__std__x86_64__linux__io__ios___Buf out = ((crl__lib__std__x86_64__linux__io__ios___Buf){.fd = 1, .data = outBuf, .len = 0});
    crl__lib__std__x86_64__linux__io__ios___pflush((&(out)));
}
crl__lib__std__x86_64__linux__io__ios__Spaces crl__lib__std__x86_64__linux__io__ios__spaces(uint64_t count) {
    return ((crl__lib__std__x86_64__linux__io__ios__Spaces){.count = count});
}
crl__lib__std__x86_64__linux__io__ios__Repeat crl__lib__std__x86_64__linux__io__ios__repeat(uint8_t ch, uint64_t count) {
    return ((crl__lib__std__x86_64__linux__io__ios__Repeat){.ch = ch, .count = count});
}
crl__lib__std__x86_64__linux__io__ios__Hex crl__lib__std__x86_64__linux__io__ios__hex(uint64_t value) {
    return ((crl__lib__std__x86_64__linux__io__ios__Hex){.value = value});
}
crl__lib__std__x86_64__linux__io__ios__Bin crl__lib__std__x86_64__linux__io__ios__bin(uint64_t value) {
    return ((crl__lib__std__x86_64__linux__io__ios__Bin){.value = value});
}
crl__lib__std__x86_64__linux__io__ios__Fixed crl__lib__std__x86_64__linux__io__ios__fixed(double value, uint64_t precision) {
    return ((crl__lib__std__x86_64__linux__io__ios__Fixed){.value = value, .precision = precision});
}
void crl__lib__std__x86_64__linux__io__ios__flush(void) {
    crl__lib__std__x86_64__linux__io__ios___fprintFlush(1);
}
int64_t crl__lib__std__x86_64__linux__io__ios___readI64(void) {
    crl__lib__std__x86_64__linux__text__string__String s = crl__lib__std__x86_64__linux__text__string__String_new();
    crl__lib__std__x86_64__linux__io__ios__readLine((&(s)));
    _Bool ok;
    int64_t v = crl__lib__std__x86_64__linux__io__ios__parseI64(crl__lib__std__x86_64__linux__text__string__String_asView((&(s))), (&(ok)));
    crl__lib__std__x86_64__linux__text__string__String_free((&(s)));
    return v;
}
uint64_t crl__lib__std__x86_64__linux__io__ios___readU64(void) {
    crl__lib__std__x86_64__linux__text__string__String s = crl__lib__std__x86_64__linux__text__string__String_new();
    crl__lib__std__x86_64__linux__io__ios__readLine((&(s)));
    _Bool ok;
    uint64_t v = crl__lib__std__x86_64__linux__io__ios__parseU64(crl__lib__std__x86_64__linux__text__string__String_asView((&(s))), (&(ok)));
    crl__lib__std__x86_64__linux__text__string__String_free((&(s)));
    return v;
}
double crl__lib__std__x86_64__linux__io__ios___readF64(void) {
    crl__lib__std__x86_64__linux__text__string__String s = crl__lib__std__x86_64__linux__text__string__String_new();
    crl__lib__std__x86_64__linux__io__ios__readLine((&(s)));
    _Bool ok;
    double v = crl__lib__std__x86_64__linux__io__ios__parseF64(crl__lib__std__x86_64__linux__text__string__String_asView((&(s))), (&(ok)));
    crl__lib__std__x86_64__linux__text__string__String_free((&(s)));
    return v;
}
_Bool crl__lib__std__x86_64__linux__io__ios___readBool(void) {
    crl__lib__std__x86_64__linux__text__string__String s = crl__lib__std__x86_64__linux__text__string__String_new();
    crl__lib__std__x86_64__linux__io__ios__readLine((&(s)));
    _coral_str sv = crl__lib__std__x86_64__linux__text__string__String_asView((&(s)));
    ((sv = crl__lib__core__str___coral_str_trim((&(sv)))));
    _Bool result = ((((crl__lib__core__str___coral_str_equals((&(sv)), (_coral_str){ (const uint8_t*)"true", 4 })) || (crl__lib__core__str___coral_str_equals((&(sv)), (_coral_str){ (const uint8_t*)"1", 1 })))) || (crl__lib__core__str___coral_str_equals((&(sv)), (_coral_str){ (const uint8_t*)"yes", 3 })));
    crl__lib__std__x86_64__linux__text__string__String_free((&(s)));
    return result;
}
int64_t crl__lib__std__x86_64__linux__io__ios__parseI64(_coral_str sv, _Bool* ok) {
    (((*(ok)) = 0));
    if (((sv.len == 0)))
    {
        return 0;
    }
    size_t i = 0;
    _Bool neg = 0;
    if (((sv.ptr[0] == '-')))
    {
        ((neg = 1));
        ((++i));
    }
    else
    {
        if (((sv.ptr[0] == '+')))
        {
            ((++i));
        }
    }
    if (((i == sv.len)))
    {
        return 0;
    }
    uint64_t result = 0;
    uint64_t limit = ((neg) ? (9223372036854775808) : (crl__lib__core__limits__INT64_MAX));
    while (((i < sv.len)))
    {
        uint8_t c = sv.ptr[((i)++)];
        if (((((c < '0'))) || (((c > '9')))))
        {
            return 0;
        }
        uint64_t digit = ((uint64_t)(((c - '0'))));
        if (((result > ((((limit - digit)) / 10)))))
        {
            return 0;
        }
        ((result = ((((result * 10)) + digit))));
    }
    (((*(ok)) = 1));
    if (neg)
    {
        if (((result == 9223372036854775808)))
        {
            return crl__lib__core__limits__INT64_MIN;
        }
        return (-(((int64_t)(result))));
    }
    return ((int64_t)(result));
}
uint64_t crl__lib__std__x86_64__linux__io__ios__parseU64(_coral_str sv, _Bool* ok) {
    (((*(ok)) = 0));
    if (((sv.len == 0)))
    {
        return 0;
    }
    size_t i = 0;
    if (((sv.ptr[0] == '+')))
    {
        ((++i));
    }
    if (((i == sv.len)))
    {
        return 0;
    }
    uint64_t result = 0;
    while (((i < sv.len)))
    {
        uint8_t c = sv.ptr[((i)++)];
        if (((((c < '0'))) || (((c > '9')))))
        {
            return 0;
        }
        uint64_t digit = ((uint64_t)(((c - '0'))));
        if (((result > ((((18446744073709551615 - digit)) / 10)))))
        {
            return 0;
        }
        ((result = ((((result * 10)) + digit))));
    }
    (((*(ok)) = 1));
    return result;
}
double crl__lib__std__x86_64__linux__io__ios__parseF64(_coral_str sv, _Bool* ok) {
    (((*(ok)) = 0));
    if (((sv.len == 0)))
    {
        return 0.0;
    }
    uint8_t buf[256] = {0};
    size_t len = ((((sv.len < 255))) ? (sv.len) : (255));
    crl__lib__std__x86_64__linux__memory__mman__copy_uint8_t(buf, ((uint8_t*)(sv.ptr)), len);
    ((buf[len] = 0));
    char* endptr;
    double result = strtod(buf, (&(endptr)));
    if (((endptr == buf)))
    {
        return 0.0;
    }
    while ((((((((((*(endptr)) == ' '))) || ((((*(endptr)) == (uint32_t)9))))) || ((((*(endptr)) == (uint32_t)10))))) || ((((*(endptr)) == (uint32_t)13)))))
    {
        ((endptr)++);
    }
    if ((((*(endptr)) != 0)))
    {
        return 0.0;
    }
    (((*(ok)) = 1));
    return result;
}
uint8_t crl__lib__std__x86_64__linux__io__ios__readChar(void) {
    int32_t b = getchar();
    return ((uint8_t)(((((b < 0))) ? (0) : (b))));
}
_Bool crl__lib__std__x86_64__linux__io__ios__readLine(crl__lib__std__x86_64__linux__text__string__String* out) {
    crl__lib__std__x86_64__linux__text__string__String_clear(out);
    while (1)
    {
        int32_t b = getchar();
        if (((b < 0)))
        {
            return (!(crl__lib__std__x86_64__linux__text__string__String_isEmpty(out)));
        }
        if (((b == (uint32_t)10)))
        {
            return 1;
        }
        if (((b != (uint32_t)13)))
        {
            crl__lib__std__x86_64__linux__text__string__String_pushChar(out, ((uint8_t)(b)));
        }
    }
}
int32_t crl__loc__m1__m1__ga(void) {
    return 7;
}
int32_t main(void) {
    crl__loc__m1__m1__A a = ((crl__loc__m1__m1__A){.x = crl__loc__m1__m1__ga()});
    crl__lib__std__x86_64__linux__io__ios__println__coral_str_v6189685f387084b6((_coral_str){ (const uint8_t*)"{}", 2 }, a.x);
    return 0;
}
void crl__lib__std__x86_64__linux__memory__mman__copy_voidp(void** dst, void** src, size_t count) {
    if (((((dst) && (src))) && (((count > 0)))))
    {
        memcpy(((void*)(dst)), ((const void*)(src)), ((sizeof(void*) * count)));
    }
}
void crl__lib__std__x86_64__linux__memory__mman__copy_size_t(size_t* dst, size_t* src, size_t count) {
    if (((((dst) && (src))) && (((count > 0)))))
    {
        memcpy(((void*)(dst)), ((const void*)(src)), ((sizeof(size_t) * count)));
    }
}
uint8_t* crl__lib__std__x86_64__linux__memory__mman__alloc_uint8_t(size_t count) {
    if (((count == 0)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__ensureDefaultAllocator();
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator == 0)))
    {
        return 0;
    }
    return ((uint8_t*)((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->alloc)(crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->ctx, ((sizeof(uint8_t) * count)))));
}
void crl__lib__std__x86_64__linux__memory__mman__dealloc_uint8_t(uint8_t* ptr) {
    if ((!(ptr)))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__mman__ensureDefaultAllocator();
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator == 0)))
    {
        return;
    }
    (crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->free)(crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->ctx, ((void*)(ptr)));
}
uint8_t* crl__lib__std__x86_64__linux__memory__mman__realloc_uint8_t(uint8_t* ptr, size_t newCount) {
    if (((newCount == 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman__dealloc_uint8_t(ptr);
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__ensureDefaultAllocator();
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator == 0)))
    {
        return 0;
    }
    return ((uint8_t*)((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->realloc)(crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->ctx, ((void*)(ptr)), ((sizeof(uint8_t) * newCount)))));
}
Vec__coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_new(void) {
    return ((Vec__coral_str){.data = 0, .len = 0, .cap = 0});
}
Vec__coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_withCap(size_t capacity) {
    return ((Vec__coral_str){.data = crl__lib__std__x86_64__linux__memory__mman__alloc__coral_str(capacity), .len = 0, .cap = capacity});
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_reserve(Vec__coral_str* self, size_t newCap) {
    if (((newCap <= self->cap)))
    {
        return;
    }
    ((self->data = crl__lib__std__x86_64__linux__memory__mman__realloc__coral_str(self->data, newCap)));
    ((self->cap = newCap));
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_push(Vec__coral_str* self, _coral_str val) {
    if (((self->len >= self->cap)))
    {
        size_t newCap = ((((self->cap > 0))) ? (((self->cap * 2))) : (4));
        crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_reserve(self, newCap);
    }
    ((self->data[self->len] = val));
    ((self->len)++);
}
_coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_pop(Vec__coral_str* self) {
    assert((((self->len > 0))));
    0;
    ((self->len)--);
    return self->data[self->len];
}
size_t crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_count(Vec__coral_str* self) {
    return self->len;
}
_coral_str* crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_atPtr(Vec__coral_str* self, size_t i) {
    assert((((i < self->len))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Index Out of bounds", 19 }));
    0;
    return (&(self->data[i]));
}
_coral_str* const crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_atConst(Vec__coral_str* self, size_t i) {
    assert((((i < self->len))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Index Out of bounds", 19 }));
    0;
    return ((_coral_str* const)((&(self->data[i]))));
}
_coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_at(Vec__coral_str* self, size_t i) {
    assert((((i < self->len))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Index Out of bounds", 19 }));
    0;
    return self->data[i];
}
_coral_str* crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_ptr(Vec__coral_str* self) {
    return self->data;
}
_Bool crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_isEmpty(Vec__coral_str* self) {
    return ((self->len == 0));
}
_coral_str* const crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_constPtr(Vec__coral_str* self) {
    return ((_coral_str* const)(self->data));
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_set(Vec__coral_str* self, size_t i, _coral_str val) {
    assert((((i < self->len))) && _coral_strtruth((_coral_str){ (const uint8_t*)"attempt to set in an Index Out of bounds", 40 }));
    0;
    ((self->data[i] = val));
}
_coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_front(Vec__coral_str* self) {
    assert((((self->len > 0))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Invalid Vector size", 19 }));
    0;
    return self->data[0];
}
_coral_str crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_back(Vec__coral_str* self) {
    assert((((self->len > 0))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Invalid Vector size", 19 }));
    0;
    return self->data[((self->len - 1))];
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_insert(Vec__coral_str* self, size_t i, _coral_str val) {
    assert((((i <= self->len))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Invalid Vector size", 19 }));
    0;
    if (((self->len >= self->cap)))
    {
        size_t newCap = ((((self->cap > 0))) ? (((self->cap * 2))) : (4));
        crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_reserve(self, newCap);
    }
    for (
    size_t j = self->len;((j > i));((j)--))
    {
        ((self->data[j] = self->data[((j - 1))]));
    }
    ((self->data[i] = val));
    ((self->len)++);
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_removeAt(Vec__coral_str* self, size_t i) {
    assert((((i < self->len))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Invalid Vector size", 19 }));
    0;
    for (
    size_t j = i;((j < ((self->len - 1))));((j)++))
    {
        ((self->data[j] = self->data[((j + 1))]));
    }
    ((self->len)--);
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_removeRange(Vec__coral_str* self, size_t start, size_t end) {
    assert((((start <= end))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Invalid range", 13 }));
    0;
    assert((((end <= self->len))) && _coral_strtruth((_coral_str){ (const uint8_t*)"Invalid Vector size", 19 }));
    0;
    size_t tail = ((self->len - end));
    for (
    size_t j = 0;((j < tail));((j)++))
    {
        ((self->data[((start + j))] = self->data[((end + j))]));
    }
    ((self->len -= ((end - start))));
}
_Bool crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_contains(Vec__coral_str* self, _coral_str val) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        if (_coral_streq(val, self->data[i]))
        {
            return 1;
        }
    }
    return 0;
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_fill(Vec__coral_str* self, _coral_str val) {
    for (
    size_t i = 0;((i < self->len));((i)++))
    {
        ((self->data[i] = val));
    }
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_reserveExact(Vec__coral_str* self, size_t newCap) {
    if (((newCap <= self->cap)))
    {
        return;
    }
    ((self->data = crl__lib__std__x86_64__linux__memory__mman__realloc__coral_str(self->data, newCap)));
    ((self->cap = newCap));
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_shrinkToFit(Vec__coral_str* self) {
    if (((self->len == self->cap)))
    {
        return;
    }
    ((self->data = crl__lib__std__x86_64__linux__memory__mman__realloc__coral_str(self->data, self->len)));
    ((self->cap = self->len));
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_clear(Vec__coral_str* self) {
    ((self->len = 0));
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_reverse(Vec__coral_str* self) {
    for (
    size_t i = 0;((i < ((self->len / 2))));((i)++))
    {
        size_t j = ((((self->len - 1)) - i));
        _coral_str tmp = self->data[i];
        ((self->data[i] = self->data[j]));
        ((self->data[j] = tmp));
    }
}
_Bool crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_isSortedBy(Vec__coral_str* self, FnP__Bool__coral_str__coral_str less) {
    for (
    size_t i = 1;((i < self->len));((i)++))
    {
        if (less(self->data[i], self->data[((i - 1))]))
        {
            return 0;
        }
    }
    return 1;
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_sortBy(Vec__coral_str* self, FnP__Bool__coral_str__coral_str less) {
    crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str__sortByRange(self, 0, self->len, less);
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str__sortByRange(Vec__coral_str* self, size_t lo, size_t hi, FnP__Bool__coral_str__coral_str less) {
    if (((((hi - lo)) <= 1)))
    {
        return;
    }
    size_t pi = crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str__partitionBy(self, lo, hi, less);
    if (((pi > lo)))
    {
        crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str__sortByRange(self, lo, pi, less);
    }
    if (((((pi + 1)) < hi)))
    {
        crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str__sortByRange(self, ((pi + 1)), hi, less);
    }
}
size_t crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str__partitionBy(Vec__coral_str* self, size_t lo, size_t hi, FnP__Bool__coral_str__coral_str less) {
    _coral_str pivot = self->data[((hi - 1))];
    size_t i = lo;
    for (
    size_t j = lo;((j < ((hi - 1))));((j)++))
    {
        if (less(self->data[j], pivot))
        {
            _coral_str tmp = self->data[i];
            ((self->data[i] = self->data[j]));
            ((self->data[j] = tmp));
            ((i)++);
        }
    }
    _coral_str tmp = self->data[i];
    ((self->data[i] = self->data[((hi - 1))]));
    ((self->data[((hi - 1))] = tmp));
    return i;
}
int64_t crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_binarySearchBy(Vec__coral_str* self, _coral_str key, FnP_int32_t__coral_str__coral_str cmp) {
    int64_t lo = 0;
    int64_t hi = ((((int64_t)(self->len)) - 1));
    while (((lo <= hi)))
    {
        int64_t mid = ((lo + ((((hi - lo)) / 2))));
        int32_t c = cmp(key, self->data[((size_t)(mid))]);
        if (((c == 0)))
        {
            return mid;
        }
        if (((c > 0)))
        {
            ((lo = ((mid + 1))));
        }
        else
        {
            ((hi = ((mid - 1))));
        }
    }
    return (-(1));
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_dispose(Vec__coral_str* self) {
    if (((self->data != 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman__dealloc__coral_str(self->data);
        ((self->data = 0));
    }
    ((self->len = 0));
    ((self->cap = 0));
}
void crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_drop(Vec__coral_str* self) {
    crl__lib__std__x86_64__linux__collections__vec__Vec__coral_str_dispose(self);
}
void crl__lib__std__x86_64__linux__memory__mman__copy_uint8_t(uint8_t* dst, uint8_t* src, size_t count) {
    if (((((dst) && (src))) && (((count > 0)))))
    {
        memcpy(((void*)(dst)), ((const void*)(src)), ((sizeof(uint8_t) * count)));
    }
}
void crl__lib__std__x86_64__linux__io__ios__println__coral_str_v6189685f387084b6(_coral_str fmt, int32_t _varg0) {
    uint8_t outBuf[1024] = {0};
    crl__lib__std__x86_64__linux__io__ios___Buf out = ((crl__lib__std__x86_64__linux__io__ios___Buf){.fd = 1, .data = outBuf, .len = 0});
    _coral_str f;
    ((f = (_coral_str){ (const uint8_t*)"{}", 2 }));
    size_t i = 0;
    uint8_t c = f.ptr[i];
    uint8_t spec = 0;
    crl__lib__std__x86_64__linux__io__ios___fprintI32((&(out)), _varg0);
    crl__lib__std__x86_64__linux__io__ios___fprintNewline((&(out)));
    crl__lib__std__x86_64__linux__io__ios___pflush((&(out)));
}
_coral_str* crl__lib__std__x86_64__linux__memory__mman__alloc__coral_str(size_t count) {
    if (((count == 0)))
    {
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__ensureDefaultAllocator();
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator == 0)))
    {
        return 0;
    }
    return ((_coral_str*)((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->alloc)(crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->ctx, ((sizeof(_coral_str) * count)))));
}
_coral_str* crl__lib__std__x86_64__linux__memory__mman__realloc__coral_str(_coral_str* ptr, size_t newCount) {
    if (((newCount == 0)))
    {
        crl__lib__std__x86_64__linux__memory__mman__dealloc__coral_str(ptr);
        return 0;
    }
    crl__lib__std__x86_64__linux__memory__mman__ensureDefaultAllocator();
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator == 0)))
    {
        return 0;
    }
    return ((_coral_str*)((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->realloc)(crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->ctx, ((void*)(ptr)), ((sizeof(_coral_str) * newCount)))));
}
void crl__lib__std__x86_64__linux__memory__mman__dealloc__coral_str(_coral_str* ptr) {
    if ((!(ptr)))
    {
        return;
    }
    crl__lib__std__x86_64__linux__memory__mman__ensureDefaultAllocator();
    if (((crl__lib__std__x86_64__linux__memory__mman__defaultAllocator == 0)))
    {
        return;
    }
    (crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->free)(crl__lib__std__x86_64__linux__memory__mman__defaultAllocator->ctx, ((void*)(ptr)));
}