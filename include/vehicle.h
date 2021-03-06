
#ifndef _VEHICLE_H
#define _VEHICLE_H
#include <stdio.h>
#include <stdlib.h>
#include <city.h>



typedef struct list{
	int size;
	char * move;
	int finalPosition; //0 or 4, for the corners
	struct list * next;
}list;

typedef struct vehicle{
	int priority;
	int size;
	int position; //Position in the node
	int speed;
	int trips;
	struct NODE *actualNode; //Actual node in which the car is
	char *nextNode;
	list rute;
	char * color;
	char * model;
}vehicle;


void move(vehicle * car);

vehicle* create(int priority, int size, int position, int speed, int trips, struct NODE * actualNode, struct list rute, char * color, char * model, char * nextNode);

void addMove(vehicle * car, char * move);

#endif