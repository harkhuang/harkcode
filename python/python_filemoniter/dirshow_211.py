#!/usr/bin/python  
#coding=gbk  

import os
import os.path
import sys
import string 
import re
import threading
import time


def kill_proc(name):#ok
    count = 0
    flag = 3
    cmd_kill ="ps -ef |grep " +  name  
    do_log( " cmd_kill is:"+ cmd_kill)
    info = os.popen(cmd_kill).read()
    str_info = "result is  %s"%info 
    list = str_info.split()

    for i,j in enumerate(list):

      if(i == 3) :
        cmd = "kill -9 " + j
        do_log("the command is :" + cmd) 
        os.system(cmd)
        break
      elif(i == 4):
        cmd = "kill -9" + j
        ret = os.system(cmd)


def  do_mount():  #ok   
    os.system("umount /hqdatabus/kmds/szkingdom/ggqq")   
   
    os.system()

def do_log(log):
        with open('./log.txt', 'a') as file:
            print log
            log =   "="  + time.strftime('%y-%m-%d %H:%M:%S"',time.localtime(time.time())) + "===>" +log + "\n"
            #print log
            file.write(log)
            file.close()
  
def callback_routine(interval,name_proce):

  while 1:
    time.sleep(interval)
    if( False == os.path.exists("/hqdatabus/kmds/szkingdom/ggqq/hq") ):
      do_log("dir lose mount")      
      kill_proc(name_proce)
      do_mount()
    else:
      do_log("mount file statu is ok...")

if __name__ == "__main__":
  #callback_routine(3,"sleep123")
  

  gVal['newPostPatStr'] = unicode(gVal['newPostPatStr'], "utf-8");
  print gVal['newPostPatStr']
