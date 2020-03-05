cmake_minimum_required(VERSION 3.15)
project(Pybind11)

set(CMAKE_CXX_STANDARD 14)

# find pybind11
find_package(pybind11 REQUIRED)

# binding C++ with Python
#pybind11_add_module(mine main.cpp)

# embed Python in C++
add_executable(mine main.cpp)
target_link_libraries(mine PRIVATE pybind11::embed)
