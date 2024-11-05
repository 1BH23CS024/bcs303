// Experiment 3 - execv() system call

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
    printf("Call execv()\n");
    execv("/bin/ls", argv);
    printf("ERROR: execv() failed\n");
}