
#!/usr/bin/env python
#coding:utf-8
import sys 
import time 
import poplib 
import smtplib 
#邮件发送函数
def send_mail(): 
     try: 
		sender = '1111@qq.com'  
		subject = 'python email test'  
		smtpserver = 'smtp.qq.com'
		username = '11111'  
		password = '11111'  

		msg = MIMEText('你好','text','utf-8') 
		msg['Subject'] = Header(subject, 'utf-8')  
		
		msg1 = MIMEText('你好','text','utf-8')
		msg1['Subject'] = 'sendmail'
		msg1['From'] = '111@qq.com'
		msg1['To'] = '1111@qq.com'



		smtp = smtplib.SMTP()  
		smtp.connect('smtp.qq.com')  
		smtp.login(username, password)  
		smtp.sendmail(sender, receiver, msg1)  
		smtp.quit()
     except: 
        return 0
#邮件接收函数
def accpet_mail(): 
    try: 
        p=poplib.POP3('pop.qq.com') 
        p.user('1111@qq.com') 
        p.pass_('12312312') 
        ret = p.stat() #返回一个元组:(邮件数,邮件尺寸) 
       #p.retr('邮件号码')方法返回一个元组:(状态信息,邮件,邮件尺寸)   
    except poplib.error_proto,e: 
        print "Login failed:",e 
        sys.exit(1)




 
#server['name'], server['user'], server['passwd']
def send_mail_detail(server, fro, to, subject, text, files=[]): 
    assert type(server) == dict 
    assert type(to) == list 
    assert type(files) == list 
 
    msg = MIMEMultipart() 
    msg['From'] = fro 
    msg['Subject'] = subject 
    msg['To'] = COMMASPACE.join(to) #COMMASPACE==', ' 
    msg['Date'] = formatdate(localtime=True) 
    msg.attach(MIMEText(text)) 
 
    for file in files: 
        part = MIMEBase('application', 'octet-stream') #'octet-stream': binary data 
        part.set_payload(open(file, 'rb'.read())) 
        encoders.encode_base64(part) 
        part.add_header('Content-Disposition', 'attachment; filename="%s"' % os.path.basename(file)) 
        msg.attach(part) 
 
    import smtplib 
    smtp = smtplib.SMTP(server['smtp.qq.com']) 
    smtp.login(server['123123213@qq.com'], server['chunqingdashazi']) 
    smtp.sendmail(fro, to, msg.as_string()) 
    smtp.close()
#运行当前文件时，执行sendmail和accpet_mail函数
if __name__ == "__main__": 
    send_mail()
    print 'send mail ok'
    accpet_mail()







