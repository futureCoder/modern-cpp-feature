/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2022/05/25 17:30:14
* @version $Revision$
* @brief
*
**/


#include "string_util.h"

#include <vector>

namespace util {

void StringUtil::split(const std::string &str, const std::string &sep, std::vector<std::string> &items) {
    items.clear();
    auto sep_size = sep.size();
    size_t sep_pos = str.find(sep);
    size_t lst_pos = 0;
    while (sep_pos != std::string::npos) {
        items.emplace_back(str.substr(lst_pos, sep_pos - lst_pos));
        lst_pos = sep_pos + sep_size;
        sep_pos = str.find(sep, lst_pos);
    }
    if (lst_pos <= str.size()) {
        items.emplace_back(str.substr(lst_pos));
    }
}

void StringUtil::split(const std::string &str, char sep, std::vector<std::string> &items) {
    split(str, std::string(1, sep), items);
}

void StringUtil::split(const std::string &str, const std::string &sep, std::set<std::string> &items) {
    items.clear();
    auto sep_size = sep.size();
    size_t sep_pos = str.find(sep);
    size_t lst_pos = 0;
    while (sep_pos != std::string::npos) {
        items.insert(str.substr(lst_pos, sep_pos - lst_pos));
        lst_pos = sep_pos + sep_size;
        sep_pos = str.find(sep, lst_pos);
    }
    if (lst_pos <= str.size()) {
        items.insert(str.substr(lst_pos));
    }
}

void StringUtil::split(const std::string &str, char sep, std::set<std::string> &items) {
    split(str, std::string(1, sep), items);
}

} // namespace util