#include "module_a.h"

#include <stdio.h>

static void print_something(void) {
	puts("something");
}

void fun_a(void) {
	print_something();
}
