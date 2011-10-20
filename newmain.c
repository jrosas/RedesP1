/* 
 * File:   newmain.c
 * Author: leofaster
 *
 * Created on October 20, 2011, 12:03 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int numero;
    //while (1){
    numero = atoi(argv[1]);


    if (numero >= 100 && numero < 200) {

        printf("Error de informacion\n");
    }

    if (numero >= 200 && numero < 300) {
        if (numero != 200) {
            printf("RARO no hablar de el\n");
        } else {


            printf("Entro perfecto\n");
        }
    }
    if (numero >= 300 && numero < 400) {
        printf("Error de redireccion\n");
    }
    if (numero >= 400 && numero < 500) {
        printf("Error del cliente\n");
    }
    if (numero >= 500 && numero < 600) {
        printf("Error del server\n");
    }
    if (numero == 112) {
        // break;
    }
    // }
    return (EXIT_SUCCESS);
}

