CFLAGS = -Wall -Wextra -Wpedantic -Werror -Wno-unused-variable -std=c99 -O2

.PHONY: all
all: arithmetic overflow

.PHONY: clean
clean:
	$(RM) arithmetic overflow

# Now it gets even more generic. `%` is treated as a wildcard similar to `*` on
# the shell. Following rule tells `make` that if a file is needed and there is
# a file with same name + `.c` available use the C compiler to generate that
# needed file.
#
# Here the `all` rule needs `arithmetic` and `overflow, since the files
# `arithmetic.c` and `overflow.c` are present `make`, by this rule, knows that
# `arithmetic.c` can be used to get `arithmetic` as well as that `overflow` can
# be generated from `overflow.c`.
#
# This is also why automatic variables like `$@` and `$<` are important. These
# variables will be set accordingly.
%: %.c
	$(CC) $(CFLAGS) -o $@ $<
