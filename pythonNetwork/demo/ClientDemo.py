import sys
sys.path.append("../")

from network.CustomClient import Client

if __name__ == "__main__":
    client = Client()
    while True:
        returnMsg = client.sendMsg("hello demo")
        print(returnMsg)
