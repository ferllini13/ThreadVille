#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/serialBridge.h"





void updateFlag(char * data,int bridge, int west, int east){
	switch (bridge){
		case 1:
			data[0]=east==1? 'G': 'R';
			data[6]=east==1? 'G': 'R';
			break;
		case 2:
			data[24]=east==1? 'G': 'R';
			data[30]=east==1? 'G': 'R';
			break;			
	}
}


void updateBridge(char * data,int bridge,struct BRIDGE * bridge){
	switch (bridge){
		case 1:
			data[1]=bridge->Vehicles[4]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[2]=bridge->Vehicles[3]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[3]=bridge->Vehicles[2]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[4]=bridge->Vehicles[1]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[5]=bridge->Vehicles[0]!=NULL?bridge->Vehicles[0]->color[0];'N';
			break;
		case 2:
			data[25]=bridge->Vehicles[4]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[26]=bridge->Vehicles[3]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[27]=bridge->Vehicles[2]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[28]=bridge->Vehicles[1]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[29]=bridge->Vehicles[0]!=NULL?bridge->Vehicles[0]->color[0];'N';
			break;			
		case 3:
			data[49]=bridge->Vehicles[4]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[50]=bridge->Vehicles[3]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[51]=bridge->Vehicles[2]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[52]=bridge->Vehicles[1]!=NULL?bridge->Vehicles[0]->color[0];'N';
			data[53]=bridge->Vehicles[0]!=NULL?bridge->Vehicles[0]->color[0];'N';
			break;	
	}	
}




void writeSerial(char * data, char * port){
	char command[50]="echo ";
	strcat(command,data);	
	strcat(command," > ");
	strcat(command,port);

	system(command);
}