#include <iostream>

#include "tridiagonal.hpp"

class MyReal {
 private:
  double x;

 public:
  MyReal() = default;
  explicit MyReal(double x) : x(x) {}

 private:
  friend MyReal operator*(const MyReal lhs, const MyReal rhs);
  friend std::ostream& operator<<(std::ostream& os, const MyReal r);
};

unsigned countMultiplications = 0;

MyReal operator*(const MyReal lhs, const MyReal rhs) {
  countMultiplications++;
  return MyReal{lhs.x * rhs.x};
}

std::ostream& operator<<(std::ostream& os, const MyReal r) { return os << r.x; }

int main() {
  const tridiagonal<MyReal> x{MyReal(1.0), MyReal(2.0), MyReal(3.0)};
  const tridiagonal<MyReal> y{MyReal(1.0), MyReal(3.0), MyReal(5.0)};

  tridiagonal<MyReal> z(3u);
  z = x * y * x;

  std::cout << "x:\t\t" << x << '\n';
  std::cout << "y:\t\t" << y << '\n';
  std::cout << "z=x*y*x:\t" << z << '\n';

  std::cout << "number of multiplications: " << countMultiplications << '\n';

  return 0;
}
