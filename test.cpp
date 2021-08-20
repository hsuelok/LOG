//
// Created by Kepler on 2021/8/18.
//

#include "LOG.h"
#include <log4cplus/logger.h>

log4cplus::Logger LOG::logger_;
int main()
{
    LOG log;
    log.debug("1234");
    return 0;
}