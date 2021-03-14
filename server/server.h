#ifndef WEBSERVER_SERVER_H
#define WEBSERVER_SERVER_H

#include <iostream>
#include <unistd.h>
#include <mysql/mysql.h>
#include <sys/socket.h>
#ifdef __linux__
#include <sys/epoll.h>
#elif __APPLE__
#include <sys/event.h>
#include <sys/types.h>
#endif

#include "../sql/sql.h"
#include "../log/log.h"

class Server {
public:
    Server();
    ~Server();

    void init(char* ip, int ip_port, char* sql_user_name, char* sql_pwd, char* sql_db, int sql_port);
    void init_mysql();
    void log_write();

private:
    SqlPool* m_sqlpool;
    Log* m_log;

private:
    char* m_sql_user;
    char* m_sql_db;
    char* m_sql_pwd;
    char* m_sql_host;
    int m_sql_port;
    int Max_sql_conn;

    int m_server_port;
    char* m_server_ip;
    bool m_write_log;

    int m_log_mode;
};

#endif //WEBSERVER_SERVER_H
