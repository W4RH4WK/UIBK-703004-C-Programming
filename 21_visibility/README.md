# Linker Visibility

The visibility of a function (or global variable) can be restricted the
translation unit it is defined in. The `static` keyword is used for this, and
it is sometimes needed to avoid conflicts during linking. For instance, 2
object files cannot be linked if they contain the same *symbol*, a function
with the same name.

In the example code, both modules have a function called `print_something`.
They link without problems since the `print_something` function in each module
has restricted visibility. Try removing the `static` keyword.

It is a good idea to expose only functions which should be used by a different
module.
