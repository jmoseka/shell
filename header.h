#ifndef _HEADER_H
#define _HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>
#include <string.h>

ssize_t _print_prompt(const char *prompt, size_t size);

#endif
