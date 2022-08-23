#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
bool IsP4(int n, int *x, int ret) {
	if (ret == n)
		return true;
	if (ret > n)
		return false;
	(*x)++;
	return IsP4(n, x, ret * 4);
}
int main(int argc, char** argv) {
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	int x = 0;
	bool p = IsP4(n, &x, 1);
	if (p)
		printf("4 ^ %d = %d", x, n);
	else
		printf("!p4");

	return 0;
}