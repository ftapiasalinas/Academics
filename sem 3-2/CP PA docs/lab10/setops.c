#include<stdio.h>
#include"setops.h"

int readSet(int A[])
{
	int index = 0;
	while(index<elements)
	{
		scanf("%d",&A[index++]);
	}
	return index;
	
}
void printSet(int A[], int N)
{
	
	int index=0;
	
	while(index<N)
	{
		printf("%d ",A[index++]);
	}
	printf("\n");

}
int Union(int A[], int N, int B[], int M, int U[])
{
	int index = 0;
	while(index<N)
	{
		U[index] = A[index++];
	}
	int current = 0;
	int dup = 0;
	while(current<M)
	{
		int i=0;
		dup = 0;
		while(i<index)
		{
			if(U[i]==B[current])
			{
				dup=1;
				break;
			}
			i++;
			
		}
		if(dup==0)
		{
			U[index] = B[current];
			index++;
			
		}
		current++;
	}
	return index;
}
int Intersection(int A[], int N, int B[], int M, int I[])
{
	int index=0;
	int current=0;
	while(current<M)
	{
		int i=0;
		while(i<N)
		{
			int intersected = 0;
			if(A[i]==B[current])
			{
				int j=0;
				int flag = 0;
				while(j<index)
				{
					if(B[current]==I[j])
					{
						flag=1;
						break;							
					}
					j++;
				}
				if(flag==0)
				{
					I[index] = B[current];			
					index++;
					intersected = 1;
				}
			}
			if(intersected==1)
				break;
			i++;
		}
		current++;	
	}

	return index;
		
}
int SetDiff(int A[], int N, int B[], int M, int D[])
{
	int current = 0;
	int index=0;
	while(current<N)
	{
		int i=0;
		int flag=0;
		while(i<M)
		{

			if(B[i] == A[current])
			{
				flag=1;
				break;	
			}
			i++;
		}
		if(flag==0)
		{
			D[index] = A[current];
			index++;
		}
		current++;
	}
	return index;
}
