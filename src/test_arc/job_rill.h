//
// Created by 董子雄 on 2021/7/30.
//

#ifndef CPP_FEATURE_JOB_RILL_H
#define CPP_FEATURE_JOB_RILL_H

class JobRillBase {
public:
    virtual ~JobRillBase() {}
    /**
     * @brief 执行当前 JobRill 的接口函数
     */
    virtual void run() = 0;         //!< for Executor
    /**
     * @brief 从当前 JobRill 中偷走一个待执行的 Job
     * @return `nullptr` 无待执行的 Job；`待执行的 Job 指针`
     */
    virtual JobRunable * steal() = 0;  //!< for Executor
};

template <class ItemType>
class JobRill : public JobRillBase {
    friend class ItemwiseJobImpl<ItemType>;
public:

};

#endif //CPP_FEATURE_JOB_RILL_H
