#ifndef WEBSERVER_THREAD_POOL_H
#define WEBSERVER_THREAD_POOL_H

#include <pthread.h>
#include <unistd.h>
#include <mutex>

template<typename T>
class Thread_pool {
public:
    Thread_pool();
    ~Thread_pool();
    Thread_pool(int thread_num = 8, int max_request = 1000);

private:
    pthread_t* m_threads;
    int m_max_thread_num;
    int m_max_request;

};

#endif //WEBSERVER_THREAD_POOL_H

template<typename T>
Thread_pool<T>::Thread_pool(int thread_num, int max_request)
{
    m_max_thread_num = thread_num;
    m_max_request = max_request;

    if(thread_num < 1 || max_request < 1)
    {
        throw std::exception();
        exit(-1);
    }

    m_threads = new pthread_t[thread_num];
    for(int i < 0; i)

}