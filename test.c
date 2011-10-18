#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <strings.h>
#include <fcntl.h>

#define PORT 80

char * get_host(char* directory){
  strtok(directory, "/");
  return (char *) strtok(NULL, "/");
}

main(int argc, char *argv[]) {


  int sockfd;
  int error;

  struct sockaddr_in serveraddress;
  struct hostent *server;

  char *host;

  //char *server = "74.125.113.105";
  //  char *server = "159.90.9.202";
  //char *server = "159.90.10.9";
  //  char *request = "GET";
  //          GET /~rgonzalez/ci4835/taller/proy1/dir1/ HTTP/1.1
  char *request = "GET /~jrosas/ HTTP/1.0\r\nhost:cancer.ac.usb.labf.usb.ve \r\n\r\n";
  char *response;

  int seg_wait=30;
  char *work_dir_name=NULL;
  char *work_file_name=NULL;

// Parse the arguments

  char *program_name=argv[0];

  int i = 1;

  while (i<argc){

    if( strcmp(argv[i],"-t") == 0 && i+1 <argc &&
        strcmp(argv[i+1],"-d")!= 0 && strcmp(argv[i+1],"-a")!= 0 &&
        strcmp(argv[i+1],"-t")!= 0 ) {

      seg_wait = atoi(argv[++i]);
      if ( strcmp(argv[i],"0") != 0 && seg_wait == 0 ){
          printf("%s \n","-t argument must be a integer");
          exit(1);
        };

    } else if( strcmp(argv[i],"-d") == 0 && i+1<argc &&
               strcmp(argv[i+1],"-d") != 0 && strcmp(argv[i+1],"-a") != 0 &&
               strcmp(argv[i+1],"-t") != 0 ) {

      work_dir_name = argv[++i];

    } else if( strcmp(argv[i],"-a") == 0 && i+1<argc &&
               strcmp(argv[i+1],"-d") != 0 && strcmp(argv[i+1],"-a") != 0 &&
               strcmp(argv[i+1],"-t") != 0 ) {

      work_file_name = argv[++i];

    }else{

      printf(
             "usage: %s [-t <seg_number>] [-d <directory>][-a <file.txt>]\n",
             program_name
             );
      exit(1);

    }

    i++;
  }

  printf("%s \n",work_dir_name);
  host=get_host(work_dir_name);
  //  response=(char *)strtok(NULL, "/");

  printf("%s \n",host);

  server = gethostbyname(host);

  if (server == NULL) {
    printf("%s \n","ERROR, no such host");
    exit(0);
  }

   response = (char *)malloc(4000*sizeof(char)); 

  bzero(&serveraddress, sizeof(serveraddress));
  serveraddress.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
        (char *)&serveraddress.sin_addr.s_addr,
        server->h_length);
  serveraddress.sin_port = htons(PORT);

  /* printf("%s \n", "1"); */

  /* Open a socket. */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0){
    printf("%s \n", "can't open socket");
    //  fatalerror("can't open socket");
  }

  /* Connect to the server. */
  error = connect(sockfd, (struct sockaddr *) &serveraddress,
                  sizeof(serveraddress));

  if(error < 0){
    printf("%s \n","can't connect to server");
    //fatalerror
  }
  printf("%s \n", "2");

  error=write(sockfd,request,400);

  if(error < 0){
    printf("%s \n","error writing in the socket");
    //fatalerror
  }
  printf("%s \n", "3");
  bzero(response,sizeof(response));
  error=read(sockfd,response,4000);
  if(error < 0){
    printf("%s \n","error reading from socket");
    //fatalerror
  }
  printf("%s \n", "4");
  printf("%s",response);
  printf("%s \n", "5");
  /* //copy(sockfd); */
  /* //close(sockfd); */



}
