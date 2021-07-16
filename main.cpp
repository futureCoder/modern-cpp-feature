#include <iostream>
#include "template/factorial.h"
#include "template/meta_programming.h"

int main() {
    std::cout << factorial<5>::value << std::endl;
    std::cout << While<Sum<10>::type>::type::type::value << std::endl;
}