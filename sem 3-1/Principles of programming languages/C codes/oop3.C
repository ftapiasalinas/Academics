#include<iostream>
using namespace std;
class B {
  public:
    int b_;
};

class D1 : public B {
};

class D2 : public B {
};

class D1v : public  virtual B {
};

class D2v : public virtual B {
};

class D : public D1, public D2 {
public:
  void f() {
//   b_= 4;   // error C2385 D::b_ is ambigous,
              // could be the 'b_' in base 'B' of base 'D1' of class 'D'
              // or the 'b_' in base 'B' of base 'D2' of class 'D'

  D1::b_ = 5; // Ok
  D2::b_ = 6; // Ok
cout<<"sahil is here";
}
};

class Dvv : public virtual D1, public virtual D2 {
public:
  void f() {
//   b_ = 4;   // error C2385: 'Dvv::b_' is ambiguous
               // could be the 'b_' in base 'B' of base 'D1' of class 'Dvv'
               // or the 'b_' in base 'B' of base 'D2' of class 'Dvv'

  D1::b_ = 7;  // Ok
  D2::b_ = 8;  // Ok
}
};

class D_vv : public D1v, public D2v {
public:
  void f() {
  b_=4;  // Ok
  D1v::b_=5;
  D2v::b_=6;
  if (     b_ != D1v::b_ ||
           b_ != D2v::b_ ||
      D1v::b_ != D2v::b_)
  {
    throw "Should not be thrown";
  }
}
};






int main() {

  D d;
  d.f();

  //Dvv dvv;
  //dvv.f();

  D_vv d_vv;
  d_vv.f();


  return 0;
}

