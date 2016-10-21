#include <stdio.h>
#include <stdlib.h>

/* Unions work in a similar way than structs, but it will only hold *one* value
 * at a time.
 */

union IntOrFloat {
	int i;
	float f;
};

typedef union IntOrFloat IntOrFloat;

int main(void) {

	IntOrFloat my_union;

	my_union.i = 42;

	printf("As int: %10d   As float: %g\n", my_union.i, my_union.f);

	my_union.f = 3.1415;

	printf("As int: %10d   As float: %g\n", my_union.i, my_union.f);

	return EXIT_SUCCESS;
}
