#include "holberton.h"
/**
 * exec - Creates a new child process,
 * executes a command and wait for the child process
 * to update the status
 * @arguments: Array of inputs by the user
 * Return: 0 if success
 */
int exec(char **arguments)
{
	pid_t pid = 0;/**Child process id*/
	int stat = 0, exe_stat = 0;/**indica el status del child process*/

	pid = fork();/**Crea un proceso hijo*/
	if (pid == -1)/**Falló al crear*/
		_printp("failed\n", 7);
	else if (pid == 0)/**Es el hijo...*/
	{
		exe_stat = execve(arguments[0], arguments, environ);/**Ejecuta el comando*/
		if (exe_stat == -1)
		{
			exe_stat = 126;
			perror("hsh");
			exit(exe_stat);
		} /**Terminar el child process con exito*/
		exit(0);
	}
	else /**Es el padre*/
		wait(&stat);/**Detiene la ejecución del padre hasta que el child termine*/
	exe_stat = WEXITSTATUS(stat);
	return (exe_stat);
	}
