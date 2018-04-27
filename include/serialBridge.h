#ifndef _SERIALBRIDGE_H
#define _SERIALBRIDGE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/serialBridge.h"
#include "../include/arduino-serial-lib.h"
#include "../include/city.h"


int intitSerial( char * port);
void initmat(char * data);
void updateFlag(char * data,int nbridge, int west1, int east1,int west2, int east2);
//void updateBridge(char * data, int nbridge, struct BRIDGE * bridge);
void writeSerial(char * data, int fd);


#endif