#ifndef ALL_IN_C_H
#define ALL_IN_C_H

// Structure containing a function pointer and its call argument/flag
typedef struct{
    char callArgument[50];
    int (*execute)();
}functionMap_t;

// Prints out each command line argument on a new line (including executed command)
int commandLineArguments(int argc, char **argv);

// Read/write/append files
int fileAccess(int argc, char **argv);

// Times duration of a command in seconds
int timer(int argc, char **argv);

// Executes command given in command line argument
int runCommand(int argc, char **argv);

// Remove/rename files or create temp file with data
int fileOperations(int argc, char **argv);

#endif