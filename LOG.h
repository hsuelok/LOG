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
