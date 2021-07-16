//
// Created by 董子雄 on 2021/6/8.
//

#ifndef CPP_FEATURE_VARIADIC_TEMPLATES_H
#define CPP_FEATURE_VARIADIC_TEMPLATES_H

#include <iostream>

void print_x() {}

template <typename T, typename... Types>
void print_x(const T& first_arg, const Types&... args) {
    std::cout << first_arg << std::endl;    // print first argument
    print_x(args...);   // call print() for remaining arguments
}

void test_print_x() {
    print_x(0, "aaa", 3.1415926, std::bitset<16>(377));
    void* ptr = malloc(100);
}

#endif //CPP_FEATURE_VARIADIC_TEMPLATES_H
