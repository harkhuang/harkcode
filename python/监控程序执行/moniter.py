#!/usr/bin/env python
# -*- coding: utf-8 -*-
import shlex
import threading
import subprocess
import time
import os
import sys
import stat


class ProcessManage(threading.Thread):
    "ProcessManage start process, check process, restart porcess"

    # processname 程序的名字
    # args 启动进程时的参数信息
    # dirpath 程序的目录(程序需与管理程序在同一个目录下)
    def __init__(self, processname, args=[], dirpath='.'):
        super(ProcessManage, self).__init__()
        self.isLinux = True
        self.currentdir = os.getcwd()
        self.processdir = dirpath
        self.args = args
        if not self.processdir.startswith('/'):
            self.processdir = self.currentdir + os.sep + self.processdir
        self.processname = processname
        self.processcmd = ''
        if self.processdir == '':
            self.processdir = '.'

        print('processname = %s, processdir = %s' % (processname, self.processdir))

        if 'win32' == sys.platform:
            self.isLinux = False
            if not self.processname.endswith('.exe'):
                self.processname = self.processname + '.exe'
            os.system('taskkill /f /im %s /t' % self.processname)
        elif sys.platform.startswith('linux'):
            os.system('killall -9 %s' % self.processname)
            if not self.processname.startswith('.'):
                self.processname = '.' + os.sep + self.processname
            self.processcmd = self.processname
            for arg in args:
                self.processcmd += " "
                self.processcmd += str(arg)
        self.process = None
        self.checkstatus = False
        # 创建锁对象
        self._mu = threading.Lock()

    def __del__(self):
        self.checkstatus = False
        if (self.process is not None) and (self.process.poll() is None):
            self.process.kill()

    def __process__(self):
        if self._mu.acquire(True):
            try:
                os.chdir(self.processdir)
                # 添加执行权限
                os.chmod(self.processname, stat.S_IXOTH | stat.S_IXGRP | stat.S_IXUSR)
                cmdline = shlex.split(self.processcmd)
                if self.isLinux:
                    # linux下，则关闭所有从父进程继承的fd
                    self.process = subprocess.Popen(cmdline, close_fds=True)
                else:
                    # windows下，则关闭子进程的conlse窗口
                    si = subprocess.STARTUPINFO()
                    si.dwFlags = subprocess.SW_HIDE
                    self.process = subprocess.Popen(cmdline, startupinfo=si)
                return True
            except OSError as e:
                print('start process %s failed,error info %s' % (self.processcmd, e.strerror))
                return False
            except ValueError as e:
                print('start process %s failed,error info %s' % (self.processcmd, e.strerror))
            finally:
                os.chdir(self.currentdir)
                self._mu.release()

    # 判断进程是否启动
    def getprocessstarted(self):
        return (self.process is not None)

    # 进程监控线程
    def run(self):
        while self.checkstatus:
            if self.process is None:
                self.__process__()
            if self.process is not None:
                self.process.wait()
                self.process = None
            print('process cmd %s terminate，will restart later' % self.processcmd)

    # 启动进程
    # 成功返回True,失败返回False
    def startprocess(self):
        startRet = False
        if self.process is None:
            self.checkstatus = True
            startRet = self.__process__()
            if startRet:
                print('start process success,cmd %s' % self.processcmd)
                self.checkstatus = True
                try:
                    self.start()
                except RuntimeError as e:
                    pass
            return startRet

    # 重启进程
    def restartprocess(self):
        if self.process is not None:
            self.checkstatus = True
            time.sleep(0.1)
            self.process.kill()
            os.system('rm ./data/*')


if __name__ == '__main__':
    process = ProcessManage('cms_server', '.')
    ret = process.startprocess()
    print("ret %d" % ret)

    time.sleep(5)
    print("test restart process run fun")
    process.restartprocess()

