#include <stdio.h>
#include <stdlib.h>

/* Basic Recursion
 *
 * We have already seen that a function can call another
 * function. It is also possible to call one self again, even
 * multiple times.
 *
 * Computing Fibonacci numbers is the vanilla example.
 */
int fibonacci(int x) {
	if (x < 2) {
		return 1;
	} else {
		return fibonacci(x - 1) + fibonacci(x - 2);
	}
}

/* Mutual Recursion
 *
 * A recursion can also happen across multiple functions.
 *
 * Note that since the compiler reads the file from top to bottom we use `fun2`
 * before it has been *declared*. We can declare a function by stating its
 * name, return value and parameters (also called the signature) followed by a
 * semicolon.
 */

/* Declaring fun2 */
int fun2(int y);

/* Declaring and defining fun1 */
int fun1(int x) {
	if (x < 2) {
		return 1;
	} else {
		return fun2(x - 1);
	}
}

/* Definition of fun2 */
int fun2(int y) {
	return fun1(y) + fun1(y - 1);
}

int main(void) {

	printf("Fibonacci 12 = %d\n", fibonacci(12));

	printf("Mutual Rec.  = %d\n", fun1(12));

	return EXIT_SUCCESS;

}
