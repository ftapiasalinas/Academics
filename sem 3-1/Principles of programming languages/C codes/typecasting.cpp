#include <cstdio>
#include <iostream>

using namespace std;
class A {};
class B { public: B (A a) {}  };


class CDummy
{
	float i,j;
};
class CAddition
{
	int x,y;
	public:
	CAddition (int a, int b) { x=a; y=b; }
	int result() { return x+y;}
};


int main()
{
	A a;
	B b=a; // implicit Conversion
		//because B has a constructor that takes an object of class A as parameter.
		//Therefore implicit conversions from A to B are allowed.

	CDummy d;
	//CAddition aaa= (CAddition)d;
	CAddition * padd;
	CAddition ca(5,10);
	padd = &ca;

    cout << padd->result() << endl;
	padd = (CAddition*) &d;

	cout << padd->result() << endl;

	/*Traditional explicit type-casting allows to convert any pointer into any other pointer type, independently of the
	types they point to. The subsequent call to member result will produce either a run-time error or a unexpected
	result.*/

	return 0;
}

