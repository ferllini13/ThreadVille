#include <ucontext.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include "../include/mypthread.h"
#include "../include/queue.h"

// TODO: ORGANIZAR TODO EN HEADER

ucontext_t main_context;
queue ready_que, finish_que;

mypthread_t main_thread;
mypthread_t *current_running;

int cancel_current = 0;
int threads_running = 0;

// ======== TIMING FUNCTIONS ========
long period_t;
struct itimerval timer;
void start_timer(void)
{
    setitimer(ITIMER_VIRTUAL, &timer, 0);
}

void stop_timer(void)
{
    setitimer(ITIMER_VIRTUAL, 0, 0);
}

void schedule_rr(int signal)
{
    mypthread_t *prev_thread, *next_thread = NULL;
    stop_timer();
    if (getcontext(&main_context) == -1)
    {
        perror("Can't get current context");
        exit(EXIT_FAILURE);
    
    }
    prev_thread = current_running;
    if (!cancel_current)
        enqueue(&ready_que, prev_thread);
    else
        cancel_current = 0;
    next_thread = dequeue(&ready_que);
    if (next_thread == NULL)
    {
        printf("Everything done in ready queue!\n"); // For testing.
        exit(EXIT_SUCCESS);
    }
    current_running = next_thread;
    start_timer();
    if (swapcontext(&(prev_thread->context), &(next_thread->context)) == -1)
        perror("Error while trying to swap context.");
}

int mypthread_cancel(mypthread_t *thread)
{
    int found = 0;
    mypthread_t *current_thread;
    for (int i = 0; i < queue_len(&ready_que); ++i)
    {
        current_thread = get_element(&ready_que, i);
        if (current_thread->id == thread->id)
        {
            if (!remove_node(&ready_que, current_thread))
                return 1;
            else {
                found = 1;
                break;
            }
        }
    }
    if (thread->id == current_running->id)
    {
        cancel_current = 1;
        schedule_rr(0); // TODO: Other scheduling algorithms.
        return 0;
    }
    if (!found)
        return 1;
    return 0;
}

void mypthread_exit(void *return_value)
{
    current_running->return_value = return_value;
    enqueue(&finish_que, current_running);
    mypthread_cancel(current_running);
}

void mypthread_run(void *(*fnc)(void *), void *args)
{
    mypthread_exit(fnc(args));
    return;
}

int mypthread_create(mypthread_t *thread, void *(*fnc)(void *), void *args)
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

    makecontext(&(thread->context), (void (*)())mypthread_run, 2, fnc, args);
    enqueue(&ready_que, thread);
    return 0;
}

void mypthread_setsched(long quantum)
{
    queue_init(&ready_que);
    queue_init(&finish_que);

    timer.it_value.tv_sec = quantum / 1000000;
    timer.it_value.tv_usec = quantum;
    timer.it_interval.tv_sec = quantum / 1000000;
    timer.it_interval.tv_usec = quantum;
    start_timer();
    signal(SIGVTALRM, schedule_rr);
    main_thread.id = -1; // Setting up main context.
    if (getcontext(&(main_thread.context)) == -1)
    {
        perror("Can't get current context.");
        exit(EXIT_FAILURE);
    }
    current_running = &main_thread;
}

void mypthread_yield(void)
{
    stop_timer();
    start_timer();
    schedule_rr(0); // TODO: Other schedule algorithms.
}