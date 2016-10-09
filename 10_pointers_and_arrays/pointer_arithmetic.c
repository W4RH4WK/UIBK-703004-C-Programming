#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* Again we start off by taking the address of a variable. */
	int var1 = 42;
	int* ptr1 = &var1;

	/* The type of a pointer tells us what it is pointing to, but there is no
	 * guarantee that the underlying object is really of this type.
	 *
	 * In fact, there is not even a guarantee that th pointer points to a sane
	 * location. Here we set it to an arbitrary value.
	 */
	int* points_somewhere = (int*) 0x1234;

	/* Even though this is dangerous, it can be quite useful. But we as a
	 * programmer have to provide semantics where the language fails to.
	 *
	 * We can use a *void pointer* to drop that type information which may not
	 * make sens in all cases. Note that we can directly assign it without a
	 * cast.
	 */
	void* ptr2 = &var1;

	/* To illustrate this concept, take a look at the `printf` function, it has
	 * a formatter which prints pointers, but `printf` does not know (or care)
	 * where this pointer points to. Hence it takes a void pointer.
	 */
	printf("var1 with value %d is located at %p\n", var1, (void*) ptr1);

	/* In C one can do basic math with pointers, we can increment / decrement
	 * them as well as add / subtract them.
	 */
	printf("First ptr1 points to: %p\n", (void*) ptr1++);
	printf("Now it points to:     %p\n", (void*) ptr1);

	/* Looking at the previous output you'll notice that the value of `ptr1`
	 * has not been increased by 1, but by `sizeof(int)`. This is because we
	 * incremented a pointer to `int`.
	 *
	 * Following that logic we cannot increment (or decrement) a void pointer
	 * since `sizeof(void)` is not defined.
	 *
	 * Lets look at how a pointer to pointer behaves.
	 */
	int** ptr3 = &ptr1;
	printf("First ptr3 points to: %p\n", (void*) ptr3++);
	printf("Now it points to:     %p\n", (void*) ptr3);

	/* It is incremented by `sizeof(int*)` which may very well differ from
	 * `sizeof(int)`. */

	return EXIT_SUCCESS;

}
