/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/30 17:53:23
* @version $Revision$
* @brief
*
**/

#ifndef CPP_FEATURE_RILL_TRIGGER_H
#define CPP_FEATURE_RILL_TRIGGER_H

#include <vector>
#include "arc_job.h"

class RillTrigger {
public:
    RillTrigger() : _recall_id(0), _level(0) {}
    RillTrigger(int recall_id, uint8_t level) : _recall_id(recall_id), _level(level) {}

//    // add_trigger
//    virtual bool set_trigger(Trigger* trigger) {
////        _triggers.push_back(trigger);
//        return true;
//    }

    virtual void trigger(QueryARCJob* query_re_job, ResultARCJob* result_re_job) {
        return;
    }

    virtual ~RillTrigger() {}

private:
    int _recall_id;
    uint8_t _level;
//    std::vector<Trigger*> _triggers;
};


#endif //CPP_FEATURE_RILL_TRIGGER_H
