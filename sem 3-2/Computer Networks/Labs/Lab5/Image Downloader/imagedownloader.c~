#include<stdio.h>
#include<stdlib.h>
#include <netdb.h>
#include<sys/socket.h>
#include <string.h>

#define USERAGENT "HTMLGET 1.0"

int createTcpSocket();
int closeSocket(int);
void assignAddressToSocket(int,struct sockaddr_in*,int ,char*);
void connectSocket(int sockid,struct sockaddr* serverAddress,int addressLength);
void getDomainName(char * string,char temp[],char *page);
void getHostIP(char domainname[],struct hostent**);
char *build_get_query(char *host, char *page);
void sendQuery(int sockid,char* query);
void fetchHtmlPage(int sockid,char buffer[]);
int main()
{
    char url[200];
    char buf[BUFSIZ+1];

    int port = 80;

    struct sockaddr_in serverAddress;
    struct hostent* dnsResolved;
    printf("Enter the url to acces the images from\n");
    printf("Ex: http://www-archive.mozilla.org/quality/networking/testing/datatests.html\n");
    scanf("%s",url);
    printf("length of url is %d\n",strlen(url));
    char domainname[strlen(url)];
    char *page = (char *)malloc(strlen(url));
    //puts(url);
    getDomainName(url,domainname,page);
    printf("The domain name is %s\n",domainname);
        
    char *ip = (char *)malloc(strlen(url));
    char *isDomainName = strstr(domainname, "www");
    if(isDomainName != NULL)
    {
        getHostIP(domainname,&dnsResolved);
        ip = (char *)inet_ntoa(dnsResolved->h_addr_list[0]);//"127.0.0.1";
        printf("the Ip is %s\n",inet_ntoa(dnsResolved->h_addr_list[0]));
    }
    else
    {
        ip = domainname;
    }

    int sockid = createTcpSocket();
    assignAddressToSocket(sockid,&serverAddress,port,"127.0.0.1");

    connectSocket(sockid,(struct sockaddr *) &serverAddress,(int)sizeof(serverAddress));
    char *getQuery = build_get_query(ip,page);
    sendQuery(sockid,getQuery);
    fetchHtmlPage(sockid,buf);

    int status = closeSocket(sockid);    
    
    return 0;
    
}
void fetchHtmlPage(int sockid,char buffer[])
{
    int received;
    while(received = recv(sockid,buffer,BUFSIZ,0)>0)
    {
        printf("No of Bytes received is %d\n",received);
        puts(buffer);
    }
    
}
void sendQuery(int sockid,char* getQuery)
{
    int sent = 0;
	while(sent < strlen(getQuery))
	{
		int tmpres = send(sockid, getQuery+sent, strlen(getQuery)-sent, 0);	
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
void getHostIP(char domainname[],struct hostent** dnsResolved)
{
//    printf("here resolving dns\n");
    (*dnsResolved) = gethostbyname(domainname);
    //printf("the ip is %s\n",(*dnsResolved)->h_name);
    if(dnsResolved == NULL)
    {   
        printf("Error in resolving DNS\n");
        exit(1);
    }
  //  printf("dns resolved\n");
}

void getDomainName(char * string,char temp[],char *page)
{
    //char temp[strlen(string)];
    int index = 0;
    char *start = strstr(string,"//");
    char *end = NULL;
    
    if(start!=NULL)
    {
        printf("found //\n");
        start +=2; 
    }
    else
    {
        printf("start is null\n");
        start = string;
    }
    end = strstr(start,"/"); 
    if(end == NULL)
    {
        printf("end is NULL\n");
        end = start + strlen(start) -1;
    }
    else
    {
        printf("end is not null\n");
        end--;
    }
    while(start <= end)
    {
        //printf("writing %c\n",*start);
        temp[index] = *start;
        start++;
        index++;
    }
    temp[index] = 0;

    if(*(end +1 ) == '\0')
    {
        strcpy(page,"/");
    }
    else
    {
        strcpy(page,end+1);
    }
    printf("%s",page);
}
void connectSocket(int sockid,struct sockaddr* serverAddress,int addressLength)
{
    int status = connect(sockid,serverAddress,addressLength);
    if(status == -1)
    {
        printf("Error in connecting \n");
        exit(-1);
    }
    else
        printf("connection succesfully established !!!\n");

}
void assignAddressToSocket(int sockid,struct sockaddr_in* serverAddress,int port,char* ip) 
{
    (*serverAddress).sin_family=AF_INET;
	(*serverAddress).sin_port=htons(port);
 	(*serverAddress).sin_addr.s_addr = inet_addr (ip);
}
int closeSocket(int sockid)
{
    int status = close(sockid);
    if(status == -1)
    {
        printf("error in closing socket \n");
        exit(1);
    }
    else
        return status;
}
int createTcpSocket()
{
    int sockid = socket(AF_INET,SOCK_STREAM,0);
    if(sockid == -1)
    {
        printf("Error in tcp socket creation\n");
        exit(1);
    }
    else
        return sockid;
}



