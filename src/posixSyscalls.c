/*
 * **WARNING**
 * You should never have to use syscalls within any normal usecase for C
 * this can pose some very serious issues that may include but are not
 * limited to: security vulnerabilities, horrible portability, horrible maintainability,
 * non-standard interfaces, hard for others to understand, loss of friendships,
 * loss of sanity, further develop a severe hatred of Java, vitamin D deficiency,
 * and then usually followed by DEATH.
 * 
 * NOTE:
 * The entire point of the C standard library is to abstract away from this entire process.
 * There is literally no reason to not just use the C standard library
 * unless you are writing custom firmware for systems that for some reason
 * do not already have their own standard library implementations.
 * This code even uses the unix standard syscalls library that contains macros for
 * every system call to the unix kernel. These macros change depending
 * on the system architecture, so I am still abstracting myself
 * from having remember and use the specific opcodes and registers
 * for each different system architechure.
 */

// Using "_exit" and "write" syscalls 
// with architecture independent macros for arguments and calling conventions
#include <unistd.h> 

// Invokes a write syscall to stdout with an input string
// My own implementation of the "puts" func from stdio.h in libc
// but only using the unix standard syscall api interacting directly with the kernel
int putsCustom(char* str);

// Invokes a variety of preimplemented syscalls and allows custom syscall inputs
// **Only works on unix-based systems**
int posixSyscalls(int argc, char **argv){
    if(argc<2){
        char str[]="Invalid number of arguments - expected 2\n";
        write(STDERR_FILENO,str,sizeof(str));
        _exit(1);
    }
    _exit(putsCustom(*++argv)); // Exit not needed but just wanted to use exit syscall
}

// Invokes a write syscall to stdout with an input string
// My own implementation of the "puts" func from stdio.h in libc
// but only using the unix standard syscall api interacting directly with the kernel
int putsCustom(char *str){
    size_t size=0;
    while(str[size])
        ++size;
    str[size++]='\n'; // Replace null char with new line char
    return (write(STDOUT_FILENO,str,size)!=(ssize_t)size);
}