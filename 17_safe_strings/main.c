#include "sstring.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	String* s = String_from_c_str("Hello World");

	String_print(s);

	printf("  %ld  %ld\n", String_size(s), String_length(s));

	String_destroy(s);

	return EXIT_SUCCESS;
}
