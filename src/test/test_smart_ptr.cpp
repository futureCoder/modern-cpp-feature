/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/05 22:55:39
* @version $Revision$
* @brief
*
**/

#include <iostream>
#include "smart_ptr/smart_ptr.h"

namespace test_smart_ptr {

class Base {
public:
    virtual void print() const {
        std::cout << "im base" << std::endl;
    }
    int base = 0;
};

class DerivedA : public Base {
public:
    void print() const override {
        std::cout << "im derived a" << std::endl;
    }
    int derived = 10;
};

class DerivedB : public Base {
public:
    void print() const override {
        std::cout << "im derived b" << std::endl;
    }
    int derived = 20;
};

int main() {
    SmartPtr<DerivedA> da(new DerivedA());
    da->print();

    SmartPtr<Base> base(da);
    base->print();
}

} // namespace test_smart_ptr
