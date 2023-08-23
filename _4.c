#include "main.h"
char *get_the_last_directory(const char *link)
{
	char *directory;
	char *the_token;
	char *users = NULL;

	if (env_0("USER"))
		users = env_0("USER");
	else if (env_0("HOSTNAME"))
		users = env_0("HOSTNAME");
	else
		users = "root";

	directory = NULL;
	the_token = strtok((char *)link, "/");

	while (the_token != NULL)
	{
		directory = the_token;
		the_token = strtok(NULL, "/");
	}
	if (compare_strings(users, directory, sizeof(directory)) == 0)
		return ("~");
	return (directory);
}
char *string_reallocation(char *x, size_t y)
{
	char *w;
	size_t i;
	size_t z;

	if (x == NULL)
	{
		w = malloc(y);
	}
	else
	{
		z = lenght_string(x);
		w = malloc(y);
		if (w != NULL)
		{
			for (i = 0; i < z && i < y; i++)
			{
				w[i] = x[i];
			}
			free(x);
		}
	}

	return (w);
}