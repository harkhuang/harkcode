# -*- coding:gb2312 -*-

import threading
import time

def thread_callback(total, interval):
    for i in range(0, int(total / interval)):
        print 'hello world'
        time.sleep(interval)
        
#go on with your main thread

if __name__ == "__main__":
  	thread_handle = threading.Thread(None, thread_callback, kwargs = {'total':60, 'interval':1})
	thread_handle.start()
