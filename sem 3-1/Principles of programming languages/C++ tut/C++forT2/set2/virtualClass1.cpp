#include <cstdio>
using namespace std;

class O
{
	public:
	int x;
	O() { x = 3; }
	void show() { printf("O's show\n") ; }
	virtual void tell() { printf("O's tell\n") ; }
};
class A : virtual public O
{
	public:
	void show() { printf("A's show\n") ; }
	virtual void tell() { printf("A's tell\n") ; }
};
class B : virtual public O
{
	public:
	void show() { printf("B's show\n") ; }
	virtual void tell() { printf("B's tell\n") ; }
};
class D : public A , public B
{
	public:
	void show() { printf("D's show\n") ; }
	virtual void tell() { printf("D's tell\n") ; }
};

int main()
{
	D d;
	// gives error if tell and void are not overridden in D
	d.show();
	d.tell(); 
	
	O *ptro;
	ptro = &d;
	ptro->show();
	ptro->tell();
	
	//printf("Value of X seen from D = %d from o = %d\n" , d.x , ptro->x);
	return 0;
}
