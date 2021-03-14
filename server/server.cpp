#include "server.h"

Server::Server()
{

}

Server::~Server()
{

}

void Server::init(char* ip, int ip_port, char* sql_user, char* sql_pwd, char* sql_db, int sql_port)
{
    m_server_ip = ip;
    m_server_port = ip_port;
    m_sql_host = "localhost";
    m_sql_db = sql_db;
    m_sql_user = sql_user;
    m_sql_port = sql_port;
    m_sql_pwd = sql_pwd;
    m_log_mode = 1;
}

void Server::init_mysql()
{
    m_sqlpool = SqlPool::GetInstance();
    m_sqlpool->init_mysql(m_sql_host, m_sql_user, m_sql_pwd, m_sql_db, m_sql_port);
}

void Server::log_write()
{
    if(m_log_mode == 1)
        Log::get_instance()->init("Server.log", 2000, 800000, 800);
    else
        Log::get_instance()->init("Server.log", 2000, 800000, 0);
}
