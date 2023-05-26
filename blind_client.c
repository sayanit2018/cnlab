#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define  BUFFERSIZE 200  // arbitrary


int main(int argc, char *argv[])
{
 
  int cd,i,n,j;
  char buffer[BUFFERSIZE];  
  struct  sockaddr_in   client;    // An IPv4 address

  cd = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
  if( cd == -1)
     {
      perror("socket-cell");
       exit(1);
      }  

  client.sin_family = AF_INET;
  client.sin_port=htons(atoi(argv[2]));

  n = inet_aton( argv[1],&(client.sin_addr));
  n=connect(cd,(struct sockaddr *)&client,sizeof(client));
while (1){
         write (1,"Enter the string.",17);
         memset( buffer, '\0', BUFFERSIZE );
        i=read (0,buffer,BUFFERSIZE);
        printf( "bytes read from keyboard=%u\n", i );
        j=write(cd,buffer,i);
printf("bytes written in server's socket=%u\n",j);

       memset( buffer, '\0', BUFFERSIZE );
        i= read(cd,buffer,BUFFERSIZE);
        write(1,"reply from echo server",17);
        write(1,buffer,i);
}
        return 0;
}
// while(1){
  //   write(1,"enter the string:17);
    // menset(buffer,'\0',size);
    // i= read(0,buffer,size
