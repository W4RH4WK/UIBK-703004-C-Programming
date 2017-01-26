CFLAGS = -Wall -Wextra -pedantic -Werror -std=c99 -O2 \
         -Wno-unused-variable -Wno-unused-but-set-variable

.PHONY: all
all: variables

.PHONY: clean
clean:
	$(RM) variables

# `make` automatically defines variables to write rules in a more generic way.
# The variable `$@` will hold whatever the target should be (here `variables`)
# and the variable `$<` will hold the first prerequisite (here `variables.c`.
variables: variables.c
	$(CC) $(CFLAGS) -o $@ $<
