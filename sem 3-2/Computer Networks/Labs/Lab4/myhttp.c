#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 80
#define USERAGENT "HTMLGET 1.0"

int create_tcp_socket()
{
	int sock;
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Can't create TCP socket");
		exit(1);
	}
	return sock;
}

char *build_get_query(char *host, char *page)
{
	char *query;
	char *getpage = page;
	char *tpl = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
	if(getpage[0] == '/')
	{
		getpage = getpage + 1;
		fprintf(stderr,"Removing leading \"/\", converting %s to %s\n", page, getpage);
	}
	
	// -5 is to consider the %s %s %s in tpl and the ending \0
	query = (char *)malloc(strlen(host)+strlen(getpage)+strlen(USERAGENT)+strlen(tpl)-5);
	sprintf(query, tpl, getpage, host, USERAGENT);
	return query;
}

int main()
{	
    system("base64 -d base64imge > image.png");
	//char *page;
	char buf[BUFSIZ+1];
	int sock = create_tcp_socket();
	char *ip = "124.124.252.106";//"127.0.0.1";
	struct sockaddr_in serveraddr;
	printf("enter the port ");
	int port = 80;
//	scanf("%d",&port);
	
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(port);
 	serveraddr.sin_addr.s_addr = inet_addr (ip);

	int flag = connect(sock,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	printf("the status returned was %d\n",flag);
 	if(flag < 0)
	{
		perror("problem in connecting to server...");
		exit(3);
	}
	else
	{
	printf("succesfully connected to server\n");
	}
	
	char *page = "https://p.imgci.com/db/PICTURES/CMS/181100/181189.jpg";//"index.html";
	char *get = build_get_query(ip, page);
	//puts(get);

	int sent = 0;
	while(sent < strlen(get))
	{
		int tmpres = send(sock, get+sent, strlen(get)-sent, 0);	
		if(tmpres == -1)
		{
			perror("Can't send query");
			exit(1);
		}
		else
		{
			printf("query sent to server succesfully\n");
		}
		sent += tmpres;
	}

	memset(buf, 0, sizeof(buf));
	int tmpres;
	int htmlstart = 0;
    char * htmlcontent;
    while((tmpres = recv(sock, buf, BUFSIZ, 0)) > 0)
	{
		puts(buf);
		htmlcontent = strstr(buf, "<body>");
		char *bodyend = strstr(buf, "</body>");
		int i=0;
		htmlcontent += 6;	
		if(htmlcontent != NULL)
		{	
				printf("the html content is \n");
			while(i<(bodyend-htmlcontent))
			{
				printf("%c",htmlcontent[i]);
				i++;
			}
		}
		char *date = strstr(buf,"Date:");
		if(date != NULL)
		{
			printf("the last modification date is :");
			date = date +5;
			date[30] = '\0';
			puts(date);
		}
	
		memset(buf, 0, tmpres);
	}
    if(tmpres < 0)
    {
    perror("Error receiving data");
    }
    close(sock);
    
    return 0;
}
