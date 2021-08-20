//
// Created by Kepler on 2021/8/18.
//

#include "LOG.h"
#include <log4cplus/logger.h>
#include <iostream>


int main() {
    if (!LOG::instance().open_log())
    {
        std::cout << "Log::open_log() failed" << std::endl;
        return false;
    }
    INFO("Server init succ");
    return 0;
}