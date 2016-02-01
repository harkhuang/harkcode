fseeko
ftello

文件描述符的分配原则：最小并且是空闲的
标准的输入(0) 输出(1) 错误处理(2)

采样频率：
量化位数：
声道数：
编码：
声音数据量=采用＊量化位*声道数＊持续的时间／8

ioctl()
基本操作：open write read lseek ltell close ...

int stat(char *pathname, struct stat *buf)
int fstat(int pfid, struct stat *buf)
int lstat(char *pathname, struct stat *buf)
struct stat
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

S_IRWXU S_IRUSR S_IWUSR S_IXUSR
S_IRWXG S_IRGRP S_IWGRP S_IXGRP
S_IRWXO S_IROTH S_IWOTH S_IXOTH

软链接 硬链接
int link(char *old, char *new_link)

int symlink(char *old, char *new_link)

mode_t umask(mode_t mask)




































