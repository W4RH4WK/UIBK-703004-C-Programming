/* Short description goes here, single line.
 *
 * Longer description goes here, typically multiple lines. Also state state how
 * to run the resulting program if its not obvious. Here just an example:
 *
 *     $ ./formatting
 *
 * Always provide / use a Makefile to bulid, do not invoke the compiler by
 * hand. All programs must compile with following flags:
 *
 *     CFLAGS = -Wall -Wextra -pedantic -Werror -std=c99 -O2
 *
 */

/* Includes go to the top of your file and are sorted alphabetically. */
#include <stdio.h>
#include <stdlib.h>

/* Add a comment to a function, like this IF the function signature (name,
 * return value and arguments) does not already give away its purpose.
 */
void super_complicated_function(void) {
	/* ... */
}

/* No need for a description here! */
int add_two(int x) {
	return x + 2;
}

int main(void) {
	/* always initialize variables */
	int foo = 42;

	if (foo > 2) {
		puts("foo is greater than two");
	} else {
		puts("foo is less than or equal to two");
	}

	/* else part may be omitted */
	if (foo > 3) {
		puts("foo is greater than three");
	}

	/* we'll learn more about loops later on, dont worry */
	int i = 0;
	while (i < foo) {
		printf("Iteration: %d\n", i);
		i = i + 1;
	}

	/* all done, everything is shiny */
	return EXIT_SUCCESS;
}
