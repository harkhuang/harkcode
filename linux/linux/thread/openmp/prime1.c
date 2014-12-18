#include <stdio.h>

#define	LEFT	30000000
#define	RIGHT	30000200

int
main()
{
	int i, j;
	int mark;
	int count;

	count=0;
#pragma omp parallel for private(j, mark)
	for (i=LEFT;i<=RIGHT;++i) {
		mark=1;
		for (j=2;j<i/2;++j) {
			if (i%j==0) {
				mark=0;
				break;
			}
		}
		if (mark==1) {
#pragma omp critical
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}

