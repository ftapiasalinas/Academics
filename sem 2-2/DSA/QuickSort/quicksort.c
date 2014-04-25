extern int Partition(int *, int, int);

#ifdef DEBUGQSORT
#include <stdio.h>
    int dbgcount = 0, callcount = 0;
    int QuickSort(int *A, int p, int r)
#else
    void QuickSort(int *A, int p, int r)
#endif
    {
    #ifdef DEBUGQSORT
        callcount++;
    #endif
    if(p < r)
        {
        int q = Partition(A,p,r);
        QuickSort(A,p,q);
        QuickSort(A,q+1,r);
        }
    #ifdef DEBUGQSORT
        return callcount+dbgcount;
    #endif
    }

