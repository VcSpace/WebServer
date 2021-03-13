#include <iostream>
//#include <getopt.h>

#include "server.h"

/*
 * static struct option server_c[] = {

        {"device", required_argument, NULL, 'd'},
        {"savefile", optional_argument, NULL, 'f'},
        {"help", no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'v'},
        {"Device list", no_argument, NULL, 'l'},
        {0, 0, 0, 0}
};
*/

int main(int argc, char** argv)
{
    int port = 10236;
    char* ip = "127.0.0.1";

    /*
     * int opt = 0;
    int optionIndex = 0;
    while((opt = getopt_long(argc, argv, "d:f:hvl", server_c, &optionIndex)) != -1)
    {
        switch(opt)
        {
            case 'd':
                device = optarg;
                break;
            case 'f':
                savefile = optarg;
                break;
            case 'h':
                Vc::PcapUsage();
                exit(1);
            case 'v':
                Vc::PcapVersion();
                exit(1);
            case 'l':
                VcDevice_List();
                exit(1);
            default:
                Vc::PcapUsage();
                exit(1);
        }
    }
    */

    if(argc > 2)
    {
        ip = argv[1];
        port = atoi(argv[2]);
    }

    Server* user = new Server();
    user->init_mysql();

    std::cout << "操作完成" << std::endl;
    return 0;
}
