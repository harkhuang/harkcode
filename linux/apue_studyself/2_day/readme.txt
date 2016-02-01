目录：
int mkdir(char *pathname, mode_t mode)
S_IR/W/XUSR/GRP/OTH


作业：
实现：ls -a -i -l

time_t time(time *t)//返回的是秒  距当前的秒数
1970.1.1 

struct tm *localtime(time_t *time)//获得系统时间

size_t strftime(char *str, size_t size, char *format, struct tm *time)//

/etc/shadow//存放隐私的地方  例如登录的密码用户等等等等。。。
struct spwd *getspnam(char *name)//这是一个结构体

void setspent(void)//
打开/etc/shadow
struct spwd *getspent(void)//读取隐私结构体
//读取/etc/shadow文件中的数据，一行一行读取直到NULL     不给权限的去读 由于单项性  所以很安全
void endspent(void)//关闭隐私
关闭/etc/shadow

/etc/passwd
struct passwd *getpwnam(char *name)//获得文件结构体
viod setpwent()//打开密码结构体
打开/etc/passwd
struct passwd *getpwent(void)
void endpwent()

















