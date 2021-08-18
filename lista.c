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
    int size;
}Lista;

void listInit(Lista* lista);
void mostrarLista(Lista* lista);
void addNode(Lista* lista,int dato);

int main(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    listInit(lista);
    addNode(lista,1);
    addNode(lista,3);
    addNode(lista,7);
    mostrarLista(lista);
}

void listInit(Lista* lista){
    lista->inicio=NULL;
    lista->fin=NULL;
    lista->size=0;
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