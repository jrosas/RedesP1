#include "lista.h"
#include "nodo.h"

/**
 * Constructor de la Lista de Nodos
 * @return Apuntador a la nueva lista creada
 */


List* newList() {
    List *l = (List*) calloc(1, sizeof (List));
    l->prim = NULL;
    l->ult = NULL;
    l->total = 0;
    return l;
}

/**
 * Constructor de la Lista de Cajas
 * @return Apuntador a la nueva lista creada
 */
Lista* newLista() {
    Lista *l = (Lista*) calloc(1, sizeof (Lista));
    l->prim = NULL;
    l->ult = NULL;
    l->total = 0;
    return l;
}

/**
 * Constructor de la estructura Caja
 * @param dominio char* que contiene el nombre del dominio
 * @return Apuntador a la nueva Caja creada
 */

Caja* newCaja(char *dominio) {
    Caja* n = (Caja*) calloc(1, sizeof (Caja));
    n->l = newList();
    strcpy(n->dominio, dominio);
    n->next = NULL;
    n->prev = NULL;
    return n;


}

/**
 * Funcion que añade un Nodo a la struct List
 * @param l Apuntador a la List
 * @param n Apuntador al Nodo a agregar
 * @return void*
 */

void* addNodo(List* l, Nodo* n) {
    if (l->total == 0) {
        l->prim = n;
        l->ult = n;
        (l->total)++;
    } else {
        l->ult->next = n;
        n->prev = l->ult;
        l->ult = n;
        (l->total)++;
    }
}

/**
 * Funcion que añade un Nodo a la struct Lista
 * @param l Apuntador a la Lista
 * @param c Apuntador a la Caja
 * @return  void*
 */
void* addCaja(Lista* l, Caja* c) {
    if (l->total == 0) {
        l->prim = c;
        l->ult = c;
        (l->total)++;
    } else {
        l->ult->next = c;
        c->prev = l->ult;
        l->ult = c;
        (l->total)++;
    }
}

/**
 * Funcion que busca en una List un nombre de archivo.
 * @param l Apuntador a la struct List
 * @param nombre char* que contiene el nombre a buscar
 * @return Devuelve 1 si es encontrado. 0 si no.
 */
int isInL(List *l, char *nombre) {
    Nodo *aux = l->prim;
    Nodo *nodo = newNodo();
    setNombre(nodo, nombre);
    while (aux != NULL) {
        if (compareN(aux, nodo) == 0) {
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

/**
 * Funcion que libera la struct List
 * @param l Apuntador a List
 */
void freeList(List* l) {
    l->total = 0;
    Nodo* nodo = l->ult;

    //Nodo* next_nodo;
    while (nodo != NULL) {
        l->ult = nodo->prev;
        free(nodo);
        nodo = l->ult;
    }
    l->prim = NULL;
}

/**
 * Funcion que libera la struc Lista
 * @param l Apuntador a Lista
 */
void freeLista(Lista* l) {
    l->total = 0;
    Caja* caja = l->ult;

    //Nodo* next_nodo;
    while (caja != NULL) {
        l->ult = caja->prev;
        free(caja);
        caja = l->ult;
    }
    l->prim = NULL;
}

/**
 * Funcion usada para depurar el correcto funcionamiento de la lista
 * @param l Apuntador a la Lista
 * @return void*
 */

void* showLista(Lista *l) {

    Caja *aux = l->prim;
    int i = 1;
    while (aux != NULL) {
        printf("Caja numero %i, es %s\n", i, aux->dominio);
        i++;
        aux = aux->next;
    }
}

int main(int argc, char **argv) {
    // printf ("holaaaa!!! \n");
    FILE *fp;
    char result[FILENAME_MAX];
    char *hola;
    hola = "HOLAAAAAA";
    //char *aux;
    //   char otra[100];
    /*
        setNombre(primero, "1");
        setNombre(segundo,           "2");
        setNombre(tercero, "3");

        addNodo(lista, primero);
        addNodo(lista, segundo);
        addNodo(lista, tercero);

        if (isInL(lista, "1") == 1) {
            printf("El elemento 1 esta en la lista\n");
        }
        if (isInL(lista, "2") == 1) {
            printf("El elemento 2 esta en la lista\n");
        }

        if (isInL(lista, "3") == 1) {
            printf("El elemento 3 esta en la lista\n");
        }
        if (isInL(lista, "4") == 1) {
            printf("El elemento 3 esta en la lista\n");
        } else {
            printf("El elemento 4 no esta en la lista\n");
        }
     */
    //freeList(lista);


    Lista *lista2 = newLista();

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Error al abrir archivo");
        return 1;
    }
    while (fscanf(fp, " http:// %s\n", result) != EOF) {
        printf("%s\n", result);
        addCaja(lista2, newCaja(result));

        //   free (aux);

    }

    showLista(lista2);
    fclose(fp);
    return (EXIT_SUCCESS);



}

