# Safe Strings

A very basic module for *safer* strings is provided without comments. Try to
figure out what the given functions do and extend the module with new ones
following the same patterns.

Take a look at what is declared in your system's `string.h` and reimplement
them for safe strings.

## Additional 0-Terminator

This module stores a 0-terminated string together with its size. While it
wouldn't be necessary to terminate the string since the size is known, it is
still done for good measure. Even though it makes the module's logic a bit more
complicated, it allows you to hand the `this->data` pointer over to the user,
for printing purposes or the like.
