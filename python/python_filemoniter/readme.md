**这是一个用来监控文件夹 并且发消息的python程序**



[依赖库](https://github.com/seb-m/pyinotify)

**1.安装第三方库**

```git clone https://github.com/seb-m/pyinotify.git```

```cd pyinotify/```

```python setup.py install```

**2.配置发信箱**
 - 1 配置发信箱  用户名和密码
 - 2 配置邮箱收发服务器极其端口
 - 注意  有的邮箱有垃圾屏蔽功能导致程序运行却收不到邮件

**3.运行监控**

```python mail.py```
