#include "holberton.h"
/**
 * fill_args - Fill an array with every input typed by the user
 * @entry: String with the input
 * @arguments: Array to be filled
 * Return: Length of the array
 */

int fill_args(char *entry, char **arguments)
{
	int i = 0;
	char *options, *aux = entry, *command;

	command = strtok(entry, "\n\t\r "); /**Extrae el comando 0 */
	arguments[i] = command; /**Almacena command 1 en args*/
	while (aux != NULL) /**Mientras que hayan tokens*/
	{
		++i;
		options = strtok(NULL, "\n\t\r "); /**Almacena el n argumento en parameter*/
		aux = options;
		arguments[i] = options; /**almacena parameter i en args[i]*/
	}
	arguments[i] = NULL; /**Marca el fin array*/
	return (i); /**Retorna el length de args[]*/
}
