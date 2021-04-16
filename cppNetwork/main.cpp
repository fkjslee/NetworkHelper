#include <network/customclient.h>
#include "network/customserver.h"
#include <iostream>
#include <QCoreApplication>

using namespace std;

std::string myProcessMsgFunc(const std::string &msg)
{
    return "My process message funcion. Porcess : " + msg;
}

void testServer()
{
    try
    {
        CustomServer server;
        server.registerProcessMsgFunc(myProcessMsgFunc);
        server.startTolisten();
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testClient()
{
    try
    {
        CustomClient server;
        while (true)
        {
            string returnMsg = server.sendMsg("qqq");
            cout << returnMsg << endl;
        }
    }
    catch (exception e)
    {
        cout << "exception " << e.what() << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testServer();
    return a.exec();
}
