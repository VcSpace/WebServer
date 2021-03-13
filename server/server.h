#ifndef WEBSERVER_SERVER_H
#define WEBSERVER_SERVER_H

#include <mysql/mysql.h>
#include <sys/socket.h>
#ifdef __linux__
#include <sys/epoll.h>
#elif __APPLE__
#include <sys/event.h>
#include <sys/types.h>
#endif

class Server {
public:
    Server();
    ~Server();

    void init_mysql();

private:
    Mysql* sql;

    char* sql_name;
    char* sql_db;
    char* sql_pwd;
    int sql_port;

    int server_port;
    char* server_ip;
};

#endif //WEBSERVER_SERVER_H
