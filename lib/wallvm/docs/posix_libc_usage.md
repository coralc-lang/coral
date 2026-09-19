# POSIX libc Usage in wallvm std

This document catalogs all POSIX/libc function usage across the wallvm standard library.
Use this as a reference when building platform-specific std variants (Windows, WASM, etc.).

## Summary

- **31 files** use POSIX libc functions
- **~120 unique POSIX functions** are called
- Most critical categories: File I/O, Thread/Mutex, Socket, String, Process

---

## File I/O

### Low-level (open/close/read/write)
| Function | Files | Notes |
|----------|-------|-------|
| `open` | `std/io/fs.crl`, `std/math/random.crl` | O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC flags |
| `close` | `std/io/fs.crl`, `std/io/temp.crl`, `std/io/process.crl`, `std/io/net.crl` | |
| `read` | `std/io/fs.crl`, `std/io/process.crl`, `std/math/random.crl` | |
| `write` | `std/io/fs.crl`, `std/io/process.crl`, `std/io/net.crl`, `std/io/ios.crl`, `std/io/term.crl` | Most used POSIX function |
| `lseek` | `std/io/fs.crl` | SEEK_SET, SEEK_CUR, SEEK_END |
| `stat` | `std/io/fs.crl` | struct stat for file metadata |
| `access` | `std/io/fs.crl` | F_OK, R_OK, W_OK, X_OK |
| `mkdir` | `std/io/fs.crl` | With mode parameter |
| `rmdir` | `std/io/fs.crl`, `std/io/temp.crl` | |
| `unlink` | `std/io/fs.crl`, `std/io/temp.crl` | |
| `rename` | `std/io/fs.crl` | |
| `opendir` | `std/io/fs.crl` | Returns DIR* |
| `readdir` | `std/io/fs.crl` | Returns struct dirent |
| `closedir` | `std/io/fs.crl` | |
| `mkstemp` | `std/io/temp.crl` | Temporary file creation |
| `mkdtemp` | `std/io/temp.crl` | Temporary directory creation |

### High-level (stdio)
| Function | Files | Notes |
|----------|-------|-------|
| `fopen` | `std/io/fios.crl` | Mode strings: "rb", "w", etc. |
| `fclose` | `std/io/fios.crl` | |
| `fread` | `std/io/fios.crl` | |
| `fwrite` | `std/io/fios.crl` | |
| `feof` | `std/io/fios.crl` | |
| `ferror` | `std/io/fios.crl` | |
| `fflush` | `std/io/fios.crl` | |
| `getchar` | `std/io/ios.crl` | Buffered stdin read |
| `snprintf` | `std/io/term.crl`, `std/io/ios.crl`, `std/text/fmt.crl`, `std/text/json.crl`, `wallvm/passes/borrowcheck.crl` | Format string output |
| `printf` | `std/platform/libc.crl` (declaration only) | Not actively used |

---

## String/Memory

| Function | Files | Notes |
|----------|-------|-------|
| `strlen` | `std/text/string.crl`, `std/io/ios.crl`, `wallvm/ir_types.crl`, `wallvm/ir_printer.crl`, `wallvm/passes/borrowcheck.crl` | |
| `memcmp` | `std/text/string.crl` | |
| `memcpy` | `std/text/string.crl`, `std/memory/mman.crl` | |
| `memmove` | `std/text/string.crl` | For overlapping regions |
| `memset` | `std/text/string.crl` | |
| `strtod` | `std/text/json.crl`, `std/text/toml.crl`, `std/io/ios.crl`, `std/math/math.crl` | String to double |
| `malloc` | `std/memory/mman.crl` | Legacy allocator fallback |
| `free` | `std/memory/mman.crl` | Legacy allocator fallback |
| `realloc` | `std/memory/mman.crl` | Legacy allocator fallback |

---

## Process

| Function | Files | Notes |
|----------|-------|-------|
| `fork` | `std/io/process.crl` | Process creation |
| `execvp` | `std/io/process.crl` | Process execution |
| `waitpid` | `std/io/process.crl` | Process reaping |
| `_exit` | `std/io/process.crl` | Immediate exit (no atexit) |
| `pipe` | `std/io/process.crl` | IPC pipes |
| `dup2` | `std/io/process.crl` | File descriptor duplication |
| `poll` | `std/io/process.crl` | I/O multiplexing |
| `getpid` | `std/platform/libc.crl` (declaration) | |
| `getppid` | `std/platform/libc.crl` (declaration) | |
| `kill` | `std/concurrent/signal.crl` | Signal delivery |
| `signal` | `std/concurrent/signal.crl` | Signal handler registration |
| `raise` | `std/concurrent/signal.crl` | Send signal to self |

---

## Thread/Concurrency

### pthread
| Function | Files | Notes |
|----------|-------|-------|
| `pthread_create` | `std/concurrent/thread.crl` | Thread creation |
| `pthread_join` | `std/concurrent/thread.crl` | Thread joining |
| `pthread_exit` | `std/concurrent/thread.crl` | Thread exit |
| `pthread_self` | `std/concurrent/thread.crl` | Get current thread ID |
| `pthread_mutex_init` | `std/concurrent/mutex.crl` | |
| `pthread_mutex_destroy` | `std/concurrent/mutex.crl` | |
| `pthread_mutex_lock` | `std/concurrent/mutex.crl` | |
| `pthread_mutex_unlock` | `std/concurrent/mutex.crl` | |
| `pthread_mutex_trylock` | `std/concurrent/mutex.crl` | |
| `pthread_mutexattr_init` | `std/concurrent/mutex.crl` | |
| `pthread_mutexattr_settype` | `std/concurrent/mutex.crl` | RECURSIVE, NORMAL |
| `pthread_mutexattr_destroy` | `std/concurrent/mutex.crl` | |
| `pthread_cond_init` | `std/concurrent/thread.crl` | |
| `pthread_cond_destroy` | `std/concurrent/thread.crl` | |
| `pthread_cond_wait` | `std/concurrent/thread.crl` | |
| `pthread_cond_signal` | `std/concurrent/thread.crl` | |
| `pthread_cond_broadcast` | `std/concurrent/thread.crl` | |
| `pthread_rwlock_init` | `std/concurrent/rwlock.crl` | |
| `pthread_rwlock_destroy` | `std/concurrent/rwlock.crl` | |
| `pthread_rwlock_rdlock` | `std/concurrent/rwlock.crl` | |
| `pthread_rwlock_wrlock` | `std/concurrent/rwlock.crl` | |
| `pthread_rwlock_tryrdlock` | `std/concurrent/rwlock.crl` | |
| `pthread_rwlock_trywrlock` | `std/concurrent/rwlock.crl` | |
| `pthread_rwlock_unlock` | `std/concurrent/rwlock.crl` | |

### Semaphore
| Function | Files | Notes |
|----------|-------|-------|
| `sem_init` | `std/concurrent/semaphore.crl` | |
| `sem_destroy` | `std/concurrent/semaphore.crl` | |
| `sem_wait` | `std/concurrent/semaphore.crl` | |
| `sem_trywait` | `std/concurrent/semaphore.crl` | |
| `sem_post` | `std/concurrent/semaphore.crl` | |
| `sem_getvalue` | `std/concurrent/semaphore.crl` | |

---

## Socket/Network

| Function | Files | Notes |
|----------|-------|-------|
| `socket` | `std/io/net.crl` | AF_INET, SOCK_STREAM, SOCK_DGRAM |
| `connect` | `std/io/net.crl` | |
| `bind` | `std/io/net.crl` | |
| `listen` | `std/io/net.crl` | |
| `accept` | `std/io/net.crl` | |
| `send` | `std/io/net.crl` | |
| `sendto` | `std/io/net.crl` | UDP |
| `recv` | `std/io/net.crl` | |
| `recvfrom` | `std/io/net.crl` | UDP |
| `htons` | `std/io/net.crl` | Host to network byte order |
| `htonl` | `std/io/net.crl` | |
| `setsockopt` | `std/io/net.crl` | SO_REUSEADDR, etc. |

---

## Time

| Function | Files | Notes |
|----------|-------|-------|
| `clock_gettime` | `std/core/time.crl` | CLOCK_MONOTONIC, CLOCK_REALTIME |
| `gettimeofday` | `std/core/time.crl` | Legacy alternative |
| `time` | `std/core/time.crl` | |
| `nanosleep` | `std/core/time.crl` | |

---

## Environment

| Function | Files | Notes |
|----------|-------|-------|
| `getenv` | `std/io/env.crl` | |
| `setenv` | `std/io/env.crl` | |
| `unsetenv` | `std/io/env.crl` | |
| `environ` | `std/io/env.crl` | Global env array |

---

## Math

| Function | Files | Notes |
|----------|-------|-------|
| `fabs` | `std/math/math.crl` | |

---

## Terminal

| Function | Files | Notes |
|----------|-------|-------|
| `isatty` | `std/io/term.crl` | Check if fd is a terminal |

---

## Regex

| Function | Files | Notes |
|----------|-------|-------|
| `regcomp` | `std/text/regex.crl` | POSIX regex compilation |
| `regexec` | `std/text/regex.crl` | POSIX regex execution |
| `regfree` | `std/text/regex.crl` | Free compiled regex |

---

## Windows Equivalents Needed

| POSIX | Windows Equivalent | Category |
|-------|-------------------|----------|
| `open/close/read/write/lseek` | `CreateFile/ReadFile/WriteFile/SetFilePointer` | File I/O |
| `stat` | `GetFileAttributesEx` | File metadata |
| `access` | `_access` | File access check |
| `mkdir` | `_mkdir` or `CreateDirectory` | Directory |
| `unlink` | `_unlink` or `DeleteFile` | File deletion |
| `rename` | `rename` or `MoveFile` | File rename |
| `opendir/readdir/closedir` | `FindFirstFile/FindNextFile/FindClose` | Directory listing |
| `fork/execvp/waitpid` | `CreateProcess/WaitForSingleObject` | Process |
| `pipe` | `CreatePipe` | IPC |
| `dup2` | `DuplicateHandle` | FD duplication |
| `poll` | `WSAPoll` or `WaitForMultipleObjects` | I/O multiplexing |
| `pthread_*` | `CreateThread/CRITICAL_SECTION/SRWLOCK` | Threading |
| `sem_*` | `CreateSemaphore` | Semaphore |
| `socket/connect/bind/listen/accept` | `WSASocket/WSAConnect/WSABind/WSAListen/WSAAccept` | Network |
| `signal/kill` | `SetConsoleCtrlHandler/TerminateProcess` | Signal |
| `gettimeofday/clock_gettime` | `QueryPerformanceCounter/GetSystemTimeAsFileTime` | Time |
| `getenv/setenv/unsetenv` | `GetEnvironmentVariable/SetEnvironmentVariable` | Environment |
| `isatty` | `_isatty` | Terminal |
| `snprintf` | `_snprintf` | Formatting |
| `regcomp/regexec/regfree` | No direct equivalent (use PCRE or custom) | Regex |

## WASM Equivalents Needed

WASM has no POSIX support. All libc calls must be replaced with:
- WASI syscalls for file I/O
- Custom implementations for threading (SharedArrayBuffer + Atomics)
- No process control (single-threaded by default)
- No sockets (use WebSocket or WASI sockets)
- No signals
- Custom time implementations

---

## Platform Abstraction Strategy

1. **`std/platform/posix.crl`** — Common POSIX implementations (current default)
2. **`std/platform/windows.crl`** — Windows implementations using Win32 API
3. **`std/platform/wasm.crl`** — WASM implementations using WASI
4. **`std/platform/linux.crl`** — Linux-specific (epoll, io_uring, etc.)
5. **`std/platform/darwin.crl`** — macOS-specific (kqueue, etc.)

Each platform file exports the same API surface. The build system selects the appropriate implementation based on the target triple.
