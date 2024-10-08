# All-in-C

An assortment of different types of scripts, programs, and projects
all written in C using the C standard library only when reasonably necessary
or for use in comparison sake.

From the C standard library, the utilities I will allow myself to use may include
but are not limited to <stdio.h> for convenient standard input/output
and **some** general utilities provided in <stdlib.h> involving
random numbers and memory management.

## Setup/Build \*IMPORTANT\*

```
Usage: make
       make clean
```

I have provided a Makefile that should make it really simple to build the binary.
I would strongly recommend to quickly read it through since it is quite short
and then alter it if necessary. By default, the only prerequisites needed are
GCC and GNU Make.

### Expected build output
```
$ make
mkdir obj
gcc -o obj/commandLineArguments.o -c src/commandLineArguments.c
gcc -o obj/fileAccess.o -c src/fileAccess.c
gcc -o obj/runCommand.o -c src/runCommand.c
gcc -o obj/timer.o -c src/timer.c
mkdir bin
gcc -o bin/all-in-c all-in-c.c all-in-c.h obj/commandLineArguments.o obj/fileAccess.o obj/runCommand.o obj/timer.o
```

### Delete object and binary directories and files
```
$ make clean
rm -r ./obj ./bin
```

## All-in-C \*Parent caller of all other scripts\*

```
Usage: all-in-c [KNOWN_SCRIPT] ...
```

**Source:** *all-in-c.c* and *all-in-c.h*

Executes the script specified in the first command line argument.

```
$ ./bin/all-in-c --commandLineArguments "Hello World!"
Running command-line-arguments ...

Argument [0]: command-line-arguments
Argument [1]: Hello World!
```

## Command-line Arguments

```
Usage: --command-line-arguments ...
```

**Source:** *src/commandLineArguments.c*

Prints out each command-line argument on a new line (including executed command).

```
$ ./bin/all-in-c --command-line-arguments -g 42 --file "bob.txt"
Running command-line-arguments ...

Argument [0]: command-line-arguments
Argument [1]: -g
Argument [2]: 42
Argument [3]: --file
Argument [4]: bob.txt
```

## File Access

```
Usage: --file-access -r [FILE]
                     -w [FILE] [STRING]
                     -a [FILE] [STRING]
```

**Source:** *src/fileAccess.c*

Read, write, and append files.

### Write
```
$ ./bin/all-in-c --file-access -w bob.txt Hello
Running file-access ...
```

### Append
```
$ ./bin/all-in-c --file-access -a bob.txt " World!"$'\n'
Running file-access ...
```

### Read
```
$ ./bin/all-in-c --file-access -r bob.txt
Running file-access ...

Hello World!
```

## Timer

```
Usage: --timer [COMMAND]
```

**Source:** *src/timer.c*

Times duration of a command in seconds.

```
$ ./bin/all-in-c --timer "./bin/all-in-c --file-access -r bob.txt"
Running timer ...

Running file-access ...

Hello World!

(0.000108s)
```

## Run Command

```
Usage: --run-command [COMMAND]
```

**Source:** *src/runCommand.c*

Executes command given in command line argument.

```
$ ./bin/all-in-c --run-command './bin/all-in-c --timer "./bin/all-in-c --file-access -r bob.txt"'
Running run-command ...

Running timer ...

Running file-access ...

Hello World!

(0.000120s)
```

## File Operations

```
Usage: --file-operations --rename [FILE] [NEW_NAME]
                         --remove [FILE]
                         --tmpfile [STRING]
```

**Source:** *src/fileOperations.c*

Remove or rename files or create a temp file with data

### Rename
```
$ ls | grep ^.*\.txt
bob.txt
$ ./bin/all-in-c --file-operations --rename bob.txt bobby.txt
Running file-operations ...

$ ls | grep ^.*\.txt
bobby.txt
```

### Remove
```
$ ls | grep ^.*\.txt
bobby.txt
$ ./bin/all-in-c --file-operations --remove bobby.txt
Running file-operations ...

$ ls | grep ^.*\.txt
```

### Temp File
```
$ ./bin/all-in-c --file-operations --tmpfile "Hello World!"
Running file-operations ...

Data contained in temp file: Hello World!
```

## POSIX System Calls

```
Usage: --syscall [STRING]
```

**Source:** *src/posixSyscalls.c*

Invokes a variety of pre-implemented system calls.
**Only works on unix-based systems.**

### Write System Call
```
$ ./bin/all-in-c --syscall "Hello World!"
Running syscall ...

Hello World!
```

## Strings

```
Usage: --strings [FUNCTION] [STRING]
```

**Source:** *src/strings.c*

Own implementation of some functions in the <string.h> C standard library header.

### Avaliable Functions

```
--islower
--isupper
--isdigit
--isalpha
--isalnum
--isspace
--ispunct
--isprint
```

### Example

```
$ ./bin/all-in-c --strings --isalnum bob123
Running strings ...

TRUE
```

```
$ ./bin/all-in-c --strings --isalnum @bob123
Running strings ...

FALSE
```

## Binary Tree

```
Usage: --binary-tree
```

**Source:** *src/binaryTree.c*

Example of dynamic memory allocation in C with binary trees.
Uses the malloc function in the C standard library that allocates
memory space for each node in the binary tree, and the returns a pointer
to that newly allocated memory space.

There is no user input for this one at all, or any fancy way of printing
out the binary tree. This is just a simple demonstration of allocating
memory, so all it does is allocate, use, print out the memory contents,
and then free said memory.

```
$ ./bin/all-in-c --binary-tree
Running binary-tree ...

HEAD
     ( 5)
    /    \
( 3)      ( 1)

LEFT BRANCH
     ( 3)
    /    \
(12)      (65)

LEFT LEFT BRANCH
     (12)
    /    \
(88)      ( 0)

LEFT RIGHT BRANCH
     (65)
    /    \
( 0)      ( 0)

RIGHT BRANCH
     ( 1)
    /    \
( 0)      ( 0)

HEAD AFTER LEFT DELETE
     ( 5)
    /    \
( 0)      ( 1)

HEAD AFTER RIGHT DELETE
     ( 5)
    /    \
( 0)      ( 0)

```