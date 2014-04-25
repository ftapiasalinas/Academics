#include <cstdio>
using namespace std;

class O
{
	public:
	int x;
	O() { x = 3; }
	 void show() { printf("O's show\n") ; }
//	virtual void tell() =0; //pure virtual methods
};
class A : virtual public O
{
	public:
	virtual void show()=0;
	//virtual void tell() { printf("A's tell\n") ; }
};
class B : virtual public O
{
	public:
	void show() { printf("B's show\n") ; }
	//virtual void tell() { printf("B's tell\n") ; }
};
class D : public A , public B
{
	public:
    void show() { printf("D's show\n") ; }//comment it
	//virtual void tell() { printf("D's tell\n") ; }
};

int main()
{

	O *ptro = new D;//is this fine ??? if not why ??
	O *o;
	A a;
	o=&a;
	o->show();
	 //o->tell();
	return 0;
}
