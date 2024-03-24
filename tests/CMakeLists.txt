add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE expressionTemplates)

add_executable(standardExample standardExample.cpp)
