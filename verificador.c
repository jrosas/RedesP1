#include "verificador.h"

/**
 *  Funcion que recibe el directorio que se desea verificar y obtiene el host
 * @param directorio del que se obter el dominio
 * @return el dominio del url pasado
 */
char * obtener_host(char* directorio) {
    char *aux = malloc(strlen(directorio));
    strcpy(aux, directorio);
    strtok(aux, "/");
    //free(aux);
    printf("%s", aux);
    return (char *) strtok(NULL, "/");

}

/**
 * Funcion que establece la conexion y devuelve el numero de socket asociado.
 * @param host con el que se desea establecer conexion
 * @return 
 */
int conneccion(char* host) {

    int sockfd;
    int error;

    struct sockaddr_in serveraddress;
    struct hostent *server;

    server = gethostbyname(host);

    if (server == NULL) {
        perror("Host no disponible: %s\n");
        //PERROR;
    }

    
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
        perror("No se puede establecer coneccion con: %s\n");
        //fatalerror
    }

    return sockfd;
}
/**
 * Funcion que estructura y realiza un request de http
 * @param sockfd socket mediante el cual se realizar el request
 * @param url pasado en el request despues del get
 * @return 
 */
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
/**
 * Fucion que lee linea a linea la respuesta del servidor y busca el patron 
 * deseado, al encontrarlo en lista, el archivo con sus datos respectivos 
 * @param fd filedescriptor donde se encuentra la respuesta del server
 * @param lArch lista de archivos donde se almacenaran los resultados
 * @return 
 */

List *leerlinea(FILE *fd, List *lArch) {
    char linea[2048];
    Nodo *nodo;
    regex_t *regex = malloc(sizeof (regex_t));
    int x = 0;
    int numero = 0;
    
    inicparser(regex);

    while (fgets(linea, 1024, fd) != NULL) {
        
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

