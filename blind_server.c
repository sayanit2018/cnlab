#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define  SIZE 200  // arbitrary
int main(int argc, char *argv[])
{
 
  int sd,i,j,newd,n,k;
 
  char a[SIZE];
  socklen_t clen;
  char buffer[SIZE];
  socklen_t length;
  struct  sockaddr_in   server,client;    // An IPv4 address

 printf( "TCP-echo-server starting...\n" );

  sd = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
   if(sd== -1)
        {
          perror("sock-cell");
           exit(1);
        }
  server.sin_family = AF_INET;
  server.sin_port=htons(atoi(argv[2]));
  n = inet_aton( argv[1],&(server.sin_addr));
  n = bind( sd, (struct sockaddr *)&server,sizeof(server));
  n=listen(sd,5);
  clen=sizeof clen;
  newd=accept(sd, (struct sockaddr *)&client,&clen);
while (1){
         memset( buffer, '\0', SIZE );
        i=read (newd,buffer,SIZE);
        j=write(1,"recieved from client",20);
         printf("%s",buffer);
          write(newd,buffer,i);
     }
        return 0;
}
