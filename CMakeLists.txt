cmake_minimum_required(VERSION 3.19)
project(cpp_feature)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(cpp_feature main.cpp src/check_cpp_version.h src/variadic_templates.h src/memory/memory_primitives.cpp src/template/tag_dispatch.h src/memory/placement_new.cpp src/test/test_vector.h src/smart_ptr/smart_ptr.cpp src/smart_ptr/smart_ptr.h src/test/test_smart_ptr.cpp src/template/output_container.h src/template/factorial.h src/template/meta_programming.h)