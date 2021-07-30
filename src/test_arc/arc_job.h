/***************************************************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/

/**
* @file src/FILENAME
* @author dongzixiong(dongzixiong@baidu.com)
* @date 2021/07/30 17:54:13
* @version $Revision$
* @brief
*
**/

#ifndef CPP_FEATURE_ARC_JOB_H
#define CPP_FEATURE_ARC_JOB_H

class ARCJob {
public:
    ARCJob();
    ARCJob(const ARCJob&) = delete;
    ARCJob& operator=(const ARCJob&) = delete;
    ~ARCJob();
};

class QueryARCJob : public ARCJob {};

class ResultARCJob : public ARCJob {};

#endif //CPP_FEATURE_ARC_JOB_H
