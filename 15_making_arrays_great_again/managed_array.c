#include <stdio.h>
#include <stdlib.h>

#define EXAMPLE_SIZE 42

/* This will be our *object* holding relevant data for the management. The of
 * this construct should handle it as a block box and use only provided
 * functions with it. */
struct Array {
	int* data;
	int size;
};

/* Again we use a typedef for convenience. */
typedef struct Array Array;

/* The first function, our *constructor*, will allocate one such object +
 * memory for the data according to the given number of elements. */
Array* Array_create(int size) {
	/* Size should be a positive value, if it's not we return NULL to indicate
	 * failure. */
	if (size <= 0) {
		return NULL;
	}

	/* Now lets allocate the management part, of course we have to check
	 * `malloc`'s return value. */
	Array* array = malloc(sizeof(Array));
	if (array == NULL) {
		return NULL;
	}

	/* Next we need memory for the underlying data. */
	array->data = malloc(size * sizeof(int));
	if (array->data == NULL) {
		/* Here we encounter an error where we have already allocated memory
		 * for `array`, but could not get memory for `array->data`. Before we
		 * return with NULL, we have to free the memory for `array`. */
		free(array);
		return NULL;
	}

	/* Lastly we store `size` inside the management object and return it to the
	 * user. */
	array->size = size;
	return array;
}

/* Of course we also needed a *destructor* which frees the allocated memory for
 * us. */
void Array_destroy(Array* this) {
	/* First the memory for the data will be freed. */
	free(this->data);

	/* Then the memory for the management object. Not the other way round,
	 * since we are not allowed to access `this` anymore after it has been
	 * freed. */
	free(this);
}

/* Further we provide a *getter* for the size, so the user can query it after
 * construction.
 *
 * Again we don't want the user to access the struct members
 * directly. This may seem a bit overkill, but given this setup, we can alter
 * the struct members in any way without breaking any other code of the user,
 * as long as all functions are adapted accordingly. */
int Array_size(const Array* this) {
	return this->size;
}

/* The next two functions are straight forward, they will either set or return
 * an element in the array. If we access out of bound, a default value is
 * returned. */
int Array_get(const Array* this, int index) {
	if (0 < index && index <= this->size) {
		return this->data[index];
	} else {
		return 0;
	}
}

void Array_set(Array* this, int index, int value) {
	if (0 < index && index <= this->size) {
		this->data[index] = value;
	}
}

/* Additionally we add a function for printing the whole array neatly. */
void Array_print(const Array* this) {
	printf("[");
	for (int i = 0; i < this->size; ++i) {
		printf("%3d", i);
		if (i != this->size - 1) {
			printf(",");
		}
	}
	printf("]");
}

int main(void) {

	/* create one such array */
	Array* a = Array_create(EXAMPLE_SIZE);

	/* check for errors */
	if (a == NULL) {
		fprintf(stderr, "Could not allocate Array of size %d\n", EXAMPLE_SIZE);
		return EXIT_FAILURE;
	}

	/* and fill them */
	for (int i = 0; i < Array_size(a); ++i) {
		Array_set(a, i, i * 10);
	}

	printf("a: ");
	Array_print(a);
	printf("\n\n");

	/* Out-of-bound access will be prevented by the wrapper. */
	Array_set(a, EXAMPLE_SIZE + 25, 25);

	printf("out-of-bound: %3d\n", Array_get(a, EXAMPLE_SIZE + 25));

	/* do not forget to clean up properly */
	Array_destroy(a);

	return EXIT_SUCCESS;
}
