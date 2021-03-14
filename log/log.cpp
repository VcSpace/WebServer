#include "log.h"

Log::Log()
{}

Log::~Log()
{}

void Log::setFilename(const char* filename)
{
    time_t t = time(NULL);
    /*
     * https://blog.csdn.net/linfengmove/article/details/104562569
     */
    struct tm *sys_tm = localtime(&t);
    struct tm my_tm = *sys_tm;

    char t_time[24] = {0};
    snprintf(t_time, 24, "%d_%02d_%02d-%02d_%02d", my_tm.tm_year + 1900, my_tm.tm_mon + 1, my_tm.tm_mday, my_tm.tm_hour, my_tm.tm_min);

    snprintf(m_file_name, 255, "%s_%s_%s", "./logs/", t_time, filename);
}

void Log::init(const char *file_name, int log_buf_size, int split_lines, int max_queue_size)
{
    setFilename(file_name);
    if(max_queue_size > 1)
    {
        m_is_async = true;
    }

}
