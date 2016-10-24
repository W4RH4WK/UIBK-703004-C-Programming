#include <stdio.h>
#include <stdlib.h>

/* Here we include the module's header file. */
#include "array.h"

#define EXAMPLE_SIZE 42

int main(void) {

	/* create one such array */
	Array* a = Array_create(EXAMPLE_SIZE);

	/* check for errors */
	if (a == NULL) {
		fprintf(stderr, "Could not allocate Array of size %d\n", EXAMPLE_SIZE);
		return EXIT_FAILURE;
	}

	/* and fill them */
	for (int i = 0; i < Array_size(a); ++i) {
		Array_set(a, i, i * 10);
	}

	printf("a: ");
	Array_print(a);
	printf("\n\n");

	/* Out-of-bound access will be prevented by the wrapper. */
	Array_set(a, EXAMPLE_SIZE + 25, 25);

	printf("out-of-bound: %3d\n", Array_get(a, EXAMPLE_SIZE + 25));

	/* do not forget to clean up properly */
	Array_destroy(a);

	return EXIT_SUCCESS;
}
