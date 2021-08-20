//
// Created by Kepler on 2021/8/18.
//

#include "LOG.h"
#include <log4cplus/logger.h>

log4cplus::Logger LOG::logger_;
log4cplus::Initializer initializer_;
string file = "log.txt";
log4cplus::SharedAppenderPtr fileAppender_(new log4cplus::FileAppender(
                                                   LOG4CPLUS_TEXT(file),
                                                   std::ios_base::app
                                           )
);

int main() {
    LOG log;
    log.debug("1234");
    return 0;
}