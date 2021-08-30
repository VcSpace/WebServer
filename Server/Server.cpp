#include "Server.h"

Server::Server(int port, std::string host, std::string username, std::string password, std::string database,
                bool uselog, int linger, int mode, int sqlnum, int threadnum, int actor, int logmode)
                : m_port(port), m_host(host), m_username(username), m_password(password), m_database(database),
                    m_uselog(uselog), m_linger(linger), et(mode), m_sql_num(sqlnum), m_thread_num(threadnum), m_actor(actor), m_log_mode(logmode)
{

}

Server::~Server()
{}

void Server::setsql()
{
    m_consql = connSql::get_instance();
    m_consql->init(m_host, m_username, m_password, m_database, m_sql_num);
}

void Server::setlog(std::string path)
{
    m_log_path = path;
    if(m_uselog)
    {
        if(m_log_mode == 1)
        {
            Log::get_instance()->init(m_log_path, m_uselog, 2000, 800000, 800);
        } else{
            Log::get_instance()->init(m_log_path, m_uselog, 2000, 800000, 0);
        }
    }

}

void Server::threadpool()
{
    m_pool = new ThreadPool<Http>(m_actor, m_consql, m_thread_num);
}

void Server::trig_mode()
{
    switch(et)
    {
        case 0:
            m_listen_mode = 0;
            m_conn_mode = 0;
            break;
        case 1:
            m_listen_mode = 0;
            m_conn_mode = 1;
            break;
        case 2:
            m_listen_mode = 1;
            m_conn_mode = 0;
            break;
        case 3:
            m_listen_mode = 1;
            m_conn_mode = 1;
            break;
        default:
            m_listen_mode = 1;
            m_conn_mode = 1;
            break;
    }
}

void Server::event_listen()
{
    m_listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(m_listenfd >= 0);

    struct linger tmp = {m_linger, 1};
    setsockopt(m_listenfd, SOL_SOCKET, SO_LINGER, &tmp, sizeof(tmp));

    int ret = 0;
    struct sockaddr_in saddr;
    bzero(&saddr, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(m_port);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int reuse = 1;
    setsockopt(m_listenfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    ret = bind(m_listenfd, (struct sockaddr *) &saddr, sizeof(saddr));
    assert(ret >= 0);

    ret = listen(m_listenfd, 5);
    assert(ret >= 0);

    utils.init(TIMESLOT);

    epoll_event events[MAX_EVENT_NUMBER];
    m_epollfd = epoll_create(5);
    assert(m_epollfd != -1);
    utils.addfd(m_epollfd, m_listenfd, false, m_listen_mode);

}