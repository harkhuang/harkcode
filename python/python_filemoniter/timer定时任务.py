#! /usr/bin/env python
#coding=utf-8
# ½èÖúÄ£ÔËËã£¬¿ÉÒÔÒ»´ÎËã³öÐèÒª¼õÈ¥µÄÌìÊý£¬¼ÆËãÉÏÒ»¸öÐÇÆÚÎå
#Í¬ÑùÒýÈëdatetime,calendarÁ½¸öÄ£¿é
import datetime 
import calendar 
    
today = datetime.date.today() 
target_day = calendar.FRIDAY 
this_day = today.weekday() 
delta_to_target = (this_day - target_day) % 7
last_friday = today - datetime.timedelta(days = delta_to_target) 
    
#print(last_friday.strftime("%d-%b-%Y"))

#! /usr/bin/env python
#coding=utf-8


#! /usr/bin/env python
#coding=utf-8
#这里需要引入三个模块
import time, os, sched 
    
# 第一个参数确定任务的时间，返回从某个特定的时间到现在经历的秒数 
# 第二个参数以某种人为的方式衡量时间 
schedule = sched.scheduler(time.time, time.sleep) 
    
def perform_command(cmd, inc): 
    os.system(cmd) 
        
def timming_exe(cmd, inc = 60): 
    # enter用来安排某事件的发生时间，从现在起第n秒开始启动 
    schedule.enter(inc, 0, perform_command, (cmd, inc)) 
    # 持续运行，直到计划时间队列变成空为止 
    schedule.run() 
        
    
print("show time after 10 seconds:") 
timming_exe("echo %time%", 10)