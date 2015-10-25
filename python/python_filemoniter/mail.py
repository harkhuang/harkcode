#coding:utf-8
import sys 
import time 
import poplib 
import smtplib 
from email.mime.text import MIMEText  
from email.header import Header 
from email.mime.multipart import MIMEMultipart  
from email.mime.text import MIMEText  
from email.mime.image import MIMEImage 
import time

#邮件发送函数
def send_mail(): 
     try: 
        
        subject = 'DARE-Monitor-Test-For-Python'
        str_from_email = 'shiyanhk@qq.com'
        str_sendto_email = 'shiyanhk@qq.com'
        seconds = time.time()
        str_time  = time.ctime(seconds)
        to_list = ['shiyanhk@qq.com','huangkui@szkingdom.com','shiyanhk@126.com']
        mail_user = 'shiyanhk'
        mail_postfix = 'qq.com'
        mail_sender_name = 'DARE-Monitor'
        me=mail_sender_name+"<"+mail_user+"@"+mail_postfix+">"

        handle = smtplib.SMTP('smtp.qq.com',25) 
        handle.login('shiyanhk@qq.com','chunqingdashazi') 
        msg_html = MIMEText('<html><h1>你好</h1></html>','html','utf-8')
        
        #主题的发送
        subject = 'python email test for monitorlog'    
        msg_html_test = MIMEText('<html><h1>DARE-Monitor</h1><body>This is a test for monitor log ...</body></html>','html','utf-8')
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
#邮件接收函数
def accpet_mail(): 
    try: 
        p=poplib.POP3('pop.qq.com') 
        p.user('shiyanhk@qq.com') 
        p.pass_('chunqingdashazi') 
        ret = p.stat() #返回一个元组:(邮件数,邮件尺寸) 
        #p.retr('shiyanhk@qq.com')#方法返回一个元组:(状态信息,邮件,邮件尺寸)   
    except poplib.error_proto,e: 
        print "Login failed:",e 
        sys.exit(1)
    
#运行当前文件时，执行sendmail和accpet_mail函数
if __name__ == "__main__": 
    send_mail() 
    print 'sendmail ok ...'
    #accpet_mail()
