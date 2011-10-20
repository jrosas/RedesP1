#include "parser.h"

regex_t regex;
regmatch_t machout[4];
int reti;
char msgbuf[100];

char *expr="<a[ \t]+href=\"[^\"]+\">\([^<>]+)</a>[ \t]+\([0-3]?[0-9]-[A-Z][a-z]{2}-[0-9]{4}[ \t]+[0-2][0-9]:[0-5][0-9])[ \t]+\(-?|[0-9]*)";

regex_t inicparser(){

  reti = regcomp(&regex,expr,REG_EXTENDED);
  if( reti ){
    perror("no se pudo compilar la expresión regular");
    exit(1);
  }

  // return regex;
}


Nodo* lineaparser(regex_t regex,char*linea){

  /* Ejecutar la expresion regular */
  reti = regexec(&regex,linea, 4,machout, 0);
  Nodo* nodo=NULL;
  
  if( !reti ){
  
    nodo=newNodo("hola");
    //puts("Match");
  
    printf("start=%d end=%d\n",machout[0].rm_so,machout[0].rm_eo);
    printf("start=%d end=%d\n",machout[1].rm_so,machout[1].rm_eo);
    printf("start=%d end=%d\n",machout[2].rm_so,machout[2].rm_eo);
    printf("start=%d end=%d\n",machout[3].rm_so,machout[3].rm_eo);
  }
  else if( reti == REG_NOMATCH ){
    puts("No match");
  }
  else{
    regerror(reti, &regex, msgbuf, sizeof(msgbuf));
    fprintf(stderr, "Regex match failed: %s\n", msgbuf);
    exit(1);
  }

  return nodo;
}
