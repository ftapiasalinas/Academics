#include<iostream>
using namespace std;

class B {
public:
    char name;
	public:
		void Tell(void) { cout << name << "\n"; }
	public:
		B() { name = '0'; }
	};
class D1 :  public B {
	//char name;
	public:
		D1() { name = '1'; }
		void Tell(void) { cout << name; B::Tell(); }
	};
class D2 : virtual public D1 {
	//char name;
	public:
		D2() { name = '2'; }
		void Tell(void) { cout << name; B::Tell(); }
	};
class D3 : virtual public D2 {
	//char name;
	public:
		D3() { name = '3'; }
		void Tell(void) { cout << name; D2::Tell();  }
	};

int main(void)
	{
	    //cout << "sahi";
	B b;
	D1 d1;
	D2 d2;
	D3 d3;
  //  b=d1;
    b.Tell();
	d1.Tell();
	d2.Tell();
	d3.Tell();
	return 0;
	}

