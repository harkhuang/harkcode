
 #/**********************************************************************
 # File Name:   moniter.py
 # Version:     1.0
 # Mail:        shiyanhk@gmail.com 
 # Created Time: 2015-10-24	
 # ************************************************************************/

#! /usr/bin/env python
#coding=utf-8
import sys 
import time 
import poplib 
import smtplib 
#�ʼ����ͺ���
def send_mail(): 
     try: 
        handle = smtplib.SMTP('smtp.126.com',25) 
        handle.login('shiyanhk@126.com','qwe789qwe') 
        msg = 'To: shiyanhk@qq.com\r\nFrom:shiyanhk@126.com\r\nSubject:hello\r\n'
        handle.sendmail('shiyanhk@126.com','shiyanhk@qq.com',msg) 
        handle.close() 
        return 1
     except: 
        return 0
#�ʼ����պ���
def accpet_mail(): 
    try: 
        p=poplib.POP3('pop.126.com') 
        p.user('shiyanhk@126.com') 
        p.pass_('qwe789qwe') 
        ret = p.stat() #����һ��Ԫ��:(�ʼ���,�ʼ��ߴ�) 
       #p.retr('�ʼ�����')��������һ��Ԫ��:(״̬��Ϣ,�ʼ�,�ʼ��ߴ�)   
    except poplib.error_proto,e: 
        print "Login failed:",e 
        sys.exit(1)
    
#���е�ǰ�ļ�ʱ��ִ��sendmail��accpet_mail����
if __name__ == "__main__": 
    send_mail() 
    accpet_mail()
