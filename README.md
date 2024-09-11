# All in C

An assortment of different types of scripts, programs, and projects all written in C using the C standard library only when reasonably necessary or for use in comparison sake and the occasional standard framework for purposes such as graphics rendering.

From the C standard library, the utilities I will allow myself to use may include but are not limited to <stdio.h> for convenient standard input/output and **some** general utilities provided in <stdlib.h> involving random numbers and memory management.

## Command-line Arguments

**Source:** *src/commandLineArguments*

Prints out each command-line argument on a new line (including executed command).

```sh
$ ./bin/all-in-c --command-line-arguments -gs 28 --help
Argument [0]: --command-line-arguments
Argument [1]: -gs
Argument [2]: 28
Argument [3]: --help
```