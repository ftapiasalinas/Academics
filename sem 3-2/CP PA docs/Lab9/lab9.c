#include<stdio.h>
#include<string.h>
int ReadString (char Str[], int N);
int matchChar (char Str[], char ch);
int updateString (char Str1[], char Str2[]);
void printString(char Str[]);
int main(void)
{
	int N;
	char string1[50];
	char string2[50];
	printf("enter N:");
	scanf("%d",&N);
	printf("Enter String 1 :");
	int numinfirst = ReadString(string1,N);	
	printf("Enter String 2 :");
	int numinsecond = ReadString(string2,N);
	printf("traling non zero numbers in string1 are %d\n",numinfirst);
	printf("traling non zero numbers in string2 are %d\n",numinsecond);
	if(numinfirst == -1 || numinsecond == -1)
	{
		printf("Input does not satisfy the input conditions\n");
		return 0;
	}		
	int dups = updateString(string1,string2);
	printString(string2);
	
	return 0;
}
int ReadString (char Str[], int N)
{
	int i=0;
	scanf("%s",Str);
	int length = strlen(Str);
	char tempstr[length];
	int lengthfound = 0;
	for(i=length-1;i>=0;i--)
	{
		strncpy(tempstr,&Str[i],length-i);
		if(atoi(tempstr) > lengthfound)
		{
			lengthfound++;
		}
		else
		{
			break;
		}
	}

	if(lengthfound >= N)
	{
		return lengthfound;
	}
	else
		return -1;
}

int matchChar (char Str[], char ch)
{
	int i=0;
	for(i=0;i<strlen(Str);i++)
	{
		if(Str[i]==ch)
			return 1;
	}
	return 0;
}

int updateString (char Str1[], char Str2[])
{
	int i=0;
	int matched = 0;
	char temp[strlen(Str2)+1];
	int notmatched = 0;
	for(i=0;i<strlen(Str2);i++)
	{
		if(matchChar(Str1,Str2[i]))
		{
			//printf("%c matched\n",Str2[i]);
			matched++;
			
		}
		else
		{
			temp[notmatched] = Str2[i];
			notmatched++;
		}
	}
	temp[notmatched] = '\0';
	//printf("sring after removina ssafusa is %s\n",temp);
	strncpy(Str2,temp,sizeof(Str2));
	Str2[notmatched] = '\0';
	return matched;
}

void printString(char Str[])
{
	printf("the string is %s\n",Str);
}
