#include "module_b.h"

#include <stdio.h>

static void print_something(void) {
	puts("something");
}

void fun_b(void) {
	print_something();
}

