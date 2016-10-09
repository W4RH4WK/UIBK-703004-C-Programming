#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* So far we haven't looked at strings, we just used them inside `printf`
	 * and `puts`. Observe the type!
	 *
	 * Strings are usually `const` but we don't care about this now.
	 */
	char* hello = "Hello World";

	/* It is a pointer, but where exactly does it point to? */
	printf("value behind hello:      %c\n", *hello);

	/* It points to the start of the string, `H` what comes next? */
	printf("value behind hello +  1: %c\n", *(hello + 1));

	/* Hm... let's look at the rest */
	for (int i = 2; i < 11; ++i) {
		printf("             hello + %2d: %c\n", i, *(hello + i));
	}

	/* So all characters of the string are located in consecutive memory cells
	 * and our pointer points to the beginning.
	 *
	 * Whats at the end? A so-called *null terminator*.
	 */
	printf("character after the actual string: %d\n", *(hello + 11));

	/* Strings are handled this way in C, you get a pointer to the first
	 * element and the string goes on until a *null byte* (terminator) is
	 * encountered.
	 *
	 * Remember that cumbersome way of *offsetting* and dereferencing the
	 * pointer, that `*(hello + 7)` well there is a shorthand for it. I present
	 * you:
	 */
	printf("Somewhere in string: %c\n", hello[7]);
	                                       /* ^-- offset */

	/* We can anything between `[` and `]` as we would be able to do with `+
	 * ...`. Let's do the for-loop again. */
	printf("Now without newlines one char at a time: ");
	for (int i = 0; i < 11; ++i) {
		printf("%c", hello[i]);
	}
	printf("\n");

	/* What we just learned are actually *arrays*. So instead of dealing with 5
	 * separate `int`s, we could just slap 5 of them together and handle a
	 * pointer to the first one. Like this: */
	int my_first_array[5] = {42, 1, 12, 4, 1337};

	/* And print them in a similar fashion. */
	for (int i = 0; i < 5; ++i) {
		printf("my_first_array pos %d: %d\n", i, my_first_array[i]);
	}

	/* A short hand for setting everything to zero */
	int my_second_array[100] = {0};

	/* Final note: Only strings have a terminator at the end, arrays don't, you
	 * ask for 100 slots, you get exactly 100 slots, no more, no less.
	 * Accessing an array outside it's *bounds* can have fatal consequences. */

	return EXIT_SUCCESS;

}
