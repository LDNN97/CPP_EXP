cmake_minimum_required(VERSION 3.15)
project(ArgParser)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/)

add_executable(ArgParser main.cpp)
