#coding:utf-8
import os
import sys 
import time 
from datetime import datetime

import datetime

from  pyinotify import  WatchManager, Notifier, \
ProcessEvent,IN_DELETE, IN_CREATE,IN_MODIFY
 

def dolog():
  time_now = datetime.datetime.now()
  file = open("mktdt73.txt",'r')
  line = file.readline(1000)
  buf = line.split("|")
  for i in buf :
     if '-' in i:
	     print "time log is====>","txt_time:",i,'',"sys_time:",time_now
	

class EventHandler(ProcessEvent):
  """事件处理"""
  def process_IN_CREATE(self, event):
    msg = os.path.join(event.path,event.name)
    msg = 'create file in path:' + msg +'\n'
    #send_mail(msg)
    print   "Create file: %s "  %   os.path.join(event.path,event.name)
    dolog()
  def process_IN_DELETE(self, event):
    msg = os.path.join(event.path,event.name)
    msg = 'Delete file in path:' + msg +'\n'
    dolog()
    print   "Delete file: %s "  %   os.path.join(event.path,event.name)

  def process_IN_MODIFY(self, event):
    msg = os.path.join(event.path,event.name)
    msg = 'Modify file in path:' + msg +'\n'
    dolog()
    print   "Modify file: %s "  %   os.path.join(event.path,event.name)
 
def FSMonitor(path='.'):
    wm = WatchManager() 
    mask = IN_DELETE | IN_CREATE |IN_MODIFY
    notifier = Notifier(wm, EventHandler())
    wm.add_watch(path, mask,auto_add=True,rec=True)
    print 'now starting monitor %s'%(path)
    while True:
      try:
          notifier.process_events()
          if notifier.check_events():
              notifier.read_events()
      except KeyboardInterrupt:
          notifier.stop()
          break


if __name__ == "__main__":
  FSMonitor('/mnt/github/trunk/python/python_filemoniter')
	
