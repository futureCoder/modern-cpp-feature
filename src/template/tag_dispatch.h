/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/06/16 19:11:06
* @version $Revision$
* @brief
*
**/

#ifndef CPP_FEATURE_TAG_DISPATCH_H
#define CPP_FEATURE_TAG_DISPATCH_H

struct STLTag{};
struct PBTag{};
struct NewTag{};

template <typename T, typename U = void>
struct TagDispatch {
    using Type = STLTag;
};

template <typename T>
struct TagDispatch<T, typename std::enable_if<std::is_pointer<typename T::Type>::value>::type> {
    using Type = PBTag;
};

template <typename T>
struct TagDispatch<T, typename std::enable_if<std::is_same<typename T::Type, int>::value>::type> {
    using Type = NewTag;
};

template <typename T>
inline void test_func_impl(T& obj, STLTag) {
    obj.print("STLTag");
}

template <typename T>
inline void test_func_impl(T& obj, NewTag) {
    obj.print("NewTag");
}

template <typename T>
inline void test_func_impl(T& obj, PBTag) {
    std::cout << std::is_pointer<T>::value << std::endl;
    std::cout << typeid(typename std::enable_if<std::is_pointer<T>::value>::type).name() << std::endl;

    obj->print("PBTag");
}

template <typename T>
inline void test_func(T& obj) {
//    std::cout << typeid(decltype(obj)).name() << std::endl;
    std::cout << typeid(T).name() << std::endl;
//    std::cout << "is pointer: " << std::is_pointer<T>::value << std::endl; //
//    std::cout << "is reference: " << std::is_reference<T>::value << std::endl;
//    std::cout << "after remove_reference, is pointer: " << std::is_pointer<std::remove_reference<decltype(obj)>>::value <<std::endl;
//    std::cout << "after remove_reference, is reference: " << std::is_reference<std::remove_reference<decltype(obj)>>::value <<std::endl;
//    static_assert(!std::is_pointer<T>::value, "param should not be a pointer");

    std::cout << typeid(typename std::enable_if<std::is_pointer<T>::value, T>::type).name() << std::endl;
//    using TYPE = typename std::decay<T>::type;
//    test_func_impl(obj, typename TagDispatch<TYPE>::Type{});
//    TYPE tmp;

}

#endif //CPP_FEATURE_TAG_DISPATCH_H
