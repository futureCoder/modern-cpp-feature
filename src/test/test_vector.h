//
// Created by 董子雄 on 2021/6/25.
//

#include <iostream>
#include <vector>

namespace test {

class A {
public:
    A(int a) : _a(a) { std::cout << "A" << _a << std::endl; }
    ~A() { std::cout << "~A" << _a << std::endl; }
    int _a;
    std::string _str;
};

const int SIZE = 100;

#include "test/test_smart_ptr.cpp"

int main() {
    test_smart_ptr::main();
//    std::vector<A> vec_a;
//    vec_a.reserve(SIZE);
//    for (int i = 0; i < SIZE; ++i) {
//        vec_a.emplace_back(i);
//    }
//    std::cout << "size: " << vec_a.size() << std::endl;
//    std::cout << "capacity: " << vec_a.capacity() << std::endl;
//    vec_a.clear();
//
//    std::cout << "size: " << vec_a.size() << std::endl;
//    std::cout << "capacity: " << vec_a.capacity() << std::endl;
//    vec_a.shrink_to_fit();
//
//    std::cout << "size: " << vec_a.size() << std::endl;
//    std::cout << "capacity: " << vec_a.capacity() << std::endl;
//
//    std::string str;
//    str.shrink_to_fit();
    return 0;
}

}