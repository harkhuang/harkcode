#include "../apue.h"

int main()
{
	int pfid;
	char buf[6];

	pfid = open("tmp.txt", O_RDWR);
	if(pfid < 0)
	{
		perror("open");
		return -1;
	}

	 lseek(pfid, 3, SEEK_SET);
	sleep(10);

	close(pfid);
}


