# Compile Phases

## Source Code (Input)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("Hello World\n");
	return EXIT_SUCCESS;
}
```

## After C-Preprocessor (cpp)

    $ gcc -E -o hello.e hello.c

Alternatively the preprocessor can be run via `cpp`.

```c

[lines omitted for brevity]

extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 898 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 950 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
# 955 "/usr/include/stdlib.h" 2 3 4
# 967 "/usr/include/stdlib.h" 3 4

# 3 "hello.c" 2


# 4 "hello.c"
int main(void) {
 printf("Hello World\n");
 return
# 6 "hello.c" 3 4
       0
# 6 "hello.c"
                   ;
}
```

## After Actual Compilation

    $ gcc -S -o hello.s hello.c

Output is referred to as assembly code.

```gas
	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"Hello World"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
```

## After Assembling

    $ gcc -c -o hello.o hello.c

Output is referred to as object code. It is a binary file, but not yet
executable. View it using `hexdump` or via `objdump`.

    $ objdump -D hello.o

```
hello.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	bf 00 00 00 00       	mov    $0x0,%edi
   9:	e8 00 00 00 00       	callq  e <main+0xe>
   e:	b8 00 00 00 00       	mov    $0x0,%eax
  13:	5d                   	pop    %rbp
  14:	c3                   	retq

Disassembly of section .rodata:

[lines omitted for brevity]

```

## After Linking

    $ gcc -o hello hello.c

Final executable. Can also be investigated with `objdump`.

    $ ./hello
    Hello World
