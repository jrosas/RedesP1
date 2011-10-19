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



/**
 * Constructor de la Lista de Nodos
 * @return Apuntador a la nueva lista creada
 */


List* newList();
/**
 * Constructor de la Lista de Cajas
 * @return Apuntador a la nueva lista creada
 */
Lista* newLista();
/**
 * Constructor de la estructura Caja
 * @param dominio char* que contiene el nombre del dominio
 * @return Apuntador a la nueva Caja creada
 */

Caja* newCaja(char *dominio);
/**
 * Funcion que añade un Nodo a la struct List
 * @param l Apuntador a la List
 * @param n Apuntador al Nodo a agregar
 * @return void*
 */

void* addNodo(List* l, Nodo* n);
/**
 * Funcion que añade un Nodo a la struct Lista
 * @param l Apuntador a la Lista
 * @param c Apuntador a la Caja
 * @return  void*
 */
void* addCaja(Lista* l, Caja* c);

/**
 * Funcion que busca en una List un nombre de archivo.
 * @param l Apuntador a la struct List
 * @param nombre char* que contiene el nombre a buscar
 * @return Devuelve 1 si es encontrado. 0 si no.
 */
int isInL(List *l, char *nombre);
/**
 * Funcion que libera la struct List
 * @param l Apuntador a List
 */
void freeList(List* l);
/**
 * Funcion que libera la struc Lista
 * @param l Apuntador a Lista
 */
void freeLista(Lista* l);
/**
 * Funcion usada para depurar el correcto funcionamiento de la lista
 * @param l Apuntador a la Lista
 * @return void*
 */

void* showLista(Lista *l);

#endif
