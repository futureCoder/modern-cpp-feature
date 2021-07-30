/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/30 18:00:45
* @version $Revision$
* @brief
*
**/


#include "itemwise_job.h"
#include "rill_trigger.h"

namespace test_arc {

int main() {
    RillTrigger* trigger_task = new RillTrigger(0, 0);

    ItemwiseJobImpl<ARCJob> job;
    job.emplace_back(&RillTrigger::trigger, trigger_task);
    return 0;
}

} // namespace test_arc