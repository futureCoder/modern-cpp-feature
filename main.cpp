#include <iostream>
#include "template/factorial.h"
#include "template/meta_programming.h"

#include "test_arc/test_arc.h"

int main() {
//    std::cout << factorial<5>::value << std::endl;
//    std::cout << While<Sum<10>::type>::type::type::value << std::endl;
    test_arc::main();
    std::cout << "wow" << std::endl;
}