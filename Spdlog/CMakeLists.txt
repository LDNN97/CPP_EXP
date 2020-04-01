cmake_minimum_required(VERSION 3.15)
project(Spdlog)

set(CMAKE_CXX_STANDARD 14)

find_package(spdlog REQUIRED)

add_executable(Spdlog main.cpp test.h test.cpp)
target_link_libraries(Spdlog PRIVATE spdlog::spdlog_header_only)
