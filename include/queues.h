#ifndef _PQUEUE_H
#define _PQUEUE_H
#include "vehicle.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct pnode {
    struct vehicle *car;
    int priority;
    struct pnode* next;
 
} node;


typedef struct pqueu{
	struct node * first;
	struct node * last;
	int maxsize;
	int size;

}pqueu;


void Push(pqueu* queue, struct vehicle *pcar, int priority);	
struct vehicle Pop(pqueu* queue);


#endif
