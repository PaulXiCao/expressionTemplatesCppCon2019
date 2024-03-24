#include <array>
#include <iostream>

class Vec {
 private:
  std::array<double, 3> arr;

 public:
  static constexpr size_t size = 3;

  // default ctor
  Vec() { std::cout << "Vec()\n"; }

  // copy ctor
  Vec(const Vec &other) {
    std::cout << "Vec(const Vec &other)\n";
    arr = other.arr;
  }

  // move ctor
  Vec(Vec &&other) {
    std::cout << "Vec(Vec &&)\n";
    arr = std::move(other.arr);
  }

  // copy assignment by const ref
  Vec &operator=(const Vec &other) {
    std::cout << "Vec& operator=(const Vec&)\n";
    arr = other.arr;
    return *this;
  }

  // copy assignment by rvalue
  Vec &operator=(Vec &&other) {
    std::cout << "Vec& operator=(Vec&&)\n";
    arr = std::move(other.arr);
    return *this;
  }

  double operator[](size_t i) const { return arr[i]; }
  double &operator[](size_t i) { return arr[i]; }

  ~Vec() { std::cout << "~Vec\n"; }
};

/// @brief sum 'u' and 'v' into a new instance of Vec
Vec operator+(Vec const &u, Vec const &v) {
  Vec sum;
  for (size_t i = 0; i < Vec::size; i++) {
    sum[i] = u[i] + v[i];
  }
  return sum;
}

int main() {
  std::cout << "`Vec a;`\n";
  Vec a;

  std::cout << "\n`a = a`\n";
  a = a;

  std::cout << "\n`a = a + a`\n";
  a = a + a;

  std:: cout << "\n`a = a + a + a`\n";
  a = a + a + a;

  std::cout << "\n<return from main>\n";
  return 0;
}
