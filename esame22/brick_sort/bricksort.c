#include <stdlib.h>
#include <stdbool.h>
void BrickSort(int* v, size_t v_size) {

	bool scambio = true;
	while (scambio) {
		scambio = false;
		for (size_t i = 0; i < v_size; ++i) {
			if (((2 * i + 1) < v_size) && ((2 * i + 2) < v_size)) {
				if (v[2 * i + 1] > v[2 * i + 2]) {
					int app = v[2 * i + 1];
					v[2 * i + 1] = v[2 * i + 2];
					v[2 * i + 2] = app;
					scambio = true;
				}
			}
			else
				break;
		}
		for (size_t i = 0; i < v_size; ++i) {
			if (((2 * i) < v_size) && ((2 * i + 1) < v_size)) {
				if (v[2 * i] > v[2 * i + 1]) {
					int app = v[2 * i];
					v[2 * i] = v[2 * i + 1];
					v[2 * i + 1] = app;
					scambio = true;
				}
			}
			else
				break;
		}
	}
	return;
}