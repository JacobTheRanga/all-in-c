/*
 * I do not endorse this code at all.
 * I felt like I was writing in Java, I deeply apologise.
 * Please forgive me for this horrendous code.
*/
#include <stdio.h>

int strcmp_(char *a, char *b);
int range_(int ch, int lower, int upper);

int islower_(int ch);
int isupper_(int ch);
int isdigit_(int ch);
int isalpha_(int ch);
int isalnum_(int ch);
int isspace_(int ch);
int ispunct_(int ch);
int isprint_(int ch);

// Own implementation of some functions in the <string.h> libc header
int strings(int argc, char **argv){
    if(argc < 3){
        fprintf(stderr, "ERROS: Not enough arguments - expected 2\n");
        return 1;
    }
    if(*argv[1]++ != '-' || *argv[1]++ != '-'){
        fprintf(stderr, "ERROR: Invalid arguement - need --[CONDITION] [STRING]\n");
        return 1;
    }
    struct{
        char name[50];
        int (*func)();
    } checks[] = {
        {"islower", islower_},
        {"isupper", isupper_},
        {"isdigit", isdigit_},
        {"isalpha", isalpha_},
        {"isalnum", isalnum_},
        {"isspace", isspace_},
        {"ispunct", ispunct_},
        {"isprint", isprint_},
    };
    for(int i = 0; i < sizeof(checks) / sizeof(checks[0]); ++i){
        if(strcmp_(argv[1], checks[i].name) == 0){
            while(*argv[2])
                if(!checks[i].func(*(argv[2]++))){
                    printf("FALSE\n");
                    return 0;
                }
            printf("TRUE\n");
            return 0;
        }
    }
    fprintf(stderr, "ERROR: Could not find function\n");
    printf("Avaliable functions:\n");
    for(int i = 0; i < sizeof(checks) / sizeof(checks[0]); ++i){
        printf("--%s\n", checks[i].name);
    }
    return 1;
}

int strcmp_(char *a, char *b){
    for( ; *a == *b; ++a, ++b)
        if(!*a)
            return 0;
    return *a - *b;
}

int range_(int ch, int lower, int upper){
    return (ch >= lower && ch <= upper);
}

int islower_(int ch){
    return range_(ch, 'a', 'z');
}

int isupper_(int ch){
    return range_(ch, 'A', 'Z');
}

int isdigit_(int ch){
    return range_(ch, '0', '9');
}

int isalpha_(int ch){
    return (islower_(ch) || isupper_(ch));
}

int isalnum_(int ch){
    return (isalpha_(ch) || isdigit_(ch));
}

int isspace_(int ch){
    return range_(ch, '\t', '\r');
}

int ispunct_(int ch){
    return (range_(ch, '!', '/') || range_(ch, ':', '@') || range_(ch, '[', '`') || range_(ch, '{', '~'));
}

int isprint_(int ch){
    return (isalnum_(ch) || ispunct_(ch) || isspace_(ch));
}