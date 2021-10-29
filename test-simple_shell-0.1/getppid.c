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
