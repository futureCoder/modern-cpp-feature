//
// Created by 董子雄 on 2021/8/3.
//

#ifndef CPP_FEATURE_PRINT_H
#define CPP_FEATURE_PRINT_H

namespace util {

template <typename... Args>
void print(Args... args) {
    std::cout << (... + args) << std::endl;
}

} // namespace util

#endif //CPP_FEATURE_PRINT_H
