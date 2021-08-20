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

using std::string;
using namespace log4cplus;

#define DEBUG(str) LOG::debug(str)

class LOG {
public:
    LOG();
    void set_file_name(const string& file_name);
    void set_path(const string& path);
    static void debug(const string& str);
    static log4cplus::Logger logger_;

private:
    string file_name_;
    string path_;


};


#endif //LOG_LOG_H
