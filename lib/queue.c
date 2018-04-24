#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include "../include/queue.h"



void queue_init(queue *que)
{
    que->front = NULL;
    que->back = NULL;
    que->count = 0;
}

int queue_len(queue *que)
{
    return que->count;
}

int enqueue(queue *que, mypthread_t *thread)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
    {
        perror("Could not create node:");
        return -1;
    }
    new_node->data = thread;
    new_node->next = NULL;
    if (que->back)
    {
        que->back->next = new_node;
        que->back = new_node;
    }
    else
    {
        que->back = new_node;
        que->front = new_node;
    }
    ++(que->count);
    return 1;
}

mypthread_t *dequeue(queue *que)
{
    if (que->front == NULL)
        return NULL;
    node *current_front = que->front;
    que->front = que->front->next;
    --(que->count);
    mypthread_t *return_value = current_front->data;
    return return_value;
}

int remove_node(queue *que, mypthread_t *thread)
{
    node *current_node = que->front;
    node *previous_node = NULL;
    if (current_node == NULL)
        return -1;
    while (current_node)
    {
        if (current_node->data->id == thread->id)
        {
            if (previous_node == NULL)
                que->front = current_node->next;
            else
                previous_node->next = current_node->next;
            if (current_node == que->back)
                que->back = previous_node;
            free(current_node);
            --(que->count);
            return 1;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }

    return 0;
}

mypthread_t *get_element(queue *que, int position)
{
    node *current_node = que->front;
    if (que->count == 0)
    {
        return 0;
    }
    int counter = 0;
    mypthread_t *thread = 0;
    while (current_node)
    {
        if (counter == position)
        {
            thread = current_node->data;
            return thread;
        }
        current_node = current_node->next;
        ++counter;
    }
    return 0;
}

void print_queue(queue *que)
{
    node *current_node = que->front;
    if (current_node == NULL)
    {
        return;
    }
    printf("Beginning of queue\n");
    while (current_node)
    {
        printf("Thread %d\n", current_node->data->id);
        current_node = current_node->next;
    }
    printf("End of queue\n");
}

int clean_queue(queue *que) // TODO: Clean nodes.
{
    node *current_node = que->front;
    while (current_node)
    {
        mypthread_t *thread = current_node->data;
        free(thread);
        //free(current_node);
        current_node = current_node->next;
    }

    return 0;
}