cmake_minimum_required(VERSION 4.1)
project(algInto)

set(CMAKE_CXX_STANDARD 20)

find_package(benchmark REQUIRED)

find_package(Eigen3 CONFIG REQUIRED)

add_executable(algInto main.cpp sort/insertSort.cpp
        sort/mergeSort.cpp
        sort/bubbleSort.cpp
        utils/utils.cpp
        matrix/multiply.cpp
        sort/heapSort.cpp
)

target_link_libraries(algInto PRIVATE benchmark::benchmark
        PRIVATE Eigen3::Eigen)
