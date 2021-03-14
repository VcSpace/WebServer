#ifndef WEBSERVER_LOG_H
#define WEBSERVER_LOG_H

#include <cstring>
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <stdarg.h>
#include <chrono>

class Log {
public:
    static Log *get_instance()
    {
        static Log instance;
        return &instance;
    }

    void setFilename(const char* filename);
    void init(const char *file_name, int log_buf_size, int split_lines, int max_queue_size);

private:
    Log();
    virtual ~Log();

    char dir_name[128];
    char m_file_name[128];
    int log_line;
    bool m_is_async;

};

#endif //WEBSERVER_LOG_H
