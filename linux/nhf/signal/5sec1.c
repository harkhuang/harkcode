#include <stdio.h>
#include <time.h>
#include <stdint.h>

int
main()
{
	time_t end;
	int64_t	count;

	count = 0;

	end = time(NULL)+5;

	while (time(NULL)<end) {
		count++;
		printf ("%d\n", count);

	}

	printf("%lld\n", count);

	return 0;
}

