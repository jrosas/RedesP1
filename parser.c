#include "parser.h"
#include <time.h>


int reti;
char msgbuf[100];

char *expr = "<a[ \t]+href=\"[^\"]+\">\([^<>]+)</a>[ \t]+\([0-3]?[0-9]-[A-Z][a-z]{2}-[0-9]{4}[ \t]+[0-2][0-9]:[0-5][0-9])[ \t]+\(-?|[0-9]*)";

char * subString(char* str, int start, int length) {
    //  printf("\n%i %i\n",start,length);
    int end = length - start;
    char *newString = (char *) malloc(end + 1 * sizeof (char));
    //int i, x = 0;
    bcopy(str + start, newString, end);
    //for(i = start ; i <= end; i++){
    //  newString[x++] = str[i];
    //}
    newString[end] = '\0';
    //printf("sdfjdfjlsdjsdljlfjsdlj%s\n",newString);
    return newString;
}

void* inicparser(regex_t *regex) {

 
    reti = regcomp(regex, expr, REG_EXTENDED);

    if (reti) {
        perror("no se pudo compilar la expresión regular");
        exit(1);
    }

 
    //return 
}

Nodo* lineaparser(char*linea, regex_t *regex) {
    Nodo* nodo = NULL;
    int numero;
    struct tm ts2;
    struct tm *ts3;
    
    regmatch_t machout[4];

    char *nombre = (char *) malloc(1024 * sizeof (char));
    char *fecha = (char *) malloc(1024 * sizeof (char));
    char *tamano = (char *) malloc(1024 * sizeof (char));

    
/* Ejecutar la expresion regular */
    reti = regexec(regex, linea, 4, machout, 0);
    

    if (!reti) {
      //  printf("%s\n", "Match");

        nombre = subString(linea, machout[1].rm_so, machout[1].rm_eo);
        fecha = subString(linea, machout[2].rm_so, machout[2].rm_eo);
        tamano = subString(linea, machout[3].rm_so, machout[3].rm_eo);
        nodo = newNodo(nombre);
        //hora = "1992-18-10 10:21:33";
        //26-Sep-2011 21:11
        //printf (" Fecha que entra! %s\n",fecha);
        setF(nodo,fecha);
           
           
        setT(nodo, atoi(tamano));

      //  printf("1 start=%i, end=%i, %s\n", machout[1].rm_so, machout[1].rm_eo, nombre);
      // printf("2 start=%d end=%d %s\n", machout[2].rm_so, machout[2].rm_eo, fecha);
       // printf("3 start=%d end=%d %s\n", machout[3].rm_so, machout[3].rm_eo, tamano);
    }
    else if (reti == REG_NOMATCH) {
       // puts("No match");
    } else {
        regerror(reti, regex, msgbuf, sizeof (msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }

    return nodo;

        

    
}
