#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>
#define SIZE 200 // arbitrary

int main(int argc, char *argv[])
{
int cd; // to be used as socket descriptor
int n,i,j;
char buffer[SIZE];
struct sockaddr_in client;
if( argc != 3 )
{
printf("Usage: %s server-address server-port \n", argv[0] );
exit(1);
}
cd = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
if( cd == -1 ) { perror("socket-call"); exit( 1 ); }

client.sin_family = AF_INET;
client.sin_port = htons( atoi(argv[2]) );

n = inet_aton( argv[1], &(client.sin_addr) );
n = connect( cd, (struct sockaddr *) &client,
sizeof(client) );
memset( buffer, '\0', SIZE );
i = read(cd, buffer, SIZE );
if( i == -1 ) { perror("read1"); exit(1); }
j = write( 1, buffer, i );
if( j == -1 ) { perror("write1"); exit(1); }
return 0;
}
