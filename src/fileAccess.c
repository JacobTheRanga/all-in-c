#include <stdio.h>

#define MODE (*(argv[1]))
#define INPUT_FILE (argv[2])
#define INPUT_STRING (argv[3])

// Reads file to stdout
int read(char *filename){
    FILE *fp = fopen(filename, "r");
    if(!fp){
        fprintf(stderr, "ERROR: file does not exist\n");
        return 1;
    }
    char buf[256];
    while(fgets(buf, sizeof(buf), fp))
        printf("%s", buf);
    fclose(fp);
    return 0;
}

// Writes to file
int write(char *filename, char *str){
    FILE *fp = fopen(filename, "wx");
    if(!fp){
        fprintf(stderr, "ERROR: file already exists - did you want to append?\n");
        return 1;
    }
    fputs(str, fp);
    fclose(fp);
    return 0;
}

// Appends to end of file
int append(char *filename, char *str){
    FILE *fp = fopen(filename, "a");
    if(!fp){
        fprintf(stderr, "ERROR: file does not exist\n");
        return 1;
    }
    fputs(str, fp);
    fclose(fp);
    return 0;
}

// Manipulates files
int fileAccess(int argc, char **argv){
    if(argc <= 2){
        fprintf(stderr, "ERROR: Invalid number of arguments - need '-[r/w/a/x] [file]'\n");
        return 1;
    }

    if(*(argv[1]++) != '-' || !INPUT_FILE){
        fprintf(stderr, "ERROR: Invalid argument format - need '-[r/w/x] [file]'\n");
        return 1;
    }

    if(MODE == 'r')
        return read(INPUT_FILE);
    if(MODE == 'w' && INPUT_STRING)
        return write(INPUT_FILE, INPUT_STRING);
    if(MODE == 'a' && INPUT_STRING)
        return append(INPUT_FILE, INPUT_STRING);
    fprintf(stderr, "ERROR: No string to write to file - need another argument containing the string to write\n");
    return 1;
}