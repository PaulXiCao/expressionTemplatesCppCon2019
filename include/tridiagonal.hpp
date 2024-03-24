#pragma once

#include <ostream>
#include <vector>

#include "expressionTemplates.hpp"

template <class T>
class tridiagonal {
 private:
  std::vector<T> v_;

 public:
  explicit tridiagonal(std::size_t n) : v_(n) {}

  tridiagonal(std::initializer_list<T> lst) : v_{lst} {}

  template <class src_type>
  tridiagonal& operator=(src_type const& src) {
    index const I = v_.size();
    for (index i = 0; i < I; ++i) v_[i] = src[i];
    return *this;
  }

  T& operator[](index i) { return v_.at(i); }
  T operator[](index i) const { return v_.at(i); }

  template <class U>
  friend std::ostream& operator<<(std::ostream& os, const tridiagonal<U>& t);
};

template <class T>
constexpr bool is_binary_op_ok<tridiagonal<T>, tridiagonal<T>> = true;

template <class T>
struct is_array<tridiagonal<T>> : public std::true_type {};

template <class T>
std::ostream& operator<<(std::ostream& os, const tridiagonal<T>& t) {
  if (t.v_.empty()) return os;
  auto it = t.v_.begin();
  while (true) {
    os << *it;
    ++it;
    if (it == t.v_.end()) return os;
    os << ", ";
  }
}
