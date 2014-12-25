#coding:utf-8
from asyncore import dispatcher 
from asynchat import async_chat
import socket, asyncore

PORT = 5005

class ChatSession(async_chat):#定义会话窗口类

	def __init__(self, sock):#必须要这么写初始化的
		async_chat.__init__(self, sock)

		self.set_terminator("\r\n")#中断
		self.data = []#数据
	def collect_incoming_data(self, data):
		self.data.append(data)#收集信息  加入列表

	def found_terminator(self):#读到空数据 把他们链接起来
		line = ''.join(self.data)#用空格把数据链接起来
		self.data = []  
		#处理这行数据
		print line 

class ChatServer(dispatcher):#继承类属性
	def __init(self, port):#必须要这么写初始化的
		dispatcher.__init__(self)#初始化发报机

		self.create_socket(socket.AF_INET, socket.STREAM)
		self.set_reuse_addr()
		self.bind(('',port))
		self.listen(5)
		self.sessions = []#初始化会话内容

	def handle_accpet(self):
		conn.addr = self.accpet()
		self.sessions.append(ChatSession(conn))

if __name__ == '__main__':
	s = ChatServer()#????为何这行会报错?
	try:asyncore.loop()#循环轮询
	except KeyboardInterruot:print