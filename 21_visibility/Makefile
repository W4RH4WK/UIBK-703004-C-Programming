CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99 -O2

.PHONY: all
all: main

.PHONY: clean
clean:
	$(RM) main main.o module_a.o module_b.o

main: main.o module_a.o module_b.o

main.o: main.c module_a.h module_b.h
module_a.o: module_a.c module_a.h
module_b.o: module_b.c module_b.h
