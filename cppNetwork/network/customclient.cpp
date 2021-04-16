#include "customclient.h"
#pragma comment(lib,"ws2_32.lib")
#include "customserver.h"

CustomClient::CustomClient(std::string addr, int port)
{
    using namespace std;
    initWsa();

    s_server = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = inet_addr(addr.c_str());
    server_addr.sin_port = htons(port);
    if (connect(s_server, (SOCKADDR *)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        throw exception("Connect failed!");
        WSACleanup();
    }

}

CustomClient::~CustomClient()
{
    closesocket(s_server);
    WSACleanup();
}

std::string CustomClient::sendMsg(std::string msg)
{
    using namespace std;

    string send_buf = msg;
    int send_len = send(s_server, send_buf.c_str(), send_buf.length(), 0);
    if (send_len < 0)
    {
        throw exception("Send message failed!");
    }
    char recv_buf[1024];
    string recvBuffer;
    int recv_len = recv(s_server, recv_buf, 1024, 0);
    if (recv_len < 0)
    {
        throw exception("Receive message failed!");
    }
    else
    {
        recvBuffer = recv_buf;
    }
    return recvBuffer;
}

void CustomClient::initWsa()
{
    using namespace std;
    WORD w_req = MAKEWORD(2, 2);
    WSADATA wsadata;
    int err = WSAStartup(w_req, &wsadata);
    if (err != 0)
        throw exception("Initiate wsa failed");
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2)
    {
        throw exception("Error wsa version");
        WSACleanup();
    }
}
