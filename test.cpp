//
// Created by Kepler on 2021/8/18.
//

#include "LOG.h"


int main()
{
    LOG log;
    LOG::logger_ = log4cplus::Logger();
    LOG::debug("1234");
}