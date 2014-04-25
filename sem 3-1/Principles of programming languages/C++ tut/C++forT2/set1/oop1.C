#include <iostream>
#include <cstdio>
#include <math.h>

int gcount = 0;

using namespace std;

class B {
	public:
		virtual void f() { cout << "Hello world!\n"; }
		virtual void Tell() { f(); }
	};
class D1: virtual public B {
	public:
		void f() { cout << "Hello programmer!\n"; }
	};
class D2: public D1 {
	public:
		void Tell() { f(); }
	};

class stack {
	int top, size, *q;
	public:
		stack(int sz = 100) { q = new int [size = sz]; top = 0;
			cout << "New stack of " << size << " at " << q << "\n"; }
		int empty(void) { return top == 0; }
		int full(void) { return top == size; }
		int pop(void) { if(top) return q[--top]; else return top = 0; }
		int push(int x) { if(top < size) return q[top++] = x; else return -x; }
		friend void f1(stack&);
		~stack(void) { f1(*this); cout << "exiting stack " << q << "\n"; }
	};

void f1(stack& s) { printf("Size %d\n",s.size); }

class gobject {
	gobject *centre, *axis;
	public:
		gobject(void)
			{
			centre = NULL;
			axis = NULL;
			}
		virtual void draw(void)
			{
			}
	};

class line : public gobject {
	int m, c;
	};

void f2(void)
	{
	stack s[4];
	}

int main(void)
	{
	stack *s, s1(30);

	B *b;
	D1 d;
	b=&d;
	b->f();
	return 0;
	}
