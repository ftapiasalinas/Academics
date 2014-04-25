#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define  NUM_THREADS 5

void* printhello(void *threadid)
{
	long tid;
	tid=(long) threadid;
	printf("hello World!It's me, thread# %d\n",tid);
	pthread_exit(NULL);
}

int main()
{
	pthread_t threads[NUM_THREADS];
int i;
	for(i=0;i<5;i++)
	printf("afsd %d\n",threads[i]);
	int rc;
	long t;
	for(t=0; t<NUM_THREADS; t++)
	{
		printf("In main: creating thread %d\n",t);
		rc=pthread_create(&threads[t], NULL, printhello,(void*)t);
		if(rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
		exit(-1);
		}
	
	}
	for(t=0;t<NUM_THREADS;t++)
	{
		printf("joining thread#%d\n",t);
		pthread_join(threads[t],NULL);
	}

	pthread_exit(NULL);
}

