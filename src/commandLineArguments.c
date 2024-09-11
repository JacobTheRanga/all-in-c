#include <stdio.h>

void commandLineArguments(int argc, char **argv){
    for(int i = 0; i < argc; i++)
       printf("Argument [%d]: %s\n", i, argv[i]);
}