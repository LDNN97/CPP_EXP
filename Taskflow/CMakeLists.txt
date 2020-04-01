cmake_minimum_required(VERSION 3.15)
project(Taskflow)

set(CMAKE_CXX_STANDARD 14)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(Taskflow main.cpp)
TARGET_LINK_LIBRARIES(Taskflow Threads::Threads)
