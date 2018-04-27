#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/serialBridge.h"
#include "../include/arduino-serial-lib.h"
#include "../include/city.h"

void initmat(char * data){
	for (int i=0;i < 64;++i){
		data[i]='N';
	}
	//printf("%s\n", data);
}


void updateFlag(char * data,int nbridge, int west, int east){
	switch (nbridge){
		case 79:
			data[0]=east==1? 'G': 'R';
			data[6]=west==1? 'G': 'R';
			break;
		case 80:
			data[24]=east==1? 'G': 'R';
			data[30]=west==1? 'G': 'R';
			break;			
	}
}


void updateBridge(char * data,int nbridge,struct BRIDGE * bridge){
	printf("%d\n", nbridge);
	switch (nbridge){
		case 79:
			data[1]=bridge->Vehicles[0]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[2]=bridge->Vehicles[1]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[3]=bridge->Vehicles[2]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[4]=bridge->Vehicles[3]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[5]=bridge->Vehicles[4]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			break;
		case 80:
			data[25]=bridge->Vehicles[0]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[26]=bridge->Vehicles[1]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[27]=bridge->Vehicles[2]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[28]=bridge->Vehicles[3]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[29]=bridge->Vehicles[4]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			break;			
		case 81:
			data[49]=bridge->Vehicles[0]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[50]=bridge->Vehicles[1]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[51]=bridge->Vehicles[2]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[52]=bridge->Vehicles[3]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			data[53]=bridge->Vehicles[4]!=NULL?bridge->Vehicles[0]->color[0]:'N';
			break;	
	}	
}

void writeSerial(char * data, char * port){
	int fd = -1;
    fd = serialport_init(port, 9600);
    if (fd == -1){
        perror("Could not open port.");
    }
    serialport_flush(fd);
    serialport_write(fd, data);
}