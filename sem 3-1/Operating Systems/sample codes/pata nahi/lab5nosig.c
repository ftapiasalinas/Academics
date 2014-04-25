#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

FILE *fp;

void execfile(int odd)
{
	char *token,command[20],temp[20],*cvec[5];
	int i,c=1;
	
	while (fgets(command,sizeof command,fp) != NULL) 
	{
		if(!(c%2 ^ odd)) /* to make sure odd process execute odd commands in the file and vice-versa */
		{
       		 	strcpy(temp,command);
			int len = strlen(command)-1;
	     		if(command[len] == '\n') 
		 	{
				command[len] = '\0';
			}
	
			
			token = strtok(command," ");
			i=0;	
			while(token != NULL)
			{
				cvec[i++] = token;
				token = strtok(NULL, " ");
			}
			cvec[i] = 0;

			if (!fork())
			{	
				if(odd)
					printf("ODD process %d executing command %d : %s",getpid(),c,temp);
				else
					printf("EVEN process %d executing command %d : %s",getpid(),c,temp);
				execvp(cvec[0],cvec);   
			}
			wait(NULL);
		}
		c++;
	}
	
}
int main()
{
	FILE *fp2;
	pid_t odd,even;
	fp = fopen("commands.txt","r");
	
	odd = fork();
	if(odd == 0)
	{
		execfile(1);
	}
	else if (odd>0)
	{
		even = fork();
		if(even>0)
		{	
			wait(NULL);
		}		
		else if(even == 0)
		{
			execfile(0);
		}
		wait(NULL);
	}
	fclose(fp);	
	return 0;
}
