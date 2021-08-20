//
// Created by Kepler on 2021/8/18.
//



#include "LOG.h"
#include <iostream>
using namespace std;

// LOG Level: FATAL, ERROR, WARN, INFO, DEBUG, TRACE.


using namespace log4cplus;


LOG::LOG(){
    log4cplus::Initializer initializer_;
    //    string file = path_ + file_name_;
    string file = "log.txt";
    log4cplus::SharedAppenderPtr fileAppender(new log4cplus::FileAppender(
            LOG4CPLUS_TEXT(file),
            std::ios_base::app
            )
            );
    fileAppender->setName(LOG4CPLUS_TEXT("file"));
    log4cplus::tstring pattern = LOG4CPLUS_TEXT("%D{%m/%d/%y %H:%M:%S,%Q} %-5p %c - %m [%l]%n");
    fileAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(pattern)));

    logger_ = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT ("LOG"));
    logger_.setLogLevel(log4cplus::INFO_LOG_LEVEL);
    logger_.addAppender(fileAppender);
    logger_.setLogLevel(log4cplus::ALL_LOG_LEVEL);
    LOG4CPLUS_INFO(logger_, LOG4CPLUS_TEXT("hello world!"));
}

void LOG::debug(const string& str){
    cout << "debug!!!" << endl;
    LOG4CPLUS_INFO(logger_, LOG4CPLUS_TEXT(str));
}

//void LOG::init() {
//    log4cplus::Initializer initializer;
//    log4cplus::SharedAppenderPtr consoleAppender(new log4cplus::ConsoleAppender);
//
//    string file = path_ + file_name_;
//    log4cplus::SharedAppenderPtr fileAppender(new log4cplus::FileAppender(
//            LOG4CPLUS_TEXT(file),
//            std::ios_base::app
//            )
//            );
//    fileAppender->setName(LOG4CPLUS_TEXT("file"));
//    log4cplus::tstring pattern = LOG4CPLUS_TEXT("%D{%m/%d/%y %H:%M:%S,%Q} %-5p %c - %m [%l]%n");
//    fileAppender->setLayout(std::unique_ptr<log4cplus::Layout>(new log4cplus::PatternLayout(pattern)));
//    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT ("LOG"));
//    logger.setLogLevel(log4cplus::INFO_LOG_LEVEL);
//    logger.addAppender(fileAppender);
//    LOG4CPLUS_INFO(logger, LOG4CPLUS_TEXT("Hello world"));
//}

void LOG::set_file_name(const string &file_name) {
    file_name_ = file_name;
}

void LOG::set_path(const string &path) {
    path_ = path;
}

