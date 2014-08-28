#ifndef ANYTIMER_H
#define ANYTIMER_H

#define	AT_JOBMAX	1024

typedef	void	at_jobfunc_t	(void*);

int at_addjob(int, at_jobfunc_t*, void*);
//int at_addjob(int, at_jobfunc_t*, void*);
/*
 * 	ret:	>=0			正常，返回任务描述符
 * 			==-ENOMEM	数组满了或内存不足
 */

int at_canceljob(int);
/*
 * 	ret:	==0			成功，任务已经取消
 * 			==-ESRCH	失败，任务不存在
 * 			==-EINVAL	失败，参数非法
 * 			==-EBUSY	失败，任务已经结束，尚未回收
 * 			==-ECANCELED	失败，任务早已经被取消
 */

int at_waitjob(int);
/*
 * 	ret:	==0			成功，任务已经删除
 * 			==-ESRCH	失败，任务不存在
 * 			==-EINVAL	失败，参数非法
 */


/******************************************/
/****************  V 2.0   ****************/
/******************************************/
int at_addjob(struct timeval*, at_jobfunc_t*, void*);

#endif

