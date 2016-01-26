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

// ִ�����߳�
class CActionCenterThread: public CLCommThread
{
	public:
		CActionCenterThread() { }
		virtual ~CActionCenterThread() { }
		int Run();
};

//��ʽ��DAY|n, n���ʼ��һ��
#define DEF_ACTION_DATE "DATE|"
//δʹ��
#define DEF_ACTION_NOWTIME "NOWTIME"
//δʹ��
#define DEF_ACTION_DATETIME "DATETIME|"
//��ʽ:TIME|HH:MM:SS, �򵽴��ʱ����д���
#define DEF_ACTION_TIME "TIME|"			

// ִ����
class CActionCenter: public Singleton<CActionCenter>
{
	friend class CActionCenterThread;
	public:
		CActionCenter();
		virtual ~CActionCenter();

    // ���ö���ִ������, ��������ͬ�������ַ���ʧ��
		// ���: lpszActionName ������
		//       lpszStartTime  ��ʼ����ʱ�� 
		//                                   DATE|n 
		//                                   TIME|HH:MM:SS       ÿ��ʱ��
		//                                   
		//       ncycle ����(��)
		// ����: 0  - �ɹ�
		//       -1 - ʧ��
		//���øö��������ƣ����õ�һ��������ʱ�䣬����ÿ������ʱ�����㴥������
		int SetActionTime(char  *lpszActionName,char *lpszStartTime,int ncycle);
		//���趯��ִ������
		int ReSetActionTime(char * lpszActionName, char *lpszStartTime,int ncycle);
		// ע�ᶯ���ӿ�
		int RegisterAction(char * lpszActionName, CActionInterface *pActionInterface);

		// ��ע�ᶯ���ӿ�
		int UnRegisterAction(char *lpszActionName, CActionInterface *pActionInterface);
		
		int StartThread();
		int StopThread();
		
		int IsActionCenterThreadRunning();
	private:
		int Clear();

		struct ST_TIMEINFO
		{
			char sztimeinfoname[256];        // ��������
			int nCycle;                      // ʱ������
			time_t dwStartSettingTime;        // ��ʼ����ʱ��
			int nRunTimes;                   // ���д���
			time_t dwFirstRunTime;            // ��һ������ʱ��
			time_t dwLastRunTime;             // �������ʱ��
			time_t dwNextRunningTime;         // ��һ������ʱ��
			int nRunning;                    // �Ƿ�������
		};
		
		// ���������� ���� ʱ����Ϣ
		typedef std::map<std::string, ST_TIMEINFO *> map_timesinfo;
		map_timesinfo m_map_timesinfo;
		
		// ����ע��� ���� �����ӿ�
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
