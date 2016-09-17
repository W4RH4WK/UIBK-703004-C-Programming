#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a = 23;
	int b = 42;

	/* Simple branch in our control-flow. */
	if (a < b) {
		puts("a is smaller than b");
	} else {
		puts("a is bigger than or equal to b");
	}

	/* The `else` part may be omitted. */
	if (a < b) {
		puts("a is still smaller than b");
	}

	/* Another multiple `if`s may be chained together. */
	if (a < b) {
		puts("a is still smaller than b");
	} else if (a > b) {
		puts("a is bigger than b");
	} else {
		puts("a must be equal to b");
	}

	return EXIT_SUCCESS;

}
