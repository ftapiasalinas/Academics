#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

int sockUDP()
{
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0)
	{
		printf("Error creating UDP socket..\n");
		exit(1);
	}
	return sock;
}

int isSubString(const char* s1, const char* s2)
{      
	char* retCmp = strstr(s1, s2);
	if(retCmp==NULL)
		return 0;
	return 1;
}

int areSame(char* s1, char* s2)
{
	if(s1==NULL && s2==NULL)
		return 1;
	if(s1==NULL || s2==NULL) //only one of s1 and s2 can be NULL at this point
		return 0;
	while(*s1!='\0' && *s2!='\0')
	{
		if(*s1!=*s2)
			return 0;
		s1++;
		s2++;
	}
	if(*s1!='\0' || *s2!='\0')
		return 0;
	
	return 1;
}

void sendFile(int sock, char* filename, struct sockaddr_in cliAdd)
{
	FILE* filepointer;
	char path[100] = "\0";
	strcpy(path, "/host/academia/CompNet/labs/lab5/Server/Share/");
	strcat(path, filename);
	char buffer[20] = "\0";
	char character;

	filepointer = fopen(path, "r");
	if(filepointer==NULL)
	{	
		printf("cant open %szzzz\n",path);
	}

	int i=0, retSend;
	
	while (fgets(buffer, sizeof(buffer), filepointer)) 
	{
		retSend = sendto(sock, buffer, sizeof(buffer), 0 ,(struct sockaddr*)&cliAdd, sizeof(struct sockaddr_in));
		bzero(buffer, sizeof(buffer));
	}
	
	fclose(filepointer);
}

void sendQueryResponse(int sock, int queryId, char* keyword, struct sockaddr_in cliAdd)
{
	//printf("Keyowrld : reacedL %s\n", keyword);
	
	FILE* sharedFiles = fopen("/home/pravin/shared_list", "r");
		
	char record[20], response[150] = "\0";
	int hit = 0;
	sprintf(response, "BPGC\tQueryHit\r\nQueryID: %d\nQueryWord: %s\r\n", queryId, keyword);
	
	while(fgets(record, sizeof(record), sharedFiles))
	{
		record[strlen(record)] = '\0';
	
	
		if(isSubString(record, keyword))
		{
			hit = 1;
			strcat(response, record);
		}
	}
	if(hit)
	{
                int retSend = sendto(sock, response, sizeof(response), 0 ,(struct sockaddr*)&cliAdd, sizeof(struct sockaddr_in));
                //printf("sent bytes in response : %d\n", retSend);
	}
	fclose(sharedFiles);
	printf("%s\n", response);
}

void processMsg(int sock, char* msg, struct sockaddr_in cliAdd)
{
	char* firstLine = strtok(msg, "\n"), *filename, *line;
	
	if(areSame(firstLine, "BPGC\tQuery\r"))
	{
		int queryId = atoi((strstr(strtok(NULL, "\n"), " ") + 1));
		char* keyword = strstr(strtok(NULL, "\n"), " ") + 1;
		sendQueryResponse(sock, queryId, keyword, cliAdd);
	}
	else if(areSame(firstLine, "BPGC\tDownload\r"))
	{
		printf("resolved: download\n");
		strtok(NULL, "\n");
		line = strtok(NULL, "\n");
		line[strlen(line)] = '\0';
                filename = strstr(line, ": ") + 2;
                filename[strlen(filename)-1] = '\0';
                sendFile(sock, filename, cliAdd);
        
	}
	else if(areSame(firstLine, "BPGC\tACK\r"))
	{
	        
		printf("resolved: ack\n");
	}
	
}


int main()
{
	int sock = sockUDP(), fromLen = sizeof(struct sockaddr);
	char message[100];
		
	struct sockaddr_in serverAdd, cliAdd;
	bzero(&serverAdd, sizeof(serverAdd));
	bzero(&cliAdd, sizeof(cliAdd));
	
	inet_aton("127.0.0.1", &(serverAdd.sin_addr));
	serverAdd.sin_port = htons(30000);
	serverAdd.sin_family = AF_INET;
	
	
	if(bind(sock, (struct sockaddr*)&serverAdd, sizeof(serverAdd)) < 0)
	{
		printf("Error -- binding the socket\n");
		exit(1);
	}
	
	while(1)
	{
	        int retRec = recvfrom(sock, message, sizeof(message), 0, (struct sockaddr*)&cliAdd, &fromLen);
	        if(retRec <= 0)
	        {
		        printf("Error -- Receiving message\n");
		        exit(1);
	        }
	
	        processMsg(sock, message, cliAdd);
	
	        bzero(message, sizeof(message));
	}
}
