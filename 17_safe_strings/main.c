#include "sstring.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	String* s = String_from_c_str("Hello World\n");

	String_print(s);

	String_destroy(s);

	return EXIT_SUCCESS;
}
