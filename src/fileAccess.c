#include <stdio.h>

#define MODE (*(argv[1]))
#define INPUT_FILE (argv[2])
#define INPUT_STRING (argv[3])

// Reads file to stdout
int readFile(char *filename);

// Writes to file
int writeFile(char *filename, char *str);

// Appends to end of file
int appendFile(char *filename, char *str);

// Read/write/append files
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
        return readFile(INPUT_FILE);
    if(MODE == 'w' && INPUT_STRING)
        return writeFile(INPUT_FILE, INPUT_STRING);
    if(MODE == 'a' && INPUT_STRING)
        return appendFile(INPUT_FILE, INPUT_STRING);
    fprintf(stderr, "ERROR: No string to write to file - need another argument containing the string to write\n");
    return 1;
}

// Reads file to stdout
int readFile(char *filename){
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
int writeFile(char *filename, char *str){
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
int appendFile(char *filename, char *str){
    FILE *fp = fopen(filename, "a");
    if(!fp){
        fprintf(stderr, "ERROR: file does not exist\n");
        return 1;
    }
    fputs(str, fp);
    fclose(fp);
    return 0;
}