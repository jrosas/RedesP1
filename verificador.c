#include "verificador.h"

/*
  char* directorio: URL del Directorio que se desea verificar
  Funcion que recibe el directorio que se desea verificar y obtiene el host
 */

char * obtener_host(char* directorio) {
    char *aux = malloc(strlen(directorio));
    strcpy(aux, directorio);
    strtok(aux, "/");
    //free(aux);
    printf("%s", aux);
    return (char *) strtok(NULL, "/");

}

/*
  char* host:host con el que se desea establecer la conexion
  Funcion que establece la conexion y devuelve el numero de socket asociado.
 */
int conneccion(char* host) {

    int sockfd;
    int error;

    struct sockaddr_in serveraddress;
    struct hostent *server;

    server = gethostbyname(host);

    if (server == NULL) {
        printf("Host no disponible: %s\n", host);
        //PERROR;
    }

    //OJO SERVER ADDRESS
    bzero(&serveraddress, sizeof (serveraddress));

    serveraddress.sin_family = AF_INET;
    bcopy((char *) server->h_addr,
            (char *) &serveraddress.sin_addr.s_addr,
            server->h_length);
    serveraddress.sin_port = htons(PORT);

    /* Abrir el Socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("No se puede abrir el socket");
        //  fatalerror("can't open socket");
    }

    /* Connect to the server. */
    error = connect(sockfd, (struct sockaddr *) &serveraddress,
            sizeof (serveraddress));

    if (error < 0) {
        printf("No se puede establecer coneccion con: %s\n", host);
        //fatalerror
    }

    return sockfd;
}

FILE *hacerrequest(int sockfd, char *url) {

    FILE *fd = fdopen(sockfd, "w+");
    if (fd == NULL) {
        perror("No se puede abrir el descriptor de archivo");
        exit(1);
    }
    printf("GET %s HTTP/1.0 \r\n\r\n", url);
    fprintf(fd, "GET %s HTTP/1.0 \r\n\r\n", url);

    return fd;

}

List *leerlinea(FILE *fd, List *lArch) {
    char linea[2048];
    Nodo *nodo;
    regex_t *regex = malloc(sizeof (regex_t));
    int x = 0;
    int numero = 0;
    //regmatch_t machout[4];
    //List *lArch = newList();

    //  printf("aca2\n");
    inicparser(regex);

    while (fgets(linea, 1024, fd) != NULL) {
        //   printf("%s",linea);
        if (x == 0) {
            sscanf(linea, "HTTP/1.1 %d", &numero);
            x = 1;

        } else {
            if (numero >= 100 && numero < 200) {

                perror("Error de informacion\n");
            }

            if (numero >= 200 && numero < 300) {
                if (numero != 200) {
                    printf("RARO no hablar de el\n");
                } else {
                    nodo = lineaparser(linea, regex);
                    if (nodo != NULL) {
                        addNodo(lArch, nodo);
                    }

                }
            }
            if (numero >= 300 && numero < 400) {
                perror("Error de redireccion\n");
            }
            if (numero >= 400 && numero < 500) {
                perror("Error del cliente\n");
            }
            if (numero >= 500 && numero < 600) {
                perror("Error del server\n");
            }

        }
    }
    return lArch;
}

//08-10729
