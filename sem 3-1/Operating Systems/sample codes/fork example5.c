#include<stdio.h>
int main()
{
	printf("## my pid=%d, my parent pid=%d ##\n",getpid(),getppid());
	if(!fork())
		fork();
	wait(NULL);
	printf("my pid=%d, my parent pid=%d\n",getpid(),getppid());
	

return 0;
}
/*
 * ## my pid=2691, my parent pid=1853 ##
 * my pid=2693, my parent pid=2692
 * my pid=2692, my parent pid=2691
 * my pid=2691, my parent pid=1853
 */
