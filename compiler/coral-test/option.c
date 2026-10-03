#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#undef INT8_MIN
#undef INT8_MAX
#undef INT16_MIN
#undef INT16_MAX
#undef INT32_MIN
#undef INT32_MAX
#undef INT64_MIN
#undef INT64_MAX

typedef struct _coral_str { const uint8_t* ptr; size_t len; } _coral_str;
typedef struct Option_doubledouble Option_doubledouble;
typedef void (*FnP_349)(int32_t);
typedef void (*FnP_353)(int32_t);
typedef void* (*FnP_404)(void*);
typedef double (*FnP_76)(double);
typedef Option_doubledouble (*FnP_85)(double);
typedef Option_doubledouble (*FnP_91)();
typedef uint8_t cchar;
static int64_t INT64_MIN = (-(9223372036854775808));
static int64_t INT64_MAX = 9223372036854775807;
static int32_t INT32_MIN = (-(2147483648));
static int32_t INT32_MAX = 2147483647;
static int32_t INT16_MIN = (-(32768));
static int32_t INT16_MAX = 32767;
static int32_t INT8_MIN = (-(128));
static int32_t INT8_MAX = 127;
static uint64_t U64_MAX = 18446744073709551615;
static uint32_t U32_MAX = 4294967295;
static uint16_t U16_MAX = 65535;
static uint8_t U8_MAX = 255;
static double F64_MAX = 1.7976931348623157e+308;
static double F64_MIN = 2.2250738585072014e-308;
static double F32_MAX = 3.40282347e+38;
static double F32_MIN = 1.17549435e-38;
extern uint8_t** environ;
struct Option_doubledouble {
    int32_t tag;
    union {
        struct { char _e;
        } v0;
        struct {
            double value;
        } v1;
    } u;
};

int32_t getcchar(void);
int32_t putcchar(int32_t c);
void* mmap(void* addr, uint64_t length, int32_t prot, int32_t flags, int32_t fd, int64_t offset);
int32_t munmap(void* addr, uint64_t length);
int32_t open(uint8_t* const path, int32_t flags, int32_t mode);
int32_t close(int32_t fd);
int32_t stat(uint8_t* const path, void* buf);
int32_t mkdir(uint8_t* const path, int32_t mode);
void* opendir(uint8_t* const path);
void* readdir(void* dir);
int32_t closedir(void* dir);
int64_t lseek(int32_t fd, int64_t offset, int32_t whence);
int32_t regcomp(void* preg, uint8_t* const pattern, int32_t cflags);
int32_t regexec(const void* preg, uint8_t* const string, uint64_t nmatch, void* pmatch, int32_t eflags);
void regfree(void* preg);
uint64_t regerror(int32_t errcode, const void* preg, uint8_t* errbuf, uint64_t errbufSize);
int32_t fork(void);
int32_t waitpid(int32_t pid, int32_t* status, int32_t options);
int32_t poll(void* fds, uint64_t nfds, int32_t timeout);
void _exit(int32_t code);
int32_t pipe(int32_t* fds);
int32_t dup2(int32_t oldfd, int32_t newfd);
int32_t execvpe(uint8_t* const file, uint8_t** const argv, uint8_t** const envp);
FnP_349 signal(int32_t signum, FnP_353 handler);
int32_t kill(int32_t pid, int32_t sig);
int32_t raise(int32_t sig);
int32_t gettimeofday(void* tv, void* tz);
uint64_t time(void* t);
int64_t clock_gettime(int32_t clockId, void* tp);
int32_t nanosleep(const void* req, void* rem);
int32_t isatty(int32_t fd);
int32_t pthread_create(void** thread, const void* attr, FnP_404 start, void* arg);
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
Option_doubledouble checkedPow(double base, double exponent);
int32_t main(void);
_Bool Option_doubledouble_isSome(Option_doubledouble self);
_Bool Option_doubledouble_isNone(Option_doubledouble self);
double Option_doubledouble_unwrap(Option_doubledouble self);
double Option_doubledouble_unwrapOr(Option_doubledouble self, double default_);
double* Option_doubledouble_ptr(Option_doubledouble self);
double* const Option_doubledouble_constPtr(Option_doubledouble self);
void Option_doubledouble_map(Option_doubledouble self, FnP_76 fn);
void Option_doubledouble_andThen(Option_doubledouble self, FnP_85 fn);
void Option_doubledouble_orElse(Option_doubledouble self, FnP_91 fn);
double Option_doubledouble_take(Option_doubledouble self);
Option_doubledouble checkedPow(double base, double exponent) {
    _Bool __t0;
    size_t __t1;
    _Bool __t2;
    _Bool __t3;
    double __t4;
    _Bool __t5;
    _Bool __t6;
    Option_doubledouble __t7;
    double __t8;
    int32_t __t9;
    _Bool __t10;
    _Bool __t11;
    double __t12;
    _Bool __t13;
    _Bool __t14;
    Option_doubledouble __t15;
    double __t16;
    Option_doubledouble __t17;
    double count = 1;
    double currentBase = base;
    size_t exp = ((size_t)(exponent));
    __L1: ;
    __t0 = (exp > 0);
    if (!(__t0)) goto __L2;
    {
        __t1 = (exp % 2);
        __t2 = (__t1 == 1);
        if (!(__t2)) goto __L4;
        {
            __t3 = (currentBase > 0);
            __t4 = (((double)(INT32_MAX)) / count);
            __t5 = (currentBase > __t4);
            if (!(__t3)) goto __L5;
            if (!(__t5)) goto __L5;
            __t6 = 1;
            goto __L6;
            __L5: ;
            __t6 = 0;
            __L6: ;
            if (!(__t6)) goto __L8;
            __t7 = (Option_doubledouble){ .tag = 0};
            return __t7;
            __L8: ;
            __t8 = (count *= currentBase);
            __t8;
        }
        __L4: ;
        __t9 = (exp /= 2);
        __t9;
        __t10 = (exp > 0);
        if (!(__t10)) goto __L10;
        {
            __t11 = (currentBase > 0);
            __t12 = (((double)(INT32_MAX)) / currentBase);
            __t13 = (currentBase > __t12);
            if (!(__t11)) goto __L11;
            if (!(__t13)) goto __L11;
            __t14 = 1;
            goto __L12;
            __L11: ;
            __t14 = 0;
            __L12: ;
            if (!(__t14)) goto __L14;
            __t15 = (Option_doubledouble){ .tag = 0};
            return __t15;
            __L14: ;
            __t16 = (currentBase *= currentBase);
            __t16;
        }
        __L10: ;
    }
    goto __L1;
    __L2: ;
    __t17 = (Option_doubledouble){ .tag = 1, .u.v1 = {.value = count}};
    return __t17;
}
int32_t main(void) {
    Option_doubledouble __t0;
    _Bool __t1;
    double __t2;
    Option_doubledouble __t3;
    double __t4;
    int32_t __t5;
    __t0 = checkedPow(2, 10);
    Option_doubledouble result = __t0;
    __t1 = Option_doubledouble_isSome(result);
    if (!(__t1)) goto __L16;
    {
        __t2 = Option_doubledouble_unwrap(result);
        __t3 = checkedPow(3, 2);
        __t4 = Option_doubledouble_unwrapOr(__t3, (-(1)));
        __t5 = printf((_coral_str){ (const uint8_t*)"success: %f %f\n", 15 }.ptr, __t2, __t4);
        __t5;
        return 0;
    }
    __L16: ;
    return 1;
}
_Bool Option_doubledouble_isSome(Option_doubledouble self) {
    double value;
    __L18: ;
    if ((self.tag == 1)) goto __L19;
    goto __L21;
    __L19: ;
    value = self.u.v1.value;
    {
        return 1;
    }
    goto __L17;
    __L21: ;
    {
        return 0;
    }
    goto __L17;
    __L17: ;
}
_Bool Option_doubledouble_isNone(Option_doubledouble self) {
    double value;
    __L23: ;
    if ((self.tag == 1)) goto __L24;
    goto __L26;
    __L24: ;
    value = self.u.v1.value;
    {
        return 0;
    }
    goto __L22;
    __L26: ;
    {
        return 1;
    }
    goto __L22;
    __L22: ;
}
double Option_doubledouble_unwrap(Option_doubledouble self) {
    double value;
    __L28: ;
    if ((self.tag == 1)) goto __L29;
    goto __L31;
    __L29: ;
    value = self.u.v1.value;
    {
        return value;
    }
    goto __L27;
    __L31: ;
    {
        return 0;
    }
    goto __L27;
    __L27: ;
}
double Option_doubledouble_unwrapOr(Option_doubledouble self, double default_) {
    double value;
    __L33: ;
    if ((self.tag == 1)) goto __L34;
    goto __L36;
    __L34: ;
    value = self.u.v1.value;
    {
        return value;
    }
    goto __L32;
    __L36: ;
    {
        return default_;
    }
    goto __L32;
    __L32: ;
}
double* Option_doubledouble_ptr(Option_doubledouble self) {
    double value;
    __L38: ;
    if ((self.tag == 1)) goto __L39;
    goto __L41;
    __L39: ;
    value = self.u.v1.value;
    {
        return (&(value));
    }
    goto __L37;
    __L41: ;
    {
        return 0;
    }
    goto __L37;
    __L37: ;
}
double* const Option_doubledouble_constPtr(Option_doubledouble self) {
    double value;
    __L43: ;
    if ((self.tag == 1)) goto __L44;
    goto __L46;
    __L44: ;
    value = self.u.v1.value;
    {
        return (&(value));
    }
    goto __L42;
    __L46: ;
    return 0;
    goto __L42;
    __L42: ;
}
void Option_doubledouble_map(Option_doubledouble self, FnP_76 fn) {
    double __t0;
    Option_doubledouble __t1;
    Option_doubledouble __t2;
    double value;
    __L48: ;
    if ((self.tag == 1)) goto __L49;
    goto __L51;
    __L49: ;
    value = self.u.v1.value;
    {
        __t0 = fn(value);
        __t1 = (Option_doubledouble){ .tag = 1, .u.v1 = {.value = __t0}};
        __t2 = (self = __t1);
        __t2;
    }
    goto __L47;
    __L51: ;
    {
    }
    goto __L47;
    __L47: ;
}
void Option_doubledouble_andThen(Option_doubledouble self, FnP_85 fn) {
    Option_doubledouble __t0;
    Option_doubledouble __t1;
    double value;
    __L53: ;
    if ((self.tag == 1)) goto __L54;
    goto __L56;
    __L54: ;
    value = self.u.v1.value;
    {
        __t0 = fn(value);
        __t1 = (self = __t0);
        __t1;
    }
    goto __L52;
    __L56: ;
    {
    }
    goto __L52;
    __L52: ;
}
void Option_doubledouble_orElse(Option_doubledouble self, FnP_91 fn) {
    Option_doubledouble __t0;
    Option_doubledouble __t1;
    double value;
    __L58: ;
    if ((self.tag == 1)) goto __L59;
    goto __L61;
    __L59: ;
    value = self.u.v1.value;
    {
    }
    goto __L57;
    __L61: ;
    {
        __t0 = fn();
        __t1 = (self = __t0);
        __t1;
    }
    goto __L57;
    __L57: ;
}
double Option_doubledouble_take(Option_doubledouble self) {
    Option_doubledouble __t0;
    Option_doubledouble __t1;
    double value;
    __L63: ;
    if ((self.tag == 1)) goto __L64;
    goto __L66;
    __L64: ;
    value = self.u.v1.value;
    {
        __t0 = (Option_doubledouble){ .tag = 0};
        __t1 = (self = __t0);
        __t1;
        return value;
    }
    goto __L62;
    __L66: ;
    {
        assert(0);
        0;
    }
    goto __L62;
    __L62: ;
}