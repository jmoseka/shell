# Concepts to know to create shell

## 1. PROCESS ID (PID) and PARENT PROCESS ID (PPID)

### File: getppid
A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call getpid (man 2 getpid):
In order to retrieve the parent process, use getppid system call (man 2 getppid), from within the child process.
```
julien@ubuntu:~/c/shell$ cat getppid.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main()
{
	unsigned int p_pid;

	getpid();
	p_pid = getpid(); /*parent process id*/
	printf("PPID: %u\n", p_pid);	
	return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Werror -pedantic getppid.c -o getppid && ./mypid
3237
julien@ubuntu:~/c/shell$ ./getppid 
3238
julien@ubuntu:~/c/shell$ ./getppid 
3239
julien@ubuntu:~/c/shell$ 
```

## 2. Promt 
### File: promt.c
Uses function getline. 

getline()  reads  an  entire  line  from  stream,  storing  the address of the buffer containing the text into
       *lineptr.  The buffer is null-terminated and includes the newline character, if one was found.

       If *lineptr is set to NULL and *n is set 0 before the call, then getline() will allocate a buffer for  storing
       the line.  This buffer should be freed by the user program even if getline() failed.

       Alternatively,  before  calling  getline(),  *lineptr can contain a pointer to a malloc(3)-allocated buffer *n
       bytes in size.  If the buffer is not large enough to hold the line, getline() resizes it with realloc(3),  up‐
       dating *lineptr and *n as necessary.

       In  either case, on a successful call, *lineptr and *n will be updated to reflect the buffer address and allo‐
       cated size respectively.

```
vagrant@ubuntu-focal:~/simple_shell/concepts$ cat promt.c
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
    /*cmdline stores value returned by getline. On success, returns the number character read*/
    cmdline = getline(&input, &len, stdin);
    printf("Command entered: %s", input);
    printf("Length of input read from commandline:\n %lu", cmdline);
    printf("Length of actual input(newline + null terminator):\n %lu", len);

    free(input);
}
vagrant@ubuntu-focal:~/simple_shell/concepts$ gcc -Wall -Werror -pedantic promt.c -o promt
vagrant@ubuntu-focal:~/simple_shell/concepts$ ./promt
$ mila
Command entered: mila
Length of input read from commandline: 5
Length of actual input(newline + null terminator): 6
vagrant@ubuntu-focal:~/simple_shell/concepts$
```
## 3. strok() function
### File: strok.c
strtok() function is used to split a string into a series of tokens based on a particular delimiter. A token is a substring extracted from the original string.
The user input from command line is tokenized to establish paths, commands , etc  The  strtok()  function  breaks  a string into a sequence of zero or more nonempty tokens.  On the first call to strtok(), the string to be parsed should be
       specified in str.  In each subsequent call that should parse the same string, str must be NULL.

       The delim argument specifies a set of bytes that delimit the tokens in the parsed string.  The caller may specify different strings in delim  in  successive
       calls that parse the same string.

       Each  call  to  strtok()  returns a pointer to a null-terminated string containing the next token.  This string does not include the delimiting byte.  If no
       more tokens are found, strtok() returns NULL.
       

```vagrant@ubuntu-focal:~/simple_shell/concepts$ cat strok.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
        /*Creating a promt*/
        char *input;
            size_t len = 1;
        input = (char*) malloc(len * sizeof(char));
        printf("$ ");
        getline(&input, &len, stdin);

  /*Splitting the string*/
  char *p;

  p = strtok (input,",:");
  while (p!= NULL)
  {
    printf ("%s\n",p);
    p = strtok (NULL, ",:");
  }
  return 0;
}
vagrant@ubuntu-focal:~/simple_shell/concepts$ gcc -Wall -Werror -pedantic strok.c -o strok
vagrant@ubuntu-focal:~/simple_shell/concepts$ ./strok
$ /bin/ls ls
/bin/ls ls

vagrant@ubuntu-focal:~/simple_shell/concepts$ ./strok
$ /bin/ls: ls
/bin/ls
 ls

vagrant@ubuntu-focal:~/simple_shell/concepts$

```
