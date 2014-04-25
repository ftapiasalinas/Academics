#include<stdio.h>
int main()
{
	printf("## my pid=%d, my parent pid=%d ##\n",getpid(),getppid());
	if(fork())
		fork();
	wait(NULL);
	printf("my pid=%d, my parent pid=%d\n",getpid(),getppid());
	

return 0;
}
/*
 * ## my pid=2671, my parent pid=1853 ##
 * my pid=2672, my parent pid=2671
 * my pid=2673, my parent pid=2671
 * my pid=2671, my parent pid=1853
 */
