//
// Created by Kepler on 2021/8/18.
//

#ifndef LOG_LOG_H
#define LOG_LOG_H
#include "log4cplus/loglevel.h"
#include "log4cplus/ndc.h"
#include "log4cplus/logger.h"
#include "log4cplus/configurator.h"
#include "iomanip"
#include "log4cplus/fileappender.h"
#include "log4cplus/layout.h"
#include <log4cplus/loggingmacros.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

#define PATH_SIZE 100

//日志封装
#define TRACE(p) LOG4CPLUS_TRACE(LOG::_logger, p)
#define DEBUG(p) LOG4CPLUS_DEBUG(LOG::_logger, p)
#define INFO(p) LOG4CPLUS_INFO(LOG::_logger, p)
#define WARNING(p) LOG4CPLUS_WARN(LOG::_logger, p)
#define FATAL(p) LOG4CPLUS_ERROR(LOG::_logger, p)

class LOG {
public:
    // 打开日志
    bool open_log();

    // 获得日志实例
    static LOG& instance();
    static LOG& instance(const char* file_name);
    static LOG& instance(const char* pth, const char* file_name);

    static Logger _logger;

private:
    LOG();
    LOG(const char* file_name);
    LOG(const char* pth, const char* file_name);

    virtual ~LOG();

    //log文件路径及名称
    char _log_path[PATH_SIZE];
    char _log_name[PATH_SIZE];
};


#endif //LOG_LOG_H
