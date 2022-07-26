cmake_minimum_required(VERSION 3.19)
project(cpp_feature)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(cpp_feature
        main.cpp
        src/utils/string_util.h src/utils/string_util.cpp src/test/test_coroutine.cpp src/algorithms/heap.h)