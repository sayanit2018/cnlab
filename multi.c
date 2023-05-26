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
  
  int sd,i,newd,n,k; 
  //
//  char a[SIZE];
  char buffer[SIZE]; 
  socklen_t length;
  struct  sockaddr_in   server,client;    // An IPv4 address

  printf( "TCP-echo-server starting...\n" );

  // A TCP (IPv4 stream) socket is created
  sd = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
  

  server.sin_family = AF_INET;
  server.sin_port=htons(atoi(argv[2]));
  n = inet_aton( argv[1],&(server.sin_addr));
  n = bind( sd, (struct sockaddr *)&server,sizeof(server));
  n=listen(sd,20);
  length=sizeof(client);
while(1){
  newd=accept(sd, (struct sockaddr *)&client,&length);
 printf("client ip address is <%s>\n",inet_ntoa(client.sin_addr));
            printf("client port is <%d>\n",ntohs(client.sin_port));
 
  pid_t pid = fork();
  if(pid == 0){
while (1){
	 n=read(newd,buffer,SIZE);
	write(1,"Received from client:",20);
       printf("%s\n",buffer);
	 write(newd,buffer,n);
    }
}
}
}
//// client file name is  client.c////
