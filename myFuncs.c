#include <stdlib.h>
#include <stdio.h>

FILE* openFile(char* path){
    FILE *file;
    file = fopen(path,"r");
    if(file==NULL){
        fprintf(stdout,"Error al abrir el archivo: %s",path);
        exit(EXIT_FAILURE);
    }
    return file;
}