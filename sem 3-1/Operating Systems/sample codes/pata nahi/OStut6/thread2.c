#include<pthread.h>
#include <stdio.h>
int ncr=0;
int factor=1;
void *fact();
int main ( int argc, char *argv[ ] ) 
{ pthread_t tid[3];
pthread_attr_t attr;
int input[2];
pthread_attr_init ( &attr);
scanf("%d",&input[0]);
scanf("%d",&input[1]);
int nr=input[0]-input[1];
int nfact;
int rfact;
int nrfact;
pthread_create ( &tid[0], &attr, fact, &input[0]); 
pthread_join ( tid[0], NULL );
nfact=factor;
factor=1;
pthread_create ( &tid[1], &attr, fact, &input[1]); 
pthread_join ( tid[1], NULL );
rfact=factor;
factor=1;
pthread_create ( &tid[2], &attr, fact, &nr); 
pthread_join ( tid[2], NULL );
nrfact=factor;
factor=1;
printf("%dc%d = %d\n",input[0],input[1],(nfact/((nrfact)*(rfact))));
return 0;
}

void *fact (int* input)
{ //int upper = atoi (param);
int i;
if ( *input > 0 ) {
for ( i=1; i <= *input; i++ ) {
factor = factor *i; }
}
pthread_exit(0);
}
