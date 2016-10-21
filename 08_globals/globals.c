#include <stdio.h>
#include <stdlib.h>

/* This variable has global scope and can be used in all functions. We can also
 * set it to a value right away, otherwise it will be initialized to 0.
 *
 * It will be placed in the data section of your program.
 */
int my_global_var = 42;

void increment_global(void) {
	++my_global_var;
}

void print_global(void) {
	printf("my global var: %d\n", my_global_var);
}

/* Another way of placing variables in the data section is by using the
 * `static` keyword on a local variable. You can initialize it with a value,
 * this value will be set only once at the start of your program.
 */
int counter(void) {
	static int c = 2;
	++c;
	return c;
}

/* Global constants can be defined like this, note the all-caps naming
 * convention */
const int ULTIMATE_ANSWER = 42;

/* Another way is by using the pre-processor. */
#define MY_AWESOME_CONSTANT 1337

/* Or by using an `enum`, more about enums later on.
 *
 * see: <http://stackoverflow.com/a/1674459>
 */
enum { HALF_TRUTH = 21 };

/* All three methods have their own benefits and drawbacks. But they exceed the
 * scope of these examples.
 *
 * Generally speaking, you should avoid global variables (and any kind of
 * global state) whenever possible. See [1] and [2] for a detailed
 * explanation.
 *
 * Constants are fine as long as they serve a purpose and have a telling name.
 *
 * [1]: <http://programmers.stackexchange.com/a/148109>
 * [2]: <http://programmers.stackexchange.com/a/148154>
 */
int main(void) {

	/* set my_global_var from 42 to 12 */
	my_global_var = 12;

	increment_global();
	increment_global();
	increment_global();
	print_global();

	printf("counter: %d\n", counter());
	printf("counter: %d\n", counter());
	printf("counter: %d\n", counter());
	printf("counter: %d\n", counter());

	return EXIT_SUCCESS;

}
