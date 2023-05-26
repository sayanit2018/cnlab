#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<time.h>
#define SIZE 200 // arbitrary
int main(int argc, char *argv[])
{
int sd,i,newd,n,k;
char a[SIZE];
time_t t,T;

char *time1;
char buffer[SIZE];
socklen_t length;
char date_string[25];
struct sockaddr_in server,client;
printf( "TCP-echo-server starting...\n" );
sd = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
server.sin_family = AF_INET;
length=sizeof(client);
newd=accept(sd, (struct sockaddr *)&client,&length);
server.sin_port=htons(atoi(argv[2]));
n = inet_aton( argv[1],&(server.sin_addr));
n = bind( sd, (struct sockaddr *)&server,sizeof(server));
n=listen(sd,5);
length=sizeof(client);
newd=accept(sd, (struct sockaddr *)&client,&length);
memset( buffer, '\0', SIZE );
T=time(&t);
printf("No of seconds=%lu\n",T);
time1=ctime(&t);
printf("string format %s\n",time1);
write(STDOUT_FILENO,"Seconds since Epoch using [date] command = ",
43 );
system("/bin/date +%s");
printf("before [ctime] call, Time zone = %s \n", *tzname );
// following statement copies, date and time in human readable
// form, in [date_string]
strcpy( date_string, ctime( &t) );
printf("after [ctime] call, Time zone = %s \n", *tzname );
i=strlen(time1);
write(newd,time1,i);
printf("after [ctime] call, Time zone = %s \n", *tzname );
printf("date by [ctime] call = %s \n", date_string );
return 0;
}
