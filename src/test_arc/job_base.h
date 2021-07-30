//
// Created by 董子雄 on 2021/7/30.
//

#ifndef CPP_FEATURE_JOB_BASE_H
#define CPP_FEATURE_JOB_BASE_H

template <class ItemType> class JobRill;

/**
 * @brief Job 基类，接口类，主要用于在 Executor 中屏蔽类型细节
 */
class JobRunable {
public:
    virtual ~JobRunable() {}
    /**
     * @brief 执行 Job
     * @return `<0` 代表出错；`>= 0` 代表到处理结束总共处理的 item 个数
     */
    virtual int run() = 0;  //!< for Executor

    virtual const std::string& name() const = 0;  //!< for chrome://tracing
};

#endif //CPP_FEATURE_JOB_BASE_H
