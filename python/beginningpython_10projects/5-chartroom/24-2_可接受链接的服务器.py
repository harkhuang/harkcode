#coding:utf-8
from asyncore import dispatcher#从同步核导入发报机
import socket, asyncore#导入套接字和同步模块

#初始化监听类socket
class ChatServer(dispatcher):#初始化类  成员是一个发报机
	def handle_accpet(self):#定义操作客户端链接socket的句柄
		conn.addr = self.accept()#链接地址是操作句柄
		print 'Connect attempt form ',addr[0]#打印欢迎信息和地址
	
s = ChatServer()
s.create_socket(socket.AF_INET, socket.SOCK_STREAM)#初始化ipv4+tcp
s.bind(('',5005))#监听所有进程哦
s.listen(5)#超时等待是5秒
asyncore.loop()#轮询监听
