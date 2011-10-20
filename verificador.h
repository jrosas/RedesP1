#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "lista.h"
#include "parser.h"
//#include <string.h>
//#include <fcntl.h>

//#ifndef VERIFICADOR


#define PORT 80
char* obtener_host(char* directorio);
int conneccion(char* host);
FILE* hacerrequest(int sockfd,char *url);
void *leerlinea(FILE *fd);


//#endif
