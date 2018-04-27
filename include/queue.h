 #ifndef _QUEUE_H
#define _QUEUE_H
#include <ucontext.h>
#include "mypthread.h"

typedef struct node
{
    struct node *next;
    mypthread_t *data;
} node;

typedef struct queue
{
    node *front;
    node *back;
    int count;
} queue;

void queue_init(queue *);
int queue_len(queue *);
int enqueue(queue *, mypthread_t *);
mypthread_t *dequeue(queue *);
int remove_node(queue *, mypthread_t *);
mypthread_t *get_element(queue *, int);
void print_queue(queue *);
int clean_queue(queue *);

#endif