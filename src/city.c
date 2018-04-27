#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <../include/city.h>

int regularPathWeight = 5;
int highwayWeight = 1;

//***NODE******************************************************************************************
NODE* createNode(int id, char *name, int pathWeight){
	NODE *node = (NODE *)calloc(1, sizeof(NODE));
	node->id = id;
	node->name = strdup(name);
	node->pathWeight = pathWeight;
	node->nextStraight = NULL;
	node->nextRight = NULL;
	node->nextRoundabout = NULL;
	node->nextBridge = NULL;

	for(int i = 0; i < 5; i++){
		node->Vehicles[i] = NULL;
	}
	return node;
}
//*************************************************************************************************

//***HIGHWAY***************************************************************************************
//Create highway with the id, name and pathWeight
HIGHWAY* createHighway(int id, char *name, int pathWeight){
	HIGHWAY *highway = (HIGHWAY *)calloc(1, sizeof(HIGHWAY));
	highway->id = id;
	highway->name = strdup(name);
	highway->pathWeight = pathWeight;
	highway->nextRight = NULL;

	for(int i = 0; i < 5; i++){
		highway->Vehicles[i] = NULL;
	}
	return highway;
}
//*************************************************************************************************

//***ROUNDABOUT************************************************************************************
//Create Roundabout nodes with the id, name and pathWeight
ROUNDABOUT* createRoundabout(int id, char *name, int pathWeight){
	ROUNDABOUT *roundabout = (ROUNDABOUT *)calloc(1, sizeof(ROUNDABOUT));
	roundabout->id = id;
	roundabout->name = strdup(name);
	roundabout->pathWeight = pathWeight;
	roundabout->nextStraight = NULL;
	roundabout->nextRight1 = NULL;
	roundabout->nextRight2 = NULL;

	for(int i = 0; i < 5; i++){
		roundabout->Vehicles[i] = NULL;
	}
	return roundabout;
}
//*************************************************************************************************

//***BRIDGE****************************************************************************************
BRIDGE* createBridge(int id, char *name, int pathWeight, int type, int timeOut, int K){
	BRIDGE *bridge = (BRIDGE *)calloc(1, sizeof(BRIDGE));
	bridge->id = id;
	bridge->name = strdup(name);
	bridge->type=type;
	bridge->timeOut=timeOut;
	bridge->K=K;
	bridge->empty=1;
	bridge->flagEast=0;
	bridge->flagWest=0;
	bridge->nextEast = NULL;
	bridge->nextWest = NULL;

	for (int i = 0; i < 5; i++){
		bridge->Vehicles[i] = NULL;
	}
	return bridge;
}

void manageBridge(BRIDGE* bridge){
	if ((*bridge).type==1){ //Transit officer
		while (1){
			if((*bridge).eastQueue.size == 7 && (*bridge).empty){
				bridge->flagEast=1;	
			}
			else if((*bridge).westQueue.size == 7 && (*bridge).empty){
				bridge->flagEast=0;	
			}
		}

	}
	else if ((*bridge).type==2){ //Timeout
		while (1){
			int temp;
			sleep((*bridge).timeOut);
			temp=bridge->flagEast;
			bridge->flagEast=bridge->flagWest;
			bridge->flagWest=temp;
		}
	}
	else {	//Jungle law
		bridge->flagEast=1;
		bridge->flagWest=1;
	}
}

//*************************************************************************************************

//***Defining streets*********************************
//Nodes from A
NODE *nodeA14;
NODE *nodeA21;
NODE *nodeA32;

//Node from AB
NODE *nodeA43B12;

//Nodes from B
NODE *nodeB14;
NODE *nodeB32;

//Node from BC
NODE *nodeB34C21;

//Nodes from C
NODE *nodeC14;
NODE *nodeC32;

//Nodes from D
NODE *nodeD14;
NODE *nodeD32;

//Node from DE
NODE *nodeD43E12;

//Nodes from E
NODE *nodeE14;
NODE *nodeE32;

//Node from EF
NODE *nodeE34F21;

//Nodes from F
NODE *nodeF14;
NODE *nodeF43;
NODE *nodeF32;

//Nodes from G
NODE *nodeG14;
NODE *nodeG21;
NODE *nodeG32;

//Node from GH
NODE *nodeG43H12;

//Nodes from H
NODE *nodeH14;
NODE *nodeH32;

//Node from HI
NODE *nodeH34I21;

//Nodes from I
NODE *nodeI14;
NODE *nodeI32;

//Nodes from J
NODE *nodeJ14;
NODE *nodeJ32;

//Node from JK
NODE *nodeJ43K12;

//Nodes from K
NODE *nodeK14;
NODE *nodeK32;

//Node from KL
NODE *nodeK34L21;

//Nodes from L
NODE *nodeL14;
NODE *nodeL43;
NODE *nodeL32;

//Nodes from M
NODE *nodeM14;
NODE *nodeM21;
NODE *nodeM32;

//Node from MN
NODE *nodeM43N12;

//Nodes from N
NODE *nodeN14;
NODE *nodeN32;

//Node from NO
NODE *nodeN34O21;

//Nodes from O
NODE *nodeO14;
NODE *nodeO32;

//Nodes from P
NODE *nodeP14;
NODE *nodeP32;

//Node from PQ
NODE *nodeP43Q12;

//Nodes from Q
NODE *nodeQ14;
NODE *nodeQ32;

//Node from QR
NODE *nodeQ34R21;

//Nodes from R
NODE *nodeR14;
NODE *nodeR43;
NODE *nodeR32;

//Nodes from S
NODE *nodeS14;
NODE *nodeS21;
NODE *nodeS32;

//Node from ST
NODE *nodeS43T12;

//Nodes from T
NODE *nodeT14;
NODE *nodeT32;

//Node from TU
NODE *nodeT34U21;

//Nodes from U
NODE *nodeU14;
NODE *nodeU32;

//Nodes from V
NODE *nodeV14;
NODE *nodeV32;

//Node from VW
NODE *nodeV43W12;

//Nodes from W
NODE *nodeW14;
NODE *nodeW32;

//Node from WX
NODE *nodeW34X21;

//Nodes from X
NODE *nodeX14;
NODE *nodeX43;
NODE *nodeX32;

//***Roundabouts******************************************
//Y Roundabout
ROUNDABOUT *roundaboutY;

//Z Roundabout
ROUNDABOUT *roundaboutZ;

//***HIGHWAYS**********************************************
//Highway SN1
HIGHWAY * highwaySN1;

//Highway SN2
HIGHWAY * highwaySN2;

//Highway NS1
HIGHWAY * highwayNS1;

//Highway NS2
HIGHWAY * highwayNS2;

//***Bridges**********************************************
//Bridge 1
BRIDGE *bridge1;

//Bridge 2
BRIDGE *bridge2;

//Bridge 3
BRIDGE *bridge3;


NODE* init(){

	//***Defining streets*********************************
	//Nodes from A
	nodeA14 = createNode(1, "nodeA14", regularPathWeight);
	nodeA21 = createNode(2, "nodeA21", regularPathWeight);
	nodeA32 = createNode(3, "nodeA32", regularPathWeight);

	// int ID = nodeA14->id;
	// printf("nodeA14 %d\n\n", ID);

	//Node from AB
	nodeA43B12 = createNode(4, "nodeA43B12", regularPathWeight);

	//Nodes from B
	nodeB14 = createNode (5, "nodeB14", regularPathWeight);
	nodeB32 = createNode (6, "nodeB32", regularPathWeight);

	//Node from BC
	nodeB34C21 = createNode (7, "nodeB34C21", regularPathWeight);

	//Nodes from C
	nodeC14 = createNode (8, "nodeC14", regularPathWeight);
	nodeC32 = createNode (9, "nodeC32", regularPathWeight);

	//Nodes from D
	nodeD14 = createNode (10, "nodeD14", regularPathWeight);
	nodeD32 = createNode (11, "nodeD32", regularPathWeight);

	//Node from DE
	nodeD43E12 = createNode (12, "nodeD43E12", regularPathWeight);

	//Nodes from E
	nodeE14 = createNode (13, "nodeE14", regularPathWeight);
	nodeE32 = createNode (14, "nodeE32", regularPathWeight);

	//Node from EF
	nodeE34F21 = createNode (15, "nodeE34F21", regularPathWeight);

	//Nodes from F
	nodeF14 = createNode (16, "nodeF14", regularPathWeight);
	nodeF43 = createNode (17, "nodeF43", regularPathWeight);
	nodeF32 = createNode (18, "nodeF32", regularPathWeight);

	//Nodes from G
	nodeG14 = createNode (19, "nodeG14", regularPathWeight);
	nodeG21 = createNode (20, "nodeG21", regularPathWeight);
	nodeG32 = createNode (21, "nodeG32", regularPathWeight);

	//Node from GH
	nodeG43H12 = createNode (22, "nodeG43H12", regularPathWeight);

	//Nodes from H
	nodeH14 = createNode (23, "nodeH14", regularPathWeight);
	nodeH32 = createNode (24, "nodeH32", regularPathWeight);

	//Node from HI
	nodeH34I21 = createNode (25, "nodeH34I21", regularPathWeight);

	//Nodes from I
	nodeI14 = createNode (26, "nodeI14", regularPathWeight);
	nodeI32 = createNode (27, "nodeI32", regularPathWeight);

	//Nodes from J
	nodeJ14 = createNode (28, "nodeJ14", regularPathWeight);
	nodeJ32 = createNode (29, "nodeJ32", regularPathWeight);

	//Node from JK
	nodeJ43K12 = createNode (30, "nodeJ43K12", regularPathWeight);

	//Nodes from K
	nodeK14 = createNode (31, "nodeK14", regularPathWeight);
	nodeK32 = createNode (32, "nodeK32", regularPathWeight);

	//Node from KL
	nodeK34L21 = createNode (33, "nodeK34L21", regularPathWeight);

	//Nodes from L
	nodeL14 = createNode (34, "nodeL14", regularPathWeight);
	nodeL43 = createNode (35, "nodeL43", regularPathWeight);
	nodeL32 = createNode (36, "nodeL32", regularPathWeight);

	//Nodes from M
	nodeM14 = createNode (37, "nodeM14", regularPathWeight);
	nodeM21 = createNode (38, "nodeM21", regularPathWeight);
	nodeM32 = createNode (39, "nodeM32", regularPathWeight);

	//Node from MN
	nodeM43N12 = createNode (40, "nodeM43N12", regularPathWeight);

	//Nodes from N
	nodeN14 = createNode (41, "nodeN14", regularPathWeight);
	nodeN32 = createNode (42, "nodeN32", regularPathWeight);

	//Node from NO
	nodeN34O21 = createNode (43, "nodeN34O21", regularPathWeight);

	//Nodes from O
	nodeO14 = createNode (44, "nodeO14", regularPathWeight);
	nodeO32 = createNode (45, "nodeO32", regularPathWeight);

	//Nodes from P
	nodeP14 = createNode (46, "nodeP14", regularPathWeight);
	nodeP32 = createNode (47, "nodeP32", regularPathWeight);

	//Node from PQ
	nodeP43Q12 = createNode (48, "nodeP43Q12", regularPathWeight);

	//Nodes from Q
	nodeQ14 = createNode (49, "nodeQ14", regularPathWeight);
	nodeQ32 = createNode (50, "nodeQ32", regularPathWeight);

	//Node from QR
	nodeQ34R21 = createNode (51, "nodeQ34R21", regularPathWeight);

	//Nodes from R
	nodeR14 = createNode (52, "nodeR14", regularPathWeight);
	nodeR43 = createNode (53, "nodeR43", regularPathWeight);
	nodeR32 = createNode (54, "nodeR32", regularPathWeight);

	//Nodes from S
	nodeS14 = createNode (55, "nodeS14", regularPathWeight);
	nodeS21 = createNode (56, "nodeS21", regularPathWeight);
	nodeS32 = createNode (57, "nodeS32", regularPathWeight);

	//Node from ST
	nodeS43T12 = createNode (58, "nodeS43T12", regularPathWeight);

	//Nodes from T
	nodeT14 = createNode (59, "nodeT14", regularPathWeight);
	nodeT32 = createNode (60, "nodeT32", regularPathWeight);

	//Node from TU
	nodeT34U21 = createNode (61, "nodeT34U21", regularPathWeight);

	//Nodes from U
	nodeU14 = createNode (62, "nodeU14", regularPathWeight);
	nodeU32 = createNode (63, "nodeU32", regularPathWeight);

	//Nodes from V
	nodeV14 = createNode (64, "nodeV14", regularPathWeight);
	nodeV32 = createNode (65, "nodeV32", regularPathWeight);

	//Node from VW
	nodeV43W12 = createNode (66, "nodeV43W12", regularPathWeight);

	//Nodes from W
	nodeW14 = createNode (67, "nodeW14", regularPathWeight);
	nodeW32 = createNode (68, "nodeW32", regularPathWeight);

	//Node from WX
	nodeW34X21 = createNode (69, "nodeW34X21", regularPathWeight);

	//Nodes from X
	nodeX14 = createNode (70, "nodeX14", regularPathWeight);
	nodeX43 = createNode (71, "nodeX43", regularPathWeight);
	nodeX32 = createNode (72, "nodeX32", regularPathWeight);

	//***Roundabouts******************************************
	//Y Roundabout
	roundaboutY = createRoundabout(73, "roundaboutY", regularPathWeight);

	//Z Roundabout
	roundaboutZ = createRoundabout(74, "roundaboutZ", regularPathWeight);

	//***HIGHWAYS**********************************************
	//Highway SN1
	highwaySN1 = createHighway(75, "highwaySN1", highwayWeight);

	//Highway SN2
	highwaySN2 = createHighway(76, "highwaySN2", highwayWeight);

	//Highway NS1
	highwayNS1 = createHighway(77, "highwayNS1", highwayWeight);

	//Highway NS2
	highwayNS2 = createHighway(78, "highwayNS2", highwayWeight);

	//***Bridges**********************************************
	//Bridge 1
	bridge1  = createBridge(79, "bridge1", highwayWeight, 1, 3, 4);

	//Bridge 2
	bridge2 = createBridge(80, "bridge2", highwayWeight, 1, 3, 4);

	//Bridge 3
	bridge3 = createBridge(81, "bridge3", highwayWeight, 1, 3, 4);

	//Connecting nodes
	//threadville->nodes = nodeY1;

	//***Connecting roads nodes********************************
	//Nodes from A
	nodeA14->nextStraight = nodeB14;
	nodeA14->nextRight = nodeA43B12;
	nodeA21->nextStraight = NULL;
	nodeA21->nextRight = nodeA14;
	nodeA32->nextStraight = NULL;
	nodeA32->nextRight = nodeA21;

	//Node from AB
	nodeA43B12->nextStraight = nodeG43H12;
	nodeA43B12->nextRight = nodeA32;

	//Nodes from B
	nodeB14->nextStraight = nodeC14;
	nodeB14->nextRight = NULL;
	nodeB32->nextStraight = nodeA32;
	nodeB32->nextRight = NULL;

	//Node from BC
	nodeB34C21->nextStraight = NULL;
	nodeB34C21->nextRight = nodeC14;

	//Nodes from C
	nodeC14->nextRoundabout = roundaboutY;
	nodeC14->nextRight = NULL;
	nodeC32->nextStraight = nodeB32;
	nodeC32->nextRight = nodeB34C21;

	//Nodes from D
	nodeD14->nextStraight = nodeE14;
	nodeD14->nextRight = nodeD43E12;
	nodeD32->nextBridge = bridge1;
	nodeD32->nextRight = NULL;

	//Node from DE
	nodeD43E12->nextStraight = nodeJ43K12;
	nodeD43E12->nextRight = nodeD32;

	//Nodes from E
	nodeE14->nextStraight = nodeF14;
	nodeE14->nextRight = NULL;
	nodeE32->nextStraight = nodeD32;
	nodeE32->nextRight = NULL;

	//Node from EF
	nodeE34F21->nextStraight = NULL;
	nodeE34F21->nextRight = nodeF14;

	//Nodes from F
	nodeF14->nextStraight = NULL;
	nodeF14->nextRight = nodeF43;
	nodeF43->nextStraight = nodeL43;
	nodeF43->nextRight = nodeF32;
	nodeF32->nextStraight = nodeE32;
	nodeF32->nextRight = nodeE34F21;

	//Nodes from G
	nodeG14->nextStraight = nodeH14;
	nodeG14->nextRight = nodeG43H12;
	nodeG21->nextStraight = nodeA21;
	nodeG21->nextRight = nodeG14;
	nodeG32->nextStraight = NULL;
	nodeG32->nextRight = nodeG21;

	//Node from GH
	nodeG43H12->nextStraight = nodeM43N12;
	nodeG43H12->nextRight = nodeG32;

	//Nodes from H
	nodeH14->nextStraight = nodeI14;
	nodeH14->nextRight = NULL;
	nodeH32->nextStraight = nodeG32;
	nodeH32->nextRight = NULL;

	//Node from HI
	nodeH34I21->nextStraight = nodeB34C21;
	nodeH34I21->nextRight = nodeI14;

	//Nodes from I
	nodeI14->nextBridge = bridge1;
	nodeI14->nextRight = NULL;
	nodeI32->nextStraight = nodeH32;
	nodeI32->nextRight = nodeH34I21;

	//Nodes from J
	nodeJ14->nextStraight = nodeK14;
	nodeJ14->nextRight = nodeJ43K12;
	nodeJ32->nextBridge = bridge2;
	nodeJ32->nextRight = NULL;

	//Node from JK
	nodeJ43K12->nextStraight = nodeP43Q12;
	nodeJ43K12->nextRight = nodeJ32;

	//Nodes from K
	nodeK14->nextStraight = nodeL14;
	nodeK14->nextRight = NULL;
	nodeK32->nextStraight = nodeJ32;
	nodeK32->nextRight = NULL;

	//Node from KL
	nodeK34L21->nextStraight = nodeE34F21;
	nodeK34L21->nextRight = nodeL14;

	//Nodes from L
	nodeL14->nextStraight = NULL;
	nodeL14->nextRight = nodeL43;
	nodeL43->nextStraight = nodeR43;
	nodeL43->nextRight = nodeL32;
	nodeL32->nextStraight = nodeK32;
	nodeL32->nextRight = nodeK34L21;

	//Nodes from M
	nodeM14->nextStraight = nodeN14;
	nodeM14->nextRight = nodeM43N12;
	nodeM21->nextStraight = nodeG21;
	nodeM21->nextRight = nodeM14;
	nodeM32->nextStraight = NULL;
	nodeM32->nextRight = nodeM21;

	//Node from MN
	nodeM43N12->nextStraight = nodeS43T12;
	nodeM43N12->nextRight = nodeM32;

	//Nodes from N
	nodeN14->nextStraight = nodeO14;
	nodeN14->nextRight = NULL;
	nodeN32->nextStraight = nodeM32;
	nodeN32->nextRight = NULL;

	//Node from NO
	nodeN34O21->nextStraight = nodeH34I21;
	nodeN34O21->nextRight = nodeO14;

	//Nodes from O
	nodeO14->nextBridge = bridge2;
	nodeO14->nextRight = NULL;
	nodeO32->nextStraight = nodeN32;
	nodeO32->nextRight = nodeN34O21;

	//Nodes from P
	nodeP14->nextStraight = nodeQ14;
	nodeP14->nextRight = nodeP43Q12;
	nodeP32->nextBridge = bridge3;
	nodeP32->nextRight = NULL;

	//Node from PQ
	nodeP43Q12->nextStraight = nodeV43W12;
	nodeP43Q12->nextRight = nodeP32;

	//Nodes from Q
	nodeQ14->nextStraight = nodeR14;
	nodeQ14->nextRight = NULL;
	nodeQ32->nextStraight = nodeP32;
	nodeQ32->nextRight = NULL;

	//Node from QR
	nodeQ34R21->nextStraight = nodeK34L21;
	nodeQ34R21->nextRight = nodeR14;

	//Nodes from R
	nodeR14->nextStraight = NULL;
	nodeR14->nextRight = nodeR43;
	nodeR43->nextStraight = nodeX43;
	nodeR43->nextRight = nodeR32;
	nodeR32->nextStraight = nodeQ32;
	nodeR32->nextRight = nodeQ34R21;

	//Nodes from S
	nodeS14->nextStraight = nodeT14;
	nodeS14->nextRight = nodeS43T12;
	nodeS21->nextStraight = nodeM21;
	nodeS21->nextRight = nodeS14;
	nodeS32->nextStraight = NULL;
	nodeS32->nextRight = nodeS21;

	//Node from ST
	nodeS43T12->nextStraight = NULL;
	nodeS43T12->nextRight = nodeS32;

	//Nodes from T
	nodeT14->nextStraight = nodeU14;
	nodeT14->nextRight = NULL;
	nodeT32->nextStraight = nodeS32;
	nodeT32->nextRight = NULL;

	//Node from TU
	nodeT34U21->nextStraight = nodeN34O21;
	nodeT34U21->nextRight = nodeU14;

	//Nodes from U
	nodeU14->nextBridge = bridge3;
	nodeU14->nextRight = NULL;
	nodeU32->nextStraight = nodeT32;
	nodeU32->nextRight = nodeT34U21;

	//Nodes from V
	nodeV14->nextStraight = nodeW14;
	nodeV14->nextRight = nodeV43W12;
	nodeV32->nextRoundabout = roundaboutZ;
	nodeV32->nextRight = NULL;

	//Node from VW
	nodeV43W12->nextStraight = NULL;
	nodeV43W12->nextRight = nodeV32;

	//Nodes from W
	nodeW14->nextStraight = nodeX14;
	nodeW14->nextRight = NULL;
	nodeW32->nextStraight = nodeV32;
	nodeW32->nextRight = NULL;

	//Node from WX
	nodeW34X21->nextStraight = nodeQ34R21;
	nodeW34X21->nextRight = nodeX14;

	//Nodes from X
	nodeX14->nextStraight = NULL;
	nodeX14->nextRight = nodeX43;
	nodeX43->nextStraight = NULL;
	nodeX43->nextRight = nodeX32;
	nodeX32->nextStraight = nodeW32;
	nodeX32->nextRight = nodeW34X21;

	//***Roundabouts******************************************
	//Y Roundabout
	roundaboutY->nextStraight = nodeD14; // Next node straight direction, going to D1
	roundaboutY->nextRight1 = highwaySN1; // Next node to the right, going to highway
	roundaboutY->nextRight2 = highwaySN2; // Next node to the right, going to highway

	//Z Roundabout
	roundaboutZ->nextStraight = nodeU32; // Next node straight direction, going to D1
	roundaboutZ->nextRight1 = highwayNS1; // Next node to the right, going to highway
	roundaboutZ->nextRight2 = highwayNS2; // Next node to the right, going to highway

	//***Bridges**********************************************
	//Bridge 1
	bridge1->nextEast = nodeC32;// Next node straight direction East
	bridge1->nextWest = nodeJ14;// Next node straight direction West

	//Bridge 2
	bridge2->nextEast = nodeI32;// Next node straight direction East
	bridge2->nextWest = nodeP14;// Next node straight direction West

	//Bridge 3
	bridge3->nextEast = nodeO32;// Next node straight direction East
	bridge3->nextWest = nodeV14;// Next node straight direction West

	//***HIGHWAYS**********************************************
	//Highway SN1
	highwaySN1->nextRight = roundaboutZ;

	//Highway SN2
	highwaySN2->nextRight = roundaboutZ;

	//Highway NS1
	highwayNS1->nextRight = roundaboutY;

	//Highway NS2
	highwayNS2->nextRight = roundaboutY;

	// manageBridge(bridge1);
	// manageBridge(bridge2);
	// manageBridge(bridge3);

	bridge1->flagEast = 1;
	bridge2->flagWest = 1;

	return nodeA14;
}
