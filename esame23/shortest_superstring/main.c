#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
extern char* SolveSuperstring(const char** v, size_t v_size);

int main(void) {
	const char** v = malloc(4 * sizeof(char*));
	v[0] = "ABCDH";
	v[1] = "DHE";
	v[2] = "BCDH";
	v[3] = "HEF";
	
	char* r = SolveSuperstring(v, 4);

	free(r);
	free(v);
	_CrtDumpMemoryLeaks();
	return 0;
} 