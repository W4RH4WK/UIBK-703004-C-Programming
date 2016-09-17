#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* # Integer operations */
	{
		int a = 42;
		int b = 23;

		printf("- %d    = %d\n", a, - a);
		printf("%d + %d = %3d\n", a, b, a + b);
		printf("%d - %d = %3d\n", a, b, a - b);
		printf("%d * %d = %3d\n", a, b, a * b);
		printf("%d / %d = %3d    (integer division)\n", a, b, a / b);
		printf("%d %% %d = %3d    (modulo)\n\n", a, b, a % b);
	}

	/* # Floating point operations */
	{
		double a = 2e3;
		double b = -3e-2;

		printf("- %g       = %g\n", a, - a);
		printf("%g + %g = %g\n", a, b, a + b);
		printf("%g - %g = %g\n", a, b, a - b);
		printf("%g * %g = %g\n", a, b, a * b);
		printf("%g / %g = %g\n\n", a, b, a / b);
	}

	/* # Bitwise operations */
	{
		int a = 0xcf; /* = 0011 1111 */
		int b = 0xfc; /* = 1111 1100 */

		printf("neg 0x%08x            = 0x%08x\n", a, ~ a);
		printf("lshift 4 0x%08x       = 0x%08x\n", a, a << 4);
		printf("rshift 4 0x%08x       = 0x%08x\n", a, a >> 4);
		printf("0x%08x and 0x%08x = 0x%08x\n", a, b, a & b);
		printf("0x%08x or  0x%08x = 0x%08x\n", a, b, a | b);
		printf("0x%08x xor 0x%08x = 0x%08x\n\n", a, b, a ^ b);
	}

	/* # Boolean operations */
	{
		int a = true;
		int b = false;

		printf("not %d   = %d\n", a, ! a);
		printf("%d and %d = %d\n", a, b, a && b);
		printf("%d or  %d = %d\n\n", a, b, a || b);
	}

	/* # Comparison operations (integer) */
	{
		int a = 42;
		int b = 23;

		printf("%d == %d = %d\n", a, b, a == b);
		printf("%d != %d = %d\n", a, b, a != b);
		printf("%d <  %d = %d\n", a, b, a < b);
		printf("%d <= %d = %d\n", a, b, a <= b);
		printf("%d >  %d = %d\n", a, b, a > b);
		printf("%d >= %d = %d\n\n", a, b, a >= b);

	}

	/* # Comparison operators (floating point)
	 *
	 * Similar for float, but do not use `==` or `!=` since you are not dealing
	 * with exact values most of the time! State your precision (epsilon) and
	 * compare a threshold. Observe following examples.
	 */
	{
		double a = 0.3 - 0.1;

		/* do not do it like this */
		if (a == 0.2) {
			puts("0.3 - 0.1 == 0.2");
		} else {
			puts("0.3 - 0.1 != 0.2");
		}

		/* do it like this instead */
		const double EPSILON = 1e-3;
		if (0.2 - EPSILON < a && a < 0.2 + EPSILON) {
			puts("0.3 - 0.1 == ~ 0.2");
		} else {
			puts("0.3 - 0.1 != ~ 0.2");
		}

		puts("");
	}

	/* # Compound assignment
	 *
	 * Modifying a variable by just adding / subtracting / ... another value is
	 * so common that there is a shorthand available in C. These go by the name
	 * of compound assignment and are available for all basic operations.
	 */
	{
		int a = 2;

		/* following two statements are equivalent */
		a = a + 3;
		a += 3;
	}

	/* # Increment / decrement operators
	 *
	 * Adding and subtracting `1` is such a common operation that there is even
	 * a shorter form.
	 */
	{
		int a = 3;
		a++;
		a--;
		++a;
		--a;

		/* Even better, they can be used inside a expression. Here `a` is
		 * incremented before it is used.
		 */
		printf("++a = %d\n", ++a);
		printf("a   = %d\n\n", a);

		/* Here `a` is incremented after it is used. */
		printf("a++ = %d\n", a++);
		printf("a   = %d\n\n", a);
	}

	/* # Short circuit evaluation
	 *
	 * When using boolean operations like `&&` and `||` the evaluation is
	 * terminated as soon as the result is known. This concept is known as
	 * short circuit evaluation.
	 *
	 * In this example `b` is initialized with `true || ++a`. Since `true` ORed
	 * with anything will always give try, the evaluation terminates
	 * immediately, not even looking at `++a`. Hence `a` is still 2 after `b`'s
	 * initialization.
	 */
	{
		int a = 2; bool b = true || ++a; printf("a = %d\n", a);
	}

	/* # Sequence points
	 *
	 * This is an exercise for the interested reader, try to compile following
	 * block. You should encounter an error about possible undefined behaviour.
	 * Lookup the phrase *sequence point* and figure out why.
	 */
	/*
	{
		int a = 3;
		a = ++a;
	}
	*/

	return EXIT_SUCCESS;
}
