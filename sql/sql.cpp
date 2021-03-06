#include "sql.h"

SqlPool::SqlPool()
{
    m_CurConn = 0; //当前已使用的连接数
    m_FreeConn = 0; //当前空闲的连接数
}

SqlPool::~SqlPool()
{
    //Sql_destory();
}

SqlPool* SqlPool::GetInstance()
{
    static SqlPool sqlPool;
    return &sqlPool;
}

void SqlPool::init_mysql(char* sql_host, char* sql_user, char* sql_pwd, char* sql_db, int sql_port)
{
    MYSQL* Sql = NULL;
    for(int i = 0; i < 8; i++)
    {
        Sql = NULL;
        Sql = mysql_init(Sql);
        if(Sql == NULL)
        {
            std::cout << "sql error = " << i << std::endl;
            exit(-1);
        }

        Sql = mysql_real_connect(Sql, sql_host, sql_user, sql_pwd, sql_db, sql_port, NULL, 0);
        if(Sql == NULL)
        {
            std::cout << "sql error = 2" << std::endl;
            exit(-1);
        }

        Sql_Pool.push_back(Sql);
        m_FreeConn++;
    }
}

void SqlPool::Sql_destory()
{
    if(Sql_Pool.size() > 0)
    {
        std::list<MYSQL*>::iterator it;
        for(it = Sql_Pool.begin(); it != Sql_Pool.end(); it++)
        {
            MYSQL* sql = *it;
            mysql_close(sql);

        }
        m_CurConn = 0;
        m_FreeConn = 0;
        Sql_Pool.clear();
    }
}
