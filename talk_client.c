#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define BUFFERSIZE 200 // arbitrary
int main(void)
{
int cd,i,n,j;
char buffer[BUFFERSIZE];
struct sockaddr_in client; // An IPv4 address
int port;
char address[20];
write( 1,"IP address of server ? ", 23 );
scanf( "%s", address );
write( 1,"port number of server ? ", 24 );

scanf("%u", &port );
printf( "TCP-echo-client starting...\n" );

cd = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
client.sin_family = AF_INET;
client.sin_port=htons(port);
n = inet_aton( address,&(client.sin_addr));
n=connect(cd,(struct sockaddr *)&client,sizeof(client));
while (1){

memset( buffer, '\0', BUFFERSIZE );
n = read(cd,buffer,BUFFERSIZE);
write (1,"from Server:", 12);

write(1,buffer,n);
write (1,"\nto server:",11);
memset( buffer, '\0', BUFFERSIZE );
n = read(0,buffer,BUFFERSIZE);
write(cd,buffer,n);
if(strstr(buffer,"quit")) break;
}
return 0;
}
