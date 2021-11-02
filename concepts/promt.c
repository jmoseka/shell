#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char *input;
    size_t len = 1;
    ssize_t cmdline;
    
    /*dynamically allocates memory to string input so that it can store*/
    input = (char*) malloc(len * sizeof(char));

    printf("$ ");
    /*cmdline stores value returned by getline */
    cmdline = getline(&input, &len, stdin);
    printf("Command entered: %s", input);
    printf("Length of input read from commandline: %lu\n", cmdline);
    printf("Length of actual input(newline + null terminator): %lu\n", len);

    free(input);
}
