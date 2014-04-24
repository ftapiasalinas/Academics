#include<stdio.h>
int main()
{
    printf("enter a number between 10000 and 99999\n");
    int number ;
    scanf("%d",&number);
    if(number >10000 && number < 99999)
    {
        int temp = number;
        int i=0;
        int reverse=0;
        for(i=0;i<5;i++)    
        {   
            reverse = (reverse *10) + temp%10;
            temp = temp/10; 
        }
        printf("reverse number is %d\n",reverse);
        if(reverse == number)
            printf("yes palindrome\n");
        else
            printf("not a palindrome\n");
    }
    else
    printf("invalid number\n");
}
