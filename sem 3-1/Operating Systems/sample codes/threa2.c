#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define  NUM_THREADS 5

void *printhello1(void *threadid)
{
	long tid;
	tid=(long) threadid;
	printf("hello1 World!It's me, thread# %d\n",tid);
	pthread_exit(NULL);
}

void *printhello2(void *threadid)
{
	long tid;
	tid=(long) threadid;
	printf("hello2 World!It's me, thread# %d\n",tid);
	pthread_exit(NULL);
}
void *printhello3(void *threadid)
{
	long tid;
	tid=(long) threadid;
	printf("hello3 World!It's me, thread# %d\n",tid);
	pthread_exit(NULL);
}
void *printhello4(void *threadid)
{
	long tid;
	tid=(long) threadid;
	printf("hello4 World!It's me, thread# %d\n",tid);
	pthread_exit(NULL);
}
void *printhello5(void *threadid)
{
	long tid;
	tid=(long) threadid;
	printf("hello5 World!It's me, thread# %d\n",tid);
	pthread_exit(NULL);
}
int main()
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t=0;
		printf("In main: creating thread\n");
		pthread_create(threads + t++, NULL, printhello1,(void*)t);
		pthread_create(threads + t++, NULL, printhello2,(void*)t);
		pthread_create(threads + t++, NULL, printhello3,(void*)t);
		pthread_create(threads + t++, NULL, printhello4,(void*)t);
		pthread_create(threads + t++, NULL, printhello5,(void*)t);
	
	for(t=0;t<NUM_THREADS;t++)
	{
		printf("joining thread#%d\n",t);
		pthread_join(threads[t],NULL);
	}

	pthread_exit(NULL);
}

