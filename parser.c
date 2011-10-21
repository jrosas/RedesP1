/**
 *Programa parser usado como parte auxiliar del verificador de directorios
 */
#include "parser.h"
#include <time.h>

int reti;
char msgbuf[100];

char *expr = "<a[ \t]+href=\"[^\"]+\">\([^<>]+)</a>[ \t]+\([0-3]?[0-9]-[A-Z][a-z]{2}-[0-9]{4}[ \t]+[0-2][0-9]:[0-5][0-9])[ \t]+\(-?|[0-9]*)";
/**
 * Funcion que obtiene el substring del string dado
 * @param str apuntador al string a seccionar
 * @param start punto de inicio del substring
 * @param length fin del substring
 * @return  un nuevo substring
 */
char * subString(char* str, int start, int length) {

    int end = length - start;
    char *newString = (char *) malloc(end + 1 * sizeof (char));

    bcopy(str + start, newString, end);

    newString[end] = '\0';

    return newString;
}

/**
 * Procedimiento que inicializa el parser
 * @param regex Expresion regular a inicializar
 */
void* inicparser(regex_t *regex) {

    reti = regcomp(regex, expr, REG_EXTENDED);

    if (reti) {
        perror("no se pudo compilar la expresión regular");
        exit(1);
    }

}
/**
 * Funcion que parsea una linea de html buscando el formato dado
 * @param linea Linea a parsear
 * @param regex expresion regular a buscar en la linea
 * @return 
 */
Nodo* lineaparser(char*linea, regex_t *regex) {
    Nodo* nodo = NULL;
    int numero;
    struct tm ts2;
    struct tm *ts3;

    regmatch_t machout[4];

    char *nombre = (char *) malloc(1024 * sizeof (char));
    char *fecha = (char *) malloc(1024 * sizeof (char));
    char *tamano = (char *) malloc(1024 * sizeof (char));

    reti = regexec(regex, linea, 4, machout, 0);


    if (!reti) {


        nombre = subString(linea, machout[1].rm_so, machout[1].rm_eo);
        fecha = subString(linea, machout[2].rm_so, machout[2].rm_eo);
        tamano = subString(linea, machout[3].rm_so, machout[3].rm_eo);
        nodo = newNodo(nombre);

        setF(nodo, fecha);

        setT(nodo, atoi(tamano));


    } else if (reti == REG_NOMATCH) {
    } else {
        regerror(reti, regex, msgbuf, sizeof (msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    return nodo;

}
