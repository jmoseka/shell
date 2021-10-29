#include <stdio.h>
#include <unistd.h>

int main()
{
	int p_id;
	
	p_id = getpid();
	
	printf("Process ID: %d\n", p_id);

	return 0;
}

