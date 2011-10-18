
#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"

#ifndef LIST
#define LIST

typedef struct list {
    Nodo *prim;
    Nodo *ult;
    int total;
} List;

typedef struct lista {
    Caja *prim;
    Caja *ult;
    int total;
} Lista;



List* newList();
Lista* newLista() ;
void* addNodo(List *l, Nodo *n);
void* addCaja(Lista* l, Caja* c);

int isInL(List *l, char *nombre);

void* eliminarLista(List *l);



#endif
