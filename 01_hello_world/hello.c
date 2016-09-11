#include <stdio.h>		/* defines standard IO operations like `printf` */
#include <stdlib.h>		/* defines EXIT_SUCCESS / EXIT_FAILURE */

/* Main entry point of our program.
 *
 * It returns an exit code indication whether
 * execution was successful or not. Your shell stores the last exit code
 * received in `$?`. Try this:
 *
 *     $ make
 *     $ ./hello
 *     $ echo $?
 *
 * It should show answer with `0` which is equivalent to EXIT_SUCCESS (on
 * Unix). Try changing EXIT_SUCCESS to a different number like 42 or 1337.
 */
int main(void) {
	/* Print the string `Hello World` followed by a new-line. Another option
	 * would be to use the `puts` function. */
	printf("Hello World\n");

	/* `main` returns the exit code of the program. */
	return EXIT_SUCCESS;
}
