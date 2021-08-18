//
// Created by Kepler on 2021/8/18.
//

#ifndef LOG_LOG_H
#define LOG_LOG_H
#include <string>

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <log4cplus/log4cplus.h>

#define DEBUG(debug) LOG4CPLUS_DEBUG(logger_, LOG4CPLUS_TEXT(debug))
#define INFO(info) LOG4CPLUS_DEBUG(logger_, LOG4CPLUS_TEXT(info))
#define ERROR(error) LOG4CPLUS_ERROR(logger_, LOG4CPLUS_TEXT(error))
#define FATAL(fatal) LOG4CPLUS_FATAL(logger_, LOG4CPLUS_TEXT(fatal))
#define TRACE(trace) LOG4CPLUS_TRACE(logger_, LOG4CPLUS_TEXT(trace))
#define WARN(warn) LOG4CPLUS_WARN(logger_, LOG4CPLUS_TEXT(warn))

using std::string;
using namespace log4cplus;

class LOG {
public:
    void init();
    void set_file_name(const string& file_name);
    void set_path(const string& path);

private:
    string file_name_;
    string path_;
    log4cplus::Initializer initializer_;
    log4cplus::Logger logger_;

};


#endif //LOG_LOG_H
