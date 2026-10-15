cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(matrix)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(matrix src/main.cpp)

add_executable(my_test tests/test_vector_1.cpp tests/test_vector_2.cpp tests/test_matrix.cpp)

enable_testing()