#include <limits.h>     /* integer tyep limits */
#include <stdbool.h>    /* defines `bool`, `true`, `false */
#include <stdio.h>
#include <stdlib.h>

/* fixed size integers, like uint64_t or uint_least32_t */
#include <stdint.h>

/* floating point type limits, not needed when just using float or double */
#include <float.h>

int main(void) {

	/* # Your most important (integer) type: `char`
	 *
	 * `char` is your smallest integer type and 1 byte in size (C99 standard).
	 *
	 * It may be used for small values -128..127 (signed) or * 0..255
	 * (unsigned). It is typically encountered when dealing with binary data,
	 * since its size corresponds to one byte.
	 *
	 * Or when dealing with characters (ASCII symbols like letters and
	 * numbers), see:
	 *
	 *     $ man ascii
	 *
	 */
	char my_char = 0;
	char my_other_char = 'a'; /* same as = 97; */


	/* # Primitive integer types
	 *
	 * These types are your bread and butter when dealing with integers.
	 * Contrary to `char`, their sizes vary from architecture to architecture.
	 */
	short my_short = 1;
	int my_int = 2;
	long my_long = 3;
	long long my_long_long = 4;

	puts("size of integer types in bytes:");
	printf("\tshort:       %ld\n", sizeof(my_short));
	printf("\tint:         %ld\n", sizeof(my_int));
	printf("\tlong:        %ld\n", sizeof(my_long));
	printf("\tlong long:   %ld\n\n", sizeof(my_long_long));


	/* ## The `unsigned` keyword
	 *
	 * All integer types can be prefixed with the `unsigned` keyword. While
	 * their actual size does not change, `unsigned` states that values in this
	 * variable will always be interpreted as positive values.
	 *
	 * Signed integers range from -2^(N-1) to 2^(N-1) -1,
	 *
	 * unsigned integers range from 0 to 2^N -1,
	 *
	 * where N is the size of a given type in bits.
	 */
	unsigned long my_unsigned_long = 2;


	/* # Fixed size integers and limits
	 *
	 * While varying sized integers are helpful for portability, it is often
	 * better to know exactly how big a certain variables is --- hence what
	 * range of values it can hold --- no matter what architecture you are on.
	 *
	 * `stdint.h` provides these fixed sized types.
	 *
	 * `limits.h` provides limits for what values can go into which types.
	 */
	int64_t my_int64 = 2;

	printf("ULLONG_MAX = %llu\n\n", ULLONG_MAX);
	/*                    ^^^----- note the formatter for unsigned long long */


	/* # Floating point types
	 *
	 * Floating point types are signed, can hold very small (between 0 and 1)
	 * as well as extremely large numbers. The crux of it, not all values can
	 * be represented exactly. Most of the time you will hold only an
	 * approximation.
	 *
	 * `float.h` defines the limits for floating point types, but is not
	 * required in order to use `float` or `double`.
	 */
	float my_float = 3.14;
	double my_double = 6e-3;
	long double my_long_double = 12e-2;

	puts("size of floating point types in bytes:");
	printf("\tfloat:       %ld\n", sizeof(my_float));
	printf("\tdouble:      %ld\n", sizeof(my_double));
	printf("\tlong double: %ld\n\n", sizeof(my_long_double));


	/* # Boolean
	 *
	 * There are is no boolean type in C. Integers are used for boolean values,
	 * everything equal to 0 is considered `false`, everything not equal to
	 * zero is considered `true`.
	 *
	 * `stdbool.h` defines the type `bool` which just an alias for `int`, as
	 * well as values `true` (= 1) and `false` (= 0). Using these can make your
	 * code more readable but won't change any behaviour.
	 */
	bool my_bool = true;

	puts("size of boolean:");
	printf("\tbool:        %ld\n\n", sizeof(my_bool));

	int zero = 0;
	int one = 1;
	int minus_one = -1;

	if (zero)      puts(" 0 is true"); else puts(" 0 is false");
	if (one)       puts(" 1 is true"); else puts(" 1 is false");
	if (minus_one) puts("-1 is true"); else puts("-1 is false");

	/* # The `const` keyword
	 *
	 * You can define any variable as `const` meaning its value cannot be
	 * changed later on.
	 */
	const int my_const = 42;

	/* following statement will result in a compile-time error */
	/* my_const = 21; */

	/* # Scopes
	 *
	 * You can open a new scope whenever you need one. This can be helpful to
	 * group parts within a function together.
	 *
	 * Variables declared within it are only valid for that scope (and scopes
	 * within that scope). You may even give them the same name as a variable
	 * from the parent scope. This is called shadowing.
	 */
	{
		int another_variable = 2;

		/* lets shadow a variable */
		int my_const = 13;
		printf("my_const within another scope = %d\n", ++my_const);
	}

	/* `another_variable` is not available here */
	/* printf("another_variable = %d\n", another_variable); */
	printf("my_const outside is still = %d\n", my_const);

	return EXIT_SUCCESS;

}
