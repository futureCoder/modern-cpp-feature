//
// Created by 董子雄 on 2021/8/3.
//

#ifndef CPP_FEATURE_TEST_STACK_IMPL_H
#define CPP_FEATURE_TEST_STACK_IMPL_H

#include "stack_impl.h"

#include "utils/print.h"

namespace cpp_templates {

void main() {
    Stack<int> int_stack;
    int_stack.push(7);
    util::print(int_stack.top());

    Stack<std::string> string_stack;
    string_stack.push("hello");
    util::print(string_stack.top());
    string_stack.pop();
}

} // namespace cpp_templates

#endif //CPP_FEATURE_TEST_STACK_IMPL_H
