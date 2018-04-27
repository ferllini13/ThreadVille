#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vehicle.h"
#include "../include/city.h"
#include "../include/serialBridge.h"

vehicle* create(int priority, int size, int position, int speed, int trips, struct NODE * actualNode, struct BRIDGE * actualNodeB, struct ROUNDABOUT * actualNodeR, struct HIGHWAY * actualNodeH, struct list rute, char * color, char * model, char * nextNode){
	vehicle *car=(vehicle*)calloc(1, sizeof(vehicle));
	car->priority = priority;
	car->size = size;
	car->position = position;
	car->speed = speed;
	car->trips = trips;
	car->actualNode = actualNode;
	car->actualNodeB = actualNodeB;
	car->actualNodeR = actualNodeR;
	car->actualNodeH = actualNodeH;
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
	

	char * data = (char*)calloc(64,sizeof(char));
	initmat(data);
	printf("%s\n", data);
	writeSerial(data, "/dev/ttyACM0");



	int run = 1; //0 means end
	char * lastNodeName = car->actualNode->name;
	while(run){
		printf("car->position: %d\n", car->position);
		if (car->actualNode != NULL)
			printf("car->actualNode->name: %s\n", car->actualNode->name);
		else if (car->actualNodeB != NULL)
			printf("car->actualNodeB->name: %s\n", car->actualNodeB->name);
		else if (car->actualNodeH != NULL)
			printf("car->actualNodeH->name: %s\n", car->actualNodeH->name);
		else if (car->actualNodeR != NULL)
			printf("car->actualNodeR->name: %s\n", car->actualNodeR->name);

		printf("car->nextNode: %s\n", car->nextNode);
		printf("car->rute.move: %s\n\n\n", car->rute.move);
		//printf("car->rute.size: %d\n\n\n", car->rute.size);

		// if( car->rute.size < 2)
			sleep((*car).speed/1000);
		
	// char* nameNextNodeStraight2 = car->actualNode->nextStraight->name;
	// char* nameNextNodeRight2 = car->actualNode->nextRight->name;
	// char* nameNextNode2 = car->nextNode;
	// printf("nameNextNodeStraight: %s\n", nameNextNodeStraight2);
	// printf("nameNextNodeRight: %s\n", nameNextNodeRight2);
	// printf("nameNextNode: %s\n", nameNextNode2);
	// int cmp2 = strcmp(nameNextNode2, nameNextNodeRight2);
	// printf("cmp2: %d\n", cmp2);




		if(car->rute.size == 0 && car->position < 4){ //Normal roads and bridges
			if(car->actualNode != NULL){ //Normal road
				//printf("***************************************************NORMAL 0\n");
				if(car->actualNode->Vehicles[car->position + 1] == NULL){
					car->actualNode->Vehicles[car->position + 1] = car;
					car->actualNode->Vehicles[car->position] = NULL;
					car->position = car->position + 1;
				}
			} else if(car->actualNodeB != NULL){ //Bridge

				printf("***************************************************BRIDGE\n");
					
				char *nextBridge1East = "nodeI14";
				char *nextBridge1West = "nodeD32";
				char *nextBridge2East = "nodeO14";
				char *nextBridge2West = "nodeJ32";
				char *nextBridge3East = "nodeU14";
				char *nextBridge3West = "nodeP32";

				int cmpB1E= 0;
				int cmpB1W = 0;
				int cmpB2E= 0;
				int cmpB2W = 0;
				int cmpB3E= 0;
				int cmpB3W = 0;

				cmpB1E = strcmp(lastNodeName, nextBridge1East); //0 is =
				cmpB1W = strcmp(lastNodeName, nextBridge1West); //0 is =
				cmpB2E = strcmp(lastNodeName, nextBridge2East); //0 is =
				cmpB2W = strcmp(lastNodeName, nextBridge2West); //0 is =
				cmpB3E = strcmp(lastNodeName, nextBridge3East); //0 is =
				cmpB3W = strcmp(lastNodeName, nextBridge3West); //0 is =


				if(cmpB1E == 0){

					if(car->actualNodeB->Vehicles[car->position + 1] == NULL){
						car->actualNodeB->Vehicles[car->position + 1] = car;
						car->actualNodeB->Vehicles[car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				} else if(cmpB1W == 0){
					if(car->actualNodeB->Vehicles[3 - car->position] == NULL){
						car->actualNodeB->Vehicles[3 - car->position] = car;
						car->actualNodeB->Vehicles[4 - car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
					
				} else if(cmpB2E == 0){

					if(car->actualNodeB->Vehicles[car->position + 1] == NULL){
						car->actualNodeB->Vehicles[car->position + 1] = car;
						car->actualNodeB->Vehicles[car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				} else if(cmpB2W == 0){
					if(car->actualNodeB->Vehicles[3 - car->position] == NULL){
						car->actualNodeB->Vehicles[3 - car->position] = car;
						car->actualNodeB->Vehicles[4 - car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
					
				} else if(cmpB3E == 0){

					if(car->actualNodeB->Vehicles[car->position + 1] == NULL){
						car->actualNodeB->Vehicles[car->position + 1] = car;
						car->actualNodeB->Vehicles[car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				} else if(cmpB3W == 0){
					if(car->actualNodeB->Vehicles[3 - car->position] == NULL){
						car->actualNodeB->Vehicles[3 - car->position] = car;
						car->actualNodeB->Vehicles[4 - car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
					
				}
				
			}
		// } else if(car->rute.size > 0 && car->position < 15 && car->actualNodeR != NULL){ //For roundabouts
		// 	printf("***************************************************ROUNDABOUT 0\n");
		// 	if(car->actualNodeR->Vehicles[car->position + 1] == NULL){
		// 		car->actualNodeR->Vehicles[car->position + 1] = car;
		// 		car->actualNodeR->Vehicles[car->position] = NULL;
		// 		car->position = car->position + 1;
		// 	}			
		// } else if(car->rute.size > 0 && car->position < 20 && car->actualNodeH != NULL){ //For Highways
		// 	printf("***************************************************HIGHWAY 0\n");
		// 	if(car->actualNodeH->Vehicles[car->position + 1] == NULL){
		// 		car->actualNodeH->Vehicles[car->position + 1] = car;
		// 		car->actualNodeH->Vehicles[car->position] = NULL;
		// 		car->position = car->position + 1;
		// 	}	
		} 

//**********************************************************************************************

		else if(car->rute.size == 0 && car->position >= 4 && car->actualNode != NULL){  //From normal roads to roads, bridges or roundabouts
			
			int cmp = 0;
			
			char* nameNextNode = car->nextNode;


			lastNodeName = car->actualNode->name;

			char *nextBridge1East = "nodeI14";
			char *nextBridge1West = "nodeD32";
			char *nextBridge2East = "nodeO14";
			char *nextBridge2West = "nodeJ32";
			char *nextBridge3East = "nodeU14";
			char *nextBridge3West = "nodeP32";

			int cmpB1E= 0;
			int cmpB1W = 0;
			int cmpB2E= 0;
			int cmpB2W = 0;
			int cmpB3E= 0;
			int cmpB3W = 0;

			char *nextRY = "roundaboutY";
			char *nextRZ = "roundaboutZ";

			int cmpRY = 0;
			int cmpRZ = 0;

			char *nextB1 = "bridge1";
			char *nextB2 = "bridge2";
			char *nextB3 = "bridge3";

			int cmpB1 = 0;
			int cmpB2 = 0;
			int cmpB3 = 0;

			// char *nextHSN1 = "highwaySN1";
			// char *nextHSN2 = "highwaySN2";
			// char *nextHNS1 = "highwayNS1";
			// char *nextHNS2 = "highwayNS2";

			// int cmpHSN1 = 0;
			// int cmpHSN2 = 0;
			// int cmpHNS1 = 0;
			// int cmpHNS2 = 0;

			cmpB1E = strcmp(lastNodeName, nextBridge1East); //0 is =
			cmpB1W = strcmp(lastNodeName, nextBridge1West); //0 is =
			cmpB2E = strcmp(lastNodeName, nextBridge2East); //0 is =
			cmpB2W = strcmp(lastNodeName, nextBridge2West); //0 is =
			cmpB3E = strcmp(lastNodeName, nextBridge3East); //0 is =
			cmpB3W = strcmp(lastNodeName, nextBridge3West); //0 is =

			cmpRY = strcmp(nameNextNode, nextRY); //0 is =
			cmpRZ = strcmp(nameNextNode, nextRZ); //0 is =

			cmpB1 = strcmp(nameNextNode, nextB1); //0 is =
			cmpB2 = strcmp(nameNextNode, nextB2); //0 is =
			cmpB3 = strcmp(nameNextNode, nextB3); //0 is =

			// cmpHSN1 = strcmp(nameNextNode, nextHSN1); //0 is =
			// cmpHSN2 = strcmp(nameNextNode, nextHSN2); //0 is =
			// cmpHNS1 = strcmp(nameNextNode, nextHNS1); //0 is =
			// cmpHNS2 = strcmp(nameNextNode, nextHNS2); //0 is =


			if(cmpRY == 0 || cmpRZ == 0){ //From road to roundabout

			} else if(cmpB1 == 0 || cmpB2 == 0 || cmpB3 == 0){ //From road to bridge

				if(cmpB1E == 0 && car->actualNode->nextBridge->flagEast == 1){

					if(car->actualNode->nextBridge->Vehicles[0] == NULL){
						car->actualNode->nextBridge->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB1W == 0 && car->actualNode->nextBridge->flagWest == 1){

					if(car->actualNode->nextBridge->Vehicles[4] == NULL){

						car->actualNode->nextBridge->Vehicles[4] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB2E == 0 && car->actualNode->nextBridge->flagEast == 1){

					if(car->actualNode->nextBridge->Vehicles[0] == NULL){
						car->actualNode->nextBridge->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB2W == 0 && car->actualNode->nextBridge->flagWest == 1){

					if(car->actualNode->nextBridge->Vehicles[4] == NULL){

						car->actualNode->nextBridge->Vehicles[4] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB3E == 0 && car->actualNode->nextBridge->flagEast == 1){

					if(car->actualNode->nextBridge->Vehicles[0] == NULL){

						car->actualNode->nextBridge->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB3W == 0 && car->actualNode->nextBridge->flagWest == 1){

					if(car->actualNode->nextBridge->Vehicles[4] == NULL){

						car->actualNode->nextBridge->Vehicles[4] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				printf("***************************************************BRIDGE\n");

				updateBridge(data,car->actualNodeB->id,car->actualNodeB);
				writeSerial(data, "/dev/ttyACM0");


			// } else if(cmpHSN1 == 0 || cmpHSN2 == 0 || cmpHNS1 == 0 || cmpHNS2 == 0){

			// 	if(car->actualNodeR->nextRight1->Vehicles[0] == NULL){
			// 		car->actualNodeR->nextRight1->Vehicles[0] = car;
			// 		car->actualNodeR->Vehicles[0] = NULL;
			// 		car->position = 0;
			// 		car->actualNodeR = NULL;
			// 		car->actualNodeH = car->actualNodeR->nextRight1;
			// 	}

			
			} else { //From road to road

				if(car->actualNode->nextStraight == NULL){
					char* nameNextNodeRight = car->actualNode->nextRight->name;
					cmp = strcmp(nameNextNode, nameNextNodeRight); //0 is =
					if(cmp==0)
						cmp = 1;
				} else if(car->actualNode->nextRight == NULL){
					char* nameNextNodeStraight = car->actualNode->nextStraight->name;
					cmp = strcmp(nameNextNode, nameNextNodeStraight); //0 is =
				} else {
					char* nameNextNodeStraight = car->actualNode->nextStraight->name;
					char* nameNextNodeRight = car->actualNode->nextRight->name;
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
				car->nextNode = NULL;
				if(car->rute.size - 1 == -1){
					car->rute.size = -1;
				}

			}
			// int cmp2 = 0;
			// if(car->actualNode->nextStraight == NULL){
			// 	char* nameNextNodeRight2 = car->actualNode->nextRight->name;
			// 	char* nameNextNode2 = car->nextNode;
			// 	cmp2 = strcmp(nameNextNode2, nameNextNodeRight2); //0 is =
			// 	if(cmp2 == 0)
			// 		cmp2 = 1;
			// } else if(car->actualNode->nextRight == NULL){
			// 	char* nameNextNodeStraight2 = car->actualNode->nextStraight->name;
			// 	char* nameNextNode2 = car->nextNode;
			// 	cmp2 = strcmp(nameNextNode2, nameNextNodeStraight2); //0 is =
			// } else {
			// 	char* nameNextNodeStraight2 = car->actualNode->nextStraight->name;
			// 	char* nameNextNodeRight2 = car->actualNode->nextRight->name;
			// 	char* nameNextNode2 = car->nextNode;
			// 	cmp2 = strcmp(nameNextNode2, nameNextNodeStraight2); //0 is =
			// }
			

			// // printf("nameNextNodeStraight2: %s\n", nameNextNodeStraight2);
			// // printf("nameNextNodeRight2: %s\n", nameNextNodeRight2);
			// // printf("nameNextNode2: %s\n\n\n", nameNextNode2);
			
			// switch(cmp2){
			// 	case 0: //nameNextNodeStraight
			// 		if(car->actualNode->nextStraight->Vehicles[0] == NULL){
			// 			car->actualNode->nextStraight->Vehicles[0] = car;
			// 			car->actualNode->Vehicles[4] = NULL;
			// 			car->position = 0;
			// 			car->actualNode = car->actualNode->nextStraight;
			// 		}
			// 		break;
			// 	default: //nameNextNodeRight
			// 		if(car->actualNode->nextRight->Vehicles[0] == NULL){
			// 			car->actualNode->nextRight->Vehicles[0] = car;
			// 			car->actualNode->Vehicles[4] = NULL;
			// 			car->position = 0;
			// 			car->actualNode = car->actualNode->nextRight;
			// 		}
			// 		break;
			// }

			// //Update the rute information
			// car->nextNode = NULL;
			// if(car->rute.size - 1 == -1){
			// 	car->rute.size = -1;
			// }

		} else if(car->rute.size == 0 && car->position >= 4 && car->actualNodeB != NULL){ //From bridges to roads
			int cmp = 0;
			char* nameNextNodeWest = car->actualNodeB->nextWest->name;
			char* nameNextNodeEast = car->actualNodeB->nextEast->name;
			char* nameNextNode = car->nextNode;
			cmp = strcmp(nameNextNode, nameNextNodeWest); //0 is =			

			switch(cmp){
				case 0: //nameNextNodeWest
					if(car->actualNodeB->nextWest->Vehicles[0] == NULL){
						car->actualNodeB->nextWest->Vehicles[0] = car;
						car->actualNodeB->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNode = car->actualNodeB->nextWest;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
						car->actualNodeB = NULL;
					}
					break;
				default: //nameNextNodeEast
					if(car->actualNodeB->nextEast->Vehicles[0] == NULL){
						car->actualNodeB->nextEast->Vehicles[0] = car;
						car->actualNodeB->Vehicles[0] = NULL;
						car->position = 0;
						car->actualNode = car->actualNodeB->nextEast;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
						car->actualNodeB = NULL;
					}
					break;
			}

			//Update the rute information
			car->nextNode = NULL;
			if(car->rute.size - 1 == -1){
				car->rute.size = -1;
			}
		}

//**********************************************************************************************

		 /* else if(car->rute.size == 0 && car->position >= 4){
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
			

			printf("nameNextNodeStraight2: %s\n", nameNextNodeStraight2);
			printf("nameNextNodeRight2: %s\n", nameNextNodeRight2);
			printf("nameNextNode2: %s\n\n\n", nameNextNode2);
			
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





		  //If is the last trip
		} 

		*/






		  //For last trip
		  else if(car->rute.size == -1 && car->rute.finalPosition == car->position){
			run = 0;
		} else if(car->rute.size == -1 && car->rute.finalPosition == 4 && car->position < 4){
			run = 0;
			for(int i = 0; i < 5; i++){
				sleep((*car).speed/1000);


				if(i > 0){ // if used to print the values
					printf("car->position: %d\n", car->position);
					printf("car->actualNode->name: %s\n", car->actualNode->name);
					printf("car->nextNode: %s\n", car->nextNode);
					printf("car->rute.move: %s\n\n\n", car->rute.move);
					// printf("car->rute.size: %d\n\n\n", car->rute.size);
					// printf("car->rute.finalPosition: %d\n\n\n", car->rute.finalPosition);
				}
				
				if(car->actualNode->Vehicles[car->position + 1] == NULL){
					car->actualNode->Vehicles[car->position + 1] = car;
					car->actualNode->Vehicles[car->position] = NULL;
					car->position = car->position + 1;
				}
			}
		}

		  





		  //If car change position inside the node, bridge, highway or roundabout
		  else if(car->rute.size > 0 && car->position < 4){ //For normal road and bridges
			if(car->actualNode != NULL){ //Normal road
				//printf("***************************************************NORMAL\n");
				if(car->actualNode->Vehicles[car->position + 1] == NULL){
					car->actualNode->Vehicles[car->position + 1] = car;
					car->actualNode->Vehicles[car->position] = NULL;
					car->position = car->position + 1;
				}
			} else if(car->actualNodeB != NULL){ //Bridge
				printf("***************************************************BRIDGE\n");

				char *nextBridge1East = "nodeI14";
				char *nextBridge1West = "nodeD32";
				char *nextBridge2East = "nodeO14";
				char *nextBridge2West = "nodeJ32";
				char *nextBridge3East = "nodeU14";
				char *nextBridge3West = "nodeP32";

				int cmpB1E= 0;
				int cmpB1W = 0;
				int cmpB2E= 0;
				int cmpB2W = 0;
				int cmpB3E= 0;
				int cmpB3W = 0;

				cmpB1E = strcmp(lastNodeName, nextBridge1East); //0 is =
				cmpB1W = strcmp(lastNodeName, nextBridge1West); //0 is =
				cmpB2E = strcmp(lastNodeName, nextBridge2East); //0 is =
				cmpB2W = strcmp(lastNodeName, nextBridge2West); //0 is =
				cmpB3E = strcmp(lastNodeName, nextBridge3East); //0 is =
				cmpB3W = strcmp(lastNodeName, nextBridge3West); //0 is =


				if(cmpB1E == 0){
					if(car->actualNodeB->Vehicles[car->position + 1] == NULL){
						car->actualNodeB->Vehicles[car->position + 1] = car;
						car->actualNodeB->Vehicles[car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				} else if(cmpB1W == 0){
					if(car->actualNodeB->Vehicles[3 - car->position] == NULL){
						car->actualNodeB->Vehicles[3 - car->position] = car;
						car->actualNodeB->Vehicles[4 - car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				} else if(cmpB2E == 0){
					if(car->actualNodeB->Vehicles[car->position + 1] == NULL){
						car->actualNodeB->Vehicles[car->position + 1] = car;
						car->actualNodeB->Vehicles[car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				} else if(cmpB2W == 0){
					if(car->actualNodeB->Vehicles[3 - car->position] == NULL){
						car->actualNodeB->Vehicles[3 - car->position] = car;
						car->actualNodeB->Vehicles[4 - car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				} else if(cmpB3E == 0){
					if(car->actualNodeB->Vehicles[car->position + 1] == NULL){
						car->actualNodeB->Vehicles[car->position + 1] = car;
						car->actualNodeB->Vehicles[car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				} else if(cmpB3W == 0){
					if(car->actualNodeB->Vehicles[3 - car->position] == NULL){
						car->actualNodeB->Vehicles[3 - car->position] = car;
						car->actualNodeB->Vehicles[4 - car->position] = NULL;
						car->position = car->position + 1;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
					}
				}
			}
		} else if(car->rute.size > 0 && car->position < 15 && car->actualNodeR != NULL){ //For roundabouts
			//printf("***************************************************ROUNDABOUT\n");
			if(car->actualNodeR->Vehicles[car->position + 1] == NULL){
				car->actualNodeR->Vehicles[car->position + 1] = car;
				car->actualNodeR->Vehicles[car->position] = NULL;
				car->position = car->position + 1;
			}			
		} else if(car->rute.size > 0 && car->position < 20 && car->actualNodeH != NULL){ //For Highways
			//printf("***************************************************HIGHWAY\n");
			if(car->actualNodeH->Vehicles[car->position + 1] == NULL){
				car->actualNodeH->Vehicles[car->position + 1] = car;
				car->actualNodeH->Vehicles[car->position] = NULL;
				car->position = car->position + 1;
			}			



		} else if(car->rute.size > 0 && car->position >= 4 && car->actualNode != NULL){  //From normal roads to roads, bridges or roundabouts
			int cmp = 0;
			
			char* nameNextNode = car->nextNode;


			lastNodeName = car->actualNode->name;

			char *nextBridge1East = "nodeI14";
			char *nextBridge1West = "nodeD32";
			char *nextBridge2East = "nodeO14";
			char *nextBridge2West = "nodeJ32";
			char *nextBridge3East = "nodeU14";
			char *nextBridge3West = "nodeP32";

			int cmpB1E= 0;
			int cmpB1W = 0;
			int cmpB2E= 0;
			int cmpB2W = 0;
			int cmpB3E= 0;
			int cmpB3W = 0;

			char *nextRY = "roundaboutY";
			char *nextRZ = "roundaboutZ";

			int cmpRY = 0;
			int cmpRZ = 0;

			char *nextB1 = "bridge1";
			char *nextB2 = "bridge2";
			char *nextB3 = "bridge3";

			int cmpB1 = 0;
			int cmpB2 = 0;
			int cmpB3 = 0;

			// char *nextHSN1 = "highwaySN1";
			// char *nextHSN2 = "highwaySN2";
			// char *nextHNS1 = "highwayNS1";
			// char *nextHNS2 = "highwayNS2";

			// int cmpHSN1 = 0;
			// int cmpHSN2 = 0;
			// int cmpHNS1 = 0;
			// int cmpHNS2 = 0;

			cmpB1E = strcmp(lastNodeName, nextBridge1East); //0 is =
			cmpB1W = strcmp(lastNodeName, nextBridge1West); //0 is =
			cmpB2E = strcmp(lastNodeName, nextBridge2East); //0 is =
			cmpB2W = strcmp(lastNodeName, nextBridge2West); //0 is =
			cmpB3E = strcmp(lastNodeName, nextBridge3East); //0 is =
			cmpB3W = strcmp(lastNodeName, nextBridge3West); //0 is =

			cmpRY = strcmp(nameNextNode, nextRY); //0 is =
			cmpRZ = strcmp(nameNextNode, nextRZ); //0 is =

			cmpB1 = strcmp(nameNextNode, nextB1); //0 is =
			cmpB2 = strcmp(nameNextNode, nextB2); //0 is =
			cmpB3 = strcmp(nameNextNode, nextB3); //0 is =

			// cmpHSN1 = strcmp(nameNextNode, nextHSN1); //0 is =
			// cmpHSN2 = strcmp(nameNextNode, nextHSN2); //0 is =
			// cmpHNS1 = strcmp(nameNextNode, nextHNS1); //0 is =
			// cmpHNS2 = strcmp(nameNextNode, nextHNS2); //0 is =


			if(cmpRY == 0 || cmpRZ == 0){ //From road to roundabout

			} else if(cmpB1 == 0 || cmpB2 == 0 || cmpB3 == 0){ //From road to bridge

				if(cmpB1E == 0 && car->actualNode->nextBridge->flagEast == 1){

					if(car->actualNode->nextBridge->Vehicles[0] == NULL){
						car->actualNode->nextBridge->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB1W == 0 && car->actualNode->nextBridge->flagWest == 1){

					if(car->actualNode->nextBridge->Vehicles[4] == NULL){

						car->actualNode->nextBridge->Vehicles[4] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB2E == 0 && car->actualNode->nextBridge->flagEast == 1){

					if(car->actualNode->nextBridge->Vehicles[0] == NULL){
						car->actualNode->nextBridge->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB2W == 0 && car->actualNode->nextBridge->flagWest == 1){

					if(car->actualNode->nextBridge->Vehicles[4] == NULL){

						car->actualNode->nextBridge->Vehicles[4] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB3E == 0 && car->actualNode->nextBridge->flagEast == 1){

					if(car->actualNode->nextBridge->Vehicles[0] == NULL){

						car->actualNode->nextBridge->Vehicles[0] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				} else if(cmpB3W == 0 && car->actualNode->nextBridge->flagWest == 1){

					if(car->actualNode->nextBridge->Vehicles[4] == NULL){

						car->actualNode->nextBridge->Vehicles[4] = car;
						car->actualNode->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNodeB = car->actualNode->nextBridge;
						car->actualNode = NULL;
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

				printf("***************************************************BRIDGE\n");

				updateBridge(data,car->actualNodeB->id,car->actualNodeB);
				writeSerial(data, "/dev/ttyACM0");

			// } else if(cmpHSN1 == 0 || cmpHSN2 == 0 || cmpHNS1 == 0 || cmpHNS2 == 0){

			// 	if(car->actualNodeR->nextRight1->Vehicles[0] == NULL){
			// 		car->actualNodeR->nextRight1->Vehicles[0] = car;
			// 		car->actualNodeR->Vehicles[0] = NULL;
			// 		car->position = 0;
			// 		car->actualNodeR = NULL;
			// 		car->actualNodeH = car->actualNodeR->nextRight1;
			// 	}

			
			} else { //From road to road

				if(car->actualNode->nextStraight == NULL){
					char* nameNextNodeRight = car->actualNode->nextRight->name;
					cmp = strcmp(nameNextNode, nameNextNodeRight); //0 is =
					if(cmp==0)
						cmp = 1;
				} else if(car->actualNode->nextRight == NULL){
					char* nameNextNodeStraight = car->actualNode->nextStraight->name;
					cmp = strcmp(nameNextNode, nameNextNodeStraight); //0 is =
				} else {
					char* nameNextNodeStraight = car->actualNode->nextStraight->name;
					char* nameNextNodeRight = car->actualNode->nextRight->name;
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

		} else if(car->rute.size > 0 && car->position >= 4 && car->actualNodeB != NULL){ //From bridges to roads
			int cmp = 0;
			char* nameNextNodeWest = car->actualNodeB->nextWest->name;
			char* nameNextNodeEast = car->actualNodeB->nextEast->name;
			char* nameNextNode = car->nextNode;
			cmp = strcmp(nameNextNode, nameNextNodeWest); //0 is =			

			switch(cmp){
				case 0: //nameNextNodeWest
					if(car->actualNodeB->nextWest->Vehicles[0] == NULL){
						car->actualNodeB->nextWest->Vehicles[0] = car;
						car->actualNodeB->Vehicles[4] = NULL;
						car->position = 0;
						car->actualNode = car->actualNodeB->nextWest;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
						car->actualNodeB = NULL;
					}
					break;
				default: //nameNextNodeEast
					if(car->actualNodeB->nextEast->Vehicles[0] == NULL){
						car->actualNodeB->nextEast->Vehicles[0] = car;
						car->actualNodeB->Vehicles[0] = NULL;
						car->position = 0;
						car->actualNode = car->actualNodeB->nextEast;
						updateBridge(data,car->actualNodeB->id,car->actualNodeB);
						writeSerial(data, "/dev/ttyACM0");
						car->actualNodeB = NULL;
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


/*

char *nextBridge1East = "nodeI14";
			char *nextBridge1West = "nodeD32";
			char *nextBridge2East = "nodeO14";
			char *nextBridge2West = "nodeJ32";
			char *nextBridge3East = "nodeU14";
			char *nextBridge3West = "nodeP32";

			int cmpB1E= 0;
			int cmpB1W = 0;
			int cmpB2E= 0;
			int cmpB2W = 0;
			int cmpB3E= 0;
			int cmpB3W = 0;

			cmpB1E = strcmp(lastNodeName, nextBridge1East); //0 is =
			cmpB1W = strcmp(lastNodeName, nextBridge1West); //0 is =
			cmpB2E = strcmp(lastNodeName, nextBridge2East); //0 is =
			cmpB2W = strcmp(lastNodeName, nextBridge2West); //0 is =
			cmpB3E = strcmp(lastNodeName, nextBridge3East); //0 is =
			cmpB3W = strcmp(lastNodeName, nextBridge3West); //0 is =

			*/