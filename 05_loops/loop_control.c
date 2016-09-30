#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* Skipping one iteration
	 *
	 * The `continue` keyword allows you to skip one loop iteration.
	 */
	for (int i = 0; i < 10; ++i) {
		if (i % 2 != 0) {
			continue;
		}
		printf("%d is even\n", i);
	}

	/* Skipping all remaining iterations
	 *
	 * The `break` keyword allows you to skip all remaining iterations.
	 */
	for (int i = 0; i < 10; ++i) {
		if (i == 5) {
			break;
		}
		printf("%d is smaller than 5\n", i);
	}

	/* Nested loops
	 *
	 * Of course loops can be nested, the `continue` and `break` directives
	 * only work on the innermost loop they are used in.
	 */
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (j == 10) {
				break;
			}
			printf("(%d,%d) ", i, j);
		}
		printf("\n\n");
	}

	/* Multi-loop break
	 *
	 * There is no such thing, but we can realize this with `goto`. This is one
	 * of the rare occasions where `goto` is okay to use.
	 */
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (j == 10) {
				goto loopexit;
			}
			printf("(%d,%d) ", i, j);
		}
		printf("\n\n");
	}
loopexit:

	puts("");

	return EXIT_SUCCESS;

}
