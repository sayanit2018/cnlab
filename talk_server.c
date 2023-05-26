#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SIZE 200 // arbitrary
#define PORT 8000
int main(int argc, char *argv[])
{
int sd,i,newd,n,k;

char a[SIZE];
char buffer[SIZE];
socklen_t length;
struct sockaddr_in server; // An IPv4 address

printf( "TCP-echo-server starting...\n" );
sd = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
server.sin_family = AF_INET;
server.sin_port=htons(PORT);
server.sin_addr.s_addr = htonl( INADDR_ANY );
n = bind( sd, (struct sockaddr *)&server,sizeof(server));
n=listen(sd,1);

while (1){
newd=accept(sd,NULL,0);
write(newd,buffer,sizeof(buffer));
while(1){
memset( buffer, '\0', SIZE);
n=read(newd,buffer,SIZE);
if( strstr( buffer, "quit" ) != NULL) break;
write(1,"From client:",12);
write(1,buffer,n);
write(1,"TO client:",10);
memset( buffer, '\0', SIZE);
n=read(0,buffer,SIZE);
write(newd,buffer,n);
}
}
return 0;
}
/// to  run this code write(   cc  your file name -o as)  then  type   ./as      /////// 
   //// then run client  write  (   cc your file name -o aa ) then type ./aa yourip address  and 8000     /////
       ///   then  again type your ip  and port 8000 ///// 
