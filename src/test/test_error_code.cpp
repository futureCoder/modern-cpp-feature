/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/28 17:59:22
* @version $Revision$
* @brief
*
**/


#include <cstdio>

//class BCMergerSelector;
//class MergerSelector;
//
//class Any
//{
//
//public:
//    inline Any()
//            : _val_ptr{NULL}
//    {
//    }
//
//    template<class T>
//    inline Any(const T & val)
//            : _val_ptr{new Type<T>{val}}
//    {
//    }
//
//
//    /* First instantiated from: insights.cpp:71 */
//    template<>
//  inline Any<BCMergerSelector *>(BCMergerSelector *const & val)
//  : _val_ptr{static_cast<Typeless *>(new Type<BCMergerSelector *>(val))}
//  {
//  }
//
//
//    template<class T>
//    inline Any(const Any & other)
//            : _val_ptr{other._val_ptr ? (other._val_ptr)->clone() : NULL}
//    {
//    }
//
//    inline ~Any() noexcept
//    {
//        if(this->_val_ptr) {
//            delete this->_val_ptr;
//            this->_val_ptr = NULL;
//        }
//
//    }
//
//    template<class T>
//    inline T * any_cast()
//    {
//        return this->_val_ptr ? &(static_cast<Type<T> *>(this->_val_ptr)->_val) : NULL;
//    }
//
//    /* First instantiated from: insights.cpp:72 */
//    template<>
//  inline MergerSelector ** any_cast<MergerSelector *>()
//  {
//    return this->_val_ptr ? &(static_cast<Type<MergerSelector *> *>(this->_val_ptr)->_val) : NULL;
//  }
//
//
//private:
//    class Typeless;
//    class Typeless
//    {
//
//    public:
//        inline virtual ~Typeless() noexcept
//        {
//        }
//
//        virtual Typeless * clone() const = 0;
//
//        // inline constexpr Typeless() noexcept = default;
//    };
//
//    template<class T>
//    class Type : public Typeless
//    {
//
//    public:
//        inline explicit Type(const T & val)
//                : _val{val}
//        {
//        }
//
//        inline virtual Typeless * clone() const
//        {
//            return new Type<T>{this->_val};
//        }
//
//        T _val;
//    };
//
//    /* First instantiated from: insights.cpp:8 */
//
//    template<>
//  class Type<BCMergerSelector *> : public Typeless
//  {
//
//    public:
//    inline explicit Type(BCMergerSelector *const & val)
//    : Typeless()
//    , _val{val}
//    {
//    }
//
//    inline virtual Typeless * clone() const
//    {
//      return static_cast<Typeless *>(new Type<BCMergerSelector *>(this->_val));
//    }
//
//    BCMergerSelector * _val;
//    // inline virtual ~Type() noexcept = default;
//  };
//
//    /* First instantiated from: insights.cpp:22 */
//    template<>
//  class Type<MergerSelector *> : public Typeless
//  {
//
//    public:
//    inline explicit Type(MergerSelector *const & val);
//
//    inline virtual Typeless * clone() const;
//
//    MergerSelector * _val;
//  };
//
//
//private:
//    Typeless * _val_ptr;
//public:
//};
//
//
//
//class ARCJob
//{
//};
//
//
//class Merger
//{
//};
//
//
//
//class MergerSelector
//{
//
//public:
//    inline MergerSelector()
//    {
//    }
//
//    inline virtual bool init()
//    {
//        return true;
//    }
//
//    inline virtual Merger * get_merger(ARCJob * arc_job)
//    {
//        return nullptr;
//    }
//
//    inline ~MergerSelector() noexcept
//    {
//    }
//
//};
//
//
//
//class BCMergerSelector
//{
//
//public:
//    inline BCMergerSelector()
//    {
//    }
//
//    virtual bool init();
//
//    virtual Merger * get_merger(ARCJob * arc_job);
//
//    ~BCMergerSelector();
//
//};
//
//
//
//int main()
//{
//    Any object = Any(Any(new BCMergerSelector()));
//    MergerSelector * ptr = *(object.any_cast<MergerSelector *>());
//    return 0;
//}
