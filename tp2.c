#include <stdio.h>
#include "meminfo.h"
#include "cpuinfo.h"
#include "version.h"

int main(void){

    meminfo();
    cpuinfo();
    version();
    return 0;
}