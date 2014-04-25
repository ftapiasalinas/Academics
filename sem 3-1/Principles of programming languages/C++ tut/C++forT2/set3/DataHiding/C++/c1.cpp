#include <cstdio>

class c1
{
	int i;
	float f;
	public:
	void tell();
};

void c1::tell()
{
	printf("i = %d f = %lf\n" , i , f);
}
