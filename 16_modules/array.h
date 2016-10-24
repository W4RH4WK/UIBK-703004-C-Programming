/* This is a header-guard why exactly it is needed is left as an exercise to
 * the reader. You may sometimes see `#pragma once` which can be faster but is
 * less portable. */
#ifndef __ARRAY_H_
#define __ARRAY_H_

/* We only declare the struct, the user won't be able to directly create such a
 * struct since its details are not known beyond this translation unit. */
struct Array;

/* And again we provide a typedef */
typedef struct Array Array;

/* Next we declare all the functions made available by the module. Usually
 * documentation is added for each function, this is omitted here since you
 * should already be familiar with their purpose. */
Array* Array_create(int size);

void Array_destroy(Array* this);

int Array_size(const Array* this);

int Array_get(const Array* this, int index);

void Array_set(Array* this, int index, int value);

void Array_print(const Array* this);

#endif
