#include <cstdio>


class A {
protected:
  int x;
public:
  A(int x) {
    this->x = x;
    printf("a constructor\n");
  }

  virtual void Print() = 0;
};


class B: virtual public A {
  int y;
public:
  B(int x, int y): A(x) {
    this->y = y;
    printf("b constructor\n");
  }

  void Print() override {
    printf("x: %d, y: %d\n", x, y);
  }
};


int main() {
  B b(1, 2);
  A* bp = &b;
  B* casted_p = dynamic_cast<B*>(bp);
  casted_p->Print();
  return 0;
}

