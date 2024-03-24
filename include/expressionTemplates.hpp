#pragma once

#include <tuple>  // tuple, apply

using index = std::size_t;

template <class operand>
auto subscript(operand const& v, index const i);

struct expression {};

template <class callable, class... operands>
class expr : public expression {
 private:
  callable f_;
  std::tuple<operands const&...> args_;

 public:
  expr(callable f, operands const&... args) : args_(args...), f_(f) {}

  auto operator[](index const i) const {
    auto const call_at_index = [this, i](operands const&... a) {
      return f_(subscript(a, i)...);
    };
    return std::apply(call_at_index, args_);
  }
};

template <class T>
struct is_array {
  static constexpr bool value = false;
};

template <class T>
struct is_array<std::vector<T>> {
  static constexpr bool value = true;
};

template <class T>
constexpr bool is_array_v = is_array<std::remove_cv_t<T>>::value;

template <class T>
constexpr bool is_array_or_expression =
    is_array_v<T> || std::is_base_of_v<expression, std::remove_cv_t<T>>;

template <class operand>
auto subscript(operand const& v, index const i) {
  if constexpr (is_array_or_expression<operand>)
    return v[i];
  else
    return v;
}

template <class LHS, class RHS>
constexpr bool is_binary_op_ok =
    is_array_or_expression<LHS> || is_array_or_expression<RHS>;

template <class LHS, class RHS>
  requires(is_binary_op_ok<LHS, RHS>)
auto operator*(LHS const& lhs, RHS const& rhs) {
  return expr{[](auto const& l, auto const& r) { return l * r; }, lhs, rhs};
}
