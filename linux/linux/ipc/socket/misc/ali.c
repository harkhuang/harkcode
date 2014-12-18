#include <stdio.h>
#include <sys/types.h>

int
main()
{
	struct {
		u_int8_t name[13];
		int32_t math, chinese;
	}__attribute__((packed)) s;

	printf("%d\n", sizeof(s));

	return 0;
}

