#include "verificador.h"

int main(int argc, char *argv[]) {

    //Parser de los argumentos

    int i = 1;

    int t = 1;
    int d = 1;
    int a = 1;

    char *nombre_prog = argv[0];

    int seg_esp = 3;
    char *dir_trabajo = NULL;
    char *archivo_trabajo = NULL;

    if (argc < 2) {
        printf(
                "uso: %s [-t <num_segundos>][-d <directorio>][-a <archivo.txt>]\n",
                nombre_prog
                );
        exit(1);
    }

    while (i < argc) {

        if (strcmp(argv[i], "-t") == 0 && i + 1 < argc &&
                strcmp(argv[i + 1], "-d") != 0 && strcmp(argv[i + 1], "-a") != 0 &&
                strcmp(argv[i + 1], "-t") != 0 && t) {

            seg_esp = atoi(argv[++i]);

            if (strcmp(argv[i], "0") != 0 && seg_esp == 0) {
                printf("%s \n", "el argumento de -t debe ser entero");
                exit(1);
            };

            t = 0;

        } else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc &&
                strcmp(argv[i + 1], "-d") != 0 && strcmp(argv[i + 1], "-a") != 0 &&
                strcmp(argv[i + 1], "-t") != 0 && d) {

            dir_trabajo = argv[++i];
            d = 0;

        } else if (strcmp(argv[i], "-a") == 0 && i + 1 < argc &&
                strcmp(argv[i + 1], "-d") != 0 && strcmp(argv[i + 1], "-a") != 0 &&
                strcmp(argv[i + 1], "-t") != 0 && a) {

            archivo_trabajo = argv[++i];
            a = 0;

        } else {

            printf(
                    "uso: %s [-t <num_segundos>][-d <directorio>][-a <archivo.txt>]\n",
                    nombre_prog
                    );
            exit(1);

        }

        i++;
    }

    if (dir_trabajo != NULL) {
        char *host;
        Lista *ld = newLista();
        List *l = newList();
        int sockfd;
        FILE *fd;
        addCaja(ld, newCaja(dir_trabajo));
        char key;
        while (1) {
            host = obtener_host(dir_trabajo);
            printf("Hacer el request: %s\n", dir_trabajo);
            sockfd = conneccion(host);
            fd = hacerrequest(sockfd, dir_trabajo);

            l = leerlinea(fd, l);
            setList(ld->prim, l);
            //
            if (stdin != NULL) {
                fscanf(stdin, "%c", &key);

                // s == 115 & S == 83
                if (key == 115 || key == 83) {

                    printf("Se cancelo la ejecucion del programa\n");
                    break;

                }

                // p == 112 & P == 80
                if (key == 112 || key == 80) {
                    printf("Se ha pausado el programa\n");
                    while (1) {
                        key = getchar();
                        // c == 99 & C = 67
                        if (key == 99 || key == 67) {

                            printf("Continua la ejecucion del programa\n");
                            break;
                        }
                    }
                }
            }
            //
            sleep(seg_esp);
        }


    } else if (dir_trabajo == NULL && archivo_trabajo != NULL) {
        FILE *fp;
        char result[FILENAME_MAX];
        Lista *lista = newLista();
        if ((fp = fopen(archivo_trabajo, "r")) == NULL) {
            printf("Error al abrir archivo\n");
            return 1;
        }
        while (fscanf(fp, " %s\n", result) != EOF) {
            //  printf("%s\n", result);
            addCaja(lista, newCaja(result));
        }
        Caja *aux = lista->prim;
        FILE *fd;
        char * path;
        int sockfd;
        char *host;
        int paso = 0;
        List *l;
        char key;
        while (1) {
            printf("%s\n", "inicio bucle infinito");
            if (paso == 0) {

                while (aux != NULL) {

                    printf("%s\n", aux->dominio);
                    l = newList();
                    host = obtener_host(aux->dominio);
                    sockfd = conneccion(host);
                    fd = hacerrequest(sockfd, aux->dominio);
                    aux->l = leerlinea(fd, l);
                    aux = aux->next;
                }
                paso = 1;
            } else {
                while (aux != NULL) {
                    l = aux->l;
                    printf("%s\n", aux->dominio);
                    //List *l = newList();
                    host = obtener_host(aux->dominio);
                    sockfd = conneccion(host);
                    fd = hacerrequest(sockfd, aux->dominio);
                    aux->l = leerlinea(fd, l);
                    aux = aux->next;
                }
            }

            aux = lista->prim;
            if (stdin != NULL) {
                fscanf(stdin, "%c", &key);

                // s == 115 & S == 83
                if (key == 115 || key == 83) {

                    printf("Se cancelo la ejecucion del programa\n");
                    break;

                }

                // p == 112 & P == 80
                if (key == 112 || key == 80) {
                    printf("Se ha pausado el programa\n");
                    while (1) {
                        key = getchar();
                        // c == 99 & C = 67
                        if (key == 99 || key == 67) {

                            printf("Continua la ejecucion del programa\n");
                            break;
                        }
                    }
                }
            }
            sleep(seg_esp);
        }

    }

}
