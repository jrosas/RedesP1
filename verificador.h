#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "lista.h"
#include "parser.h"


#ifndef VERIFICADOR
#define VERIFICADOR

#define PORT 80
char* obtener_host(char* directorio);
int conneccion(char* host);
FILE* hacerrequest(int sockfd,char *url);
List *leerlinea(FILE *fd,List *lArch);


#endif
