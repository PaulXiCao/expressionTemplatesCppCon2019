cmake_minimum_required(VERSION 3.14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE GTest::gtest_main expressionTemplates)
gtest_discover_tests(tests)

add_executable(standardExample standardExample.cpp)
