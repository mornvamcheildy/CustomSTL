cmake_minimum_required(VERSION 3.10)
project(CustomSTL)

# Tell the compiler where to find your .h files
include_directories(Headers)

# Define the executable and where the source code is
add_executable(stl_test Sources/main.cpp)
