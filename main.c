#include "verificador.h"

int main(int argc,char *argv[]){

  //Parser de los argumentos

  int i=1;

  int t=1;
  int d=1;
  int a=1;

  char *nombre_prog=argv[0];

  int seg_esp=30;
  char *dir_trabajo=NULL;
  char *archivo_trabajo=NULL;

  while (i<argc){

    if( strcmp(argv[i],"-t") == 0 && i+1 <argc &&
        strcmp(argv[i+1],"-d")!= 0 && strcmp(argv[i+1],"-a")!= 0 &&
        strcmp(argv[i+1],"-t")!= 0 && t)
      {

        seg_esp = atoi(argv[++i]);

        if ( strcmp(argv[i],"0") != 0 && seg_esp == 0 ){
          printf("%s \n","el argumento de -t debe ser entero");
          exit(1);
        };
        
        t=0;

      } else if( strcmp(argv[i],"-d") == 0 && i+1<argc &&
                 strcmp(argv[i+1],"-d") != 0 && strcmp(argv[i+1],"-a") != 0 &&
                 strcmp(argv[i+1],"-t") != 0 && d) {

      dir_trabajo = argv[++i];
      d=0;

    } else if( strcmp(argv[i],"-a") == 0 && i+1<argc &&
               strcmp(argv[i+1],"-d") != 0 && strcmp(argv[i+1],"-a") != 0 &&
               strcmp(argv[i+1],"-t") != 0 && a) {

      archivo_trabajo = argv[++i];
      a=0;

    }else{

      printf(
             "uso: %s [-t <num_segundos>][-d <directorio>][-a <archivo.txt>]\n",
             nombre_prog
             );
      exit(1);

    }

    i++;
  }
  /*
  printf("%s\n",nombre_prog);
  printf("%i\n",seg_esp);
  printf("%s\n",dir_trabajo);
  printf("%s\n",archivo_trabajo);
  */
  if(dir_trabajo!=NULL){
    // char *host=(char*)malloc(sizeof(char)*2048);
    char *host;
    int sockfd;
    FILE *fd;
    //char * path;
    printf("Hacer el request: %s\n",dir_trabajo);
    host=obtener_host(dir_trabajo);
    printf("Hacer el request: %s\n",dir_trabajo);    
    //strtok(dir_trabajo, "/");
    //host=(char*)strtok(NULL, "/");
    printf("Hacer el request: %s\n",host);
    sockfd=conneccion(host);
    fd=hacerrequest(sockfd,dir_trabajo);
    
    leerlinea(fd);
  }

  else if(dir_trabajo==NULL ) {    
  }

}
