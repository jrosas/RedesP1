#include <sys/types.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "lista.h"
#include "nodo.h"

#ifndef PARSER  
#define PARSER
void* inicparser(regex_t *regex);
Nodo* lineaparser(char*linea,regex_t *regex);
//Nodo* lineaparser(char*linea,regex_t regex);
//regex_t inicparser(regex_t regex);
#endif
