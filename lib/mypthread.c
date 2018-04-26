#include <ucontext.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include "../include/mypthread.h"
#include "../include/queue.h"

int schedule_algorithm; // 0: Round Robin, 1: Lottery, 2: Real
int initialized = 0;
int ticket_count = 0;

ucontext_t main_context;
queue ready_que, finish_que;

mypthread_t main_thread;
mypthread_t *current_running;

int cancel_current = 0;
int threads_running = 0;

struct itimerval timer;

void schedule_rr(void)
{
    mypthread_t *prev_thread, *next_thread = NULL;
    setitimer(ITIMER_VIRTUAL, 0, 0); // Stop time.
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
    setitimer(ITIMER_VIRTUAL, &timer, 0); // Start time.
    if (swapcontext(&(prev_thread->context), &(next_thread->context)) == -1)
        perror("Error while trying to swap context.");
}

void schedule_lott(void)
{
    // TODO
}

void schedule(int signal)
{
    switch (schedule_algorithm)
    {
    case 0:
        schedule_rr();
        break;
    case 1:
        schedule_rr(); // TODO: Implement lottery ticket scheduling
        break;
    }
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
            else
            {
                found = 1;
                break;
            }
        }
    }
    if (thread->id == current_running->id)
    {
        cancel_current = 1;
        schedule(0);
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

int mypthread_create(mypthread_t *thread, int priority, void *(*fnc)(void *), void *args)
{
    if (!(schedule_algorithm == 0 || schedule_algorithm == 1 || schedule_algorithm == 2))
    {
        printf("Error: No scheduling algorithm specified.\n");
        return -1;
    }
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
    if (schedule_algorithm == 1)
    {
        int tickets;
        int last_ticket = ticket_count + 1;
        switch (priority)
        {
        case 3:
            tickets = 10;
            break;
        case 2:
            tickets = 5;
            break;
        case 1:
            tickets = 1;
            break;
        }
        int *tickets_recieved = (int *)malloc(sizeof(int) * tickets);
        for (int i = 0; i < tickets; ++i)
        {
            tickets_recieved[i] = last_ticket;
            last_ticket++;
            ticket_count++;
        }
        thread->tickets = tickets_recieved;
    }
    enqueue(&ready_que, thread);
    return 0;
}

void mypthread_setsched(int algorithm, long quantum)
{
    if (algorithm == 0)
    {
        schedule_algorithm = 0;
        timer.it_value.tv_sec = quantum / 1000000;
        timer.it_value.tv_usec = quantum;
        timer.it_interval.tv_sec = quantum / 1000000;
        timer.it_interval.tv_usec = quantum;
        setitimer(ITIMER_VIRTUAL, &timer, 0);
        signal(SIGVTALRM, schedule);
    }
    else if (algorithm == 1)
        schedule_algorithm = 1;
    if (!initialized)
    {
        queue_init(&ready_que);
        queue_init(&finish_que);
        main_thread.id = -1; // Setting up main context.
        if (getcontext(&(main_thread.context)) == -1)
        {
            perror("Can't get current context.");
            exit(EXIT_FAILURE);
        }
        current_running = &main_thread;
        initialized = 1;
    }
}

void mypthread_yield(void)
{
    setitimer(ITIMER_VIRTUAL, 0, 0);
    setitimer(ITIMER_VIRTUAL, &timer, 0);
    schedule(0);
}

void mymutex_init(mypthread_mutex_t *mutex)
{
    mutex->lock = 0; // Unlocked by default.
}

int mypthread_join(mypthread_t *thread, void **ret_val)
{
    if (thread == current_running)
        return 1;
    mypthread_t *selected_thread;
    while (1)
    {
        for (int i = 0; i < queue_len(&finish_que); ++i)
        {
            selected_thread = get_element(&finish_que, i);
            if (thread->id == selected_thread->id)
            {
                if (!remove_node(&finish_que, selected_thread))
                {
                    ret_val = 0;
                    return 1;
                }
                else
                    ret_val = selected_thread->return_value;
                
            }
        }
    }
    mypthread_yield();
}

void mymutex_lock(mypthread_mutex_t *mutex)
{
    setitimer(ITIMER_VIRTUAL, 0, 0); // Stop time.
    while (mutex->lock == 1)
    {
        // TODO: Changes for Lottery
        setitimer(ITIMER_VIRTUAL, &timer, 0); // Start time.
        mypthread_yield();
        setitimer(ITIMER_VIRTUAL, 0, 0); // Stop time.
    }
    mutex->lock = 1;
    setitimer(ITIMER_VIRTUAL, &timer, 0); // Start time.
}

void mymutex_unlock(mypthread_mutex_t *mutex)
{
    mutex->lock = 0;
}