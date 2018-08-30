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
	double area=0.0f;

#pragma omp parallel for reduction(+: area)
	for (i=0;i<SLICES;++i) {
		area += sin(LEFT+i*WIDTH)*WIDTH;
	}

	printf("area = %f\n", area);

	return 0;
}

