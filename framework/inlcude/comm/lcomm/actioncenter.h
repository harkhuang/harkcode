#ifndef __ACTION_CENTER_INCLUDE_H__
#define __ACTION_CENTER_INCLUDE_H__

#include <string>
#include <map>
#include <platform/criticalsection.h>
#include <platform/lcommthread.h>
#include <lcomm/singleton.h>
#include <lcomm/actioninterface.h>
// liulj 10131126 add Timeout
#ifdef _LINUX_
#include <unistd.h>
#endif

// 执行类线程
class CActionCenterThread: public CLCommThread
{
	public:
		CActionCenterThread() { }
		virtual ~CActionCenterThread() { }
		int Run();
};

//格式：DAY|n, n天初始化一次
#define DEF_ACTION_DATE "DATE|"
//未使用
#define DEF_ACTION_NOWTIME "NOWTIME"
//未使用
#define DEF_ACTION_DATETIME "DATETIME|"
//格式:TIME|HH:MM:SS, 则到达此时间进行触发
#define DEF_ACTION_TIME "TIME|"			

// 执行类
class CActionCenter: public Singleton<CActionCenter>
{
	friend class CActionCenterThread;
	public:
		CActionCenter();
		virtual ~CActionCenter();

    // 设置动作执行周期, 若存在相同动作名字返回失败
		// 入参: lpszActionName 动作名
		//       lpszStartTime  开始运行时间 
		//                                   DATE|n 
		//                                   TIME|HH:MM:SS       每天时间
		//                                   
		//       ncycle 周期(秒)
		// 出参: 0  - 成功
		//       -1 - 失败
		//设置该动作的名称，设置第一次启动的时间，设置每过多少时间间隔便触发动作
		int SetActionTime(char  *lpszActionName,char *lpszStartTime,int ncycle);
		//重设动作执行周期
		int ReSetActionTime(char * lpszActionName, char *lpszStartTime,int ncycle);
		// 注册动作接口
		int RegisterAction(char * lpszActionName, CActionInterface *pActionInterface);

		// 反注册动作接口
		int UnRegisterAction(char *lpszActionName, CActionInterface *pActionInterface);
		
		int StartThread();
		int StopThread();
		
		int IsActionCenterThreadRunning();
	private:
		int Clear();

		struct ST_TIMEINFO
		{
			char sztimeinfoname[256];        // 动作名称
			int nCycle;                      // 时间周期
			time_t dwStartSettingTime;        // 开始设置时间
			int nRunTimes;                   // 运行次数
			time_t dwFirstRunTime;            // 第一次运行时间
			time_t dwLastRunTime;             // 最后运行时间
			time_t dwNextRunningTime;         // 下一次运行时间
			int nRunning;                    // 是否运行中
		};
		
		// 动作发生表 类型 时间信息
		typedef std::map<std::string, ST_TIMEINFO *> map_timesinfo;
		map_timesinfo m_map_timesinfo;
		
		// 动作注册表 类型 动作接口
		typedef std::multimap<std::string, CActionInterface *> multimap_actions;
		multimap_actions m_multimap_actions;

		CLCommThread *m_pactioncenter_thread;

		CriticalSection m_cslock;
		// liulj 10131126 add Timeout
#ifdef _LINUX_
		sem_t m_waithandle;
#endif
};

#endif // __ACTION_CENTER_INCLUDE_H__
