# 这是一个用于通信的库
## 原因
由于经常需要使用类似cpp传信息到python之类的操作，或者同语言传信息等。不想每次造轮子，同时尽量处理好每次的exception。写一下以后方面用

## 需要的库 
### python:
socket，默认应该有

### cpp:
winsock.h
stdexcept
默认都有

## 用法
### python:
1. 下载后复制到对应目录导入
2. server端：需要重新定义如何处理消息并把函数在CustomServer.Server中注册
3. client端：使用CustomClient.Client中的sendMsg即可
可以参考demo文件夹下的用法
### cpp:
1. 下载后复制到对应目录
2. include对应文件
3. server端: 在CustomServer中注册接受信息时的功能(registerProcessMsgFunc函数)
4. client端: 新建对象后sendMsg(msg)即可
同样可以参考main.cpp文件下的testServer函数和testClient函数