#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_FILE_NAME "../conf/config.conf"



void readConfigFile(int *expD, double * speed ,int * traficC, double * semaphE, double * semaphW, int *amount, int *ambulance, int *radio , int *schedule ){
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
                if(strcmp(key, "EXPONENTIAL_DISTRIBUTION") == 0){  //Read the CPUthreshold
                    sscanf(value, "%lf", &(*expD));
                } else if(strcmp(key, "CARS_SPEED") == 0){  //Read the Memthreshold
                    sscanf(value, "%lf", &(*speed));
                } else if(strcmp(key, "TRAFFIC_CONTROL") == 0){  //Read the SYNthreshold
                    sscanf(value, "%lf", &(*traficC));
                } else if(strcmp(key, "SEMAPHORE_EAST_TIME") == 0){  //Read the SYNthreshold
                    sscanf(value, "%lf", &(*semaphE));
                } else if(strcmp(key, "SEMAPHORE_WEST_TIME") == 0){  //Read the SYNthreshold
                    sscanf(value, "%lf", &(*semaphW));
                } else if(strcmp(key, "AMOUNT_CARS") == 0){  //Read the SYNthreshold
                    sscanf(value, "%lf", &(*amount));
                } else if(strcmp(key, "AMBULANCE_PERCENT") == 0){  //Read the SYNthreshold
                    sscanf(value, "%lf", &(*ambulance));
                } else if(strcmp(key, "RADIOACTIVE_PERCENT") == 0){  //Read the SYNthreshold
                    sscanf(value, "%lf", &(*radio));
                } else if(strcmp(key, "SCHEDULING_METHOD") == 0){  //Read the SYNthreshold
                    sscanf(value, "%lf", &(*schedule));
                }

            }
        }
        fclose(fp);    
    }
    
}


