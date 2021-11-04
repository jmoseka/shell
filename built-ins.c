#include "shell.h"
/**
 * print_env - prints the current environment
 * @environ: the command environment
 * @exit_prog: exits the program
 * Return: Always 0
 */
int print_env(char **environ, int *exit_prog)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		print_str(environ[i]);
		_putchar('\n');
		i++;
	}
	*exit_prog = 0;
	return (EXIT_SUCCESS);
}


/**
 * _builtin -  implements the exit and print_env functions
 * @l: the buffer with the commands
 * @args: the parsed arguments
 * @environ: the command environment
 * @exit_prog:  exits the program 
 * Return: Nothing
 */
void _builtin(char *l, char **args, char **environ, int *exit_prog)
{

	if (_strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(l);
		exit(*exit_prog);
	}

	if (_strcmp(args[0], "environ") == 0)
		print_env(environ, exit_prog);
}
