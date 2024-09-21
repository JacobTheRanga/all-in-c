#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Times duration of a command in seconds
int timer(int argc, char **argv){
    if(argc <= 1){
        fprintf(stderr, "ERROR: Invalid number of arguments - 1 arguments expected\n");
        return 1;
    }

    clock_t start = clock();
    system(*(++argv));
    clock_t end = clock();
    printf("\n(%lfs)\n", ((double)end - start) / CLOCKS_PER_SEC);
    return 0;
}