# CppCon 2019: Expression Templates

Code taken from slides shown in the CppCon2019 talk "Expression Templates for Efficient, Generic Finance Code" by Bowie Owens.

- [video on YouTube](https://youtu.be/4IUCBx5fIv0)
- [slides](https://github.com/CppCon/CppCon2019/blob/e84f0777fb0e17517852c4b669c73ed66f6a1a91/Presentations/expression_templatesfor_efficient_generic_finance_code/expression_templatesfor_efficient_generic_finance_code__bowie_owens__cppcon_2019.pdf)


# Build

```bash
cmake -B build -G Ninja
cmake --build build
```

# Code structure and short explanation

- `include/expressionTemplates.hpp`: General `expr` class and concepts for whitelisted arguments for binary operation.
- `include/triangle.hpp`: One sample type making use of `expr`.
- `tests/standardExample.cpp`: Showing the general problem of temporaries in expressions.
- `tests/tests.cpp`: Applying expression templates for triangle matrix elementwise multiplication.
    Type `MyReal` is introduced to count multiplications.
