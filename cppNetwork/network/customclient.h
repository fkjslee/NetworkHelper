#ifndef CUSTOMCLIENT_H
#define CUSTOMCLIENT_H

#include <winsock.h>
#include <stdexcept>

class CustomClient
{
public:
    CustomClient(std::string addr = "127.0.0.1", int port = 8080);
    ~CustomClient();
    std::string sendMsg(std::string msg);

private:
    void initWsa();
    SOCKET s_server;
};

#endif // CUSTOMCLIENT_H
