#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_FILE_NAME "../conf/config.conf"



void readConfigFile(int *expD, float* speed ,int * traficC, float * semaphE, float * semaphW, int *amount, int *ambulance, int *radio , int *schedule, char *port ){
    FILE * fp;    

    fp = fopen(CONFIG_FILE_NAME, "r");
    if (fp == NULL){
        fclose(fp); 
        exit(EXIT_FAILURE);
    }
    else{
        char key[256], value[256];
        char * line = NULL;
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, fp)) != -1) {
            if(line[0] == '#' || line[0] == '\n')
                continue;
            else{
                sscanf(line, "%s = %s", key, value);
                if(strcmp(key, "EXPONENTIAL_DISTRIBUTION") == 0){  //Read the EXPONENTIAL_DISTRIBUTION
                    sscanf(value, "%d", expD);
                } else if(strcmp(key, "CARS_SPEED") == 0){  //Read the CARS_SPEED
                    sscanf(value, "%f", speed);
                } else if(strcmp(key, "TRAFFIC_CONTROL") == 0){  //Read the TRAFFIC_CONTROL
                    sscanf(value, "%d", traficC);
                } else if(strcmp(key, "SEMAPHORE_EAST_TIME") == 0){  //Read the SEMAPHORE_EAST_TIME
                    sscanf(value, "%f", semaphE);
                } else if(strcmp(key, "SEMAPHORE_WEST_TIME") == 0){  //Read the SEMAPHORE_WEST_TIME
                    sscanf(value, "%f", semaphW);
                } else if(strcmp(key, "AMOUNT_CARS") == 0){  //Read the AMOUNT_CARS
                    sscanf(value, "%d", amount);
                } else if(strcmp(key, "AMBULANCE_PERCENT") == 0){  //Read the AMBULANCE_PERCENT
                    sscanf(value, "%d", ambulance);
                } else if(strcmp(key, "RADIOACTIVE_PERCENT") == 0){  //Read the RADIOACTIVE_PERCENT
                    sscanf(value, "%d", radio);
                } else if(strcmp(key, "SCHEDULING_METHOD") == 0){  //Read the SCHEDULING_METHOD
                    sscanf(value, "%d", schedule);
                } else if(strcmp(key, "PORT_VALUE") == 0){       //Identify the LOGFILE path
                    strncpy(port,value, 255);
                }

            }
        }
        fclose(fp);    
    }
    
}
