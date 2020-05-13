cmake_minimum_required(VERSION 3.15)
project(PyTorch)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_PREFIX_PATH ./libtorch)

option(DOWNLOAD_MNIST "Download the MNIST dataset from the internet" ON)
if (DOWNLOAD_MNIST)
    message(STATUS "Downloading MNIST dataset")
    execute_process(
            COMMAND python ${CMAKE_CURRENT_LIST_DIR}/download_mnist.py
            -d ${CMAKE_BINARY_DIR}/data
            ERROR_VARIABLE DOWNLOAD_ERROR)
    if (DOWNLOAD_ERROR)
        message(FATAL_ERROR "Error downloading MNIST dataset: ${DOWNLOAD_ERROR}")
    endif()
endif()

find_package(Torch REQUIRED)

add_executable(PyTorch main.cpp)
target_link_libraries(PyTorch "${TORCH_LIBRARIES}")
set_property(TARGET PyTorch PROPERTY CXX_STANDARD 14)