#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
	/*Creating a promt*/
	char *input;
	    size_t len = 1;
	input = (char*) malloc(len * sizeof(char));
	printf("$ ");
       	getline(&input, &len, stdin);
	
  /*Splitting the string*/
  char *p;
 
  p = strtok (input,",:");
  while (p!= NULL)
  {
    printf ("%s\n",p);
    p = strtok (NULL, ",:");
  }
  return 0;
}
