#ifndef _PTHREAD_H
#define _PTHREAD_H
#include <ucontext.h>

typedef struct
{
    int id;
    ucontext_t context;
    void *return_value;
} mypthread_t;

typedef struct
{
    int lock;
} mypthread_mutex_t;

void start_timer(void);
void stop_timer(void);
void schedule_rr(int);
int mypthread_cancel(mypthread_t *);
void mypthread_exit(void *);
int mypthread_create(mypthread_t *, void* (*)(void *), void *);
void mypthread_setsched(long );

#endif