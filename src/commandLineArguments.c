#include <stdio.h>

// Prints out each command line argument on a new line (including executed command)
int commandLineArguments(int argc, char **argv){
    for(int i = 0; i < argc; i++)
       printf("Argument [%d]: %s\n", i, argv[i]);
    return 0;
}