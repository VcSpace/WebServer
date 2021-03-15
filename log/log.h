#ifndef WEBSERVER_LOG_H
#define WEBSERVER_LOG_H

#include <cstring>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <cstdlib>
#include <stdarg.h>
#include <chrono>

class Log {
public:
    static Log* get_instance()
    {
        static Log instance;
        return &instance;
    }

    void setFilename(const char* filename);
    void init(const char *file_name, int log_buf_size, int split_lines, int max_queue_size);
    std::ofstream infile;

private:
    Log();
    virtual ~Log();

    char* m_buf; //缓冲区
    char m_file_name[128];
    bool m_is_async;
    int m_split_lines;  //日志最大行数
    int m_log_buf_size; //日志缓冲区大小
    long long m_count;  //日志行数记录
    int m_today;        //因为按天分类,记录当前时间是那一天
    FILE *m_fp;         //打开log的文件指针

};

#endif //WEBSERVER_LOG_H
