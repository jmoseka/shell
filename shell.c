#include "holberton.h"
/**
 * main - This is a simple shell created by
 * Marisol Ramirez Henao and David Alejandro Hincapié
 * for Holberton School
 * Return: 0 if success
 */
int main(void)
{
	ssize_t bytes_rd = 0; /** Bytes leídos de un getline*/
	size_t bf_size = 0; /**Tamaño del buffer*/
	char *entry = NULL, *arguments[20]; /**String de args que ingresa el usr*/
	int counter = 1, vf_stat = 0, exist_stat = 0, exit_stat = 0, blt_stat = 0;

	_printp("$ ", 2);/**prompt mini-shell*/
	bytes_rd = getline(&entry, &bf_size, stdin); /**sizeof entry, o -1 (EOF))*/
	while (bytes_rd != -1)
	{
		if (*entry != '\n')
		{
			fill_args(entry, arguments);
			if (arguments[0] != NULL)
			{
				exist_stat = exist(arguments[0]);/**Exist evalua si path ingresado existe*/
				if (exist_stat != 0)/**No encontró el archivo*/
				{
					vf_stat = verify_path(arguments);
					if (vf_stat == 0)
						exit_stat = exec(arguments), free(entry), free(*arguments);
					else
					{
					blt_stat = verify_blt(arguments, exit_stat);
					if (blt_stat != 0)
						exit_stat = print_not_found(arguments, counter), free(entry);
					}
				}
				else /**Encontró el archivo*/
					exit_stat = exec(arguments), free(entry);
			}
			else
				free(entry);
		}
		else if (*entry == '\n')
			free(entry);
		entry = NULL, counter++;
		_printp("$ ", 2), bytes_rd = getline(&entry, &bf_size, stdin);
	}
	last_free(entry);
	return (exit_stat);
}
