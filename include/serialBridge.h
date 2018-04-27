#ifndef _SERIALBRIDGE_H
#define _SERIALBRIDGE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/serialBridge.h"
#include "../include/arduino-serial-lib.h"
#include "../include/city.h"



void initmat(char * data);
void updateFlag(char * data,int nbridge, int west, int east);
void updateBridge(char * data,int nbridge,struct BRIDGE * bridge);
void writeSerial(char * data, char * port);


#endif