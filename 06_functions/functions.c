#include <stdio.h>
#include <stdlib.h>

/* Beyond main
 *
 * Up until now we placed all of our code in the `main` function which is
 * executed by default. This changes now with the introduction of functions.
 *
 * Functions allow you to group parts of your program together and reuse them
 * at multiple locations. In addition to this, values *transfered* to and from
 * a function via parameters and the return value.
 *
 * But let's keep things simple for now.
 */

/* Prints a divider
 *
 * Does nothing else. We can use it as often as we like, if we decide to change
 * the look of our divider later on, we only have to change the body of this
 * one function.
 */
void divider(void) {
	puts("- - - - - - - - - - - - - - - - - - - - - - - - - - -");
}

/* Returning a value
 *
 * The first part when defining a function indicates the type of the return
 * value. This function will return the ultimate answer.
 */
int ultimate_answer(void) {
	return 42;
}

/* Calculations
 *
 * A more useful application for function is to compute stuff, here parameters
 * allow you to define a computation in a generic way. The actual values for
 * your computation will be provided when you *call* the function.
 *
 * Multiple parameters can be given, separated by a comma.
 */
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; ++i) {
		result *= i;
	}
	return result;
}

/* Pass by value
 *
 * In C everything is *passed by value*, which means that the function will
 * receive and return a copy of the value. For example, changing a parameter
 * inside the function will not modify the original variable.
 */
void useless_function(int x) {
	x += 1337;
}

/* Success or failure
 *
 * Many functions in C use the return value to indicate whether they have
 * succeeded or failed. If such a function is used, the return value should
 * always be changed and the failure case should be handled adequately.
 *
 * The documentation of a function usually tells you which return value
 * corresponds to which error and which to success.
 */
int fails_sometimes(int x, int y) {
	if (x < 10) {
		/* failure nr 1 */
		return 1;
	}

	if (x == y) {
		/* failure nr 2 */
		return 2;
	}

	/* success */
	return 0;
}

/* Good & Bad, Hot & Cold
 *
 * We could have implemented the previous function with a nested if-else block,
 * but we decided against it to show a common pattern when. You may already see
 * that this pattern visually separates the failure paths from the succeeding
 * path. The succeeding path goes from the top of the function straight down to
 * its bottom failure cases are handled *horizontally* and exit the function
 * prematurely.
 *
 * Typically the success path will be taken most of the time. If this is the
 * case this sometimes refereed to the *hot* path in contrast to the *cold*
 * path which are only taken here and then.
 */
int chain_of_computation(int x, int y, float z) {
	if (fails_sometimes(x, y) != 0) {
		return 1;
	}

	if (fails_sometimes(-x, y) != 0) {
		return 2;
	}

	if (z < 5) {
		return 3;
	}

	return 0;
}

int main(void) {

	printf("Section 1: Ultimate Answer = %d\n", ultimate_answer());

	divider();

	printf("Section 2: Factorial 12 = %d\n", factorial(12));

	divider();

	int some_variable = 23;
	useless_function(some_variable);
	printf("Section 3: Pass by value = %d\n", some_variable);

	divider();

	printf("Section 4: Success = %d\n", fails_sometimes(10, 0));
	printf("           Chain   = %d\n", chain_of_computation(2, 3, 2.0f));

	divider();

	return EXIT_SUCCESS;

}
