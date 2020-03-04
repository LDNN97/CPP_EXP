cmake_minimum_required(VERSION 3.15)
project(Armadillo)

set(CMAKE_CXX_STANDARD 14)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(Armadillo main main.cpp)
target_link_libraries(Armadillo ${ARMADILLO_LIBRARIES})