#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int DivideNConquerRec(double n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return DivideNConquerRec(ceil(n / 2)) + DivideNConquerRec(floor(n / 2)) + n;
}
int main(int argc, char **argv)
{
	if (argc != 2) {
		return 1;
	}
	char* endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (endptr[0] != 0 || n<0)
		return 1;
	int ret = DivideNConquerRec((double)n);
	printf("%d", ret);
	return 0;
}