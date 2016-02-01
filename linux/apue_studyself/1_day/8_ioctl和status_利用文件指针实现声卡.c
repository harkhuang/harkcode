#include <linux/soundcard.h>
#include "../apue.h"
/*模拟声卡的炒作   status = read(fd, buf, sizeof(buf))*/

int main()
{
	int fd;
	int arg;
	int status;
/*struct stat
{
	mode_t st_mode;
	ino_t st_ino;
	dev_t st_dev;
	dev_t st_rdev;
	nlink_t st_nlink;
	gid_t st_gid;
	uid_t st_uid; 
	off_t st_size;
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
	blksize_t st_blksize;块的大小
	blkcnt_t st_blocks;块的个数
}
*/
	char buf[8000*1*16*3/8];

	fd = open("/dev/dsp", O_RDWR);//打开设备  读写方式打开
	if(fd<0)
	{
		perror("open");
		return -1;
	}
	
	arg = 16;
	status = ioctl(fd, SOUND_PCM_WRITE_BITS, &arg);

	arg = 1;
	status = ioctl(fd, SOUND_PCM_WRITE_CHANNELS , &arg);

	arg = 8000;
	status = ioctl(fd, SOUND_PCM_WRITE_RATE, &arg);

	while(1)
	{
		printf("say something\n");
		status = read(fd, buf, sizeof(buf));

		printf("you said\n");
		status = write(fd, buf, sizeof(buf));
		status = ioctl(fd, SOUND_PCM_SYNC, 0);
	}
}














