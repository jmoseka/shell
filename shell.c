#include "shell.h"

/**
 * main - Creates a simple UNIX command line interpreter
 * @argc: number of argument 
 * @argv: argument passed to main
 * @environ: the environment
 * Return: 0
 */
int main(int argc, char **argv, char **environ)
{
	char *com = "##--->";
	char *l = NULL;
	char **args = NULL;
	int i = 0, status = 0, arg_numb = 0;
	static int exit_stat, total;
	size_t length = 0;
	ssize_t read = 0;
	(void)argc, (void)**argv;

	while (TRUE)
	{
		if (isatty(STDINFILENO) == 1)
			write(STDOUTFILENO, "$", 2);

		read = getline(&l, &length, stdin);
		++tally;
		if (spec_char(l, read, &exit_stat) == 127)
			continue;

		no_new_line(l);

		args = parser(l);

		for (i = 0; args[i]; i++)
			arg_numb++;

		builtins(l, args, environ, &exit_stat);

		status = _path(args[0], args, environ, &exit_stat);

		_execute(status, args, &exit_stat, &total);

		fflush(stdin);
	}
	free(line);
	return (0);
}
