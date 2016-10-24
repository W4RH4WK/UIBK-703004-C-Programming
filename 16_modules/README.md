# Modules

Using the example from the previous section, we move all the parts relevant to
the *managed array* to its own module. A module consists of a header and a
source file. The header files contains declarations and communicates the
interface of a module. It should not contain implementation details, these go
into the source file.

The source file containing the main function will use the module via its
header. Each module, and the file containing the main function, will be
compiled separately into an object file (translation units). They will be
linked together afterwards.

Since this is a common procedure `make` has implicit rules for creating object
files. We only need to state the dependencies of each file.

## Dependencies

Modules can depend on other modules and since we produce object files, we need
to know which modules to (re)build when we alter a portion of the code. This is
where using `make` pays off. For starters, we state the dependencies of all
modules (including the main part) in the Makefile. `make` will build whatever
is needed, and rebuild stuff if it is out-of-date. This happens by comparing
timestamps (target file vs. dependencies).

Going a step further, the compiler can tell us which other files a given source
file depends on. It even generates a `make`-compatible output for us. Try this:

    $ gcc -MM array.c
    $ gcc -MM main.c

This output can be saved in a file corresponding to the module (`main.d` or
`array.d`) and included in the Makefile, but this goes beyond the scope of this
example and is left for the reader to figure out.
