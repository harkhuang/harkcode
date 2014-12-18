#include <stdio.h>
#include <stdint.h>

int
main()
{
	struct {
		uint8_t name[13];
		int32_t math, chinese;
	}__attribute__((packed)) s;

	printf("%d\n", sizeof(s));

	return 0;
}

