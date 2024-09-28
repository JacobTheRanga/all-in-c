# All-in-C

An assortment of different types of scripts, programs, and projects all written in C using the C standard library only when reasonably necessary or for use in comparison sake and the occasional standard framework for purposes such as graphics rendering.

From the C standard library, the utilities I will allow myself to use may include but are not limited to <stdio.h> for convenient standard input/output and **some** general utilities provided in <stdlib.h> involving random numbers and memory management.

## Setup/Build \*IMPORTANT\*

```sh
Usage: make
       make clean
```

I have provided a Makefile that should make it really simple to build the binary. I would strongly recommend to quickly read it through since it is quite short and then alter it if necessary. By default, the only prerequisites needed are GCC and GNU Make.

### Expected build output
```sh
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
```sh
$ make clean
rm -r ./obj ./bin
```

## All-in-C \*Parent caller of all other scripts\*

```sh
Usage: all-in-c [KNOWN_SCRIPT] ...
```

**Source:** *all-in-c.c* and *all-in-c.h*

Executes the script specified in the first command line argument.

```sh
$ ./bin/all-in-c --commandLineArguments "Hello World!"
Running command-line-arguments ...

Argument [0]: command-line-arguments
Argument [1]: Hello World!
```

## Command-line Arguments

```sh
Usage: --command-line-arguments ...
```

**Source:** *src/commandLineArguments.c*

Prints out each command-line argument on a new line (including executed command).

```sh
$ ./bin/all-in-c --command-line-arguments -g 42 --file "bob.txt"
Running command-line-arguments ...

Argument [0]: command-line-arguments
Argument [1]: -g
Argument [2]: 42
Argument [3]: --file
Argument [4]: bob.txt
```

## File Access

```sh
Usage: --file-access -r [FILE]
                     -w [FILE] [STRING]
                     -a [FILE] [STRING]
```

**Source:** *src/fileAccess.c*

Read, write, and append files.

### Write
```sh
$ ./bin/all-in-c --file-access -w bob.txt Hello
Running file-access ...
```

### Append
```sh
$ ./bin/all-in-c --file-access -a bob.txt " World!"$'\n'
Running file-access ...
```

### Read
```sh
$ ./bin/all-in-c --file-access -r bob.txt
Running file-access ...

Hello World!
```

## Timer

```sh
Usage: --timer [COMMAND]
```

**Source:** *src/timer.c*

Times duration of a command in seconds.

```sh
$ ./bin/all-in-c --timer "./bin/all-in-c --file-access -r bob.txt"
Running timer ...

Running file-access ...

Hello World!

(0.000108s)
```

## Run Command

```sh
Usage: --run-command [COMMAND]
```

**Source:** *src/runCommand.c*

Executes command given in command line argument.

```sh
$ ./bin/all-in-c --run-command './bin/all-in-c --timer "./bin/all-in-c --file-access -r bob.txt"'
Running run-command ...

Running timer ...

Running file-access ...

Hello World!

(0.000120s)
```

## File Operations

```sh
Usage: --file-operations --rename [FILE] [NEW_NAME]
                         --remove [FILE]
                         --tmpfile [STRING]
```

**Source:** *src/fileOperations.c*

Remove or rename files or create a temp file with data

### Rename
```sh
$ ls | grep ^.*\.txt
bob.txt
$ ./bin/all-in-c --file-operations --rename bob.txt bobby.txt
Running file-operations ...

$ ls | grep ^.*\.txt
bobby.txt
```

### Remove
```sh
$ ls | grep ^.*\.txt
bobby.txt
$ ./bin/all-in-c --file-operations --remove bobby.txt
Running file-operations ...

$ ls | grep ^.*\.txt
```

### Temp File
```sh
$ ./bin/all-in-c --file-operations --tmpfile "Hello World!"
Running file-operations ...

Data contained in temp file: Hello World!
```

## POSIX System Calls

```sh
Usage: --syscall [STRING]
```

**Source:** *src/posixSyscalls.c*

Invokes a variety of pre-implemented system calls.
**Only works on unix-based systems.**

### Write System Call
```sh
$ ./bin/all-in-c --syscall "Hello World!"
Running syscall ...

Hello World!
```