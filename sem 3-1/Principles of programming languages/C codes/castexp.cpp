#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
class B {
	public:
		int key;
		B()
		{
			key = 0;
		 	printf("B constructed\n");
		}
        virtual void Tell(void)
		{
			static int count = 0;
			printf("B here with count %d, key %d\n",count++,key);
		}

		~B(void)
		{
			cout <<"B destroyed"<<endl << endl;
		}
	};


class D1 : public B
{
	public:
		D1(void)
		{
			B::key = 1;
			printf("D1 constructed %d\n\n",key);
		}
		D1(B b)
		{
			B::key = 2;
			b.Tell();
			printf("D1 constructed %d\n\n",key);
		}
		void Tell(void)
		{
			printf("D1 Here\n");
		}
		~D1(void)
		{
			cout <<"D1 destroyed"<<endl;
		}
	};

class D2 :private B
	{
    
    public:
        void Tell(void)
        {
            printf("asfas");

        }

	};

class D3 : virtual public B
{
	public:
		D3(void)
		{
			B::key = 3;
			printf("D3 constructed %d\n\n" , key);
		}
		D3(B b)
		{
			B::key = 4;
			b.Tell();
			printf("D3 constructed %d\n\n" , key);
		 }
		void Tell(void) { printf("D3 Here\n"); }
		~D3(void) {cout <<"D3 destroyed"<<endl;}
	};

int main(void)
	{
	B b;
	D1 d1;
	D2 d2;
	D3 d3;

	printf("\nExperiment Begins\n\n");

	/*printf(" b : "); b.Tell();
	printf("d1 : "); d1.Tell();
	printf("d2 : "); d2.Tell();
	printf("d3 : "); d3.Tell();*/

//	printf("(B)d1 : "); ((B)d1).Tell();//normal B's object would be constructed and it's tell will be called

//	dynamic_cast<B*>(&d1)->Tell();//if tell is virtual in B then d1's tell will be called else otherwise

//	printf("(B)d3 : "); ((B)d3).Tell();
/*	printf("(D1)((B)d1) : ");((D1)((B)d1)).Tell();
	printf("(static_cast<D1>((B)d1)) : ");
    (static_cast<D1>((B)d1)).Tell();
	printf("\n\n\n");*/
	

	printf("(D1)((B)d3) : "); ((D1)((B)d3)).Tell();
	printf("(static_cast<D1>((B)d3)) : "); (static_cast<D1>((B)d3)).Tell();
//	printf("\n\n\n");
	

	/*
	printf("(D3)((B)d1) : "); ((D3)((B)d1)).Tell();
	printf("(static_cast<D3>((B)d1)) : "); (static_cast<D3>((B)d1)).Tell();
	//printf("\n\n\n");
	//*/
	/*
	printf("(D3)((B)d3) : "); ((D3)((B)d3)).Tell();
	printf("(static_cast<D3>((B)d3)) : "); (static_cast<D3>((B)d3)).Tell();
	//printf("\n\n\n");
	//*/
	/*
	printf("\n\n\n"); d1.B::Tell();
	printf("\n\n\n"); d3.B::Tell();//*/


	B *bp;
	D3 *d3p;
	D1 *d1p;
	D2 *d2p;

	d1p = &d1;

	//bp = dynamic_cast<B*>(d1p);//ok
	printf("her thafa caonfasdf is :\n");

    /*d1p = (D1*)&b;//complete abuse 
    d1p->Tell();*/ 
    
	/*(dynamic_cast<B*>(d1p))->Tell();
	if(bp == NULL)
		printf("bp null\n");*/
    
	/*d3p = dynamic_cast<D3*>(bp);//allowed at compile time
	if(d3p == NULL)//this will give segment fault at run time if put above bp=dynamic_cast statement for bp above
		printf("d3p null\n");*/

	/*d2p = dynamic_cast<D2*>(bp);//this will also return null as the above dynamic cast of base pointer to d1 is responsible for that
	if(d2p == NULL)
		printf("d2p null\n");*/

	/*d1p = dynamic_cast<D1*>(bp);
	printf("\n");
	(dynamic_cast<D1*>(bp))->Tell();
	if(d1p == NULL)
		printf("d1p null\n");
	*/
	printf("\n\nExperiment Over\n\n\n");



	return 0;
}


