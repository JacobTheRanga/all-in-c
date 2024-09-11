#include "all-in-c.h"

// Stores all the main functions of the programs and their call arguments
const functionMap_t programs[] = 
{
    {"--command-line-arguments", commandLineArguments}
};

int main(int argc, char **argv){
    // Attempts to match the index 1 command line argument with a function call argument

    // Iterates through all indexed programs
    for(int i = 0; i < sizeof(programs) / sizeof(programs[0]); i++)
        // Iterates through each character in the function call argument string
        for(int j = 0; j < sizeof(programs[0].callArgument) / sizeof(programs[0].callArgument[0]); j++){
            // Breaks out of current string comparison if not a character match
            if(argv[1][j] != programs[i].callArgument[j])
                break;
            // Executes program if both the command line and function call arguments are out of index
            if(!programs[i].callArgument[j] && !argv[1][j]){
                // Executes program with all arguments (excluding the binary name)
                programs[i].execute(argc - 1, argv + 1);
                return 0;
            }
        }
    // Could not find program
    return 1;
}