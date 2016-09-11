# Introduction to C Programming 2016

This repository is intended for group number 4 and is not essential for
completing this course. All files provided are simply here to support your
learning experience.

This stuff may not always be in line with the lecture, discretion is advised.

## What you should know by now

### Bash / Commandline

- Basics: `echo` / `ls` / `cd` / `touch` / `mkdir` / `cp` / `mv` / `rm` / `pwd`
  / `cat` / `less`
- Filesystem structure
- Getting help: `apropos` / `man` / `info`
- Finding files: `find` / `grep`
- Permissions: `chmod` / `chown`
- Archives: `tar` / `zip` / `unzip`
- Environment variables / `export` / `unset`
- Executing binaries / `$PATH`
- Hidden files
- Exit code of a command (0 typically indicates success)

### Compiler

- What is the purpose of a compiler
- Typical stages of a compiler
- Calling `gcc` with additional flags

### Makefile

- Defining and using variables
- Defining and invoking rules
- Why `.PHONY` is needed
- What target is build by default
- How to build a specific target
- Dependencies (*prerequisites*) of a target
- Purpose of the targets `all` and `clean`
- Forcing a rebuild of a target by passing `-B`
- Predefined variables like `$(CC)` and `$(RM)`

### C Programming

- `Hello World` example

## References

- [This Repo](https://git.io/viBjr)
- [Learning the Shell](http://linuxcommand.org/lc3_learning_the_shell.php)
- [`make` Documentation](https://www.gnu.org/software/make/manual/html_node/index.html)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Clang Format Documentation](http://clang.llvm.org/docs/ClangFormat.html)
