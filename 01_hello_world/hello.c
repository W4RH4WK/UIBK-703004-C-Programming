#include <stdio.h>   /* defines standard IO operations like `printf` */
#include <stdlib.h>  /* defines EXIT_SUCCESS / EXIT_FAILURE */

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
	 * would be to use the `puts` function.
	 *
	 * To get more information `printf` checkout the related man-page. Be aware
	 * that there is also a command named `printf` on the commandline which
	 * also has a man-page. Attach the related *section* to your man invokation
	 * like this:
	 *
	 *     $ man printf         # man-page of the `printf` command
	 *     $ man 1 printf       # same as above
	 *     $ man 3 printf       # man-page of the C function `printf`
	 *
	 */
	printf("Hello World\n");
	/*                 ^^--- line break */

	/* `main` returns the exit code of the program, which indicates whether the
	 * program was successful or not.
	 */
	return EXIT_SUCCESS;

}
