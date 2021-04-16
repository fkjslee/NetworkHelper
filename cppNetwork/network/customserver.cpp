#include "customserver.h"

CustomServer::CustomServer(int port)
{
    initWsa();
    sockServer = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN addrServer;
    addrServer.sin_family = AF_INET;
    addrServer.sin_port = htons(port);
    addrServer.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

    bind(sockServer, (SOCKADDR *)&addrServer, sizeof(SOCKADDR));
    listen(sockServer, SOMAXCONN);
    registerProcessMsgFunc(defaultDealingMsg);
}

void CustomServer::startTolisten()
{
    SOCKADDR_IN addrClient;
    int len = sizeof(SOCKADDR_IN);
    while (1)
    {
        SOCKET sockConn = accept(sockServer, (SOCKADDR *)&addrClient, &len);
        while (1)
        {
            char recvBuf[1024];
            int len = recv(sockConn, recvBuf, 1024, 0);
            if (len <= 0)
                break;
            recvBuf[len] = '\0';
            std::string temp;
            std::string returnMsg = dealMsgFunc(recvBuf);
            send(sockConn, returnMsg.c_str(), returnMsg.length(), 0);
        }
        closesocket(sockConn);
    }
}

void CustomServer::registerProcessMsgFunc(funcPointer processMsgFunc)
{
    this->dealMsgFunc = processMsgFunc;
}

void CustomServer::initWsa()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    wVersionRequested = MAKEWORD( 1, 1 );
    err = WSAStartup( wVersionRequested, &wsaData );
    if ( err != 0 )
    {
        throw std::exception("Start wsa error!");
        return;
    }
    if ( LOBYTE( wsaData.wVersion ) != 1 ||	HIBYTE( wsaData.wVersion ) != 1 )
    {
        WSACleanup( );
        throw std::exception("Wrong wsa version!");
        return;
    }
}

std::string CustomServer::defaultDealingMsg(const std::string &msg)
{
    return "Not register process message function. Using default process msg: " + msg;
}
