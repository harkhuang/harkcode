#coding:utf-8
from asyncore import dispatcher
import socket,asyncore

PORT=5005

class ChatServer(dispatcher):#初始化链接类
	def __init__(self, port):#初始化链接
		dispatcher.__init__(self)#初始化函数定义
		self.create_socket(socket.AF_INET, socket.SOCK_STREAM)#创建套接字
		self.set_reuse_addr()#表示端口号被程序复用
		self.bind(('',port))#绑定
		self.listen(5)#等待超时5second

	def handle_accpet(self):
		conn.addr = self.handle_accpet()
		print 'Connection attempt from', addr[0]

if __name__=='__main__':
		s = ChatServer(PORT)
		try:asyncore.loop()
		except KeyboardInterrupt: pass#pass表示什么都不做