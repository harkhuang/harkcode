#coding:utf-8
import os
import os.path
import sys
import string 
import psutil
import re
import threading
import time
def thread_callback(total, interval):
    for i in range(0, int(total / interval)):
        print 'hello world'
        time.sleep(interval)

def is_dir_existence(name):
  if os.path.isdir(name):
    print("is existence..")
    return True
  else:
    print("no existence..")
    #os.system("touch 2_noexistence")
    return False

def dir_work():
    flag = 1
    if (is_dir_existence("/mnt/kingdom/") & is_dir_existence("/mnt/github/") & is_dir_existence("/mnt/github/trunk/")):
        print "cant do mount  "

    else :
        print "do mount "
        kill_proc("kdhqtrans1")
        do_mount()
    return flag


def  do_mount(src, dest ):
    cmd_umount = "umount " + dest
    ret = os.system(cmd_umount)
    #if ret == 0:
    print("umount ok") 
    ret = os.system("mount -t vboxsf test  /mnt/test")

    cmd_mount = "mount -t vbox  "  +dest + src
    ret = os.system(cmd_mount)
    #print "mount /mnt/test ok.."
    print "mount ok"

def callback_routine(interval):
    #checke dir 
    
    #kill process

    #mount dir 


	print "do work ..."


def do_log(log):
    try:
        with open('file.txt', 'a') as file:
            file.write('input')
    except Exception, e:
        raise e
        print str(e)
#def is_dir_existence():

def kill_proc(name):
    count = 0
    flag = 3
    cmd_kill ="ps -ef |grep " +  name  
    print cmd_kill
    info = os.popen(cmd_kill).read()
    str_info = "result is  %s"%info 
    list = str_info.split()

    print info 
    for i,j in enumerate(list):
      #if( i == flag + count * 12 ):
      print i,j
      #print type(j)
      #count +=1
      if(i == 3) :
        cmd = "kill -9 " + j
        print "the command is :" + cmd
        os.system(cmd)
        break
      elif(i == 4):
        cmd = "kill -9" + j
        ret = os.system(cmd)
      #print ret 

if __name__ == "__main__":
  #dir_work()   
  #thread_handle = threading.Thread(None, thread_callback, kwargs = {'total':60, 'interval':1})
  #thread_handle.start()  
  #time.sleep(5)
  kill_proc("sleep100") 


