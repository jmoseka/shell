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

