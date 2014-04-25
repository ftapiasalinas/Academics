#include <cstdio>
#include <iostream>

using namespace std;

class A
{
	public:
	int x , y , z;
	A(int x=4 , int y=2 , int z=1)
	{
		this->x = x;
		this->y = y;
		this->z = z;
        printf("defalult callsfjlasfs \n");
	}

	A(A& a)
	{
		x = a.x;
		y = a.y;
		z = a.z;
		printf("Copy Constructor called\n");
		a.x++;
	}

	//not a copy constructor
	A(A *a)
	{
		x = a->x;
		y = a->y;
		z = a->z;
		printf("Some Constructor called\n");
		(a->x)++;
	}
	void tell() { printf("x=%d y=%d z=%d\n" , x , y , z);}
};

class B
{
	public:
	void Btell(A a)
	{
		printf("from B x=%d y=%d z=%d\n" , a.x , a.y , a.z);
		a.y++;
		printf("below from B x=%d y=%d z=%d\n" , a.x , a.y , a.z);
	}

	void BtellbyRef(A &a)
	{
		printf("from B x=%d y=%d z=%d\n" , a.x , a.y , a.z);
		a.y++;
		printf("below from B x=%d y=%d z=%d\n" , a.x , a.y , a.z);
	}
};



int main()
{
	A a1;
	A a2(a1);
	A *a3p;

	a3p = &a1;

	a1.tell();
	a2.tell();

	A a4(a3p);
	a1.tell();
	a4.tell();

	B b;
	b.Btell(a1);
	a1.tell();

	b.BtellbyRef(a1);
	a1.tell();
	return 0;
}

