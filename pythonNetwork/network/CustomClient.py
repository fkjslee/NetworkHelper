import socket


class Client:
    def __init__(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self, addr="127.0.0.1", port=8080):
        self.sock.connect((addr, port))

    def sendMsg(self, msg="default msg", addr="127.0.0.1", port=8080):
        self.connect(addr=addr, port=port)
        self.sock.send(msg.encode('utf-8'))
        rtn_msg = self.receiveMsg()
        self.sock.close()
        return rtn_msg

    def receiveMsg(self):
        msg = self.sock.recv(1024)
        return msg.decode('utf-8')
