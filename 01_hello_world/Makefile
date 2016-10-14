# Makefile variables can be set directly from the commandline, setting
# variables inside the Makefile will then be skipped. Try this:
#
#     $ make CFLAGS=-O0
#
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99 -O2

.PHONY: all
all: hello

# `make` already defines `rm -f` for us, we can use this definition to be more
# portable and easily change this in the future if we need to.
.PHONY: clean
clean:
	$(RM) hello

# Similar to `$(RM)`, `make` automatically defines a variable for the C
# compiler. Similar to the way we setup `$(CFLAGS)` one can override the
# default value when calling make
#
#     $ make CC=my_awesome_c_compiler
#
hello: hello.c
	$(CC) $(CFLAGS) -o hello hello.c
