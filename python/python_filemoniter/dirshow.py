
# -*- coding=gb2312 -*-
import os
import os.path
import sys
import string 
import re
import threading
import time
def thread_callback(total, interval):
    for i in range(0, int(total / interval)):
        print 'hello world'
        time.sleep(interval)

def is_dir_existence(name):  
  if os.path.isdir(name):
    do_log("file  mount statu is ok..")
    return True   
  else:
    #print("no existence..")
    do_log("file is lose mount ..")
    #os.system("touch 2_noexistence")
    return False

def dir_work():
    flag = 1
    if (is_dir_existence("/mnt/kingdom/") & is_dir_existence("/mnt/github/") & is_dir_existence("/mnt/github/trunk/")):
        print "cant do mount  "
        return True
    else :
        print "do mount "
        kill_proc("sleep123")
        do_mount()
        return False

def kill_proc1(name):
  cmd_kill ="ps -ef |grep " +  name  
  info = os.popen(cmd_kill).read()
  str_info = "result is  %s"%info 
  list = str_info.split()
  count = 0
  flag = 3
  for i,j in enumerate(list):
	  if(i == flag  + count * 12 ):
		print i,j
		print type(j)
		count +=1
		cmd = "kill -9 " + j 
		ret = os.system(cmd)
		print ret 

def kill_proc(name):#ok
    count = 0
    flag = 3
    cmd_kill ="ps -ef |grep " +  name  
    do_log( " cmd_kill is:"+ cmd_kill)
    info = os.popen(cmd_kill).read()
    str_info = "result is  %s"%info 
    list = str_info.split()

    #print info 
    for i,j in enumerate(list):
      #if( i == flag + count * 12 ):
      #print i,j
      #print type(j)
      #count +=1
      if(i == 3) :
        cmd = "kill -9 " + j
        do_log("the command is :" + cmd) 
        os.system(cmd)
        break
      elif(i == 4):
        cmd = "kill -9" + j
        ret = os.system(cmd)
      #print ret 

def  do_mount():  #ok
    #cmd_umount = "umount " + dest
    #ret = os.system(cmd_umount)

    #if( False == os.path.exists("mnt/test/1") ):
    #os.system("umount /hqdatabus/kmds/szkingdom/ggqq")   
    #os.system('''mount -t cifs -o iocharset=cp936,codepage=cp936,username="jzjy",password="citicsjzjy" //10.23.117.11/港股etf/ggqq /hqdatabus/kmds/szkingdom/ggqq''')
    os.system("umount /mnt/test")     
    os.system('''mount -t  vboxsf test /mnt/test''')
  
    #cmd_mount = "mount -t vbox  "  +dest + src
    #ret = os.system(cmd_mount)
    #print "mount /mnt/test ok.."    
      

def do_log(log):
    #try:
        with open('./log.txt', 'a') as file:
            print log
            log =   "="  + time.strftime('%y-%m-%d %H:%M:%S"',time.localtime(time.time())) + "===>" +log + "\n"
            #print log
            file.write(log)
            file.close()
    #except Exception, e:
        #raise e
        #print str(e)

  
def callback_routine(interval,name_proce):
  flag = 1
  interval = 3

  while 1:
    time.sleep(interval)
    if( False == os.path.exists("mnt/test/1") ):
      do_log("dir lose mount")      
      kill_proc(name_proce)
      do_mount()
    else:
      do_log("mount file statu is ok...")



if __name__ == "__main__":
  unicodeData = '''mount -t cifs -o iocharset=cp936,codepage=cp936,username="jzjy",password="citicsjzjy" //10.23.117.11/港股etf/ggqq /hqdatabus/kmds/szkingdom/ggqq'''
  gbkData = unicodeData.encode("GBK")
  gVal['newPostPatStr'] = unicode(gVal['newPostPatStr'], "utf-8");
  print gbkData
