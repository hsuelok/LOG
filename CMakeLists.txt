cmake_minimum_required(VERSION 3.18)
project(log)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(/usr/local/include/)
include_directories(/usr/bin)

add_executable(log
        LOG.cpp LOG.h test.cpp)
