#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef NODO
#define NODO

/*
 Tipo NODO. 
 Contiene la informacion de la lista
 variables: 
  char nombre
  struct nodo *next
  struct nodo *prev
  struct tm fecha
 
 
 */
typedef struct nodo {
    struct nodo *next;
    struct nodo *prev;
    char *nombre;
    struct tm *fecha;
    int tam;
} Nodo;

typedef struct caja {
    char dominio[FILENAME_MAX];
    struct caja *next;
    struct caja *prev;
} Caja;

/*
 *Funcion newNodo()
 *Funcion que crea un nuevo nodo
 */
Nodo* newNodo();
Caja* newCaja(char *dominio);
/*
 * Funcion setNombre()
 * Entrada
 * Salida
 */

void* setNombre(Nodo* n, char *nombre);
/*
 * Funcion setF
 * Entrada
 * Salida
 */

void* setF(Nodo* n, struct tm* fecha);
/*
 * Funcion setN
 * Entrada
 * Salida
 */

void* setN(Nodo* n, Nodo *next);
/*
 * Funcion setP
 * Entrada
 * Salida
 */
void* setP(Nodo* n, Nodo *prev);
int compare(Nodo* n, Nodo *p  );

double compareF(Nodo* n, Nodo* p);

int compareN(Nodo* n, Nodo *p);

#endif
