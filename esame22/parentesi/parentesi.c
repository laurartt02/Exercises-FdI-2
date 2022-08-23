#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
static void ParentesiRec(int n, int i, int* nsol, int* sol, int aperte, int chiuse) {
	if (sol[0] == 1 || sol[2 * n - 1] == 0)
		return;
	if (i == 2 * n) {
		if (aperte != chiuse || (aperte == 0 && chiuse == 0))
			return;
		int aperte_count = 0;
		int chiuse_count = 0;
		for (int a = 0; a < 2 * n; ++a) {
			if (sol[a] == 0)
				aperte_count++;
			else
				chiuse_count++;
			if (chiuse_count > aperte_count)
				return;
		}
		for (int b = 0; b < 2 * n; ++b) {
			if (sol[b] == 0)
				printf("(");
			else
				printf(")");
		}
		printf("\n");
		(*nsol)++;
		return;
	}

	for (size_t j = 0; j < 2; ++j) {
		sol[i] = j; // j = 0 -> "(", j = 1 -> ")"
		if (j == 0)
			ParentesiRec(n, i + 1, nsol, sol, aperte + 1, chiuse);
		else
			ParentesiRec(n, i + 1, nsol, sol, aperte, chiuse + 1);
		sol[i] = -1;
	}
}
int Parentesi(int n) {
	if (n < 0)
		return -1;
	int nsol = 0;
	int *sol = malloc(sizeof(int) * 2 * n);
	memset(sol, -1, 2 * n * sizeof(int));
	ParentesiRec(n, 0, &nsol, sol, 0, 0);
	free(sol);
	return nsol;
}