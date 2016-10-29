# `argc` and `argv`

Similar to the way functions take parameters, your program can also take
parameters from the user. These parameters, passed via the command-line are
forwarded to `main`.

```c
int main(int argc, char* argv[]) {
	/* ... */
```

The argument count `argc`, tells you how many entries there are in the argument
vector `argv`. As can be inferred from the type, each entry is a string.

The first entry usually (but does not have to) corresponds to the program name.
The example provided prints all provided arguments with their position. By
default your shell splits arguments by spaces. This can be avoided by using
quotes or escaping a space. Try calling the example program with different
arguments, quotes and escaped spaces:

    $ ./main
    $ ./main hello world
    $ ./main "hello cruel" world
    $ ./main hello\ beautiful world

This allows you to get user input in a non-interactive way, which is often
simpler than dealing with `please enter...` prompts. We'll probably use this
mechanism in future sections.

## Exercise

Build a basic Fibonacci calculator which reads the target number `N` from the
first argument (`argv[1]`). Print usage information if the user provides too
few or too many arguments.

Note that the argument is provided as string and needs to be converted to an
integer. Take a look at the function `atoi`.
