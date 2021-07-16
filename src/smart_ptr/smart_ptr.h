/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/05 22:17:41
* @version $Revision$
* @brief
*
**/

#ifndef CPP_FEATURE_SMART_PTR_H
#define CPP_FEATURE_SMART_PTR_H

#include <algorithm>

class shared_count {
public:
    shared_count() noexcept : _count(1) {}
    ~shared_count() noexcept = default;

    void add_count() noexcept { ++_count; }
    int sub_count()  { return --_count; }
    int get_count() const noexcept { return _count; }

private:
    int _count;
};

template <typename T>
class SmartPtr {
public:
    template <typename U>
    friend class SmartPtr;

    explicit SmartPtr(T* ptr = nullptr) noexcept : _ptr(ptr),_ref_count(nullptr) {
        if (ptr) {
            _ref_count = new shared_count();
        }
    }

    ~SmartPtr() noexcept {
        if (_ptr && _ref_count->sub_count() == 0) {
            delete _ptr;
            delete _ref_count;
        }
    }

    SmartPtr(const SmartPtr& rhs) noexcept {
        _ptr = rhs._ptr;
        _ref_count = rhs._ref_count;
        if (_ptr) {
            _ref_count->add_count();
        }
    }

    template <typename U>
    explicit SmartPtr(SmartPtr<U>& rhs) noexcept {
        _ptr = rhs._ptr;
        _ref_count = rhs._ref_count;
        if (_ptr) {
            _ref_count->add_count();
        }
    }

    template <typename U>
    explicit SmartPtr(const SmartPtr<U>& rhs, T* ptr) {
        _ptr = ptr;
        _ref_count = rhs._ref_count;
        if (_ptr) {
            _ref_count->add_count();
        }
    }

    SmartPtr(SmartPtr&& rhs) noexcept {
        _ptr = rhs._ptr;
        _ref_count = rhs._ref_count;
        rhs._ptr = nullptr;
        rhs._ref_count = nullptr;
    }

    template <typename U>
    explicit SmartPtr(SmartPtr<U>&& rhs) noexcept {
        _ptr = rhs._ptr;
        _ref_count = rhs._ref_count;
        rhs._ptr = nullptr;
        rhs._ref_count = nullptr;
    }

    SmartPtr& operator=(SmartPtr rhs) noexcept {
        swap(rhs);
    }

    bool operator()() const { return _ptr != nullptr; }
    T* operator->() const { return _ptr; }
    T& operator*() const { return *_ptr; }


    void swap(SmartPtr& rhs) noexcept {
        using std::swap;
        swap(this->_ptr, rhs._ptr);
        swap(this->_ref_count, rhs._ref_count);
    }
private:
    T* _ptr {nullptr};
    shared_count* _ref_count{nullptr};
};

template <typename T>
void swap(SmartPtr<T>& lhs, SmartPtr<T>& rhs) noexcept {
    lhs.swap(rhs);
}

#endif //CPP_FEATURE_SMART_PTR_H
