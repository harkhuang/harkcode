#include <>

#include <proto.h>
#include "medialib.h"
#include "main.h"

static struct chn_list_ent *listp;
static int list_n;

struct global_config_st global_config = {
	
};

static void daemon_exit(int s)
{
	thr_hoster_destroy();
	thr_channel_destroyall();
	media_freechnlist(listp);
}

/*
 * 	-M	指定多播组
 * 	-P	指定接收端口
 * 	-D	指定媒体目录
 * 	-I	指定播送网卡
 * 	-F	前台运行
 * 	-H	显示帮助信息
 */
int
main()
{

	/* 配置默认值 */
	/* 解析命令行参数 */

	if (media_getchnlist(&listp, &list_n)) {
	}

	if (thr_hoster_create(listp, list_n)) {
	}

	for (i=0;i<list_n;++i) {
		thr_channel_create(listp+i);
	}

	while (1) pause();

	return 0;
}

