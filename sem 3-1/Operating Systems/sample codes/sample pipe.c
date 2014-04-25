/* Communication between child process and parent process using pipe. */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int pfds[2];
	char buf[30];
	pipe(pfds);
	
	if (!fork()) 
	{
		printf("CHILD: writing to the pipe\n");
		write(pfds[0], "Hello World", 12);
		printf("CHILD exiting\n");
		exit(0);
	} 
	else 
	{
		printf("PARENT: reading from pipe\n");
		read(pfds[1], buf, 12);
		printf("PARENT: read \"%s\"\n", buf);
		wait(NULL);
	}
	
	return 0;
}


