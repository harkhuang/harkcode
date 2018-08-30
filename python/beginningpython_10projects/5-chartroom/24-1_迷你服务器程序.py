#coding:utf-8  
 
from asyncore import dispatcher
import asyncore 

'''register a server do nothing...'''
class ChatServer(dispatcher):pass

s = ChatServer()
asyncore.loop()