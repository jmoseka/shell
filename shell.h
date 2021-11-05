#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>


int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strdup(char *str);

void _builtin(char *argv, char **args, char **environ, int *exit_prog);
int print_env(char **environ, int *exit_prog);
