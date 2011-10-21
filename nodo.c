#include "nodo.h"

/**
 * Constructor de la struc Nodo
 * @param nombre nombre del archivo
 * @return apuntador al Nodo creado
 */
Nodo* newNodo(char *nombre) {
    Nodo* n = (Nodo*) calloc(1, sizeof (Nodo));
    n->next = NULL;
    n->prev = NULL;
    strcpy(n->nombre, nombre);
    n->fecha;
   // n->fecha = 
    n->tam = 0;
    return n;
}

/**
 * Funcion que escribe el nombre del archivo en nodo n
 * @param n apuntador al nodo
 * @param nombre nombre nuevo
 * @return void*
 */


void* setNombre(Nodo* n, char *nombre) {
    strcpy(n->nombre, nombre);
}

/**
 * Funcion que escribe una nueva fecha en el nodo n
 * @param n apuntador al nodo
 * @param fecha fecha nueva bajo la estructura tm
 * @return void*
 */

void* setF(Nodo* n, char* fecha) {
    strcpy(n->fecha, fecha);

}

/**
 * Funcion que coloca el siguiente en el nodo n
 * @param n apuntador al nodo
 * @param next apuntador al siguiente nodo
 * @return void*
 */
void* setN(Nodo* n, Nodo *next) {
    n->next = next;
}

/**
 * Funcion que coloca el nodo anterior al nodo n
 * @param n Apuntador al nodo
 * @param prev apuntador al nodo previo
 * @return void*
 */
void* setP(Nodo* n, Nodo *prev) {
    n->prev = prev;
}

/**
 * Funcion que escribe el tamaño del archivo
 * @param n Apuntador al nodo
 * @param t tamaño nuevo del archivo
 * @return void*
 */
void* setT(Nodo* n, int t) {
    n->tam = t;
}

/**
 * Funcion que compara dos nodos
 * @param n Apuntador al primero a comparar
 * @param p Apuntador al segundo a comparar
 * @return Devuelve 0 en caso de ser iguales
 *         1 en caso de que el nodo n es mas actual
 *         2 en caso de que el nodo p es mas actual
 */
int compare(Nodo* n, Nodo *p) {
    
    int comp = compareF(n, p);
    
    if (comp == 0) {
        if (n->tam == p->tam) {
            return 0;
        }
    }
    if (comp < 0) {
        return 2; // nodo p es mas actual
    }
    return 1; // nodo n es mas actual

}

/**
 * Funcion que compara las fechas de dos nodos
 * @param n Primer nodo a comparar
 * @param p Segundo nodo a comparar
 * @return  Devuelve un double de la resta de las fechas
 */
int compareF(Nodo* n, Nodo* p) {
   
   int salida = (strcmp (n->fecha,p->fecha));     
    //Fprintf("%s vs %s\n",n->fecha,p->fecha) ;
    //printf ("%f\n",salida);
    return (salida);
}

/**
 * Funcion que compara los nombres de dos nodos
 * @param n Primer nodo a comparar
 * @param p Segundo nodo a comparar
 * @return Devuelve 0 si son iguales
 *                  otro si sin distintos
 */
int compareN(Nodo* n, Nodo *p) {
    int salida;
    salida = strcmp(n->nombre, p->nombre);
    return (salida);
}
