cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(ExpressionTemplates LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_library(expressionTemplates INTERFACE)
target_include_directories(expressionTemplates INTERFACE include/)

add_subdirectory(tests)
