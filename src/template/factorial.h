//
// Created by 董子雄 on 2021/7/8.
//

#ifndef CPP_FEATURE_FACTORIAL_H
#define CPP_FEATURE_FACTORIAL_H

template <int n>
struct factorial {
    static constexpr int value = n * factorial<n - 1>::value;
};

template <>
struct factorial<0> {
    static constexpr int value = 1;
};

#endif //CPP_FEATURE_FACTORIAL_H
