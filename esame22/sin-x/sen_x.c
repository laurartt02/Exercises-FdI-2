#include <stdio.h>
#include <stdlib.h>

void SinX(double x, double i, double ret, double n, double pot, double den) {
	if (i == n - 1) {
		printf("%lf", ret);
		return;
	}
	
	pot *= x * x * (-1);
	
	den *=(2*n+1)*2 * n;

	ret += pot / den;
	SinX(x, i, ret, n + 1, pot, den);
}

int main(int argc, char** argv) {
	if (argc != 3)
		return 1;

	char* endptr;
	double x = strtod(argv[1], &endptr);
	if (endptr[0] != 0)
		return 1;
	double i = strtod(argv[2], &endptr);
	if (i < 0)
		return 1;

	SinX(x, i, x, 1, x, 1);


	return 0;
}