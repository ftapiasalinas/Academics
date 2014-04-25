#include<stdio.h>
int main()
{
	printf("## my pid=%d, my parent pid=%d ##\n",getpid(),getppid());
	if(fork())
	{
	   if(!fork())
	   {
		fork();
	   }
//		wait(NULL);
//		wait(NULL);

  		while(wait(NULL)!=-1);
 	
	}
	printf("my pid=%d, my parent pid=%d\n",getpid(),getppid());
	

return 0;
}
/*
 *## my pid=4763, my parent pid=1853 ##
 * my pid=4764, my parent pid=4763
 * my pid=4766, my parent pid=4765
 * my pid=4765, my parent pid=4763
 * my pid=4763, my parent pid=1853
 */
