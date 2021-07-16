/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/08 23:14:24
* @version $Revision$
* @brief
*
**/

#ifndef CPP_FEATURE_META_PROGRAMMING_H
#define CPP_FEATURE_META_PROGRAMMING_H

/*
 * 元编程最主要的一点：需要把计算转变成类型推导(类型计算)
 */

// if
template <bool condition, typename Then, typename Else>
struct If;

template <typename Then, typename Else>
struct If<true, Then, Else> {
    using type = Then;
};

template <typename Then, typename Else>
struct If<false, Then, Else> {
    using type = Else;
};

// while
template <bool condition, typename Body>
struct WhileLoop;

template <typename Body>
struct WhileLoop<true, Body> {
    using type = typename WhileLoop<Body::cond_value, typename Body::next_type>::type;
};

template <typename Body>
struct WhileLoop<false, Body> {
    using type = typename Body::res_type;
};

template <typename Body>
struct While {
    using type = WhileLoop<Body::cond_value, Body>;
};

// integer
template <typename T, T v>
struct integral_constant {
    static const T value = v;
    using value_type = T;
    using type = integral_constant;
};

template <int result, int n>
struct SumLoop {
    static const bool cond_value = (n != 0);
    static const int res_value = result;
    using res_type = integral_constant<int, res_value>;
    using next_type = SumLoop<result + n, n - 1>;
};

template <int n>
struct Sum {
    using type = SumLoop<0, n>;
};

#endif //CPP_FEATURE_META_PROGRAMMING_H
