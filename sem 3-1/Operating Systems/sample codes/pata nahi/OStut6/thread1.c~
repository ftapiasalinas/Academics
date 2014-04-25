#include<pthread.h>
#include <stdio.h>

int res=1;
int input;
void *fact();
int main ( int argc, char *argv[ ] ) 
{ 
	pthread_t tid;
	pthread_attr_t attr;

	pthread_attr_init ( &attr);
	scanf("%d",&input);

	pthread_create ( &tid, &attr, fact, NULL); 
	pthread_join ( tid, NULL ); 

	printf("Result (%d!) = %d\n",input,res);
	return 0;
}

void *fact ()
{
	int k;
	if ( input > 0 )
 	{
		for ( k=1; k <= input; k++ ) 
		{
			res = res * k; 
		}
	}

	pthread_exit(0);
}
