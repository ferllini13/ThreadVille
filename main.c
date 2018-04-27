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
	struct list rute14;
	struct list rute15;
	struct list rute16;
	struct list rute17;
	struct list rute18;
	struct list rute19;
	struct list rute20;
	struct list rute21;
	struct list rute22;
	struct list rute23;
	struct list rute24;
	struct list rute25;
	struct list rute26;


	rute1.size = 1;
	rute1.move = "nodeV14";
	rute1.next = NULL;
	rute1.finalPosition = 0;

	rute2.size = 2;
	rute2.move = "bridge3";
	rute2.next = &rute1;
	rute2.finalPosition = 0;

	rute3.size = 3;
	rute3.move = "nodeU14";
	rute3.next = &rute2;
	rute3.finalPosition = 0;
	
	rute4.size = 4;
	rute4.move = "nodeT14";
	rute4.next = &rute3;
	rute4.finalPosition = 0;

	rute5.size = 5;
	rute5.move = "nodeS14";
	rute5.next = &rute4;
	rute5.finalPosition = 0;

	rute6.size = 6;
	rute6.move = "nodeS21";
	rute6.next = &rute5;
	rute6.finalPosition = 4;

	rute7.size = 7;
	rute7.move = "nodeS32";
	rute7.next = &rute6;
	rute7.finalPosition = 4;

	rute8.size = 8;
	rute8.move = "nodeS43T12";
	rute8.next = &rute7;
	rute8.finalPosition = 4;

	rute9.size = 9;
	rute9.move = "nodeM43N12";
	rute9.next = &rute8;
	rute9.finalPosition = 4;

	rute10.size = 10;
	rute10.move = "nodeG43H12";
	rute10.next = &rute9;
	rute10.finalPosition = 4;

	rute11.size = 11;
	rute11.move = "nodeG14";
	rute11.next = &rute10;
	rute11.finalPosition = 4;

	rute12.size = 12;
	rute12.move = "nodeG21";
	rute12.next = &rute11;
	rute12.finalPosition = 4;

	rute13.size = 13;
	rute13.move = "nodeG32";
	rute13.next = &rute12;
	rute13.finalPosition = 4;

	rute14.size = 14;
	rute14.move = "nodeH32";
	rute14.next = &rute13;
	rute14.finalPosition = 4;

	rute15.size = 15;
	rute15.move = "nodeI32";
	rute15.next = &rute14;
	rute15.finalPosition = 4;

	rute16.size = 16;
	rute16.move = "bridge2";
	rute16.next = &rute15;
	rute16.finalPosition = 4;

	rute17.size = 17;
	rute17.move = "nodeJ32";
	rute17.next = &rute16;
	rute17.finalPosition = 4;

	rute18.size = 18;
	rute18.move = "nodeJ43K12";
	rute18.next = &rute17;
	rute18.finalPosition = 4;

	rute19.size = 19;
	rute19.move = "nodeJ14";
	rute19.next = &rute18;
	rute19.finalPosition = 4;

	rute20.size = 20;
	rute20.move = "bridge1";
	rute20.next = &rute19;
	rute20.finalPosition = 4;

	rute21.size = 21;
	rute21.move = "nodeI14";
	rute21.next = &rute20;
	rute21.finalPosition = 4;

	rute22.size = 22;
	rute22.move = "nodeH14";
	rute22.next = &rute21;
	rute22.finalPosition = 4;

	rute23.size = 23;
	rute23.move = "nodeG14";
	rute23.next = &rute22;
	rute23.finalPosition = 4;

	rute24.size = 24;
	rute24.move = "nodeG21";
	rute24.next = &rute23;
	rute24.finalPosition = 4;

	rute25.size = 25;
	rute25.move = "nodeG32";
	rute25.next = &rute24;
	rute25.finalPosition = 4;

	rute26.size = 26;
	rute26.move = "nodeG43H12";
	rute26.next = &rute25;
	rute26.finalPosition = 4;


	struct vehicle *car;
	car = create(0, 1, 2, 0, 0, actualNode, NULL, NULL, NULL, rute26, "Purple", "", "nodeA43B12");


	
/*
	rute1.size = 1;
	rute1.move = "nodeH34I21";
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

*/	


/*
	rute1.size = 1;
	rute1.move = "nodeI32";
	rute1.next = NULL;
	rute1.finalPosition = 0;

	rute2.size = 2;
	rute2.move = "bridge2";
	rute2.next = &rute1;
	rute2.finalPosition = 0;

	rute3.size = 3;
	rute3.move = "nodeJ32";
	rute3.next = &rute2;
	rute3.finalPosition = 0;
	
	rute4.size = 4;
	rute4.move = "nodeJ43K12";
	rute4.next = &rute3;
	rute4.finalPosition = 0;

	rute5.size = 5;
	rute5.move = "nodeJ14";
	rute5.next = &rute4;
	rute5.finalPosition = 0;

	rute6.size = 6;
	rute6.move = "bridge1";
	rute6.next = &rute5;
	rute6.finalPosition = 4;

	rute7.size = 7;
	rute7.move = "nodeI14";
	rute7.next = &rute6;
	rute7.finalPosition = 4;

	rute8.size = 8;
	rute8.move = "nodeH14";
	rute8.next = &rute7;
	rute8.finalPosition = 4;

	rute9.size = 9;
	rute9.move = "nodeG14";
	rute9.next = &rute8;
	rute9.finalPosition = 4;

	rute10.size = 10;
	rute10.move = "nodeG21";
	rute10.next = &rute9;
	rute10.finalPosition = 4;

	rute11.size = 11;
	rute11.move = "nodeG32";
	rute11.next = &rute10;
	rute11.finalPosition = 4;

	rute12.size = 12;
	rute12.move = "nodeG43H12";
	rute12.next = &rute11;
	rute12.finalPosition = 0;



	struct vehicle *car;
	car = create(0, 1, 2, 0, 0, actualNode, NULL, NULL, NULL, rute12, "", "", "nodeA43B12");
*/
	move(car);


	return 0;
}