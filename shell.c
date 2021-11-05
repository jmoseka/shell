#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>
#include <string.h>

ssize_t prompt(const char *prompt, size_t size);

/**
 * ctr_c - prevent shell to quit by pressing Ctrl + c
 * @signal: signal
 */
void ctr_c(int signal)
{
	signal = signal;
	write(1, "\n", 1);
	write(1, "$ ", 2);
	fflush(stdout);
}

/**
 * main - create a simple shell
 *
 * Return: 0 for success
 */
int main(void)
{
	ssize_t cmd_bytes = 0;
	size_t cmd_size = 0;
	char *cmd_input = NULL /**arg[20]*/;
	/*int cmd_count = 1, valid_cmd = 0;*/

	if (isatty(STDIN_FILENO))
	{
		prompt("$ ", 2);
		signal(SIGINT, ctr_c);
	cmd_bytes = getline(&cmd_input, &cmd_size, stdin);
	}

	printf("%ld", cmd_bytes);
}

/**
* prompt - display promt
* @prompt: command to be printed
* @size: length of the command
*
* Return: 0 on success, -1 if not
*/

ssize_t prompt(const char *prompt, size_t size)
{
	int written_bytes = 0;

	written_bytes = write(STDOUT_FILENO, prompt, size);
	if (written_bytes == -1)
		return (-1);
	else
		return (0);
}
/**
 * _putchar - prints a character
 * @c: character to be printed
 * Return: 0
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_count - count no. of time previous command has failed
 * @count: no. of time user inputs a command
 *
 */

void _print_count(int count)
{
	if (count / 10)
		_print_count(count / 10);
	_putchar(count % 10 + '0');
}

/**
 * _print_wrong_input - prints prompt after invalid command
 * @cmd: user command input
 * @input_count: no. of time user inputs a command
 * Return: nothing
 */

int _print_wrong_input(char *cmd, int input_count)
{
	char *prompt = "./hsh";

	write(2, prompt, 5);
	write(2, ": ", 2);
	_print_count(input_count);
	write(2, ": ", 2);
	write(2, cmd, strlen(cmd));
	write(2, ": not found\n", 12);
	return (127);
}
