#include <stdio.h>
#include <math.h>

#define	LEFT	0.0F
#define	RIGHT	3.1416F

#define	SLICES	100000000
#define	WIDTH	((RIGHT-LEFT)/SLICES)

int
main()
{
	int i;
	double area=0.0f, s;

#pragma omp parallel for private(s)
	for (i=0;i<SLICES;++i) {
		s = sin(LEFT+i*WIDTH)*WIDTH;
#pragma omp critical
		area += s;
	}

	printf("area = %f\n", area);

	return 0;
}

