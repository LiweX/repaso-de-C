#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
    int numero;
    struct Nodo* next;   
}Nodo;

typedef struct Lista{
    Nodo* inicio;
    Nodo* fin;
    int tamaño;
}Lista;

int main(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    listInit(lista);
}

void listInit(Lista* lista){
    lista->inicio=NULL;
    lista->fin=NULL;
    lista->tamaño=0;
}

void addNode(Lista* lista,int dato){
    if(lista->tamaño==0){   // agregar el primer nodo
        Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
        newNode->next=NULL;
        newNode->numero=dato;
        lista->inicio=newNode;
        lista->fin=newNode;
        lista->tamaño=1;
    }else{                  //la lista ya tiene nodos
        Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
        newNode->next=NULL;
        newNode->numero=dato;
        lista->fin->next = newNode;   //el ultimo nodo ahora apunta hacia el nuevo nodo
        lista->fin = newNode;         //el nuevo todo ahora es el ultimo de la lista
        lista->tamaño=(lista->tamaño)+1;
    }
}

void mostrarLista(Lista* lista){
    
}