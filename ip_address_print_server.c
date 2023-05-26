#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SIZE 200 // arbitrary
int main(int argc, char *argv[])
{
int sd,i,newd,n,k;
//
char a[SIZE];
char buffer[SIZE];
socklen_t length;
struct sockaddr_in server,client; // An IPv4 address
printf( "TCP-echo-server starting...\n" );
// A TCP (IPv4 stream) socket is created
sd = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
if( sd == -1)
  {
 perror("socketcall");
  exit(1);
  }   
server.sin_family = AF_INET;
server.sin_port=htons(atoi(argv[2]));
n = inet_aton( argv[1],&(server.sin_addr));

n = bind( sd, (struct sockaddr *)&server,sizeof(server));
n=listen(sd,5);
length=sizeof(client);
newd=accept(sd, (struct sockaddr *)&client,&length);
while (1){
//write (1,"Enter the string.",17);
memset( buffer, '\0', SIZE );
i=read (newd,buffer,SIZE);
write(1,"recive from client:",19);
printf("client ip address is <%s>\n",inet_ntoa(client.sin_addr));
printf("client port is <%d>\n",ntohs(client.sin_port));
  k=0;
  for(n=i-1;n>=0;n--){
      a[k++] =buffer[n];
}
 a[k]='\0';
write(newd,a,i);
}
return 0;
}
///     client is previous programs client means   file name tcp_echo_client_architechture////
