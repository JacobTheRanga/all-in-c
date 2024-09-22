#include <stdio.h>

#define MODE argv[1]
#define ARG1 argv[2]
#define ARG2 argv[3]

// Removes file
int removeFile(char *filename);

// Renames file
int renameFile(char *filename, char *new);

// Creates temp file
int createTemp(char *input);

// Commands
struct{
    char name[10];
    int (*execute)();
} commands[] =
{
    {"remove", removeFile},
    {"rename", renameFile},
    {"tmpfile", createTemp}
};

// Error handling
int invalidArguments(char *err, char *format);

// Remove/rename files or create temp file with data
int fileOperations(int argc, char **argv){
    if(argc <= 2 || *(argv[1]++) != '-' || *(argv[1]++) != '-')
        return invalidArguments("Invalid arguments", "--[remove][rename][tmpfile] ...");
    for(int i = 0; i < 3; i++){
        int j = 0;
        while(MODE[j] == commands[i].name[j]){
            if(MODE[j] && commands[i].name[j++])
                continue;

            if(argc != 4 && i == 1)
                return invalidArguments("Invalid arguments", "--rename [OLD_FILE] [NEW_FILE]");
            if(i == 1)
                return commands[i].execute(ARG1, ARG2);
            if(argc != 3)
                return invalidArguments("Invalid arguments", "--[remove/tmpfile] [FILENAME/INPUT_DATA]");
            return commands[i].execute(ARG1);
        }
    }
    return invalidArguments("Invalid arguments", "could not find command in list");
}

// Error handling
int invalidArguments(char *err, char *format){
    fprintf(stderr, "ERROR: %s - need '%s'\n", err, format);
    return 1;
}

// Removes file
int removeFile(char *filename){
    remove(filename);
    return 0;
}

// Renames file
int renameFile(char *filename, char *new){
    rename(filename, new);
    return 0;
}

// Creates temp file
int createTemp(char *input){
    FILE* tmpf = tmpfile();
    fputs(input, tmpf);
    rewind(tmpf);
    char buffer[256];
    fgets(buffer, sizeof(buffer), tmpf);
    printf("Data contained in temp file: %s\n", buffer);
    return 0;
}