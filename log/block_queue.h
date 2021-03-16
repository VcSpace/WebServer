#ifndef WEBSERVER_BLOCK_QUEUE_H
#define WEBSERVER_BLOCK_QUEUE_H

#include <mutex>
#include <pthread.h>
#include <cstdlib>
#include <cstring>
#include <string>


template<typename T>
class Block_queue
{
public:
    Block_queue();
    ~Block_queue();
    Block_queue(int max_queue_size = 1000);

private:
    int m_queue_size;

    pthread_mutex_t m_mutex;
};

#endif //WEBSERVER_BLOCK_QUEUE_H

template<typename T>
Block_queue<T>::Block_queue(int max_queue_size)
{
    m_queue_size = max_queue_size;
    if(m_queue_size <= 0)
    {
        std::cout << "m_queue_size <= 0" << std::endl;
        exit(-1);
    }

}
