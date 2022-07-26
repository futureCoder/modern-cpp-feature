#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <numeric>

#include "utils/string_util.h"
//#include "template/factorial.h"
//#include "template/meta_programming.h"

//#include "test_arc/test_arc.h"


//#include "template/cpp_templates_2ed/test_stack_impl.h"

bool get_ngram(const std::vector<std::string>& chars,
        std::set<std::string>& ngram, int n) {
    if (n < 1) {
        return true;
    }
    for (int i = 0; i < (chars.size() - n + 1); i++) {
        std::string str_ngram = "";
        for (int j = i; j < std::min(i + n, (int) chars.size()); j++) {
            str_ngram.append(chars[j]);
        }
        ngram.insert(str_ngram);
    }
    return true;
}
#define MAX_BUFFER_LEN 5

struct test{
    char char_buffer[100];
};


struct DaQueryInfoFlags {
    // intent策略标记位，采用位域结构
    uint32_t rerank_cmd_flag : 1; // rerank多轮控制提权，占用1个bit
    uint32_t timeliness_flag : 1; // 时效性提权， 占用1gebit
    uint32_t other : 30;
    DaQueryInfoFlags& operator=(uint32_t val) {
        rerank_cmd_flag = val & 0x01;
        timeliness_flag = val & 0x02;
        other = val & 0xFFFFFFFC;
        return *this;
    }
};

#include <type_traits>
#include <unordered_map>
#include <sstream>
#include <unistd.h>
#include <fstream>

std::string to_lower(const std::string &str) {
    std::string lower = str;
    for (int i = 0; i < (int)lower.size(); i++)
    {
        std::cout <<str[i] << " ";
        if ((lower[i] >= 'A') && (lower[i] <= 'Z'))
        {
            lower[i] += 'a' - 'A';
        }
    }
    std::cout << std::endl;
    return lower;
}

class AnnResultMerger {
public:
    void compare(const AnnResultMerger& rhs) {

    }
    class AnnResult {
    public:
        int source_id = -1;
        int target_id = -1;
        double dist = std::numeric_limits<double>::max();
    };
public:
    bool append_file(std::string file_name) {
        std::ifstream infile(file_name, std::ios::in);
        if (!infile) {
            std::cout << file_name << " invalid" << std::endl;
            return false;
        }

        std::string line;
        int32_t line_nu = 0;
        while(std::getline(infile, line)) {
            std::vector<std::string> items;
            util::StringUtil::split(line, '\t', items);
            if (items.size() < 3) {
                std::cout << line_nu << " format invalid" << std::endl;
                continue;
            }
            AnnResult ann_result;
            ann_result.source_id = std::stoi(items[0]);
            ann_result.target_id = std::stoi(items[1]);
            ann_result.dist = std::stod(items[2]);
            _res_map[ann_result.source_id].push_back(ann_result);
        }
        return true;
    }
    bool output_file(std::string file_name) {
        std::ofstream outfile(file_name, std::ios::out);
        if (!outfile) {
            std::cout << file_name << " invalid" << std::endl;
            return false;
        }
        for (const auto& item : _res_map) {
            auto ann_results = item.second;
            std::sort(ann_results.begin(), ann_results.end(), [](const AnnResult& lhs, const AnnResult& rhs){
                return lhs.dist < rhs.dist;
            });
            for (int i = 0; i < 5; ++i) {
                outfile << ann_results[i].source_id << '\t'
                        << ann_results[i].target_id << '\t'
                        << ann_results[i].dist << std::endl;
            }
        }
    }

    struct ann_result_cmp {
        bool operator()(const AnnResult& lhs, const AnnResult& rhs) {
            return lhs.dist < rhs.dist;
        };
    };

private:
    std::map<int, std::vector<AnnResult>> _res_map;
};

class ClassTest {
    ClassTest() {};
    ~ClassTest();
};

void heap_adjust(std::vector<int>& nums, int i, int len) {
    int l = 2 * i + 1;
    if (l >= nums.size() or l >= len) {
        return;
    }
    while (l < nums.size() && l < len) {
        if (l + 1 < len && nums[l + 1] < nums[l]) {
            ++l;
        }
        if (nums[l] < nums[i]) {
            std::swap(nums[l], nums[i]);
        }
        i = l;
        l = i * 2 + 1;
    }
}

void make_heap(std::vector<int>& nums) {
    for (int i = nums.size() / 2; i >= 0; --i) {
        heap_adjust(nums, i, nums.size());
    }
}

int partition(std::vector<int>& nums, int begin, int end) {
    int pivot = (end - begin) / 2 + begin; // mid
    while(begin < end) {
        while(nums[begin] <= nums[pivot] && begin < pivot) ++begin;
        while(nums[end - 1] >= nums[pivot] && pivot < end) --end;
        if (begin >= end) break;
        std::swap(nums[begin], nums[end -1 ]);
    }
    return pivot;
}

void quick(std::vector<int>& nums, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int pivot = partition(nums, begin, end);
    quick(nums, begin, pivot);
    quick(nums, pivot + 1, end);
}
void quick(std::vector<int>& nums) {
    quick(nums, 0, nums.size());
}

int main() {
    std::vector<int> nums {99,1,2,3};
    quick(nums);
    for (auto i : nums) {
        std::cout << i << ",";
    }
    std::cout << std::endl;

//    make_heap(nums);
//    for (auto i : nums) {
//        std::cout << i << ",";
//    }
//    std::cout << std::endl;
//
//    for (int i = nums.size() - 1; i > 0; --i) {
//        std::swap(nums[0], nums[i]);
//        heap_adjust(nums, 0, i);
//    }
//
//    for (auto i : nums) {
//        std::cout << i << ",";
//    }
//    std::cout << std::endl;


//    std::unique_ptr<AnnResultMerger> uptr_null;
//    std::unique_ptr<AnnResultMerger> uptr = std::make_unique<AnnResultMerger>();
//    std::cout << "hello world" << std::endl;
//    std::map<int,int> mmm;
//    for (auto it = mmm.begin(); it != mmm.end(); it++) {
//        std::cout << "_user_edu_ctrls.key is:" << it->first;
//    }
//    float fnum = 77777219379237912379123791.0;
//    int inum = fnum;

//    AnnResultMerger ann_result_merger;
//    ann_result_merger.append_file("search.output.shard0");
//    ann_result_merger.append_file("search.output.shard1");
//    ann_result_merger.append_file("search.output.shard2");
//    ann_result_merger.append_file("search.output.shard3");
//    ann_result_merger.output_file("search.output");

//    std::vector<int> vvv{4,5,12,56};
//    std::sort(vvv.begin(), vvv.end(), [](int lhs, int rhs) {
//        return lhs < rhs;
//    });
//
//    for (auto i : vvv) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//
//    std::string cmd = "ps u -p " + std::to_string(getpid());
//    FILE* fp = nullptr;
//
//    if ((fp = popen(cmd.c_str(), "r")) != nullptr) {
//        char temp_ret[1024];
//        cmd = "\n";
//
//        while (fgets(temp_ret, sizeof(temp_ret), fp) != nullptr) {
//            cmd += temp_ret;
//        }
//
//        pclose(fp);
//        std::cout << cmd << std::endl;
//    }

//    std::istringstream ss("testa b c");
//    std::string a,b,c;
//    ss >> a >> b >> c;
//    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
//    std::vector<int> vecInt;
//    for (int i = 0; i < 100; ++i) {
//        int inc = i % 2;
//        if (inc) {
//            vecInt.push_back(10);
//        } else {
////            vecInt.push_back(11);
//        }
//    }
//    std::cout << "size: " << vecInt.size() << std::endl;
//
//    for (int i = 0; i < vecInt.size(); ++i) {
//        if (vecInt[i] == 10) {
//            vecInt.erase(vecInt.begin() + i);
//        }
//    }
//    std::cout << "size: " << vecInt.size() << std::endl;
//    for (int i = 0; i < vecInt.size(); ++i) {
//        std::cout << vecInt[i] << std::endl;
//    }
//    std::unordered_map<std::string, int> mm;
//    mm.insert({"",1});
//    auto iter = mm.find("");
//    if(iter == mm.end()) {
//        std::cout << "not find" << std::endl;
//    } else {
//        std::cout << "finded" << std::endl;
//    }
//
//    for (const auto& item : mm) {
//        std::cout << item.first << "--" << item.second << std::endl;
//    }

//    DaQueryInfoFlags q1{};
//    q1.rerank_cmd_flag = 1;
//    uint32_t i1 = *(uint32_t*)(&q1);
//    std::cout << i1 << std::endl;
//    q1 = 1;
//    std::cout << q1.rerank_cmd_flag << std::endl;
//
//    DaQueryInfoFlags q2{};
//    q2.timeliness_flag = 1;
//    uint32_t i2 = *(uint32_t*)(&q2);
//    std::cout << i2 << std::endl;
//
//    q2 = 2;
//    std::cout << q1.timeliness_flag << std::endl;

//    auto funcPtr = +[](){};
//    static_assert(std::is_same<decltype(funcPtr), void(*)()>::value);
//}

//int main() {
//
//    float fval = 0.0002;
//    std::cout << std::to_string(fval) << std::endl;
//
//    test a;
//    strncpy(a.char_buffer, "hello, world", 11);
//
//    test a_cpy = a;
//    std::cout << a_cpy.char_buffer << std::endl;
//
//    strncpy(a.char_buffer, "hello, world111", 15);
//    std::cout << a_cpy.char_buffer << std::endl;
//    std::cout << a.char_buffer << std::endl;
//
////    std::string query_str = "hello";
////    char query[MAX_BUFFER_LEN];
////    snprintf(query, sizeof(query), "%s", query_str.c_str());
////
////    std::cout << sizeof(query) << std::endl;
////    std::cout << query << std::endl;
//
//
////    std::vector<std::string> chars;
////    std::set<std::string> ngram;
////    std::map<int,int> mymap;
////    auto iter = mymap.find(1);
////    std::cout << iter->second ;
//
////    get_ngram(chars, ngram, 2);
////    std::cout << factorial<5>::value << std::endl;
////    std::cout << While<Sum<10>::type>::type::type::value << std::endl;
////    vt::test();
////    algorithms::main();
////    cpp_templates::main();
//    std::cout << "wow" << std::endl;
    return 0;
}