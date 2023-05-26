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
int sd,i,newd,n,k,j;
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
      perror("sock-cell");
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
j=write(1,"recive from client:",19);

//k=0;
//for(n=i-1;n>=0;n--){
//a[k++]=buffer[n];
//}
//a[k]='\0';
printf("%s\n",buffer);
// printf (" \n After the reverse of a string: %s ",
//strrev(str));
write(newd,buffer,i);
//write(newd,a,i);
}
return 0;
}
