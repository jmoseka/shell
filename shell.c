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
int _parse_input(char *user_input, char **arg);
int _check_exec(char *command);
int _fork(char **arg);
int _print_wrong_input(char *cmd, int input_count);


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

extern char **environ;

int main(void)
{
	ssize_t cmd_bytes = 0;
	size_t cmd_size = 0;
	char *cmd_input = NULL, *arg[20];
	int cmd_count = 1, valid_command = 0;

	if (isatty(STDIN_FILENO))
	{
		prompt("$ ", 2);
		signal(SIGINT, ctr_c);
	}
	cmd_bytes = getline(&cmd_input, &cmd_size, stdin);

	while (cmd_bytes != -1)
	{
		if (*cmd_input == '\n')
			free(cmd_input);
		else if (*cmd_input != '\n')
		{
			_parse_input(cmd_input, arg);
			valid_command = _check_exec(arg[0]);
			if (valid_command == 0)
				_fork(arg);
			else if (valid_command != 0)
			{
				_print_wrong_input(cmd_input, cmd_count);
			}
			free(*arg);
		}
		cmd_input = NULL;
		cmd_count++;
		if (isatty(STDIN_FILENO))
		{
			prompt("$ ", 2);
			signal(SIGINT, ctr_c);
		}
		cmd_bytes = getline(&cmd_input, &cmd_size, stdin);
	}
	/*_putchar('\n');*/
	free(cmd_input);
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

/**
* _parse_input - parses input from the user and stores in an array
* @user_input: input from user
* @arg: array with arguments to execute
* Return: arguments count
*/

int _parse_input(char *user_input, char **arg)
{
	int ac = 0;
	char *parameter;
	char *temp = user_input;

	user_input = strtok(user_input, " \n\t\r");
	arg[ac] = user_input;
	for (ac = 1; temp != NULL; ac++)
	{
		parameter = strtok(NULL, " \n\t\r");
		temp = parameter;
		arg[ac] = parameter;
	}
	arg[ac] = NULL;
	return (ac);
}

/**
* _check_exec - checks existence of command
* @command: name of executable file, args[0] gotten from _parse_input
*
* Return: 0 on success or -1 on error
*/

int _check_exec(char *command)
{
	int valid_command;

	valid_command = access(command, F_OK);
	if (valid_command != 1)
		return (valid_command);
	else
		return (valid_command);
}

/**
 * _fork - starts executes and terminates child process
 * @arg: array of arguments to execute
 *
 * Return: 0 for success or 1 if execution fails
 */

int _fork(char **arg)
{
	pid_t child_p = 0;
	int status = 0;
	int exe_stat = 0;

	child_p = fork();
	if (child_p == -1)
	{
		perror("failed fork");
		exit(EXIT_FAILURE);
	}
	else if (child_p == 0)
	{
		exe_stat = execve(arg[0], arg, environ);
		if (exe_stat == -1)
			return (1);
	}
	else
		wait(&status);
	return (0);
}
