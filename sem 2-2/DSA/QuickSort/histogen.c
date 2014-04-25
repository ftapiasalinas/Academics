#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<errno.h>
#include<malloc.h>

int main(int argc, char *argv[])
    {
    int minn = 50, nstep = 50, maxn = 10000;
    if(argc > 1)
        {
        minn = atoi(argv[1]);
        if(argc > 2)
            {
            nstep = atoi(argv[2]);
            if(argc > 3)
                {
                maxn = atoi(argv[3]);
                }
            }
        }
    int m, n;
    scanf("%d%d", &m, &n);

    int i = 1, j =1;
    printf("y(%d,%d)=%d;\n", i, j, n);

    int oldm = m;

    while(!feof(stdin))
        {
        if(scanf("%d%d", &m, &n) < 2)
            {
            printf("[NN(%d,:), XX(%d,:)]=hist(y(%d,:));\n", i, i, i);
            break;
            }
        if(oldm != m)
            {
            printf("[NN(%d,:), XX(%d,:)]=hist(y(%d,:));\n", i, i, i);
            oldm = m;
            i++;
            j = 1;
            printf("y(%d,%d)=%d;\n", i, j, n);
            }
        else
            {
            j++;
            printf("y(%d,%d)=%d;\n", i, j, n);
            }
        }
    if(i != (maxn-minn)/nstep+1) error(-2,0,"File incomplete? %d records expected, %d found",(maxn-minn)/nstep+1,i);
    printf("for i=1:%d; z(i)=mean(y(i,:)); end;\n", i);
    printf("for i=1:%d; x(i)=%d+(i-1)*%d; end;\n", i, minn, nstep);
    for(j = 1; j <= i; j++)
        {
        printf("bar(XX(%d,:), NN(%d,:)); print -dpdf histogram4n%d.pdf ;\n", j, j, minn+(j-1)*nstep);
        }
    printf("plot(x,z); grid(\"minor\"); print -dpdf runtime.pdf ;\n");
    return 0;
    }
