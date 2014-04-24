#include<stdio.h>
#include<string.h>

int isSubString(const char* s1, const char* s2)
{
	char* retCmp = strstr(s1, s2);
	if(retCmp==NULL)
		return 0;
	return 1;
}

main()
{
	char path[100] = "\0";
	strcpy(path, "/host/academia/CompNet/labs/lab5/Server/Share/");
	strcat(path, "MyFile5");
	printf("Complete path: %s\n", path);
	char temp[200] = "\0";
	char character;

	FILE* filepointer = fopen(path, "r");
	if(filepointer==NULL)
	{	
		printf("cant open %szzzz\n",path);
	}


}
