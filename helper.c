#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include "tests/errors/errors.h"
#include <string.h>
#include "tests/utils/headers.h"
#include "helper.h"

int string_match(char *main_string, char *sub_string)
{
	int match_count = 0;

	int i, j;
	j = 0;
	
	int sub_string_length;
	for (sub_string_length = 0; sub_string[sub_string_length++];);
	sub_string_length --;

	for (i = 0; main_string[i]; i++)
	{
		/* leading whitespace */
		if (main_string[i] == ' ' && main_string[i] != sub_string[j] && !match_count);
		/* any non-whitespace character mismatch */
		else if (main_string[i] != sub_string[j] && main_string[i] != ' ')
		return 0;
		
		/* character mismatch */
		else if (main_string[i] != sub_string[j] && match_count && j < sub_string_leng)
		return 0;

		/* trailing whitespace */
		        else if (main_string[i] == ' ' && j == sub_string_length)
				            ;

			        /* character match */
			        else if (main_string[i] == sub_string[j])
					        {
							            j++;
								                match_count++;
										        }

				        /* last none-null character of main_string */
				        if (main_string[i + 1] == '\0' && j == sub_string_length)
						            return match_count;        
					    }
	    return 0;
}
