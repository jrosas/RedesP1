
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

typedef struct caja {
    char dominio[FILENAME_MAX];
    struct caja *next;
    struct caja *prev;
    struct list * l; 
    
} Caja;

typedef struct lista {
    Caja *prim;
    Caja *ult;
    int total;
} Lista;
/*
typedef struct lis {
    List *prim;
    List *ult;
    char directorio[FILENAME_MAX];
    int total;
} Lis;
*/







List* newList();
Lista* newLista() ;
Caja* newCaja(char *dominio);
void* addNodo(List *l, Nodo *n);
void* addCaja(Lista* l, Caja* c);

int isInL(List *l, char *nombre);

void* eliminarLista(List *l);



#endif
