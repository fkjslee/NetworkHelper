from network.CustomServer import Server


def customProcessMsg(msg):
    print("received msg", msg)
    return "process: " + msg + " over."


if __name__ == "__main__":
    server = Server()
    server.register_dealing_msg_func(customProcessMsg)
    server.start_to_listen()