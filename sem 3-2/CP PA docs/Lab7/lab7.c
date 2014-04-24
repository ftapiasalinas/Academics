#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argumentcount,char* argumentarray[])
{
    int valid = 1;
    char *string = (char *)malloc(sizeof(char)*50);
    scanf("%[^\n]s",string);
    //puts(string);

    int index = 0;
    int lastbraceindex = 0;
    int closingbraceindex = strlen(string) - 1;
    int firstbracefound = 0;
    int coloncount = 0;

    while(string[index] != '\0')
    {
        if(index==0 && string[index] != 'f')
        {
            printf("problem in for\n");
            valid = 0;
            break;
        }
        if(index==1 && string[index] != 'o')
        {
            printf("problem in for\n");
            valid = 0;
            break;
        }        
        if(index==2 && string[index] != 'r')
        {
            printf("problem in for\n");
            valid = 0;
            break;
        } 
        if(string[index]!=' ' && index>2)
        {
            //printf("here for index %d\n",index);
            if(firstbracefound==0 && string[index]!='(')
            {
                printf("Error between first bracket and \"for\"\n");
                valid = 0;
                break;
            }
            if(string[index]=='(')
            {

                while(closingbraceindex>index)
                {
                    if(string[closingbraceindex]==')')
                    {
                        closingbraceindex--;            
                        break;                        
                    }
                    closingbraceindex--;
                }
                if(closingbraceindex < index)
                {
                    printf("The braces are not matching\n");
                    valid = 0;
                    break;
                }
                if(firstbracefound == 0)    
                {
//                    printf("here");
                    lastbraceindex = closingbraceindex + 1;
                    firstbracefound = 1;
//                    printf("the closingbraceindex is %d",closingbraceindex);
                    int tempindex = closingbraceindex+2;
                    while(tempindex < strlen(string))
                    {       
//                        printf("looking for ;\n");
                        if(string[tempindex]!=';')
                        {
                            printf("Syntax error after the for loop closing bracket\n");
                            return 0;
                        }
                        tempindex++;
                    }
                    
                }
            }
            if(string[index]==';' && index<lastbraceindex)
            {
                coloncount++;
            }                            
        }
        index++;
    }
//    printf("the number of semicolons is %d\n",coloncount);
    if(coloncount!=2)
    {
        printf("the number of semicolons within the brackets is troublesome\n");
        valid = 0;
    }
    if(valid)
        printf("the loop is fine \n");
}
