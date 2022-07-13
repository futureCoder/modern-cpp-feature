/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2022/05/25 17:27:12
* @version $Revision$
* @brief
*
**/

#ifndef DU_ANN_SERVER_STRING_UTIL_H
#define DU_ANN_SERVER_STRING_UTIL_H

#include <set>
#include <string>
#include <vector>

namespace util {

class StringUtil {
public:
    static void split(const std::string &str, const std::string &sep, std::set<std::string> &items);
    static void split(const std::string &str, char sep, std::set<std::string> &items);

    static void split(const std::string &str, const std::string &sep, std::vector<std::string> &items);
    static void split(const std::string &str, char sep, std::vector<std::string> &items);
};

} // namespace util




#endif //DU_ANN_SERVER_STRING_UTIL_H
