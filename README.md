# Introduction to C Programming 2016

This repository is intended for group number 4 and is not essential for
completing this course. All files provided are simply here to support your
learning experience.

This stuff may not always be in line with the lecture, discretion is advised.

## Don't Panic!

Soon or later you will run into problems, follow these bullets:

1. find problem
2. isolate problem
3. understand problem
4. fix problem
5. verify fix
6. rinse and repeat

### Getting Help

1. **from the commandline:** use the tools `apropos` and `man` to get
   information about general commands, system calls, config files, etc.

2. **read the fucking manual:** if you run into problems consider reading the
   manual or provided documentation before moving on.

3. **Google is your friend:** Google can help you out even when the
   documentation can not. People might have run into the same problem as you.

4. **IRC / forum / mailing list / bug tracker / email:** neither the manual nor
   Google helped you solving the problem? Take a step back and revisit the
   facts and what you have already discovered in relation to the problem. Now
   you are pardoned to get in contact with somebody. A recommended approach is
   asking in the related IRC channel or forum.

5. **provide information:** Most importantly, provide the necessary
   information. Add log files and similar info dumps to your question,
   otherwise people won't be able to help you. Be precise and state whether you
   talk about facts or presumptions.

## What you should know by now

### Linux / Shell

Everything taught in the *Brückenkurs* (see references). The more you know
about the system you are using, the better. Getting the big picture as well as
its details is the key to understanding the interaction of components (kernel,
operating system, programs, shell, networks, ...).

### Technical Stuff

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
- [Brückenkurs (internal)](https://iis.uibk.ac.at/courses/2015w/703000/start)
- [Learning the Shell](http://linuxcommand.org/lc3_learning_the_shell.php)
- [17 Unix Rules](https://en.wikipedia.org/wiki/Unix_philosophy#Eric_Raymond.E2.80.99s_17_Unix_Rules)
- [`make` Documentation](https://www.gnu.org/software/make/manual/html_node/index.html)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Clang Format Documentation](http://clang.llvm.org/docs/ClangFormat.html)
