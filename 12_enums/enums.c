#include <stdio.h>
#include <stdlib.h>

/* A good way to group values together is by using an enum. But be aware that
 * these are just integers and you do *not* gain any type safety.
 */
enum Color {
	RED,
	GREEN,
	BLUE,
};

/* You can also specify integer values directly. */
enum Truthness {
	FULL_TRUTH = 42,
	HALF_TRUTH = 21,
};

int main(void) {

	enum Color c = RED;

	printf("RED: %d\n", c);

	/* you can do this, but it's bad */
	c = 42;

	enum Truthness t = FULL_TRUTH;

	switch (t) {
		case FULL_TRUTH: printf("You are worthy\n"); break;
		case HALF_TRUTH: printf("Not there yet\n"); break;
		default:         printf("you are doomed\n"); break;
	}

	return EXIT_SUCCESS;
}
