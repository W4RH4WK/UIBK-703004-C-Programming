CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99 -O2

.PHONY: all
all: main

.PHONY: clean
clean:
	$(RM) main main.o array.o

# Strictly speaking following line will suffice. It tells `make` that the
# resulting binary needs a `main.o` and `array.o`. `make` knows how to generate
# these from their corresponding source files and will do that for us.
main: main.o array.o

# In fact, make now only knows that there is a dependency between `main`,
# `main.o` and `array.o`. But `main.o` actually depends on on `array.h`, as
# does `array.o`. While it is not necessary to provide following lines for the
# build process. It is needed for `make` to correctly know what has to be
# rebuilt if we change the source code.
#
# For example, if we modify the header `array.h` in any way, both modules
# (`main.o` and `array.o`) have to be rebuilt. Because they are out-of-date,
# because we modified the header they depend on.
main.o: main.c array.h
array.o: array.c array.h
