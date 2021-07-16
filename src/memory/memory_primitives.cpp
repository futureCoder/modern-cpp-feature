///***************************************************************************
// *
// * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// *
// **************************************************************************/
//
///**
//* @file src/FILENAME
//* @author dongzixiong(dongzixiong@baidu.com)
//* @date 2021/06/15 09:55:15
//* @version $Revision$
//* @brief
//*
//**/
//
//
//#include <cstdlib>
//#include <complex>
//#include <iostream>
//
//namespace memory {
//namespace primitives {
//
//int main() {
//    void* p1 = malloc(512); // 512 bytes
//    free(p1);
//
//    std::complex<int>* p2 = new std::complex<int>; // one object
//    delete p2;
//
//    void* p3 = ::operator new(512); // 512 bytes
//    ::operator delete(p3);
//
//    // 以下接口使用C++标准库提供的allocators。
//    // 其接口虽有标准规格，但实现厂商并未完全遵守; 下面三者形式略异。
//#ifdef _MSC_VER
//    // 以下两函数都是non-static，一定要通过 object 调用。以下分配三个ints
//    int* p4 = aallocator<int>().allocate(3, (int*)0);
//    allocator<int>().deallocate(p4, 3);
//#endif
//#ifdef __BORLANDC__
//    int* p4 = allocator<int>().allocate(5);
//    allocator<int>().deallocate(p4, 5);
//#endif
//#ifdef __GUNC__
//    void* p4 = allocator
//#endif
//
//    return 0;
//}
//
//int test_new_delete() {
//    std::string* pstr = new std::string();
//    std::cout << "str =" << *pstr << std::endl;
//    //pstr->std::string::string("jjhow");
//    return 0;
//}
//
//} // namespace primitives
//} // namespace memory