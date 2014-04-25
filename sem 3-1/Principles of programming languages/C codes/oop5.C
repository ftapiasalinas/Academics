#include<iostream>

using namespace std;

class class1 {
	//private:
		int size;
		int *a;
	public:
		class1(int n=1)
		{
		cout << "Getting " << (size=n) << " new ints\n";
		if(size > 0) a = new int[size]; else a = NULL;
		}

		void tell(void)
		{
		cout << "Size " << size << endl;
		int i;
		for(i = 0; i < size; i++)
			{
			cout << "a[" << i << "]=" << a[i] << " ";
			}
		cout << endl;
		}
		~class1(void)
		{
		cout << "Destroyed " << size << " ints\n";
		}
	} ;

int main(void)
	{
	class1 c1(10);
	class1 *p1 = new class1[2];
	p1->tell();
	p1[1].tell();
	c1.tell();
	delete[] p1;
	return 0;
	}
