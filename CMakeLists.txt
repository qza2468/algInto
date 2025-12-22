cmake_minimum_required(VERSION 4.1)
project(algInto)

set(CMAKE_CXX_STANDARD 20)

find_package(benchmark REQUIRED)


add_executable(algInto main.cpp insertSort.cpp
        mergeSort.cpp
        bubbleSort.cpp
        utils/utils.cpp
)

target_link_libraries(algInto benchmark::benchmark)
