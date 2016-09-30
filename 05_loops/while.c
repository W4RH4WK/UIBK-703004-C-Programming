#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* Simple while loop */
	{
		int i = 0;
		while (i < 10) {
			printf("Iteration: %d\n", i);
			++i;
		}
	}

	/* This will simply be skipped */
	{
		int i = 12;
		while (i < 10) {
			puts("This should not show up");
		}
	}

	/* Do-while loop will be executed at least once */
	{
		int i = 12;
		do {
			puts("This should be printed once");
		} while (i < 10);
	}

	/* Infinite loop */
	/*
		while (true) {
			puts("looping");
		}
	 */

	/* Omitting the body
	 *
	 * The body of a loop can be written as `;` (empty statement). In this case
	 * the condition is checked over and over again (*polling*) until it
	 * evaluates to true.
	 */
	/* while(until_ready()); */

	return EXIT_SUCCESS;

}
