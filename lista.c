#include "lista.h"
#include "nodo.h"

/*
 typedef struct list {
        Nodo *prim;
        Nodo *ult;
        int total;
} List;

 */

List* newList() {
    List *l = (List*) calloc(1, sizeof (List));
    l->prim = NULL;
    l->ult = NULL;
    l->total = 0;
    return l;
}

Lista* newLista() {
    Lista *l = (Lista*) calloc(1, sizeof (Lista));
    l->prim = NULL;
    l->ult = NULL;
    l->total = 0;
    return l;
}

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

/*
Si esta devuelve 1
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

/*
void llenarLista(){
  int pr;   
  char *hostaddress;
  char *path;
   pr = fscanf(argv[1], "http://%99[^/]%s", hostaddress, path); 

   
}

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

    List *lista = newList();
    Nodo *primero = newNodo();
    Nodo *segundo = newNodo();
    Nodo *tercero = newNodo();
    FILE *fp;
    char result[FILENAME_MAX];
    char *aux;
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
    while (fscanf(fp," http:// %s\n", result) !=  EOF) {
        printf ("%s\n",result);
      

        
        
        addCaja(lista2, newCaja(result));
     //   free (aux);
               
    }
   showLista(lista2);
    fclose(fp);
    return (EXIT_SUCCESS);



}

