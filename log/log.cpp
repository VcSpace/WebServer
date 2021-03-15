#include "log.h"

Log::Log()
{}

Log::~Log()
{}

void Log::setFilename(const char* filename)
{
    memset(m_file_name, '\0', sizeof(m_file_name));
    time_t t = time(NULL);
    /*
     * https://blog.csdn.net/linfengmove/article/details/104562569
     */
    struct tm *sys_tm = localtime(&t);
    struct tm my_tm = *sys_tm;

    char t_time[24] = {0};
    snprintf(t_time, 24, "%d_%02d_%02d-%02d:%02d", my_tm.tm_year + 1900, my_tm.tm_mon + 1, my_tm.tm_mday, my_tm.tm_hour, my_tm.tm_min);

    snprintf(m_file_name, 255, "%s%s_%s", "./logs/", t_time, filename);

}

void Log::init(const char *file_name, int log_buf_size, int split_lines, int max_queue_size)
{
    m_log_buf_size = log_buf_size;
    m_split_lines = split_lines;
    m_buf = new char[m_log_buf_size];
    memset(&m_buf, '\0', m_log_buf_size);

    if(max_queue_size > 1)
    {
        m_is_async = true;

    }

    setFilename(file_name);

    infile.open(m_file_name, std::ios::out);
    if(!infile)
    {
        std::cout << "infile error" << std::endl;
        exit(-1);
    }

    infile.close();

    return true;
}
