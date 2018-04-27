
#ifndef _CITY_H
#define _CITY_H
#include <stdio.h>
#include <stdlib.h>
#include <vehicle.h>
#include <queues.h>

//***NODES*****************************************************************************************
//Struct defining each road node in the map
typedef struct NODE {
	int id;
	char *name;
	struct vehicle *Vehicles[5];
	struct NODE *nextStraight; // Next node straight direction
	struct NODE *nextRight; // Next node to the right

	struct ROUNDABOUT *nextRoundabout; // Next bridge straight direction
	struct BRIDGE *nextBridge; // Next bridge straight direction
	int pathWeight;
}NODE;

//Create nodes with the id, name and pathWeight
NODE* createNode(int id, char *name, int pathWeight);
//*************************************************************************************************

//***HIGHWAY***************************************************************************************
//Struct defining each highway node in the map
typedef struct HIGHWAY {
	int id;
	char *name;
	struct vehicle *Vehicles[20];
	struct ROUNDABOUT *nextRight; // Next node
	int pathWeight;
}HIGHWAY;

//Create highway with the id, name and pathWeight
HIGHWAY* createHighway(int id, char *name, int pathWeight);
//*************************************************************************************************

//***ROUNDABOUT************************************************************************************
//Struct defining each roundabout node
typedef struct ROUNDABOUT {
	char *name;
	int id;
	struct vehicle *Vehicles[15]; 
	struct NODE *nextStraight; // Next node straight direction, going to D1
	struct HIGHWAY *nextRight1; // Next node to the right, going to highway
	struct HIGHWAY *nextRight2; // Next node to the right, going to highway
	//struct NODE *nextLeft1; // Next node to the left, going to Y
	//struct NODE *nextLeft2; // Next node to the left, reentering into de roundabout
	int pathWeight;
}ROUNDABOUT;

//Create Roundabout nodes with the id, name and pathWeight
ROUNDABOUT* createRoundabout(int id, char *name, int pathWeight);
//*************************************************************************************************

//***BRIDGES***************************************************************************************
//Struct defining bridges
typedef struct BRIDGE {
	char *name;
	int id;
	struct vehicle *Vehicles[5];
	struct pqueu westQueue;
	struct pqueu eastQueue;
	struct NODE *nextEast; // Next node straight direction East
	struct NODE *nextWest; // Next node straight direction West
	int pathWeight;
	int type;
	int flagEast;
	int flagWest;
	int timeOut;
	int K; //Amount of cars waiting
	int empty;
}BRIDGE;

void manageBridge(BRIDGE* bridge);
BRIDGE* createBridge(int id, char *name, int pathWeight, int type, int timeOut, int k);

//*************************************************************************************************

NODE* init();


#endif