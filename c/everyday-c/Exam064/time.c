# include <time.h>
# include <stdio.h>

int main()
{
	struct tm *local;
	time_t tm;

	tm = time(NULL);
	local = localtime(&tm);
	printf("Local time and date: %s\n", asctime(local));

	local = gmtime(&tm);
	printf("UTC time and date: %s\n", asctime(local));

	return 0;
}