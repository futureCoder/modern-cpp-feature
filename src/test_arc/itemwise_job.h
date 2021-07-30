/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/30 17:57:32
* @version $Revision$
* @brief
*
**/

#ifndef CPP_FEATURE_ITEMWISE_JOB_H
#define CPP_FEATURE_ITEMWISE_JOB_H

#include "rill_task.h"

template <class ItemType>
class ItemwiseJobImpl {
public:
    using task_type = typename TaskFactory<ItemType>::task_type;

    template <class... Args>
    void emplace_back(Args &&... obj) {
        _tasks.emplace_back(TaskFactory<ItemType>::new_task(obj...));
    }
    std::vector<task_type> _tasks;
};

#endif //CPP_FEATURE_ITEMWISE_JOB_H
