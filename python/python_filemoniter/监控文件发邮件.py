#coding:utf-8
import os
import sys 
import time 
import poplib 
import smtplib 
 
from email.header import Header 
from email.mime.text import MIMEText  
from email.mime.image import MIMEImage 
from email.mime.multipart import MIMEMultipart 

from  pyinotify import  WatchManager, Notifier, \
ProcessEvent,IN_DELETE, IN_CREATE,IN_MODIFY
 


def send_mail(parameter_msg): 
     try: 
        
        subject = 'DARE-Monitor-Test-For-Python'
        str_from_email = 'ex_huangkui@citics.com'
        password = '123456'
        str_sendto_email = 'ex_huangkui@citics.com'
        seconds = time.time()
        str_time  = time.ctime(seconds)
        to_list = ['ex_huangkui@citics.com','ex_huangkui@citics.com']
        mail_user = 'ex_huangkui'
        mail_postfix = 'citics.com'
        mail_sender_name = 'DARE-Monitor'
        me=mail_sender_name+"<"+mail_user+"@"+mail_postfix+">"

        handle = smtplib.SMTP('smtp.citicsinfo.com',25) 
        handle.login(str_from_email,password)
        
        
        if parameter_msg:
            msg_html_test = MIMEText('<html><h2>\n         DARE-Monitor-Log</h2><body>'+'\n'+ parameter_msg+'</body><body1>'+'\n\n\n\n\n'+'from:'+str_from_email+str_time+'</body1></html>','html','utf-8')
        else:
 			msg_html_test = MIMEText('<html><h2>DARE-Monitor</h2><body>This is a test for monitor log ...</body></html>','html','utf-8')

       
        msg_html_test['Subject'] =  Header(subject,'utf-8')
        msg_html_test['From'] = me
        msg_html_test['To'] = ";".join(to_list)
        msg_html_test['date']= str_time
               
       
        handle.sendmail(str_from_email,str_sendto_email,msg_html_test.as_string()) 
        handle.close() 
        return 1
     except Exception, e:
        print str(e)
        return 0

def accpet_mail(): 
    try: 
        p=poplib.POP3('pop3.citicsinfo.com') 
        p.user('ex_huangkui@citics.com') 
        p.pass_('123456') 
        ret = p.stat() 
       
    except poplib.error_proto,e: 
        print "Login failed:",e 
        sys.exit(1)



class EventHandler(ProcessEvent):
  """事件处理"""
  def process_IN_CREATE(self, event):
    msg = os.path.join(event.path,event.name)
    msg = 'create file in path:' + msg +'\n'
    send_mail(msg)
    print   "Create file: %s "  %   os.path.join(event.path,event.name)
 
  def process_IN_DELETE(self, event):
    msg = os.path.join(event.path,event.name)
    msg = 'Delete file in path:' + msg +'\n'
    send_mail(msg)
    print   "Delete file: %s "  %   os.path.join(event.path,event.name)

  def process_IN_MODIFY(self, event):
    msg = os.path.join(event.path,event.name)
    msg = 'Modify file in path:' + msg +'\n'
    send_mail(msg)
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
  FSMonitor('/home/hk')
