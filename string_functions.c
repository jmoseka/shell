#include "shell.h"
/**
 * _strcmp - makes comparison between two strings 
 * @str1 - string two
 * @str2 - string one
 * Return - compared value
 */


int _strcmp(char *str1, char *str2)
{

	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}


/**
 * _strlen - calculates length of a string
 * @str: string whose length is to be determined
 * Return: length of the string
 */
int _strlen(char *str)
{
	int lenght = 0;

	while (s[length] != '\0')
		length++;

	return (length);
}

/**
 * _strdup - function that duplicates a string
 * @str: - string to be duplicated
 * Return: pointer to the duplicate string. 
 */

char *_strdup(char *str)
{
	char *str_dup;

	int i, length;

	if (str == NULL)
		return (NULL);

	length = 0;

	for (i = 0; str[i] != '\0'; i++)
		length++;

	str_dup = malloc(sizeof(char) * (length + 1));

	if (str_dup == NULL)
		return (NULL);

	for (i = 0; i < length ; i++)
		str_dup[i] = str[i];

	str_dup[length] = '\0';

	return (str_dup);

}
