#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* Basic for-loop
	 *
	 * For-loops are a bit more complicated than while and do-while. But they
	 * are also more useful. They are structured like this:
	 *
	 *     for (<init> ; <condition> ; <step>) <body>
	 *
	 * `<init>`, `<condition>` and `<step>` can each be omitted if necessary. A
	 * typical for-loop could look like this.
	 */
	for(int i = 0; i < 10; ++i) {
		printf("Iteration: %d\n", i);
	}

	/* Writing the above as while-loop */
	{
		int i = 0;
		while (i < 10) {
			printf("Iteration: %d\n", i);
			++i;
		}
	}

	/* Declaring `i` in the init-part of the for-loop is only possible since
	 * C99 and is encouraged since the it is only valid for the scope of the
	 * for-loop.
	 */

	/* Infinite loop */
	/*
		for (;;) {
			puts("looping");
		}
	 */

	return EXIT_SUCCESS;

}
