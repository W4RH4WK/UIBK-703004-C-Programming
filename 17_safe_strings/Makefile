CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99 -O2

.PHONY: all
all: main

.PHONY: clean
clean:
	$(RM) main main.o sstring.o

main: main.o sstring.o

main.o: main.c sstring.h
sstring.o: sstring.c sstring.h
