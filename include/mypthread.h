#ifndef _PTHREAD_H
#define _PTHREAD_H
#include <ucontext.h>

typedef struct
{
    int id;
    ucontext_t context;
    void *return_value;
    int priority;
    int *tickets;
} mypthread_t;
/**
 * Tickets are given according to thread's priority:
 * 3 (Highest): 10 tickets.
 * 2 (Mid): 5 tickets.
 * 1 (Low): 1 ticket.
 **/

typedef struct
{
    int lock;
} mypthread_mutex_t;

static int in_list(int, int *);
static int check_winner(mypthread_t *, int);
static void schedule_rr(void);
static void schedule_lott(void);
static void schedule(int);
int mypthread_cancel(mypthread_t *);
void mypthread_exit(void *);
void mypthread_detach(mypthread_t *);
int mypthread_create(mypthread_t *, int, void *(*)(void *), void *);
void mypthread_setsched(int, long);
void mymutex_init(mypthread_mutex_t*);
int mypthread_join(mypthread_t *, void **);
void mymutex_lock(mypthread_mutex_t*);
void mymutex_lock(mypthread_mutex_t *);
void mymutex_unlock(mypthread_mutex_t*);

#endif