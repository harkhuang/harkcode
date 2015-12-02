#!/usr/bin/env python  
# coding=utf-8  
# Python 2.7.3  
# 获取邮件内容  
import poplib  
from email import parser  
  
host = 'pop.qq.com'  
username = 'MyTest22@163.com'  
password = 'xxxxxxxxx'  
  
pop_conn = poplib.POP3_SSL(host)  
pop_conn.user(username)  
pop_conn.pass_(password)  
  
#Get messages from server:  
# 获得邮件  
messages = [pop_conn.retr(i) for i in range(1, len(pop_conn.list()[1]) + 1)]  
#print messages  
  
#print "--------------------------------------------------"  
# Concat message pieces:  
messages = ["\n".join(mssg[1]) for mssg in messages]  
#print messages  
  
#Parse message intom an email object:  
# 分析  
messages = [parser.Parser().parsestr(mssg) for mssg in messages]  
i = 0  
for message in messages:  
    i = i + 1  
    mailName = "mail%d.%s" % (i, message["Subject"])  
    f = open(mailName + '.log', 'w');  
    print >> f, "Date: ", message["Date"]  
    print >> f, "From: ", message["From"]  
    print >> f, "To: ", message["To"]  
    print >> f, "Subject: ", message["Subject"]  
    print >> f, "Data: "  
    j = 0  
    for part in message.walk():  
        j = j + 1  
        fileName = part.get_filename()  
        contentType = part.get_content_type()  
        # 保存附件  
        if fileName:  
            data = part.get_payload(decode=True)  
            fileName = "%s.%d.%s" % (mailName, j, fileName)  
            fEx = open(fileName, 'wb')  
            fEx.write(data)  
            fEx.close()  
        elif contentType == 'text/plain' or contentType == 'text/html':  
            #保存正文  
            data = part.get_payload(decode=True)  
            print >> f, data  
  
    f.close()  
pop_conn.quit() 