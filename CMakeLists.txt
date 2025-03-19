# Minimum CMake version required
cmake_minimum_required(VERSION 3.16)

# Project name
project(VectorImplementation)

# Specify the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable and include the necessary source files
add_executable(testVector testVector.cpp Vector.cpp)