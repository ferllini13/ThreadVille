#include <stdio.h>
#include <stdlib.h>
#include "./include/confReader.h"
#include "./include/vehicle.h"
#include "./include/city.h"


int main(int argc, char const *argv[]){
	int expD;
	float  speed;
	int traficC; 
	float semaphE; 
	float semaphW; 
	int amount;
	int ambulance; 
	int radio;
	int schedule;

	readConfigFile(&expD, &speed, &traficC, &semaphE, &semaphW, &amount, &ambulance, &radio, &schedule);
	// printf("expD: % d\n", expD);
	// printf("speed: % f\n", speed);
	// printf("traficC: % d\n", traficC);
	// printf("semaphE: % f\n", semaphE);
	// printf("semaphW: % f\n", semaphW);
	// printf("amount: % d\n", amount);
	// printf("ambulance: % d\n", ambulance);
	// printf("radio: % d\n", radio);
	// printf("schedule: % d\n", schedule);

	struct NODE *actualNode;

	actualNode = init();
	// printf("ANTES\n");
	// int ID = (*actualNode).id;
	// printf("actualNode %d\n", ID);

	struct list rute1;
	struct list rute2;
	struct list rute3;
	struct list rute4;
	struct list rute5;
	struct list rute6;
	struct list rute7;
	struct list rute8;
	struct list rute9;
	struct list rute10;
	struct list rute11;
	struct list rute12;
	struct list rute13;

	rute1.size = 1;
	rute1.move = "nodeI21";
	rute1.next = NULL;
	rute1.finalPosition = 0;

	rute2.size = 2;
	rute2.move = "nodeI32";
	rute2.next = &rute1;
	rute2.finalPosition = 0;

	rute3.size = 3;
	rute3.move = "bridge2";
	rute3.next = &rute2;
	rute3.finalPosition = 0;
	
	rute4.size = 4;
	rute4.move = "nodeJ32";
	rute4.next = &rute3;
	rute4.finalPosition = 0;

	rute5.size = 5;
	rute5.move = "nodeJ43K12";
	rute5.next = &rute4;
	rute5.finalPosition = 0;

	rute6.size = 6;
	rute6.move = "nodeJ14";
	rute6.next = &rute5;
	rute6.finalPosition = 4;

	rute7.size = 7;
	rute7.move = "bridge1";
	rute7.next = &rute6;
	rute7.finalPosition = 4;

	rute8.size = 8;
	rute8.move = "nodeI14";
	rute8.next = &rute7;
	rute8.finalPosition = 4;

	rute9.size = 9;
	rute9.move = "nodeH14";
	rute9.next = &rute8;
	rute9.finalPosition = 4;

	rute10.size = 10;
	rute10.move = "nodeG14";
	rute10.next = &rute9;
	rute10.finalPosition = 4;

	rute11.size = 11;
	rute11.move = "nodeG21";
	rute11.next = &rute10;
	rute11.finalPosition = 4;

	rute12.size = 12;
	rute12.move = "nodeG32";
	rute12.next = &rute11;
	rute12.finalPosition = 4;

	rute13.size = 13;
	rute13.move = "nodeG43H12";
	rute13.next = &rute12;
	rute13.finalPosition = 4;





	struct vehicle *car;
	car = create(0, 1, 2, 0, 0, actualNode, NULL, NULL, NULL, rute13, "", "", "nodeA43B12");

	move(car);


	return 0;
}