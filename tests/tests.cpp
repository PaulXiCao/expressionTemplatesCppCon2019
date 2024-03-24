#include <iostream>

#include "tridiagonal.hpp"

int main() {
  const tridiagonal x({1, 2, 3});
  const tridiagonal y({1, 3, 5});

  tridiagonal z(3u);
  z = x * y;

  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';
  std::cout << "z: " << z << '\n';

  return 0;
}
