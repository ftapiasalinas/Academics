#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <error.h>

#ifdef DEBUGQSORT
extern int QuickSort(int *,int,int);
#else
extern void QuickSort(int *,int,int);
#endif

int main(void)
    {
    int i, n;
    scanf("%d",&n);
    if(n < 1) error(-1,0,"Invalid array size, nonpositive: %d",n);
    int A[n];
    for(i = 0; i < n; i++) scanf("%d",&A[i]);
    #ifdef DEBUGQSORT
      #if DEBUGQSORT > 1
        printf("\nOriginal ");
        for(i = 0; i < n; i++) printf("%d\t",A[i]);
        printf("\n");
        printf("sorted in %d steps to ",QuickSort(A,0,n-1));
        for(i = 0; i < n; i++) printf("%d\t",A[i]);
        printf("\n");
      #else
        printf("%d %d\n",n,QuickSort(A,0,n-1));
      #endif
    #else
        QuickSort(A,0,n-1);
    #endif
    return 0;
    }
