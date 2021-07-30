//
// Created by 董子雄 on 2021/7/30.
//

#ifndef CPP_FEATURE_TEST_VARIADIC_TEMPLATE_H
#define CPP_FEATURE_TEST_VARIADIC_TEMPLATE_H

#include <string>
#include <vector>

namespace vt {

// C++14 以后好像有更好的办法，但 C++11暂时先这样了
// 编译期检查可变模板参数列表是否全为真
template <bool...>
struct bool_pack;

template <bool... v>
using is_all_true = std::is_same<bool_pack<true, v...>, bool_pack<v..., true>>;

// 编译期检查可变模板参数列表数值是否与 a 一致
template <int...>
struct int_pack;

template <int a, int... v>
using is_all_eq = std::is_same<int_pack<a, v...>, int_pack<v..., a>>;

template <typename ItemType>
class Factory {
public:
    // Task 工厂类产生的 task 类型：以 ItemType * 为输入参数，void 输出参数的 std::function
    using task_type = std::function<void(ItemType *)>;
    // Task 工厂类产生的 list_task 类型：以 std::vector<ItemType *> * 为输入参数，void 输出参数的 std::function
    using list_task_type = std::function<void(std::vector<ItemType *> *)>;
    template<typename T, class... Args>
    static task_type new_task(void(T::*fn)(Args*...), T *obj) {
        // 一般都是将派生类对象指针转换成基类指针，这里是将基类指针转为派生类指针，
        // 为确保转换安全，对 fn 的参数列表做以下编译期检查：
        // 1. 检查ItemType类是否有虚接口
        static_assert (false == std::is_polymorphic<ItemType>::value,
                "Function argument(s) type should not have virtual functions.");
        // 2. 检查 fn 的参数是否都是 ItemType 的派生类型的指针，或者它本身
        static_assert (is_all_true<std::is_convertible<Args *, const ItemType *>::value...>::value,
                "Function argument(s) type is not derived from ItemType.");
        // 3. 检查 fn 的参数大小与 ItemType 保持一致，即 ItemType 的 View 只能有方法，不得有成员变量
        static_assert (is_all_eq<sizeof(ItemType), sizeof(Args)...>::value,
                "Function argument(s) size is not equal to ItemType size.");
        return bind_work(call_work, fn, obj);
    }

    template<class... Args>
    static task_type new_task(void(*fn)(Args*...)) {
        // 一般都是将派生类对象指针转换成基类指针，这里是将基类指针转为派生类指针，
        // 为确保转换安全，对 fn 的参数列表做以下编译期检查：
        // 1. 检查ItemType类是否有虚接口
        static_assert (false == std::is_polymorphic<ItemType>::value,
                "Function argument(s) type should not have virtual functions.");
        // 2. 检查 fn 的参数是否都是 ItemType 的派生类型的指针，或者它本身
        static_assert (is_all_true<std::is_convertible<Args *, const ItemType *>::value...>::value,
                "Function argument(s) type is not derived from ItemType.");
        // 3. 检查 fn 的参数大小与 ItemType 保持一致，即 ItemType 的 View 只能有方法，不得有成员变量
        static_assert (is_all_eq<sizeof(ItemType), sizeof(Args)...>::value,
                "Function argument(s) size is not equal to ItemType size.");
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

    /**
     * @brief 将 ItemType 指针强制转换为各个 ItemTypeView 的指针，然后再调用用户函数。
     */
    template <class... Args>
    static void call_work(void(*fn)(Args*...), ItemType* item) {
        (*fn)(reinterpret_cast<Args*>(item)...);
    }
    /**
     * @brief 将不同类型的函数转换为只依赖 ItemType* 指针参数的函数算子
     */
    template<typename... Args>
    static task_type bind_work(void (*f)(Args..., ItemType *), Args... args) {
        return std::bind(f, args..., std::placeholders::_1);
    }
};

class ARCJob {
public:
    ARCJob(std::string name) : _name(std::move(name)) {}
    ARCJob(const ARCJob&) = delete;
    ARCJob& operator=(const ARCJob&) = delete;
    ~ARCJob();

    void print() {
        std::cout << _name << std::endl;
    }
    std::string _name = "arc_job";
};

class QueryARCJob : public ARCJob {
public:
    QueryARCJob() : ARCJob("QueryARCJob") { }
};

class ResultARCJob : public ARCJob {
public:
    ResultARCJob() : ARCJob("ResultARCJob") { }
};

class RillTrigger {
public:
    virtual void trigger(QueryARCJob* query_re_job, ResultARCJob* result_re_job, ARCJob* job, ResultARCJob* r_job) {
        if (nullptr == query_re_job || nullptr == result_re_job || nullptr == job || nullptr == r_job) {
            std::cout << "nullptr" << std::endl;
            return;
        }

        query_re_job->print();

        result_re_job->print();
    }
};

void test() {
    RillTrigger* trigger_task = new RillTrigger();
    using task_type = Factory<ARCJob>::task_type;
    std::vector<task_type> task_list;
    task_list.emplace_back(Factory<ARCJob>::new_task(&RillTrigger::trigger, trigger_task));
    ARCJob* arc_job = new ARCJob("arc");
    for (auto && task : task_list) {
        task(arc_job);
    }
}

} // namespace vt

#endif //CPP_FEATURE_TEST_VARIADIC_TEMPLATE_H
