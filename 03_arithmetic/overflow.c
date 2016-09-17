#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* # Basic overflow issue
	 *
	 * Since variables have a certain size, only a certain range of values can
	 * be represented. When a calculation exceeds this range beyond its
	 * positive limit an *overflow* happens.
	 *
	 * Exceeding the range beyond its negative limit is results in an
	 * *underflow*.
	 */
	{
		int8_t a = INT8_MAX;
		printf("INT8_MAX     = %d\n", a);
		a = a + 1;
		printf("INT8_MAX + 1 = %d\t(this is undefined behaviour)\n\n", a);
	}

	/* You may see that the value is wrapped around and continues at its lower
	 * limit.
	 *
	 * ! But be aware !
	 *
	 * Integer overflow (and underflow) are only defined for unsigned types by
	 * the C standard. Since an signed integer overflow (and underflow) is
	 * undefined behaviour, anything may happen. You must prevent signed
	 * overflows (and underflows) from happening in your program.
	 */
	{
		uint8_t a = UINT8_MAX;
		printf("UINT8_MAX     = %d\n", a);
		a = a + 1;
		printf("UINT8_MAX + 1 = %d\t(this is defined behaviour)\n", a);
	}

	/* # Example checking for overflow / underflow
	 *
	 * In the example blow, assume you want to add the two variables `a` and
	 * `b`, but do not know whether the addition will cause an overflow.
	 * Following code will check before adding them whether an overflow (or
	 * underflow) would happen.
	 */
	{
		int a = 42;
		int b = 23;

		if (a > 0 && b > INT_MAX - a) {
			/* handle overflow */
		} else if (a < 0 && b < INT_MIN - a) {
			/* handle underflow */
		} else {
			/* save to add */
			a = a + b;
		}
	}

	return EXIT_SUCCESS;

}
