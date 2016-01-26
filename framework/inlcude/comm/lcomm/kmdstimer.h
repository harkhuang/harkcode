/******************************************************************************
*
*									KMDS V1.0
*
*           Copyright (C) 2012-2013, SHENZHEN KINGDOM Co., Ltd.
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* 文 件 名：kmdstimer.h
* 模块名称：基础类
* 功能说明：时间类
* 作    者：liulj
* 创建日期：2013-07-20
* 版 本 号：1.0
* 修改历史：
*
* 修改日期       姓名            内容
* ---------------------------------------------------------------------------
* 2013-07-20     liulj         初始版本
*
******************************************************************************/
#ifndef __KMDSTIMER_H__
#define __KMDSTIMER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#if defined _WIN32 || defined _WIN64
#include <windows.h>
#elif _LINUX_
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif

#if defined _WIN32 || defined _WIN64
typedef __int64  int64_time;
#elif _LINUX_
typedef long long  int64_time;
#ifndef NULL
#define NULL 0
#endif
#ifndef _snprintf
#define _snprintf snprintf
#endif
#ifndef _atoi64
#define _atoi64   atoll
#endif
#endif

// kmds计时类
class CKmdsTimer
{
public:
    CKmdsTimer()
	{
#if defined _WIN32 || defined _WIN64
		m_dbSystemFreq = 0.0;
		m_bflag = false;
		m_dbStartTime = 0.0;
		m_dbStopTime = 0.0;

		LARGE_INTEGER sysFreq;  // 计时器频率
		m_bflag = QueryPerformanceFrequency( &sysFreq );
		if (m_bflag)
		{
			m_dbSystemFreq = (double)sysFreq.QuadPart;
		}
#endif
	}
    void start()
	{
#if defined _WIN32 || defined _WIN64
		LARGE_INTEGER st;
		m_bflag &= QueryPerformanceCounter(&st);
		if (m_bflag)
		{
			m_dbStartTime = (double)st.QuadPart;
		}
#elif _LINUX_
		gettimeofday( &tvStart, 0 );
#endif
	}
	// 返回从 start 到 stop 所经历的时间（单位:秒）
    double stop()
	{
#if defined _WIN32 || defined _WIN64
		LARGE_INTEGER st;
		m_bflag &= QueryPerformanceCounter( &st );

		if ( !m_bflag || fabs(m_dbSystemFreq) < 0.000001)
		{
			return -1.0;
		}

		m_dbStopTime = (double)st.QuadPart;
		return ( m_dbStopTime - m_dbStartTime ) / m_dbSystemFreq;
#elif _LINUX_
		gettimeofday( &tvStop, 0);
		return (double)(tvStop.tv_sec - tvStart.tv_sec) + (double)(tvStop.tv_usec - tvStart.tv_usec)/1000000.0;
#endif
	}
	static int gettime() //获取当前时间单位秒
	{
		char sztime[64] = {0};
		time_t curTime = time(NULL);
 #ifdef _WIN32
        struct tm tm_nowtime = (*localtime(&curTime));
 #else
        struct tm tm_nowtime;
		localtime_r(&curTime, &tm_nowtime);
 #endif
		_snprintf(sztime, sizeof(sztime) - 1,"%02d%02d%02d", tm_nowtime.tm_hour, tm_nowtime.tm_min, tm_nowtime.tm_sec);
		sztime[sizeof(sztime) - 1 ] = '\0';
		return atoi(sztime);
	}
	static int gettimems() //获取当前时间  单位毫秒
	{
#if defined _WIN32 || defined _WIN64
		char sztime[64] = {0};
		SYSTEMTIME sys;
		GetLocalTime( &sys );
		_snprintf(sztime, sizeof(sztime) - 1,"%02d%02d%02d%03d", sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds);
		sztime[sizeof(sztime) - 1 ] = '\0';
		return atoi(sztime);
#elif _LINUX_
		return gettimeus()/1000;
#endif
	}
	static int getdate() //获取当前日期
	{
		char szdate[64] = {0};
		time_t curTime = time(NULL);
		struct tm tm_nowtime = *(localtime(&curTime));
		_snprintf(szdate, sizeof(szdate) - 1,"%04d%02d%02d",
			tm_nowtime.tm_year + 1900, tm_nowtime.tm_mon + 1,tm_nowtime.tm_mday);
		szdate[sizeof(szdate) - 1 ] = '\0';
		return atoi(szdate);
	}
	// 当前时间精确到微秒(不是很精确，如需获取精确执行耗时请使用 start 和stop函数)
	static int64_time gettimeus()
	{
		char sztime[64] = {0};
#if defined _WIN32 || defined _WIN64
		SYSTEMTIME sys;
		GetLocalTime( &sys );
		LARGE_INTEGER ticksPerSecond;
		QueryPerformanceFrequency (&ticksPerSecond);

		//  What time is it?
		LARGE_INTEGER tick;
		QueryPerformanceCounter (&tick);

		//  Convert the tick number into the number of seconds
		//  since the system was started.
		double ticks_div = (double) (ticksPerSecond.QuadPart / 1000000);
		int64_time us = (int64_time) (tick.QuadPart / ticks_div)%1000;

		_snprintf(sztime, sizeof(sztime) - 1,"%02d%02d%02d%03d%03d", sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds,us);
#elif _LINUX_
		struct timeval nowtimeval;
		gettimeofday(&nowtimeval,0);

		time_t now;
		struct tm tm_nowtime;

		time(&now);
		tm_nowtime = *(localtime(&now));

		_snprintf(sztime,sizeof(sztime) - 1,
			"%02d%02d%02d%03d%03d",
			tm_nowtime.tm_hour,
			tm_nowtime.tm_min,
			tm_nowtime.tm_sec,
			nowtimeval.tv_usec/1000,
			nowtimeval.tv_usec%1000);
#endif
		sztime[sizeof(sztime) - 1 ] = '\0';
		return _atoi64(sztime);
	}
/*
Lanq 20131219

LINUX下
localtime:   使用静态变量存储时间结构体，非多线程安全。
localtime_r: 提供可重入。每个glibc的实现版本不一致。归结为:
		<1>localtime_r实现内有静态全局变量，当你主动修改timezone/altzone/daylight/tzname这4个变量时候，就可能非线程安全。
		<2>localtime_r可能存在死锁. 存在情形: 父进程存在线程调用localtime_r函数，那么当父进程fork子进程的时候，
		可能会出现某一个线程已经lock了localtime_r的锁，这时候子进程继承了这个已经标记为lock的锁。
		这样就导致了在子进程中调用localtime_r获取锁的时候，一直被block。

solaris10，SUN对自己实现的time类函数是这样说的:
The asctime(), ctime(), gmtime(), and localtime()  functions are  safe  to  use  in multithread applications
because they employ  thread-specific  data.   However,   their   use   is discouraged
because  standards  do  not  require them to be  thread-safe.

The asctime_r() and  gmtime_r()  functions  are MT-Safe. The ctime_r(), localtime_r(), and tzset() functions
are MT-Safe in  multithread  applications,
as  long  as  no  user-defined function directly modifies one of the following variables:
timezone, altzone, daylight,  and  tzname.
These four  variables are not MT-Safe to access.
They are modified by the tzset() function in an MT-Safe manner.  The mktime(), localtime_r(), and ctime_r() functions call tzset().

当前系统:
LSB Version:    :core-4.0-amd64:core-4.0-noarch:graphics-4.0-amd64:graphics-4.0-noarch:printing-4.0-amd64:printing-4.0-noarch
Distributor ID: RedHatEnterpriseServer
Description:    Red Hat Enterprise Linux Server release 6.3 (Santiago)
Release:        6.3
Codename:       Santiago

  The localtime() function converts the calendar time timep to broken-time representation, expressed relative  to
       the  user’s  specified  timezone.   The  function acts as if it called tzset(3) and sets the external variables
       tzname with information about the current timezone, timezone with the difference between Coordinated  Universal
       Time  (UTC) and local standard time in seconds, and daylight to a non-zero value if daylight savings time rules
       apply during some part of the year.  The return value points to a statically allocated struct  which  might  be
       overwritten  by  subsequent  calls  to any of the date and time functions.  The localtime_r() function does the
       same, but stores the data in a user-supplied struct.  It need not set tzname, timezone, and daylight.

       The four functions asctime(), ctime(), gmtime() and localtime() return a pointer to static data and  hence  are
       not  thread-safe.   Thread-safe  versions asctime_r(), ctime_r(), gmtime_r() and localtime_r() are specified by
       SUSv2, and available since libc 5.2.5

*/
	// 当前时间精确到微秒(不是很精确，如需获取精确执行耗时请使用 start 和stop函数)
	static int64_time gettimeus_r()
	{
		char sztime[64] = {0};
#if defined _WIN32 || defined _WIN64
		SYSTEMTIME sys;
		GetLocalTime( &sys );
		LARGE_INTEGER ticksPerSecond;
		QueryPerformanceFrequency (&ticksPerSecond);

		//  What time is it?
		LARGE_INTEGER tick;
		QueryPerformanceCounter (&tick);

		//  Convert the tick number into the number of seconds
		//  since the system was started.
		double ticks_div = (double) (ticksPerSecond.QuadPart / 1000000);
		int64_time us = (int64_time) (tick.QuadPart / ticks_div)%1000;

		_snprintf(sztime, sizeof(sztime) - 1,"%02d%02d%02d%03d%03d", sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds,us);
#elif _LINUX_
		struct timeval nowtimeval;
		gettimeofday(&nowtimeval,0);

		time_t now;
		struct tm tm_nowtime;

		time(&now);
		localtime_r(&now, &tm_nowtime);

		_snprintf(sztime,sizeof(sztime) - 1,
			"%02d%02d%02d%03d%03d",
			tm_nowtime.tm_hour,
			tm_nowtime.tm_min,
			tm_nowtime.tm_sec,
			nowtimeval.tv_usec/1000,
			nowtimeval.tv_usec%1000);
#endif
		sztime[sizeof(sztime) - 1 ] = '\0';
		return _atoi64(sztime);
	}

	// 微秒单位级别   linux下能精确到微秒   window下为毫秒
	static void sleep (unsigned int nuseconds)
	{
#if defined _WIN32 || defined _WIN64
		Sleep (nuseconds*1000);
#elif _LINUX_
		struct timespec t;
		t.tv_sec  =  nuseconds / (1000 * 1000);
		t.tv_nsec = (nuseconds % (1000 * 1000)) * 1000;
		nanosleep (&t, NULL);
#endif
		return;
	}
private:
#if defined _WIN32 || defined _WIN64
    double m_dbSystemFreq;
    BOOL   m_bflag;
    double m_dbStartTime;
    double m_dbStopTime;
#elif  _LINUX_
    struct timeval tvStart;
    struct timeval tvStop;
#endif
};
#endif

/*******************************************
	使用实例
	CKmdsTimer objLxTimer;
	double time = 0.0;

	objLxTimer.start();
	...自定义操作
	time = objLxTimer.stop();// 得到自定义耗时
******************************************/
