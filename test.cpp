//
// Created by Kepler on 2021/8/18.
//

#include "LOG.h"
#include <log4cplus/logger.h>
#include <iostream>


int main() {
    const char* file_name = "asd";
    if (!LOG::instance(file_name).open_log())
    {
        std::cout << "Log::open_log() failed" << std::endl;
        return false;
    }
    INFO("Server init succ");
    return 0;
}