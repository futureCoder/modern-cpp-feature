/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/30 17:50:05
* @version $Revision$
* @brief
*
**/

#ifndef CPP_FEATURE_RILL_TASK_H
#define CPP_FEATURE_RILL_TASK_H


#include <functional>
#include <utility>

/**
 * @brief 将多参数的函数指针、仿函数转换成单参数的 function 对象的帮助类
 */
template<class ItemType>
class TaskFactory {
public:
    // Task 工厂类产生的 task 类型：以 ItemType * 为输入参数，void 输出参数的 std::function
    using task_type = std::function<void(ItemType *)>;

    /**
     * @brief 用支持 ItemTypeView 的处理函数构造 task 算子
     * @example
     *   StrategyA a;
     *   auto task = Task<ItemType>::new_task(&StrategyA::process, &a);
     *   ItemType c = {...};
     *   task(&c);
     */
    template<typename T, class... Args>
    static task_type new_task(void(T::*fn)(Args*...), T *obj) {
        // 一般都是将派生类对象指针转换成基类指针，这里是将基类指针转为派生类指针，
        // 为确保转换安全，对 fn 的参数列表做以下编译期检查：
        // 1. 检查ItemType类是否有虚接口
        static_assert (false == std::is_polymorphic<ItemType>::value,
                "Function argument(s) type should not have virtual functions.");
//        // 2. 检查 fn 的参数是否都是 ItemType 的派生类型的指针，或者它本身
//        static_assert (is_all_true<std::is_convertible<Args *, const ItemType *>::value...>::value,
//                "Function argument(s) type is not derived from ItemType.");
//        // 3. 检查 fn 的参数大小与 ItemType 保持一致，即 ItemType 的 View 只能有方法，不得有成员变量
//        static_assert (is_all_eq<sizeof(ItemType), sizeof(Args)...>::value,
//                "Function argument(s) size is not equal to ItemType size.");
//        sizeof...(item)
        return bind_work(call_work, fn, obj);
    }

    template<class... Args>
    static task_type new_task(void(*fn)(Args*...)) {
        // 一般都是将派生类对象指针转换成基类指针，这里是将基类指针转为派生类指针，
        // 为确保转换安全，对 fn 的参数列表做以下编译期检查：
        // 1. 检查ItemType类是否有虚接口
        static_assert (false == std::is_polymorphic<ItemType>::value,
                "Function argument(s) type should not have virtual functions.");
//        // 2. 检查 fn 的参数是否都是 ItemType 的派生类型的指针，或者它本身
//        static_assert (is_all_true<std::is_convertible<Args *, const ItemType *>::value...>::value,
//                "Function argument(s) type is not derived from ItemType.");
//        // 3. 检查 fn 的参数大小与 ItemType 保持一致，即 ItemType 的 View 只能有方法，不得有成员变量
//        static_assert (is_all_eq<sizeof(ItemType), sizeof(Args)...>::value,
//                "Function argument(s) size is not equal to ItemType size.");
        return bind_work(call_work, fn);
    }

    static task_type new_task(task_type t) {
        return t;
    }

    /**
     * @brief 将 ItemType 指针强制转换为各个 ItemTypeView 的指针，然后再调用用户函数。
     */
    template <class T, class... Args>
    static void call_work(void(T::*fn)(Args*...), T* object, ItemType* item) {
        (object->*fn)(reinterpret_cast<Args*>(item)...);
    }


//    /**
//     * @brief 将 ItemType 指针强制转换为各个 ItemTypeView 的指针，然后再调用用户函数。
//     */
//    template <class... Args>
//    static void call_work(void(*fn)(Args*...), ItemType* item) {
//        (*fn)(reinterpret_cast<Args*>(item)...);
//    }

    /**
     * @brief 将不同类型的函数转换为只依赖 ItemType* 指针参数的函数算子
     */
    template<typename... Args>
    static task_type bind_work(void (*f)(Args..., ItemType *), Args... args) {
        return std::bind(f, args..., std::placeholders::_1);
    }
};

#endif //CPP_FEATURE_RILL_TASK_H
