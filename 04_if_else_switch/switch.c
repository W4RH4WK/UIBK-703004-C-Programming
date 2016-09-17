#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a = 23;

	/* Sometimes you have to distinguish multiple cases based. Instead of
	 * building a long chain of `else if`s one could use a `switch`.
	 */
	switch (a) {
		case 0:
			puts("a is zero");
			break;

		case 1:
			puts("a is one");
			break;

		case 42:
			puts("a is the ultimate answer");
			break;

		default:
			puts("a is something else");
	}

	/* The `break` is important since switch allows for *fallthrough*. */
	switch (a) {
		case 0:
			puts("a is zero");
		case 1:
			puts("a is zero or one");
		case 2:
			puts("a is zero, one or two");
			break;

		case 3:
			puts("a is three");
		
		default:
			puts("a is three or something else, but not zero, one or two");
	}

	/* Braces in case
	 *
	 * Sometimes you see braces around a `case` block. Even though they are not
	 * needed most of the time, you have to add them when declaring a variable
	 * inside a `case` block.
	 */
	switch (a) {
		case 0: {
			int b = 0;
			break;
		}

		case 1: {
			int c = 0;
			break;
		}

		/* default can be omitted */
	}

	return EXIT_SUCCESS;

}
