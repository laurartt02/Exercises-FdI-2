#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static void RisolviProdottoRec(int n, const int* s, int i, int* vcurr, int*vsol, bool *used) {
	if (vsol[0] != 0)
		return;
	if (i == n * n) {
		int p = 1;
		int prodotto_r = 1;
		for (int k = 0; k < n * n; ++k) {
			if (k % n == 0 && k != 0) {
				if (p!=1&&prodotto_r!=p) {
					return;
				}
				p = prodotto_r;
				prodotto_r = 1;
			}
			prodotto_r *= vcurr[k];
		}
		int count = 0;
		int prodotto_c = 1;
		for (int k = 0; k < n * n; k += n) {
			prodotto_c *= vcurr[k];
			if (k / n == n - 1) {
				if (prodotto_c != prodotto_r)
					return;
				prodotto_c = 1;
				++count;
				if (k < n * n - 1)
					k = count - n;
			}
		}
		memcpy(vsol, vcurr, n * n * sizeof(int));
		return;
	}
	for (int j = 0; j < n * n; ++j) {
		if (!used[j] && vsol[0]==0) {
			vcurr[i] = s[j];
			used[j] = true;
			RisolviProdottoRec(n, s, i + 1, vcurr, vsol, used);
			used[j] = false;
		}
	}
}

int* RisolviProdotto(int n, const int* s) {
	int* vsol = calloc(n * n, sizeof(int));
	int* vcurr = calloc(n * n, sizeof(int));
	bool* used = calloc(n * n, sizeof(bool));
	RisolviProdottoRec(n, s, 0, vcurr, vsol, used);
	free(used);
	free(vcurr);
	if (vsol[0] == 0) {
		free(vsol);
		return NULL;
	}
	return vsol;
}