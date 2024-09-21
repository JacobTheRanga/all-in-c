#include <stdlib.h>
#include <stdio.h>

// Executes command given in command line argument
int runCommand(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr, "ERROR: Invalid number of arguments - need 1 to provide a string containing the command you want to run\n");
        return 1;
    }

    system(*(++argv));
    return 0;
}