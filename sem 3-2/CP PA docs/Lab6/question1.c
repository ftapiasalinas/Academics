#include<stdio.h>
int main()
{
    int num,n;
    int noofdigits = 0;
    printf("Enter Num and N\n");
    scanf("%d %d",&num,&n);
    int temp = num;
    while(temp > 0 )
    {
        temp /=10;
        noofdigits++; 
    }
    if(n > noofdigits-1)
        return 1;
    
    int digits[noofdigits];
    temp = num;
    int index = 0;
    while(temp > 0 )
    {
        digits[index] = temp % 10;
        temp /= 10;
        index++;
    }
    int factstoprint = n;
    int i,j;
    temp = n;
    int ascending = 0;
    for(i=0;i<n;i++)   
    {
        for(j=0;j<(n+1);j++) 
        {
                int factorial = 1;
                int factof = digits[i] - digits[j];
                if(factof < 0)
                    factof = factof * -1;
                while(factof > 1)
                {
                    factorial = factof * factorial;
                    factof --;
                }
                printf("%d ",factorial);
                if(i==n-1 && j==n-1)
                    {
                        printf("\n");
                        return 0;                
                    }
                factstoprint--;
                if(factstoprint == 0)   
                {
                    printf("\n");
                    if(ascending == 0)
                    {
                        factstoprint = --temp;
                        if(factstoprint == 0)       
                            {
                                ascending = 1;
                                factstoprint = 2;
                                temp = 2;
                            }
                    }
                    else
                    {
                        factstoprint = ++temp;
  
                    }

                }
                
        }
    }
    
}

