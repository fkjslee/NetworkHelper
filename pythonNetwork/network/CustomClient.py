import socket


class Client:
    def __init__(self, addr="127.0.0.1", port=8080):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((addr, port))

    def sendMsg(self, msg="default msg"):
        self.sock.send(msg.encode('utf-8'))
        rtn_msg = self.sock.recv(1024).decode('utf-8')
        return rtn_msg

    def __del__(self):
        self.sock.close()
