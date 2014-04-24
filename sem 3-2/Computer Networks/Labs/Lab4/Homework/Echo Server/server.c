#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 4096
 
int main()
{
    char str[MAX_LEN];
    int server_fd, client_fd;
 
    struct sockaddr_in serveraddr;
 
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
 	if(server_fd < 0)
	{
		perror("problem in creating socket...");
		exit(1);
	}
	
    bzero( &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
    serveraddr.sin_port = htons(22000);
 
    if(bind(server_fd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
    {
    	perror("bind failed");
    	exit(1);
    }
 	
 	
    if(listen(server_fd, 10) < 0)
    {
    	perror("listen failed");
    	close(server_fd);
    	exit(2);
    }
	
	
	 
	printf("\n");
/*    while(1)
    {
    	bzero( str, MAX_LEN);
        read(client_fd,str,MAX_LEN);
         			
        printf("Echoing back - %s",str);
        write(client_fd, str, strlen(str)+1);
    }
*/    
    while(1)
    {
    	if((client_fd = accept(server_fd, (struct sockaddr*) NULL, NULL)) < 0)
	   	{
   			perror("accept failed...");
   			close(server_fd);
   			exit(3);
   		}
   		
   		bzero( str, MAX_LEN);
   		int count;
   		while(count = read(client_fd,str,MAX_LEN))
   		{
   			printf("Echoing back - %s",str);
        	write(client_fd, str, strlen(str)+1);
        	bzero( str, MAX_LEN);
   		}
   		
    }
    
    close(server_fd);
    close(client_fd);
}
