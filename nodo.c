#include "nodo.h"

/*
 Funcion newNodo()
 Funcion que crea un nuevo nodo
 */
Nodo* newNodo(char *nombre) {
    Nodo* n = (Nodo*) calloc(1, sizeof (Nodo));
    n->next = NULL;
    n->prev = NULL;
    strcpy (n->nombre,nombre);
    n->fecha = (struct tm*) calloc(1, sizeof (struct tm));
    n->tam = 0;
}


/*
 * Funcion setNombre()
 * Entrada
 * Salida
 */

void* setNombre(Nodo* n, char *nombre) {
    strcpy (n->nombre,nombre);
    //printf("%s\n", n->nombre);

}

/*
 * Funcion setF
 * Entrada
 * Salida struct 
 */

void* setF(Nodo* n, struct tm* fecha) {
    n->fecha = fecha;

}

/*
 * Funcion setN
 * Entrada
 * Salida
 */

void* setN(Nodo* n, Nodo *next) {
    n->next = next;
}

/*
 * Funcion setP
 * Entrada
 * Salida
 */
void* setP(Nodo* n, Nodo *prev) {
    n->prev = prev;
}

void* setT(Nodo* n, int t) {
    n->tam = t;
}

/*
 * devuelve 0 en caso de ser iguales 
 * devuelve 1 en caso de ser distintos. 
 * 
 *  
 */
int compare(Nodo* n, Nodo *p) {
    double comp = compareF(n, p);
    if (comp == 0) {
        if (n->tam == p->tam) {
            return 0;
        }
    }
    if (comp < 0.0) {
        return 2; // nodo p es mas actual
    }
    return 1; // nodo n es mas actual

}

double compareF(Nodo* n, Nodo* p) {
    double salida;
    time_t t1;
    time_t t2;
    t1 = mktime(n->fecha);
    t2 = mktime(p->fecha);
    salida = difftime(t1, t2);
    // printf("%f\n", salida);
    return (salida);
}

int compareN(Nodo* n, Nodo *p) {
    int salida;
    salida = strcmp(n->nombre, p->nombre);
    return (salida);
}
/*
int main(int argc, char **argv) {
    Nodo* tmp = newNodo();
    Nodo* tmp2 = newNodo();
    struct tm ts2;
    struct tm ts4;
    struct tm *ts3;
    char *hora;
    char *hora2;
    char *nombre;
    nombre = "tmp2";
    double compare2;
    int nombress;

    hora = "1992-18-10 10:21:33";
    strptime(hora, "%Y-%d-%m %H:%M:%S", &ts2);
    ts3 = &ts2;
    setNombre(tmp, "tmp1");
    setF(tmp, ts3);

    hora2 = "1995-18-10 10:21:33";
    setNombre(tmp2, "tmp");
    strptime(hora2, "%Y-%d-%m %H:%M:%S", &ts4);
    ts3 = &ts4;
    setF(tmp2, ts3);
    setT(tmp, 100);
    setT(tmp2, 200);

    compare2 = compareF(tmp2, tmp);
    nombress = compareN(tmp, tmp2);

    if (nombress != 0) {
        printf("Los nombres son distintos\n");

    } else {
        printf("los nombres son iguales\n");

    }
    int comparar = compare(tmp2, tmp);
    if (comparar == 0) {
        printf("Los archivos son iguales\n");
    } else {
        printf("Los archivos son distintos \n");
        if (comparar == 1) {
            printf("El archivo %s, es mas actual\n", tmp2->nombre);
        }
        if (comparar == 2) {
            printf("El archivo %s, es el mas actual\n", tmp->nombre);
        }
    }
    
    //

    setN(tmp, tmp2);
    setP(tmp2, tmp);

    //printf ("%s\n",tmp->next->nombre);
    //printf ("%s\n",tmp2->prev->nombre);





}

**/