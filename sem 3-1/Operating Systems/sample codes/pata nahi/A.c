#include<stdio.h>
void ChildProcess();
void ParentProcess();
int a[]={1,2,3,4,5,6};
int sum=0,prdt=1,PID,i;
int pidwait, child_status;
int main()
{
PID=fork();
if(PID<0)
fprintf(stderr,"problem in creating a process\n");
if(PID==0)
{	ChildProcess();
}
if(PID>0)
{
	ParentProcess();
	pidwait=wait(&child_status);
	printf("child %d has terminated with status =%d\n",pidwait,child_status);
}
	printf("from Main %d says:This is a child process computing the sum=%d\n",getpid(),sum);
	printf("from Main %d says:This is a parent process computing the product=%d\n",getpid(),prdt);

return 0;
}

void ChildProcess()
{int i;
	for(i=0;i<6;i++)
	{
		sum+=a[i];
		printf("In Child process i=%d\n",i);
		sleep(1);
	}
	printf("This is a child process computing the sum=%d\n",sum);
	printf("child says my pid=%d\n",getpid());
	printf("child says my parent pid=%d\n",getppid());

}

void ParentProcess()
{int i;
	for(i=0;i<6;i++)
	{
		prdt*=a[i];
		printf("In Parent process i=%d\n",i);
		sleep(1);
	}
	printf("This is a parent process computing the product=%d\n",prdt);
	printf("parent says my pid=%d\n",getpid());
	printf("parent says my parent pid=%d\n",getppid());

}

