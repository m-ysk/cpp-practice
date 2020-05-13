#include <iostream>
using namespace std;

struct S {
  int n;
  S(int n) : n(n) { cout << "constructed: "s << n << "\n"s; }

  ~S() { cout << "destructed: "s << n << "\n"s; }
};

struct fractional {
  int num;
  int denom;

  fractional(int num, int denom) : num(num), denom(denom) {}

  fractional(int num) : fractional(num, 1) {}

  double to_double() { return double(num) / double(denom); }

  fractional operator+(fractional const& r) {
    if (denom == r.denom)
      return fractional{num + r.num, denom};
    else
      return fractional{num * r.denom + r.num * denom, denom * r.denom};
  }

  fractional operator-(fractional const& r) {
    if (denom == r.denom)
      return fractional{num - r.num, denom};
    else
      return fractional{num * r.denom - r.num * denom, denom * r.denom};
  }
};

int main() {
  fractional a{1, 2};
  cout << a.to_double() << endl;

  fractional b(1, 3);
  cout << b.to_double() << endl;

  auto c = a + b;
  cout << c.to_double() << endl;

  auto d = a - b;
  cout << d.to_double() << endl;
}
