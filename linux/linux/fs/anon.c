#include <stdio.h>

int
main()
{
	FILE *tmp;//定义文件指针
	int i;//定义整形变量
	char buf[1024];

	tmp = tmpfile();

	puts("tmpfile() OK.");
	getchar();

	for (i=0;i<100*1024;++i) {
		fwrite(buf, 1, 1024, tmp);
	}
	fflush(tmp);

	puts("fill OK.");
	getchar();

	fclose(tmp);

	puts("close OK.");
	getchar();

	return 0;
}

