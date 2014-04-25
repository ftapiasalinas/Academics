#include <stdio.h>
#include <stdlib.h>
int PerformSomethingOn(int i, int j)
	{
	if(i <= 0 || j <= 0) return -1;
	else
		{
		int count = 0;
		while(i != j)
			{
			count = count + 1;
			if(i < j) j = j - i; else i = i - j;
			}
		printf("I did something %d times. And here is your i:%d (or j:%d)\n",count,i,j);
		return i;
		}
	}

int main(int argc, char *argv[])
{
if(argc > 2)
	{
	int i,j,result;
	i = atoi(argv[1]); j = atoi(argv[2]);
	if(i <= 0 || j <= 0)
		{
		printf("R u crazy? I asked u for some positive feedback\n");
		return -1;
		}
	else result = PerformSomethingOn(i,j);
	printf("i:%d and j:%d were turned into %d\n",i,j,result);
	}
else
	{
	printf("Give two positive integer arguments.\n");
	return -1;
	}
}