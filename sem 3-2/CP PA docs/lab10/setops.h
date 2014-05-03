#ifndef headerincluded
#define headerincluded

int elements1;
int elements2;
int elements;
extern int readSet(int[]);
extern void printSet(int A[], int N);
extern int Union(int A[], int N, int B[], int M, int U[]);
extern int Intersection(int A[], int N, int B[], int M, int I[]);
extern int SetDiff(int A[], int N, int B[], int M, int D[]);

#endif
