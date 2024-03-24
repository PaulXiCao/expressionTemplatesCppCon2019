#pragma once

#include <ostream>
#include <vector>

#include "expressionTemplates.hpp"

class tridiagonal {
 private:
  std::vector<double> v_;

 public:
  explicit tridiagonal(std::size_t n) : v_(n) {}

  tridiagonal(std::initializer_list<double> lst) : v_{lst} {}

  template <class src_type>
  tridiagonal& operator=(src_type const& src) {
    index const I = v_.size();
    for (index i = 0; i < I; ++i) v_[i] = src[i];
    return *this;
  }

  double& operator[](index i) { return v_.at(i); }
  double operator[](index i) const { return v_.at(i); }

  friend std::ostream& operator<<(std::ostream& os, const tridiagonal& t);
};

template <>
constexpr bool is_binary_op_ok<tridiagonal, tridiagonal> = true;

template <>
struct is_array<tridiagonal> : public std::true_type {};

std::ostream& operator<<(std::ostream& os, const tridiagonal& t) {
  if (t.v_.empty()) return os;
  auto it = t.v_.begin();
  while (true) {
    os << *it;
    ++it;
    if (it == t.v_.end()) return os;
    os << ", ";
  }
}
