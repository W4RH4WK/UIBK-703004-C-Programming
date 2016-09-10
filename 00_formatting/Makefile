CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99 -O2

# Since this is the first named target, it will be executed by default.
.PHONY: all
all: formatting

# Passing `-f` to `rm` prevents it from complaining about non-existing files.
# We can call `clean` anytime without encountering an error.
.PHONY: clean
clean:
	rm -f formatting

# Here we state that the file `formatting` depends on a file called
# `formatting.c` and that `formatting` can be created by calling our compiler
# (GCC) with set flags.
formatting: formatting.c
	gcc $(CFLAGS) -o formatting formatting.c
