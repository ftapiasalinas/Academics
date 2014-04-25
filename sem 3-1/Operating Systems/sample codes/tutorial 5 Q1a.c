#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char *token,command[20],cmd[20],*cvec[5];
	int i,c=1;
	FILE *fp;

	fp = fopen("commands.txt","r"); /* Contains list of commands */
	
	while (fgets( command, sizeof command, fp ) != NULL ) /*Reading the file "commands.txt" line by line*/
	{
		strcpy(cmd,command);
       		 
		/*Removing '\n' from end of the line*/
		int len = strlen(command)-1;
     		if(command[len] == '\n') 
         	{
			command[len] = '\0';
		}
	
		/* Getting tokens from command and storing them in the command vector, cvec */
		i=0;
		token = strtok(command," ");
		while(token != NULL)
		{
			cvec[i++] = token;
			token = strtok(NULL, " ");
		}
		cvec[i] = 0;

		/*Forking a child process to execute command using exec() */
		if (!fork())
		{	
			printf("Child process %d executing command %s",getpid(),cmd);	
			fflush(stdout);	
			execvp(cvec[0],cvec);   
		}

		while(wait(NULL) != -1);
		c++;
		
	}
	fclose(fp);	
	return 0;
}
