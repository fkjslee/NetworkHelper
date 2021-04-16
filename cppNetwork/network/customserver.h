#ifndef CUSTOMSERVER_H
#define CUSTOMSERVER_H

#include <winsock.h>
#include <stdexcept>

typedef std::string (*funcPointer)(const std::string &msg);

class CustomServer
{
public:
    CustomServer(const int port = 8080);
    void startTolisten();
    void registerProcessMsgFunc(funcPointer processMsgFunc);

private:
    void initWsa();
    static std::string defaultDealingMsg(const std::string &msg);
    SOCKET sockServer;
    funcPointer dealMsgFunc;
};

#endif // CUSTOMSERVER_H
