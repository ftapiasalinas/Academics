#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>


int getRecordDetails(char* record, int* fileSize)
{
        char recId[10] = "\0", size[10] = "\0";
        int i=0, j;
        record[strlen(record)] = '\0';
        while(i<strlen(record))
        {
                if(record[i]==',')
                {        
                        i++;
                        j = 0;
                        while(record[i]!=',')
                                size[j++] = record[i++];
                        *fileSize = atoi(size);
                        return atoi(record + i + 1);
                }
                i++;
        }
}

int receiveFile(int sockfd, char* filename, int fileSize, struct sockaddr_in serverAdd)
{
        int retRecv, receivedBytes = 0, fromLen;
        char buffer[100], path[100] = "/home/sahil/";
        strcat(path, filename);
	bzero(buffer,sizeof(buffer));
        FILE* output = fopen(path, "w");
        
        if(output==NULL)
        {
                printf("Problem is opening the file\n");
                exit(1);
        }        
        while(receivedBytes < fileSize)
        {
                retRecv = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&serverAdd, &fromLen);
                //printf("%s", buffer);
                fputs(buffer,output);
                receivedBytes+=strlen(buffer);
        }
        fclose(output);
        return 0;
		
}

int downloadFile(int sockfd, char* filename, int index, int fileSize, struct sockaddr_in serverAdd, uint32_t port)
{
        char request[100] = "\0";
        int retRecv, retSend;
        sprintf(request, "BPGC\tDownload\r\nIndex: %d\r\nFileName: %s\r\nTCPPort: %u\r\n", index, filename, port);
        retSend = sendto(sockfd, request, sizeof(request), 0 ,(struct sockaddr*)&serverAdd, sizeof(struct sockaddr_in));
        
        if(retSend <= 0)
        {
                printf("Error -- sending download request\n");
                exit(1);
        }
        
        retRecv = receiveFile(sockfd, filename, fileSize, serverAdd);
        if(retRecv)
        {
                printf("Error -- receiving the file\n");
                exit(1);
        }
 }

int getPreference(char* hitRecords, char* filename, int* fileSize)
{
        int requiredId, curId;
        char* record, curRecord[20] = "\0", *matchComma;
        printf("Matched Records:\n%s\n", hitRecords);
        printf("Enter the required File Id: ");
        scanf("%d", &requiredId);
        
        record = strtok(hitRecords, "\n");
        
        while(record!=NULL)
        { 
                strcpy(curRecord, record);
                
                
                curId = getRecordDetails(curRecord, fileSize);
             
                if(curId==requiredId)
                {
                        //printf("Match found: %d", curId);
                        strcpy(filename, strtok(record, ","));
                        return requiredId;
                }
                record = strtok(NULL, "\n");
        }
}

void receiveReplies(int sock, int queryId, char* hitRecords, struct sockaddr_in* peerAdd)
{
        int fromLen, retRecv, curQueryId;
        char *line, *temp, response[150];
        fromLen = sizeof(struct sockaddr);
        retRecv = recvfrom(sock, response, sizeof(response), 0, (struct sockaddr*)peerAdd, &fromLen);
        
        if(retRecv <= 0)
        {
                printf("Error -- recive failed\n");
                exit(1);
        }
        
        if(strstr(response, "QueryHit")!=NULL)
        {
                printf("Query hit..\n");
                strtok(response, "\n"); //remove top line
                line = strtok(NULL, "\n");
                temp = strstr(line, " ");
                temp++;

                curQueryId = atoi(temp);

                if(curQueryId==queryId)
                {
                        strtok(NULL, "\n");
                        while((line = strtok(NULL, "\n"))!=NULL)
                        {        
                                strcat(hitRecords, line);
                                strcat(hitRecords, "\n");
                        }
                }
        }
}
int sendQueries(int sockfd, char* queryWord)
{
	FILE* peers = fopen("/home/sahil/peers_list.txt", "r");
	char buffer[20] = "\0", query[100] = "\0";
	int queryId;
	
	srand(time(NULL));
	queryId = rand();
	
	sprintf(query, "BPGC\tQuery\r\nQueryID: %d\nQueryWord: %s", queryId, queryWord);
	
	struct sockaddr_in peerAdd;
	peerAdd.sin_family = AF_INET;
	peerAdd.sin_port = htons(30000);
	
	while(fgets(buffer, sizeof(buffer), peers))
	{	
                //printf("%s", buffer);
		int retConvert = inet_aton(buffer, &(peerAdd.sin_addr));
		if(retConvert <= 0)
		{
			printf("Error -- Converting address from str to num\n");
			exit(1);
		}
		int retSend = sendto(sockfd, query, sizeof(query), 0 ,(struct sockaddr*)&peerAdd, sizeof(struct sockaddr_in));
		if(retSend <= 0)
		{
			printf("Error -- Sending query \n");
			exit(1);
		}
	}
	fclose(peers);
	return queryId;
}

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

int main()
{
	char queryWord[20] = "\0", hitRecords[100] = "\0", *requiredFile;
	int fileSize;
	printf("Enter Query word: \n");
	scanf("%s", queryWord);
	
	int sockfd, queryId, fileIndex; 
        struct sockaddr_in peerAdd;
	bzero(&peerAdd, sizeof(peerAdd));
	
	sockfd = sockUDP();
        queryId = sendQueries(sockfd, queryWord);
	receiveReplies(sockfd, queryId, hitRecords, &peerAdd);
	
	fileIndex = getPreference(hitRecords, requiredFile, &fileSize);
        
        downloadFile(sockfd, requiredFile, fileIndex, fileSize, peerAdd, 51718);
	
}
