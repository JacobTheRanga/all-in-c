#ifndef ALL_IN_C_H
#define ALL_IN_C_H

// Structure containing a function pointer and its call argument/flag
typedef struct{
    char callArgument[50];
    int (*execute)();
}functionMap_t;

// Prints out each command line argument on a new line (including executed command)
int commandLineArguments(int argc, char **argv);

// Manipulates files
int fileAccess(int argc, char **argv);

#endif