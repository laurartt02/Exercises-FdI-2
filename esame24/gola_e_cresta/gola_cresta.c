#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
static void GolaCrestaRec(size_t n, int* sol, size_t i) {

	if (i == n) {
		bool valid = true;
		for (size_t j = 0; j < n; j+=2) {
			if (j + 1 < n) {
				if (sol[j] >= sol[j + 1]) {
					valid = false;
					break;
				}
			}
			if (j + 2 < n) {
				if (sol[j + 1] <= sol[j + 2]) {
					valid = false;
					break;
				}
			}
		}
		if (!valid) {
			valid = true;
			for (size_t j = 0; j < n; j+=2) {
				if (j + 1 < n) {
					if (sol[j] <= sol[j + 1]) {
						valid = false;
						break;
					}
				}
				if (j + 2 < n) {
					if (sol[j + 1] >= sol[j + 2]) {
						valid = false;
						break;
					}
				}
			}
		}
		if (!valid)
			return;
		printf("(");
		for (size_t j = 0; j < n - 1; ++j) {
			printf("%i, ", sol[j]);
		}
		printf("%i), ", sol[n - 1]);
		return;
	}



	for (size_t j = 0; j < 3; ++j) {
		sol[i] = j;
		GolaCrestaRec(n, sol, i + 1);
	}
}
void GolaCresta(size_t n) {
	if (n < 3)
		return;
	int* sol = malloc(n * sizeof(int));
	GolaCrestaRec(n, sol, 0);
	free(sol);
	return;
}