#include <stdio.h>

#define	LEFT	30000000
#define	RIGHT	30000200

int
main()
{
	int i, j;
	int mark;

	for (i=LEFT;i<=RIGHT;++i) {
		mark=1;
		for (j=2;j<i/2;++j) {
			if (i%j==0) {
				mark=0;
				break;
			}
		}
		if (mark==1) {
			printf("%d is a prime\n", i);
		}
	}

	return 0;
}

