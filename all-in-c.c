#include "all-in-c.h"
#include <stdio.h>

#define PROGRAMS_TOTAL (sizeof(programs) / sizeof(programs[0]))

// Stores all the main functions of the programs and their call arguments
const functionMap_t programs[] = 
{
    {"command-line-arguments", commandLineArguments},
    {"file-access", fileAccess},
    {"timer", timer},
    {"run-command", runCommand},
    {"file-operations", fileOperations},
    {"syscall", posixSyscalls},
    {"strings", strings},
    {"binary-tree", binaryTree}
};

void printPrograms(){
    printf("\nUse one of the below scripts as an argument followed by their own required arguments:\n");
    for(int i = 0; i < PROGRAMS_TOTAL; i++){
        printf("--%s\n", programs[i].callArgument);
    }
}

int main(int argc, char **argv){
    // Validates command line index 1 program input
    if(argc == 1 || *(argv[1]++) != '-' || *(argv[1]++) != '-'){
        fprintf(stderr, "ERROR: No program specified - index 1 command line argument not '--[program-name]'\n");
        printPrograms();
        return 1;
    }

    // Attempts to match the index 1 command line argument with a function call argument
    for(int i = 0; i < PROGRAMS_TOTAL; i++)
        for(int j = 0; j < sizeof(programs[0].callArgument) / sizeof(char); j++){
            // Match failed
            if(argv[1][j] != programs[i].callArgument[j])
                break;

            // Match succeeded
            if(!programs[i].callArgument[j] && !argv[1][j]){
                // Executes program with all command line arguments (excluding the caller)
                printf("Running %s ...\n\n", programs[i].callArgument);
                return programs[i].execute(argc - 1, argv + 1);
            }
        }

    fprintf(stderr, "ERROR: Could not find specified program - index 1 command line argument not matching any in program list\n");
    printPrograms();
    return 1;
}