#include<stdio.h>
#include"setops.h"
int main()
{
	int len;
	int arrayresult[100];

	printf("Reading Elements for Set A:\n");
	printf("Enter Number of Elements:");
	scanf("%d",&elements1);
	elements = elements1;
	int array1[elements1];

	readSet(array1);
	
	printf("Reading Elements for Set B:\n");
	printf("Enter Number of Elements:");
	scanf("%d",&elements2);
	elements = elements2;
	int array2[elements2];

	readSet(array2);

	printf("The elements of set A are: ");
	printSet(array1,elements1);
	printf("The elements of set B are: ");
	printSet(array2,elements2);

	
	len = Union(array1,elements1,array2,elements2,arrayresult);
	printf("The elements of set Union are: ");
	printSet(arrayresult,len);
	
	if(elements2>=elements1)
		len = Intersection(array1,elements1,array2,elements2,arrayresult);
	else
		len = Intersection(array2,elements2,array1,elements1,arrayresult);
	printf("The elements of set intersection are: ");
	printSet(arrayresult,len);
		
	len = SetDiff(array1,elements1,array2,elements2,arrayresult);
	printf("The elements of set diff are: ");
	printSet(arrayresult,len);
}
