#include <cstdio>
using namespace std;

class CBase
{
	virtual void f(){}//what if f is not virtualp
};

class CDerived:virtual public CBase {

virtual void f()
{
    printf("afsd");
}
};

int main()
{
	CBase b; CBase* pb;
	CDerived d; CDerived* pd;
	pb = dynamic_cast<CBase*>(&d);// ok: derived-to-base
	pd = dynamic_cast<CDerived*>(&b);// wrong: base-to-derived ...  allowed only if base is polymorphic
	if(pd == NULL)
		printf("1) its null\n");

	//now pb points to d
	pd = dynamic_cast<CDerived*>(pb);
	if(pd == NULL)
		printf("2) its null\n");

	/*
	Compatibility note: dynamic_cast requires the Run-Time Type Information (RTTI) to keep track of dynamic
	types. Some compilers support this feature as an option which is disabled by default. This must be enabled for
	runtime type checking using dynamic_cast to work properly.
	*/


	return 0;
}
