#ifndef WEBSERVER_SQL_H
#define WEBSERVER_SQL_H

#include <iostream>
#include <list>
#include <mysql/mysql.h>

class SqlPool {
public:
    SqlPool();
    virtual ~SqlPool();

    static SqlPool* GetInstance();
    void init_mysql(char* sql_host, char* sql_user, char* sql_pwd, char* sql_db, int sql_port);
    void Sql_destory();

private:
    const int m_MaxConn = 8;  //最大连接数
    int m_CurConn;  //当前已使用的连接数
    int m_FreeConn; //当前空闲的连接数

    std::list<MYSQL*> Sql_Pool;
};

#endif //WEBSERVER_SQL_H
