#include <cstdio>


class A {
public:
  virtual A() = 0;

  virtual void Print() = 0;

  virtual ~A() = 0;
};


//class B: virtual public A {
  //int y;
//public:
  //B(int x, int y): A(x) {
    //this->y = y;
    //printf("b constructor\n");
  //}

  //void Print() override {
    //printf("x: %d, y: %d\n", x, y);
  //}
//};


int main() {
//  B b(1, 2);
  //A* bp = &b;
  //B* casted_p = dynamic_cast<B*>(bp);
//  casted_p->Print();
  return 0;
}

