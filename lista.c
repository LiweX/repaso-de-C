#include <stdlib.h>
#include <stdio.h>
#include "myFuncs.h"

typedef struct Nodo{
    int numero;
    struct Nodo* next;   
}Nodo;

typedef struct Lista{
    Nodo* inicio;
    Nodo* fin;
    int size;
}Lista;

void listInit(Lista* lista);
void mostrarLista(Lista* lista);
void addNode(Lista* lista,int dato);
void liberarMemoria(Lista *lista);

int main(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    char* option=(char*)malloc(sizeof(char));
    int* input=(int*)malloc(sizeof(int));
    listInit(lista);
    printf("Este programa crea una lista simplemente enlazada que almacena numeros enteros\n");
    while(-1){
        printf("\nQue operacion desea realizar?\n1.Ingresar numero\n2.Mostrar lista\n3.Salir del programa\n");
        scanf("%c",option);
        if(*option=='1'){
            printf("Ingrese el numero: ");
            scanf("%d",input);
            addNode(lista,*input);
            continue; 
        }else if(*option=='2'){
            printf("A continuacion se imprimen los numeros guardados en la lista:\n");
            mostrarLista(lista);
            continue;
        }else if(*option=='3'){
            printf("Fin del programa...\n");
            liberarMemoria(lista);
            return 0;
        }else printf("Entrada invalida...\n");   
    }   
}

void listInit(Lista* lista){
    lista->inicio=NULL;
    lista->fin=NULL;
    lista->size=0;
}

void liberarMemoria(Lista *lista){
    Nodo* pivot =(Nodo*)malloc(sizeof(Nodo));
    Nodo* aux =(Nodo*)malloc(sizeof(Nodo));
    while(pivot->next!=NULL){
        aux = pivot;
        pivot=pivot->next;
        free(aux);
    }
    free(pivot);
    free(lista);
}

void addNode(Lista* lista,int dato){
    if(lista->size==0){   // agregar el primer nodo
        Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
        newNode->next=NULL;
        newNode->numero=dato;
        lista->inicio=newNode;
        lista->fin=newNode;
        lista->size=1;
    }else{                  //la lista ya tiene nodos
        Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
        newNode->next=NULL;
        newNode->numero=dato;
        lista->fin->next = newNode;   //el ultimo nodo ahora apunta hacia el nuevo nodo
        lista->fin = newNode;         //el nuevo todo ahora es el ultimo de la lista
        lista->size=(lista->size)+1;
    }
}

void mostrarLista(Lista* lista){
    if(lista->size==0){
        printf("La lista esta vacia\n");
    }else{
        Nodo* pivot = (Nodo*)malloc(sizeof(Nodo));
        pivot = lista->inicio;
        printf("%d\n",pivot->numero);
        while(pivot->next!=NULL){
            pivot = pivot->next;
            printf("%d\n",pivot->numero);
        }
    }
}