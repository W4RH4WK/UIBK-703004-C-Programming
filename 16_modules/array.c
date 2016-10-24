/* First we include the module's header since it contains all declarations. */
#include "array.h"

#include <stdio.h>
#include <stdlib.h>

/* All left to do is to define what has already been declared. */

struct Array {
	int* data;
	int size;
};

Array* Array_create(int size) {
	if (size <= 0) {
		return NULL;
	}

	Array* array = malloc(sizeof(Array));
	if (array == NULL) {
		return NULL;
	}

	array->data = malloc(size * sizeof(int));
	if (array->data == NULL) {
		free(array);
		return NULL;
	}

	array->size = size;
	return array;
}

void Array_destroy(Array* this) {
	free(this->data);
	free(this);
}

int Array_size(const Array* this) {
	return this->size;
}

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
