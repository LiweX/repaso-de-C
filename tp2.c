#include <stdio.h>
#include "meminfo.h"
#include "cpuinfo.h"
#include "version.h"

int main(void){
    printf("Este programa resuelve las consignas referidas a strings y arreglos\n");
    printf("\nPulse una tecla para continuar:\n");
    getchar();
    printf("Meminfo:\n");
    meminfo();
    printf("\nPulse una tecla para continuar:\n");
    getchar();
    printf("Cpuinfo:\n");
    cpuinfo();
    printf("\nPulse una tecla para continuar:\n");
    getchar();
    printf("Version:\n");
    version();

    return 0;
}