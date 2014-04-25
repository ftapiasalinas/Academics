#ifdef DEBUGQSORT
extern int dbgcount;
#include <stdio.h>
#endif

int Partition(int *A, int p, int r) /* This is Hoare Partition */
    {
    int x, i, j;
    x = A[p];
    i = p-1;
    j = r+1;
    #ifdef DEBUGQSORT
        dbgcount += 1;
    #endif
    while(1)
        {
        do
            {
            j--;
            #ifdef DEBUGQSORT
                dbgcount += 1;
            #endif
            } while(A[j] > x);
        do
            {
            i++;
            #ifdef DEBUGQSORT
                dbgcount += 1;
            #endif
            } while(A[i] < x);
        if(i < j)
            {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            #ifdef DEBUGQSORT
              dbgcount += 1;
              #if DEBUGQSORT > 1
                {
                printf("Exchanged A[%d]=%d, A[%d]=%d\n",i,A[j],j,A[i]);
                int k;
                for(k = 0; k <= r; k++) printf("%d\t",A[k]);
                printf("\n");
                }
              #endif
            #endif
            }
        else
            {
            #ifdef DEBUGQSORT
              #if DEBUGQSORT > 1
                printf("Partition returns %d: A[%d]=%d\n",j,j,A[j]);
              #endif
            #endif
            return j;
            }
        }
    }

