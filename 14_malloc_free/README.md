# Dynamic Memory Management

Up until now the amount of memory needed for our data was known at
compile-time. And while we did not bother with user interaction yet, one can
imagine that a *real-world program* usually requires different amounts of
memory depending on user-input.

The way this works is by asking the operating system nicely whether there is
some free memory available. For this we use the `malloc` function.

## `malloc`

`malloc` is declared in `stdlib.h` and has following *signature*.

```c
void* malloc(size_t size);
```

`size_t` is just a *typedef* (hinted by the `_t` suffix) for an unsigned
integer (or long, or long long). Try not to think about it too much for now.

So in other words, the `malloc` functions takes and unsigned integer value (the
size of memory required in bytes) and returns a void-pointer (`void*`);

## `free`

We also have the option to tell the operating system, that the previously
requested memory is no longer needed. This happens via the `free` function and
its signature is rather simple.

```c
void free(void* ptr);
```

`free` must be invoked only with pointers received by a previous *allocation*
(call to `malloc`). And each of these pointers must only be *freed* once. See
the related man-page for more details. You *should* free all previously
allocated memory before your program terminates (no matter if it was successful
or not).

## Example

In this example an array of integers will be *allocated dynamically* at
runtime. The array will be filled using a for-loop, afterwards it's content
will be printed and the array will be *deallocated* aka freed just before our
program is finished.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* `malloc` takes the size in bytes as arugment, therefore we have to
	 * multiply the size of one integer with the number of elements we want (here
	 * 42). A void-pointer is returned which will be handled as
	 * pointer-to-integer from here on.
	 */
	int* my_array = malloc(42 * sizeof(int));

	/* From here on it behaves similar to an array, we just need to keep in mind
	 * how many elements there are.
	 */

	for (int i = 0; i < 42; ++i) {
		my_array[i] = i * 10;
	}

	for (int i = 0; i < 42; ++i) {
		printf("%3d ", my_array[i]);
		if (i % 10 == 9) {
			printf("\n");
		}
	}

	printf("\n");

	/* All done, we can free the allocated memory now. */

	free(my_array);

	return EXIT_SUCCESS;
}
```

## `malloc` and friends

There are also two other functions, similar to `malloc`, `calloc` and `realloc`
take a peek at the man-page and figure out the differences and where they can
be useful. Maybe we'll see them in a later example.

## Manual Memory Management

In plain C dynamic memory management is done manually. The programmer has to
ensure that everything fits together, memory is allocated and deallocated when
needed / no longer needed. And that we never access data outside the allocated
region.

Other programming languages, like Python for instance, do not require the
programmer to do all that by himself. Instead they simply allocate memory when
needed and have a special runtime component, the *garbage collector* which
tracks allocated segments and frees them if they are no longer needed.

Note that this convenience does not come for free, garbage collection yields a
performance overhead (in most cases).
