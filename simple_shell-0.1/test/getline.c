#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

int main(void)
{
	size_t len = 0;
	char *line = NULL;
	ssize_t nread = 0;

	nread = getline(&line, &len, stdin);
	if(nread == -1)
	return (-1);
	printf("Line read: %s", line);
	return (0);
}
