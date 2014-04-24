#include<stdio.h>
int main(int argc,char argv[])
{

    int dimension;
    int count = 1;
    printf("enter the dimension of the square matrix\n");
    scanf("%d",&dimension);
    int matrix[dimension][dimension];
    int square = dimension * dimension;
    int leftend = 0,rightend = dimension-1,topend = 0,bottomend = dimension-1;
    int i =0 , j=0;
    char direction = 'r';
    while(count <= square)
    {
//        printf("count is %d  ",count);
        matrix[i][j] = count;
        count++;
        if(j == leftend && direction == 'l')// left dead end
        {
            direction = 'u';
            leftend++;
//            printf("turning up\n");
        }
        else if(i-1 == topend && direction == 'u')//top end 
        {
            direction = 'r';
            topend++;
//            printf("turning right\n");
        }
        else if(j == rightend && direction == 'r') // right dead end
        {
            direction = 'd';
            rightend--;
//            printf("turning down\n");
        }
        else if(i == bottomend && direction == 'd' )//bottom end
        {
            direction = 'l';
            bottomend--;
//            printf("turning left\n");
        }
        

        if(direction == 'r')
            j++;
        else if(direction == 'd')
            i++;
        else if(direction == 'l')
            j--;
        else if(direction == 'u')
            i--;        
    
    }
    for(i=0;i<dimension;i++)
    {
        for(j=0;j<dimension;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
