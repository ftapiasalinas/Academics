#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 4096
 
int main(int argc,char **argv)
{
    int socket_fd,n;
	char *sendtext = malloc(MAX_LEN);
	char *recvtext = malloc(MAX_LEN);
    struct sockaddr_in serveraddr;
 
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0)//-1
	{
		perror("problem in creating socket...");
		exit(1);
	}
    
    bzero(&serveraddr, sizeof(serveraddr));//memset
 
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(22000);
 	serveraddr.sin_addr.s_addr = inet_addr ("127.0.0.1");
 
    int flag = connect(socket_fd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
 	if(flag < 0)
	{
		perror("problem in connecting to server...");
		exit(3);
	}
	
    while(1)
    {
        bzero( sendtext, MAX_LEN);
        bzero( recvtext, MAX_LEN);
        printf("\nenter message: ");
        
        fgets(sendtext, MAX_LEN, stdin); /*stdin = 0 , for standard input */
 		
 		write(socket_fd,sendtext,MAX_LEN);//send
        read(socket_fd,recvtext,MAX_LEN);//recv
        printf("server reply: %s",recvtext);
    }
    printf("TERMINATED...\n");
    close(socket_fd);
	return 0;
 
}
