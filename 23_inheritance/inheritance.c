#include <stdio.h>
#include <stdlib.h>

/* This example illustrates how inheritance can be implemented in C. The base
 * class `Animal` only contains a single integer, the two derived classes `Cat`
 * and `Bird` attach an additional integer.
 *
 * The function `Animal_print` can be used with instantiations of `Cat` and
 * `Bird`, but the instance needs to be casted. From here on type-safety is
 * gone.
 *
 *         .----------.
 *         |  Animal  |
 *         |__________|
 *              A
 *              |
 *         .----+----.
 *         |         |
 *         |         |
 *     .-------.  .--------.
 *     |  Cat  |  |  Bird  |
 *     |_______|  |________|
 */

struct Animal {
	int legs;
};
typedef struct Animal Animal;

struct Cat {
	struct Animal base;
	int whiskers;
};
typedef struct Cat Cat;

struct Bird {
	struct Animal base;
	int feathers;
};
typedef struct Bird Bird;

void Animal_print(const Animal* this) {
	printf("Animal has %d legs\n", this->legs);
}

int main(void) {
	Cat cat = { .base = { .legs = 4 }, .whiskers = 8 };
	Bird bird = { .base = { .legs = 2 }, .feathers = 128 };

	/* Casting to Animal is safe since the `Animal` part of `cat` / `bird` is
	 * located at the beginning without any padding. This is known as an
	 * *upcast*. Afterwards we no longer know whether we point to a `Cat` or a
	 * `Bird`. Hence we cannot *downcast* safely.
	 */
	Animal_print((Animal*) &cat);
	Animal_print((Animal*) &bird);

	/* With this setup you can access an instance's base class via `base`.
	 * There is also a compiler extension which allows you to flatten the
	 * class (see `-fms-extensions`).
	 */
	printf("Cat has %d legs and %d whiskers\n", cat.base.legs, cat.whiskers);

	return EXIT_SUCCESS;
}
