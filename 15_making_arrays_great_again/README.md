# Making Arrays Great Again

We have now talked about pointers, arrays, structs and dynamic memory
management. This example will bring these concepts together and show how they
can be used as a whole.

The idea is to build a *wrapper* around arrays which provides more safety. It
should prevent you from accessing the array out-of-bounds and provide some
convenience functions.

The approach will be quite *object-oriented* and is more a proof-of-concept
than a real-world solution. Of course using the wrapper yield a performance
overhead, hence doing things directly will be faster. In practise, as a C
programmer you are expected to do memory management correctly without such
helpers.

We'll reuse this example later on when we talk about modules, multiple source
files and how modules are supposed to go together. Another common example is
building a simple data-structure like a linked-list and this will be done at a
later point in time, for now I'd like to keep it simple without talking about
data-structures.

## Exercise

After you have read and understood this code, you can try and enhance this
wrapper by adding functions for dynamically growing / shrinking the array.

Furthermore look into the concept of `assert`.

## Alternatives

There are various different ways to achieve something like this, here I'll
present a few alternative implementations for the parts in `managed_array.c`.

### Typedef the Array Pointer

Sometimes you may see a `typedef` on the pointer to something like this.

```c
typedef struct Array* Array
```

Personally I don't like this. While its good practice to hide the
implementation details of a module / construct, the user should still know
whether he is handling a pointer or a whole struct.

### Initializer

In our example we built a *constructor* which allocates the management struct
dynamically (on the heap). This may not be favorable all the time, maybe the
user wants to have this on the stack. Therefore one could split the constructor
in two functions.

```c
Array* Array_create(int size) {
	if (size <= 0) {
		return NULL;
	}

	Array* array = malloc(sizeof(Array));
	if (array == NULL) {
		return NULL;
	}

	return Array_init(array, size);
}

Array* Array_init(Array* this, int size) {
	this->data = malloc(size * sizeof(int));
	if (this->data == NULL) {
		return NULL;
	}

	this->size = size;

	return this;
}

void Array_destroy(Array* this) {
	Array_uninit(this);
	free(this);
}

void Array_uninit(Array* this) {
	free(this->data);
}

/* ... */

int main(void) {

	/* this time on the stack */
	Array array;
	if (Array_init(&array, 10) == NULL) {
		return EXIT_FAILURE;
	}

	/* do stuff */

	Array_uninit(&array);

	return EXIT_SUCCESS;
}
```

### More Advanced Query

In the example, the `Array_get` returns either an element or a default value if
elements out-of-bound are accessed. Sometimes you do not want to silently
swallow such an error. You could adapt the function to always return a status
value, and write the requested data to a specific location (pointer).

```c
/* Access the array, returning 0 on success, -1 if the array pointer is NULL,
 * -2 if the index is out-of-bound or -3 if the destination is NULL. */
int Array_get(const Array* this, int index, int* dst) {
	if (this == NULL) {
		return -1;
	}

	if (index < 0 || index >= this->size) {
		return -2;
	}

	if (dst == NULL) {
		return -3;
	}

	*dst = this->data[index];

	return 0;
}
```
