//
// Created by Kepler on 2021/8/18.
//



#include "LOG.h"
#include <memory>

// LOG Level: FATAL, ERROR, WARN, INFO, DEBUG, TRACE.

Logger LOG::_logger = log4cplus::Logger::getInstance("main_log");


LOG::LOG(){
    snprintf(_log_path, sizeof(_log_path), "%s", ".");
    snprintf(_log_name, sizeof(_log_name), "%s/%s.%s", _log_path, "app", "log");
}

LOG::LOG(const char* file_name){
    snprintf(_log_path, sizeof(_log_path), "%s", ".");
    snprintf(_log_name, sizeof(_log_name), "%s/%s.%s", _log_path, file_name, "log");
}

LOG::LOG(const char* pth,const char* file_name){
    snprintf(_log_path, sizeof(_log_path), "%s", pth);
    snprintf(_log_name, sizeof(_log_name), "%s/%s.%s", _log_path, file_name, "log");
}

LOG::~LOG(){

}

LOG& LOG::instance() {
    static LOG log;
    return log;
}

LOG& LOG::instance(const char* file_name){
    static LOG log(file_name);
    return log;
}

LOG& LOG::instance(const char* pth, const char* file_name){
    static LOG log(pth, file_name);
    return log;
}

bool LOG::open_log()
{

    int Log_level = 0;

    /* step 1: Instantiate an appender object */
    SharedAppenderPtr _append(new FileAppender(_log_name, std::ios_base::app));
    _append->setName("file log test");

    /* step 2: Instantiate a layout object */
    std::string pattern = "[%p] [%D{%m/%d/%y %H:%M:%S, %Q}] [%t] - %m [%F:%L] %n";

    //    std::unique_ptr<Layout> _layout(new PatternLayout(pattern));

    //    std::auto_ptr<Layout> pTTCLayout(new TTCCLayout());
    /* step 3: Attach the layout object to the appender */
    //    _append->setLayout(_layout);
    _append->setLayout(std::unique_ptr<Layout>(new PatternLayout(pattern)));
    //    _append->setLayout(pTTCLayout);
    /* step 4: Instantiate a logger object */

    /* step 5: Attach the appender object to the logger  */
    LOG::_logger.addAppender(_append);

    /* step 6: Set a priority for the logger  */
    LOG::_logger.setLogLevel(Log_level);



    return true;
}