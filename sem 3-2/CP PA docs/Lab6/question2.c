#include<stdio.h>
int main()
{
    int number;
    int noofdigits = 0;
    printf("Enter a five digit number only\n");
    scanf("%d",&number);
    int temp = number;
    while(temp > 0 )
    {
        noofdigits ++;
        temp /= 10;
    }
    if(noofdigits != 5)        
    {
        printf("the digits are %d which is not 5\n",noofdigits);
        return 2;
    }
    int digits[5];
    temp = number;
    int index = 0;
    while(temp > 0)
    {
        digits[5-index-1] = temp %10;
        temp /= 10;
        index++;
    }
    //checking palindrome
    int counts[5] = {0};
    int i,j;
    int unpaired=0,found;
    if(digits[4]== digits[0] && digits[1]==digits[3])
    {
            printf("the number is a palindrome\n");
    }
    else
    {
        for(i=0;i<5;i++)
        {
                if(digits[i] != -1 )
                {
                    found = 0;
                    for(j=i+1;j<5;j++)
                    {
                        if(digits[i] == digits[j])
                        {
                            found = 1;
                            digits[j] = -1;
                        }
                    }
                    if(found == 0)  
                        unpaired++;
                    printf("unpaired elements are %d\n",unpaired);                
                    if(unpaired > 1)
                    {
                        printf("palindrome is not possible\n");
                        return 0;
                    }
                }               
        }
        printf("palindrome is possible\n");
    }


}
