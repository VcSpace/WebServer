#include <getopt.h>

#include "server/server.h"

static struct option server_c[] = {

        {"port", optional_argument, NULL, 'p'},
        {"ip", optional_argument, NULL, 'l'},
        {"user_name", required_argument, NULL, 'u'},
        {"password", required_argument, NULL, 'w'},
        {"database", required_argument, NULL, 'd'},
        {"sql port", optional_argument, NULL, 'm'},
        {0, 0, 0, 0}
};

int main(int argc, char** argv)
{
    int port = 10236;
    char* ip = nullptr;
    char* sql_user_name;
    char* sql_pwd;
    char* sql_db;
    int sql_port = 3306;

    int opt = 0;
    int optionIndex = 0;
    while((opt = getopt_long(argc, argv, "p:l:u:w:d:m:", server_c, &optionIndex)) != -1)
    {
        switch(opt)
        {
            case 'p':
                port = atoi(optarg);
                break;
            case 'l':
                 ip = optarg;
                break;
            case 'u':
                sql_user_name = optarg;
                break;
            case 'w':
                sql_pwd = optarg;
                break;
            case 'd':
                sql_db = optarg;
                break;
            case 'm':
                sql_port = atoi(optarg);
                break;
            default:
                std::cout << "-h help" << std::endl;
                exit(0);
        }
    }

    SqlPool sql_pool;
    Server server;
    server.init(ip, port, sql_user_name, sql_pwd, sql_db, sql_port);
    server.log_write();
    server.init_mysql();

    std::cout << "操作完成" << std::endl;
    return 0;
}
