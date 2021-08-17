#include <stdio.h>
#include <string.h>
#include "myFuncs.h"

void meminfo(void){

    struct Meminfo{
        int total;
        int free;
        int available;
        int swap;
    };

    char buffer[100];

    FILE* info = openFile("/proc/meminfo");

    fgets(buffer,100,info);
    printf("%s",buffer);
}