#include "main.h"

/**
 * the_read_line 
 *
 * @end_of_line:value
 * Return: string
 */
char *the_read_line(int *end_of_line)
{
	char *input = NULL;
	size_t bufsize = 0;

	*end_of_line = getline(&input, &bufsize, stdin);

	return (input);
}
