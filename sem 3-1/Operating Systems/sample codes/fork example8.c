#include<stdio.h>
int main()
{
	printf("## my pid=%d, my parent pid=%d ##\n",getpid(),getppid());
	if(!fork())
	{
	   if(!fork())
	   {
		fork();
	   }
	}
		while(wait(NULL)!=-1);
	printf("my pid=%d, my parent pid=%d\n",getpid(),getppid());
return 0;
}
/*
## my pid=8376, my parent pid=1853 ##
my pid=8379, my parent pid=8378
my pid=8378, my parent pid=8377
my pid=8377, my parent pid=8376
my pid=8376, my parent pid=1853
*/

