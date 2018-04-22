#include <ucontext.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include "queue.c"

ucontext_t main_context;
queue ready_que, finish_que;

void mypthread_run(void *(*start_fnc)(void *), void *args)
{
}

int mypthread_create(mypthread_t *thread, void *(*start_fnc)(void *), void *args)
{
    thread->id = queue_len(&ready_que);
    if (getcontext(&(thread->context)) == -1)
    {
        perror("Can't get context. ");
        exit(EXIT_FAILURE);
    }
    thread->context.uc_link = &main_context;
    thread->context.uc_stack.ss_sp = malloc(SIGSTKSZ);
    thread->context.uc_stack.ss_size = SIGSTKSZ;

    makecontext(&(thread->context), (void (*)())mypthread_run, 2, start_fnc, args);
    enqueue(&ready_que, thread);
    return 0;
}