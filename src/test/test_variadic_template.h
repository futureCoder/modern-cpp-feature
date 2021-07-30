//
// Created by 董子雄 on 2021/7/30.
//

#ifndef CPP_FEATURE_TEST_VARIADIC_TEMPLATE_H
#define CPP_FEATURE_TEST_VARIADIC_TEMPLATE_H

namespace vt {


template <typename ItemType>
class Factory {
public:
    template <typename T, typename... Args>
    static ItemType* new_task();
};

} // namespace vt


#endif //CPP_FEATURE_TEST_VARIADIC_TEMPLATE_H
