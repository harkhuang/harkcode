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
* 文 件 名：publicdef.h
* 模块名称：基础类
* 功能说明：公共基础宏定义
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
#ifndef  __PUBLICDEF_H__
#define  __PUBLICDEF_H__

#include <assert.h>

// 行情转发宏定义
// 价格倍数
#define   PRICE_RATE       10000
#define   PRICE_RATE_DIGIT 4

#ifndef MAX_BUF_LEN
#define MAX_BUF_LEN       1024   // 最大数据缓存长度
#endif
#ifndef MAX_FILE_PATH
#define MAX_FILE_PATH     256    // 最大路径长度
#endif
#define MAX_SRC_LEN       64     // 最大证券标识长度
#define MAX_TXN_TP_LEN    10     // 最大买卖类型长度
#define MAX_ENTRT_NBR     50     // 委托明细数量
#define MAX_ORDR_NBR_LEN  1024   // 订单明细最大长度
#define MAX_SRC_NAME_LEN  256    // 最大名称长度
#define MAX_USER_LEN      128    // 最大用户名长度
#define MAX_PWD_LEN       64     // 最大密码长度
#define MAX_HQ_TYPE_LEN   16     // 行情类型(发布主题)
#define MAX_PUBLISH_ID_LEN 4     // 发布节点(发布主题)
#define MAX_NUMBER_LEN    48     // 最大数字长度
#define MAX_BASEBUF_LEN   256    // 最大基础缓存长度
#define MAX_NAME_LEN      256    // 最大名称长度
#define MAX_SERVERID_LEN  128    // 最大服务器地址长度
#define MAX_FUTURES_LEVLE_LEN 5  // 最大期货价格档位
#define MAX_HQ_POOL       100000  // 内存池中行情指针个数
#define MAX_HQ_SIZE       10     // 内存池中行情指针malloc大小
#define MAX_CMD_ID        64     // 最大行情插件服务ID长度

// kmds调试宏
#ifdef _DEBUG
#define KMDSASSERT(exp) assert(exp)
#else
#define KMDSASSERT(exp)
#endif

// 日志缓冲区长度
#ifndef DEF_LOGBUF_LEN
#define DEF_LOGBUF_LEN (1024*4)
#endif
// 文件的最大大小为10M  超过10M则新建一个
#ifndef __MAX_FILEZIE__
#define __MAX_FILEZIE__ (1024*1024*10)
#endif
#ifndef __FILENAMEBUF__
#define __FILENAMEBUF__ "user_data"
#endif
//========================================================================================
//日志
#ifndef _DEF_KDLOG_TYPE_
#define _DEF_KDLOG_TYPE_
// 日志级别分为四种组合  分别为 写日志打屏幕  写日志不打屏幕  不写日志打屏幕  不写日志不打屏幕
enum EN_SET_KDLOGLEVEL
{
	// 下面级别需要调用SetLogLevel生效
	SET_KDLOG_DEF = 0,				// 默认级别	会根据用户调用级别打印日志
	SET_KDLOG_PRINTANDWRITE,		// 写日志打屏幕
	SET_KDLOG_ONLYWRITE,			// 写日志不打屏幕
	SET_KDLOG_ONLYPRINT,			// 不写日志打屏幕
	SET_KDLOG_END					// 不写日志不打屏幕
};
enum EN_KDLOGLEVEL
{
	KDLOG_DEBUG = 100,	// 日志调试信息，用于调试时显示于屏幕上。同时将记录于文件中 release版不会打印日志
	KDLOG_TIPS,			// 显示信息 打屏打日志(可屏蔽)
	KDLOG_FILE,			// 记录于日志，记录于文件中。 默认不打屏
	KDLOG_BIZ,			// 打印二进制串 默认不打屏
	KDLOG_WARNING,		// 警告日志，突出显示 默认打屏
	KDLOG_ERROR,		// 错误日志，突出显示 打屏(不可屏蔽写日志)
	KDLOG_SYSTEM		// 程序系统日志 打屏(不可屏蔽写日志)
};
#endif

//========================================================================================
//UI
#ifndef  __KDSERVER_UI__TYPE_
#define  __KDSERVER_UI__TYPE_
enum
{
	TT_TREEVIEW_ADD = 0,
	TT_TREEVIEW_DEL,
	TT_TREEVIEW_DELALL,
	TT_TREEVIEW_GETVIEWCOUNT,
	TT_TREEVIEW_END = TT_TREEVIEW_DELALL,

	TT_LOG = TT_TREEVIEW_DELALL + 1,
	TT_END
};
#endif
#endif

