#include<stdio.h>
#include<assert.h>

int Inversions(int *A, int n)
    {
    /* This function counts all pairs i,j such that i < j && A[i] > A[j] */
    assert(n>0);
    int i, j, count = 0;
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(A[i]>A[j]) count++;
    return count;
    /* This is the amount of work (number of exchanges) that BubbleSort needs to perform on A in the current state. */
    }

int AllBefore_nminusi_AreLessEq(int *A, int n, int i)
    /* This function checks if all A[0..n-i-1] are <= all A[n-i..n-1]. It gives the loop invariant of the outer loop of BubbleSort */
    {
    int j, k;
    for(j = n-i; j < n; j++)
        for(k = i; k < n; k++)
            if(A[j] > A[k]) return 0;
    return -1;
    }

int AllBefore_j_AreLessEq(int *A, int n, int j)
    /* This function checks if all A[0..j-1] are <= all A[j..n-1]. It gives the loop invariant of the inner loop of BubbleSort */
    {
    int i, k;
    for(i = 0; i < j; i++)
        for(k = j; k < n; k++)
            if(A[i] > A[k]) return 0;
    return -1;
    }

int BubbleSort(int *A, int n)
    {
    assert(n > 0);
    int i = 0, count = 0, sorted = 0;
    while((i<n) && (!sorted))
        {
        assert(AllBefore_nminusi_AreLessEq(A,n,i));
        sorted = 1;
        int j;
        for(j = 0; j < n-i-1; j++)
            {
            assert(AllBefore_j_AreLessEq(A,n,j));
            if(A[j] > A[j+1])
                {
                A[j] = A[j] + A[j+1];
                A[j+1] = A[j] - A[j+1];
                A[j] = A[j] - A[j+1];
                sorted = 0;
                count++;
                }
            }
        i++;
        assert(sorted || Inversions(A,n)>0);
        }
    assert(Inversions(A,n)==0);
    return count;
    }

int main(int argc, char *argv[])
    {
    int n;
    scanf("%d",&n);
    printf("%d ",n);
    int i, A[n];
    for(i = 0; i < n; i++) scanf("%d",&A[i]);
    int inv = Inversions(A,n);
    int count = BubbleSort(A,n);
    assert(count == inv);
    printf("%d\n",count);
    }
