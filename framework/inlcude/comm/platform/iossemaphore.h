#ifndef _IOS_SEMAPHORE_INCLUDE_
#define _IOS_SEMAPHORE_INCLUDE_

// apple posix信号量封装

/*
typedef int sem_t;

// this should go in limits.h>
#define SEM_VALUE_MAX 32767
#define SEM_FAILED ((sem_t *)-1)

#include <sys/cdefs.h>

__BEGIN_DECLS
int sem_close(sem_t *);
int sem_destroy(sem_t *);
int sem_getvalue(sem_t * __restrict, int * __restrict);
int sem_init(sem_t *, int, unsigned int);
sem_t * sem_open(const char *, int, ...);
int sem_post(sem_t *);
int sem_trywait(sem_t *);
int sem_unlink(const char *);
int sem_wait(sem_t *) __DARWIN_ALIAS_C(sem_wait);
__END_DECLS

*/

#include <mach/semaphore.h>
#include <mach/task.h>
#include <mach/mach.h>

typedef struct sem_t {
    semaphore_t msem;
    int value;
}  sem_t;

int sem_init(sem_t *sem, int pshared, int initialValue);
int sem_destroy(sem_t *sem);
int sem_wait(sem_t *sem);
int sem_trywait(sem_t *sem);
int sem_post(sem_t *sem);
int sem_getvalue (sem_t *sem, int *sval);
//参数ts为相对时间差值，与linux下不同
int sem_timedwait(sem_t *sem,mach_timespec_t* ts);

#endif
