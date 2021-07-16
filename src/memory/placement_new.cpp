///***************************************************************************
// *
// * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// *
// **************************************************************************/
//
///**
//* @file src/FILENAME
//* @author dongzixiong(dongzixiong@baidu.com)
//* @date 2021/06/22 10:14:58
//* @version $Revision$
//* @brief
//*
//**/
//
//#include <new>
//#include <string>
//#include <iostream>
//
//namespace memory {
//namespace primitives {
//
//int main() {
//    char* buf = new char[sizeof(std::string) * 3];
//    std::string* ps = new(buf)std::string("hello");
//    //...
//    std::cout << *ps << std::endl;
//    delete[] buf;
//    return 0;
//}
//
//}
//}