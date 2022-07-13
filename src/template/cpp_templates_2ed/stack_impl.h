//
// Created by 董子雄 on 2021/8/3.
//

#ifndef CPP_FEATURE_STACK_IMPL_H
#define CPP_FEATURE_STACK_IMPL_H

#include <vector>
#include <cassert>

namespace cpp_templates {

template <typename T>
class Stack {
private:
    std::vector<T> elems; // elements
public:
    Stack();
    Stack(Stack const&); // copy constructor
    Stack& operator=(Stack const&); // assignment operator

    void push(T const& elem); // push element
    void pop(); // pop element
    T const& top() const; // return top element
    bool empty() const { // return whether the stack is empty
        return elems.empty();
    }
};

template <typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem); // append copy of passed elem
}

template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());
    elems.pop_back(); // remove last element
}

template <typename T>
T const& Stack<T>::top() const {
    assert(!elems.empty());
    return elems.back(); // return copy of last element
}

} // namespace cpp_templates

#endif //CPP_FEATURE_STACK_IMPL_H
