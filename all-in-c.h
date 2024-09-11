#ifndef ALL_IN_C_H
#define ALL_IN_C_H

// Structure containing a function pointer and its call argument/flag
typedef struct{
    char callArgument[50];
    void (*execute)();
}functionMap_t;

// Prints out each command line argument on a new line (including executed command)
// int argc - no. of arguments
// char **argv - pointer to array of arguments
void commandLineArguments(int argc, char **argv);

#endif