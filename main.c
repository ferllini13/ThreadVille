
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

	rute1.size = 1;
	rute1.move = "nodeM21";
	rute1.next = NULL;
	rute1.finalPosition = 0;

	rute2.size = 2;
	rute2.move = "nodeS21";
	rute2.next = &rute1;
	rute2.finalPosition = 0;

	rute3.size = 3;
	rute3.move = "nodeS32";
	rute3.next = &rute2;
	rute3.finalPosition = 0;
	
	rute4.size = 4;
	rute4.move = "nodeS43T12";
	rute4.next = &rute3;
	rute4.finalPosition = 0;

	rute5.size = 5;
	rute5.move = "nodeM43N12";
	rute5.next = &rute4;
	rute5.finalPosition = 0;

	rute6.size = 6;
	rute6.move = "nodeG43H12";
	rute6.next = &rute5;
	rute6.finalPosition = 4;



	struct vehicle *car;
	car = create(0, 1, 2, 0, 0, actualNode, rute6, "", "", "nodeA43B12");
	move(car);
	return 0;
}