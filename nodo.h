#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef NODO
#define NODO

typedef struct nodo {
    struct nodo *next;
    struct nodo *prev;
    char nombre[FILENAME_MAX];
    struct tm *fecha;
    int tam;
} Nodo;



/**
 * Constructor de la struc Nodo
 * @param nombre nombre del archivo
 * @return apuntador al Nodo creado
 */
Nodo* newNodo(char *nombre);
/**
 * Funcion que escribe el nombre del archivo en nodo n
 * @param n apuntador al nodo
 * @param nombre nombre nuevo
 * @return void*
 */


void* setNombre(Nodo* n, char *nombre);
/**
 * Funcion que escribe una nueva fecha en el nodo n
 * @param n apuntador al nodo
 * @param fecha fecha nueva bajo la estructura tm
 * @return void*
 */

void* setF(Nodo* n, struct tm* fecha);
/**
 * Funcion que coloca el siguiente en el nodo n
 * @param n apuntador al nodo
 * @param next apuntador al siguiente nodo
 * @return void*
 */
void* setN(Nodo* n, Nodo *next);
/**
 * Funcion que coloca el nodo anterior al nodo n
 * @param n Apuntador al nodo
 * @param prev apuntador al nodo previo
 * @return void*
 */
void* setP(Nodo* n, Nodo *prev);
/**
 * Funcion que escribe el tamaño del archivo
 * @param n Apuntador al nodo
 * @param t tamaño nuevo del archivo
 * @return void*
 */
void* setT(Nodo* n, int t);

/**
 * Funcion que compara dos nodos
 * @param n Apuntador al primero a comparar
 * @param p Apuntador al segundo a comparar
 * @return Devuelve 0 en caso de ser iguales
 *         1 en caso de que el nodo n es mas actual
 *         2 en caso de que el nodo p es mas actual
 */
int compare(Nodo* n, Nodo *p);
/**
 * Funcion que compara las fechas de dos nodos
 * @param n Primer nodo a comparar
 * @param p Segundo nodo a comparar
 * @return  Devuelve un double de la resta de las fechas
 */
double compareF(Nodo* n, Nodo* p);
/**
 * Funcion que compara los nombres de dos nodos
 * @param n Primer nodo a comparar
 * @param p Segundo nodo a comparar
 * @return Devuelve 0 si son iguales
 *                  otro si sin distintos
 */
int compareN(Nodo* n, Nodo *p);

#endif
