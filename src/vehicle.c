#include <stdio.h>
#include <string.h>
#include "../include/vehicle.h"
#include "../include/city.h"

vehicle* create(int priority, int size, int position, int speed, int trips, struct NODE * actualNode, struct list rute, char * color, char * model, char * nextNode){
	vehicle *car=(vehicle*)calloc(1, sizeof(vehicle));
	car->priority = priority;
	car->size = size;
	car->position = position;
	car->speed = speed;
	car->trips = trips;
	car->actualNode = actualNode;
	car->rute = rute;
	car->color = color;
	car->model = model;
	car->nextNode = nextNode;
	return car;
}


 void addMove(vehicle * car,char * move){
// 	if ((* car).rute.size==0){
// 		car->rute.move=move;
// 		car->rute.size=1;
// 	}
// 	else{
// 		list * temp=(*car).rute.move;
// 		for (int i=0; i>(*car).rute.size - 1; ++i){
// 			temp=temp->next;
// 		}
// 		temp->rute=move;
// 		car->rute.size=*(car->rute.size)+1;	
// 	}

 }


void move(vehicle * car){
	int run = 1; //0 means end
	while(run){
		printf("car->position: %d\n", car->position);
		printf("car->actualNode->name: %s\n", car->actualNode->name);
		printf("car->nextNode: %s\n", car->nextNode);
		printf("car->rute.move: %s\n\n\n", car->rute.move);
		// printf("car->rute.size: %d\n\n\n", car->rute.size);
		
	// char* nameNextNodeStraight2 = car->actualNode->nextStraight->name;
	// char* nameNextNodeRight2 = car->actualNode->nextRight->name;
	// char* nameNextNode2 = car->nextNode;
	// printf("nameNextNodeStraight: %s\n", nameNextNodeStraight2);
	// printf("nameNextNodeRight: %s\n", nameNextNodeRight2);
	// printf("nameNextNode: %s\n", nameNextNode2);
	// int cmp2 = strcmp(nameNextNode2, nameNextNodeRight2);
	// printf("cmp2: %d\n", cmp2);

		if(car->rute.size == 0 && car->position < 4){
			if(car->actualNode->Vehicles[car->position + 1] == NULL){
				car->actualNode->Vehicles[car->position + 1] = car;
				car->actualNode->Vehicles[car->position] = NULL;
				car->position = car->position + 1;
			}
		} else if(car->rute.size == 0 && car->position >= 4){
			int cmp2 = 0;
			if(car->actualNode->nextStraight == NULL){
				char* nameNextNodeRight2 = car->actualNode->nextRight->name;
				char* nameNextNode2 = car->nextNode;
				cmp2 = strcmp(nameNextNode2, nameNextNodeRight2); //0 is =
				if(cmp2 == 0)
					cmp2 = 1;
			} else if(car->actualNode->nextRight == NULL){
				char* nameNextNodeStraight2 = car->actualNode->nextStraight->name;
				char* nameNextNode2 = car->nextNode;
				cmp2 = strcmp(nameNextNode2, nameNextNodeStraight2); //0 is =
			} else {
				char* nameNextNodeStraight2 = car->actualNode->nextStraight->name;
				char* nameNextNodeRight2 = car->actualNode->nextRight->name;
				char* nameNextNode2 = car->nextNode;
				cmp2 = strcmp(nameNextNode2, nameNextNodeStraight2); //0 is =
			}
			

			// printf("nameNextNodeStraight2: %s\n", nameNextNodeStraight2);
			// printf("nameNextNodeRight2: %s\n", nameNextNodeRight2);
			// printf("nameNextNode2: %s\n\n\n", nameNextNode2);
			
			switch(cmp2){
				case 0: //nameNextNodeStraight
					if(car->actualNode->nextStraight->Vehicles[0] == NULL){
						car->actualNode->nextStraight->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNode = car->actualNode->nextStraight;
					}
					break;
				default: //nameNextNodeRight
					if(car->actualNode->nextRight->Vehicles[0] == NULL){
						car->actualNode->nextRight->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNode = car->actualNode->nextRight;
					}
					break;
			}

			//Update the rute information
			car->nextNode = NULL;
			if(car->rute.size - 1 == -1){
				car->rute.size = -1;
			}

		} else if(car->rute.size == -1 && car->rute.finalPosition == car->position){
			run = 0;

		} else if(car->rute.size == -1 && car->rute.finalPosition == 4 && car->position < 4){
			run = 0;
			for(int i = 0; i < 5; i++){

				if(i > 0){
					printf("car->position: %d\n", car->position);
					printf("car->actualNode->name: %s\n", car->actualNode->name);
					printf("car->nextNode: %s\n", car->nextNode);
					printf("car->rute.move: %s\n\n\n", car->rute.move);
					//printf("car->rute.size: %d\n\n\n", car->rute.size);
					//printf("car->rute.finalPosition: %d\n\n\n", car->rute.finalPosition);
				}
				
				if(car->actualNode->Vehicles[car->position + 1] == NULL){
					car->actualNode->Vehicles[car->position + 1] = car;
					car->actualNode->Vehicles[car->position] = NULL;
					car->position = car->position + 1;
				}
			}
		} else if(car->rute.size > 0 && car->position < 4){
			if(car->actualNode->Vehicles[car->position + 1] == NULL){
				car->actualNode->Vehicles[car->position + 1] = car;
				car->actualNode->Vehicles[car->position] = NULL;
				car->position = car->position + 1;
			}
		} else if(car->rute.size > 0 && car->position >= 4){
			int cmp = 0;
			if(car->actualNode->nextStraight == NULL){
				char* nameNextNodeRight = car->actualNode->nextRight->name;
				char* nameNextNode = car->nextNode;
				cmp = strcmp(nameNextNode, nameNextNodeRight); //0 is =
				if(cmp==0)
					cmp = 1;
			} else if(car->actualNode->nextRight == NULL){
				char* nameNextNodeStraight = car->actualNode->nextStraight->name;
				char* nameNextNode = car->nextNode;
				cmp = strcmp(nameNextNode, nameNextNodeStraight); //0 is =
			} else {
				char* nameNextNodeStraight = car->actualNode->nextStraight->name;
				char* nameNextNodeRight = car->actualNode->nextRight->name;
				char* nameNextNode = car->nextNode;
				cmp = strcmp(nameNextNode, nameNextNodeStraight); //0 is =
			}

			switch(cmp){
				case 0: //nameNextNodeStraight
					if(car->actualNode->nextStraight->Vehicles[0] == NULL){
						car->actualNode->nextStraight->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNode = car->actualNode->nextStraight;
					}
					break;
				default: //nameNextNodeRight
					if(car->actualNode->nextRight->Vehicles[0] == NULL){
						car->actualNode->nextRight->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNode = car->actualNode->nextRight;
					}
					break;
			}

			//Update the rute information
			car->nextNode = car->rute.move;
			if(car->rute.size - 1 == 0){
				car->rute.size = 0;
				car->rute.move = NULL;
			} else {
				car->rute.move = car->rute.next->move;
				car->rute.next = car->rute.next->next;
				car->rute.size = car->rute.size - 1;
			}
		}
	 }
}