#include <iostream>
#include "template/factorial.h"
#include "template/meta_programming.h"

//#include "test_arc/test_arc.h"

#include "test/test_variadic_template.h"

int main() {
//    std::cout << factorial<5>::value << std::endl;
//    std::cout << While<Sum<10>::type>::type::type::value << std::endl;
    vt::test();
    std::cout << "wow" << std::endl;
}