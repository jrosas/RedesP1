#include <sys/types.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
//#include "lista.h"
//#include "nodo.h"


Nodo* lineaparser(regex_t regex,char*linea);
regex_t inicparser();