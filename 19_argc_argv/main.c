#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		printf("%3d: %s\n", i, argv[i]);
	}
	return EXIT_SUCCESS;
}
