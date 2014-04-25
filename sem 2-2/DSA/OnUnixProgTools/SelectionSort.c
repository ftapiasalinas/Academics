#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<errno.h>
#include<assert.h>

int IsSorted(int n, int *A)
    {
    if(n > 0)
        {
        do
            {
            n--;
            if(A[n-1] > A[n]) return 0;
            }
        while(n);
        }
    return -1;
    }

int findargmin(int n, int *A)
    {
    int i;
    int min = A[0];
    int imin = 0;
    for(i=1; i<n; i++)
        if(min > A[i])
            {
            min = A[i];
            imin = i;
            }
    return imin;
    }

int main(void)
    {
    int n;
    scanf("%d",&n);
    if(n <= 0) error(-1,0,"Number of elements has to be positive.");
    int A[n];
    int i;
    for(i = 0; i < n; i++)
        {
        scanf("%d",A+i);
        }
    for(i = 0; i <= n; i++)
        {
        assert(IsSorted(i,A)); /* Check if the array is sorted up to i elements */
        int temp = A[i];
        int argmin = i + findargmin(n-i,A+i);
        A[i] = A[argmin];
        A[argmin] = temp;
        }
    /* test: */
    for(i = 0; i < n-1; i++)
        if(A[i] > A[i+1]) error(-2,0,"Failed to sort at position %d!",i);
    return 0;
    }
