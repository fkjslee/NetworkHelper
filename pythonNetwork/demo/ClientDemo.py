from network.CustomClient import Client

if __name__ == "__main__":
    client = Client()
    returnMsg = client.sendMsg("hello demo")
    print(returnMsg)
