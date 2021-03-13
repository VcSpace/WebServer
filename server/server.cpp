#include "server.h"

Server::Server()
{
    server_ip = "127.0.0.1";
    server_port = 10236;
    sql_db = "Webserver";
    sql_name = "root";
    sql_port = 3306;
    sql_pwd = "Aa1248800211";

}

Server::~Server()
{
    mysql_close(&sql);     //关闭一个服务器连接。
}

void init_mysql()
{

}