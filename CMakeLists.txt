cmake_minimum_required(VERSION 3.10)
project(Webserver)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAG "-Wall -lpthread -lmysqlclient")

include_directories(server
        log
        sql)

add_executable(Webserver
    server/server.cpp
    server/server.h
    log/log.cpp
    log/log.h
    sql/sql.h
    sql/sql.cpp
    main.cpp)
