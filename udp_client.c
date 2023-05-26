#include    <stdio.h>
#include    <unistd.h>
#include    <stdlib.h>
#include    <string.h>
#include    <sys/socket.h>
#include    <arpa/inet.h>

#define     SIZE    512   



int main( int argc, char *argv[])
{
  int  cd;   // to be used as socket descriptor
  int  n;    
  ssize_t                i;       
  char                   buffer[SIZE];  
  struct   sockaddr_in   server, client;    
    socklen_t  len;
    socklen_t  len1;
	if( argc != 5 )
  {
    printf("usage -> prog-name  server-address  server-port \n");
    printf("example -> %s 192.168.5.58  7 \n", argv[0] );
    exit(1);
  }


  cd=socket( AF_INET,SOCK_DGRAM,IPPROTO_UDP);

  if( cd == -1 )  { perror("socket-call"); exit(1); }
  
//initializing the members of local address
  client.sin_family = AF_INET;
    n = inet_aton( argv[3], &(client.sin_addr));
  if( n == 0 ) { perror("invalid-address"); exit(1); }
  client.sin_port = htons(atoi(argv[4]));
  
  n = bind(cd,(struct sockaddr *) &client,sizeof(struct sockaddr));
  if( n == -1 ) { perror("bind-call"); exit(1); }
  
  //initializing the members of remote address
  server.sin_family = AF_INET;
  n = inet_aton( argv[1], &(server.sin_addr));
  if( n == 0 ) { perror("invalid-address"); exit(1); }
  server.sin_port = htons(atoi(argv[2]));
     while(1){
  write(1,"Enter a string: ", 16 );
  memset( buffer, '\0', SIZE );
  i = read(0, buffer, SIZE );

len=sizeof(struct sockaddr);
  n = sendto( cd, buffer, i, 0, (struct sockaddr *)&server,len);
  if( n == -1 ) { perror("sendto-call"); exit(1); }

   memset( buffer, '\0', SIZE );

     len1 = sizeof(struct sockaddr);
     n = recvfrom( cd, buffer,SIZE,0,(struct sockaddr *)&server,&len1);
     if( n == -1 ) { perror("recvfrom-call-full"); exit(1); }  
  write( 1, "From server->", 13 );
  write( 1, buffer, n );
}
  //shutdown( cd, SHUT_RDWR );

  return 0;
}
