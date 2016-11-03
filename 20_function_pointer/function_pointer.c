#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A pointer can not only point to data, but also to a function. The function
 * pointer's type is composed of the function's return type and argument types.
 *
 * Since the syntax is a bit cumbersome to write, a typedef comes in handy.
 *
 * In this small example we set the function pointer either to `sum` or
 * `product` and use it afterwards. What function is used depends on
 * user-input, hence can be known only at runtime.
 */

typedef int (*BinOp)(int, int);

int sum(int x, int y) {
	return x + y;
}

int product(int x, int y) {
	return x * y;
}

int main(int argc, char* argv[]) {
	BinOp op;

	if (argc == 2 && strcmp("product", argv[1]) == 0) {
		op = product;
	} else {
		op = sum;
	}

	printf("5 op 4 = %d\n", op(5, 4));

	return EXIT_SUCCESS;
}
