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

	/* # Ternary operator
	 *
	 * There is also something named the ternary operator. It is similar to to
	 * and `if else`, but it can be used inside expressions.
	 *
	 * Following two blocks are equivalent;
	 */
	{
		int a = 2 < 3 ? 4 : 5;
	}
	{
		int a;
		if (2 < 3) {
			a = 4;
		} else {
			a = 5;
		}
	}

	/* Can be used like this. */
	printf("2 < 3 is %s\n", 2 < 3 ? "true" : "false");

	/* Use it whenever it makes code more readable! */

	return EXIT_SUCCESS;

}
