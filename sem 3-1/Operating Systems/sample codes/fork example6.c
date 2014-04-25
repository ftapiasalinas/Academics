#include<stdio.h>
int main()
{
	printf("## my pid=%d, my parent pid=%d ##\n",getpid(),getppid());
	if(fork())
	{
	   if(fork())
	   {
		fork();
        
	   }
		wait(NULL);
	}

	printf("my pid=%d, my parent pid=%d\n",getpid(),getppid());
	

return 0;
}
/*
 *## my pid=2741, my parent pid=1853 ##
 * my pid=2742, my parent pid=2741
 * my pid=2743, my parent pid=2741
 * my pid=2741, my parent pid=1853
 * my pid=2744, my parent pid=2741
 */
