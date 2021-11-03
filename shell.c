#include <stdio.h>
#include <stdlib.h>
/**
 * main - shell program
 *
 * @argc: count of the arguements supllied on the command line
 * @argv: points to the strings of the arguement passed
 *
 */

int main(int argc, char *argv[])
{
    char *input;
    size_t len = 1;

    input = (char*) malloc(len * sizeof(char));

    printf("$ ");

    getline(&input, &len, stdin);
    printf("%s", input);

    free(input);
}
