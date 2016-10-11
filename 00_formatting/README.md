# Formatting

`formatting.c` illustrates my preferred source code formatting. This is just
for reference, you can stick to your own preferences as long as you respect
following rules:

- Keep your formatting consistent
- Lines should be shorter than 80 characters
- Remove trailing whitespace
- Have *one* newline at the end of a file
- Files must be UTF-8 encoded
- Use Unix style line endings (`\n`)

You could also use a formatting tool which does these things automatically for
you. Have a look at [`clang-format`].

If you choose to use tabs (as I do), only use them for indentation. Vertical
alignment should be done with spaces to keep the layout consistent across
different editor settings.

[`clang-format`]: <http://clang.llvm.org/docs/ClangFormat.html>

# Makefile

Since this is the first `Makefile` we encounter, I have made a lot of things
more explit than they need to be, we'll build upon (and shorten) this
`Makefile` along our journey. Please checkout the [official documentation].

`make` is an *extremely* versatile utility which is not only used for building
C projects. Making use of *implicit rules* and *automatic variants*, one can
automate complex setups with just a few lines of code.

[official documentation]: <https://www.gnu.org/software/make/manual/html_node/index.html>
