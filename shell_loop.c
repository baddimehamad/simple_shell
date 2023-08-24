#include "main.h"

/**
 * no_comment_fun 
 * @the_input: string
 * Return: pointer
 */
char *no_comment_fun(char *the_input)
{
	int x, __to;

	__to = 0;
	for (x = 0; the_input[x]; x++)
	{
		if (the_input[x] == '#')
		{
			if (x == 0)
			{
				free(the_input);
				return (NULL);
			}

			if (the_input[x - 1] == ' ' || the_input[x - 1] == '\t' || the_input[x - 1] == ';')
				__to = x;
		}
	}

	if (__to != 0)
	{
		the_input = the_re_alloc(the_input, x, __to + 1);
		the_input[__to] = '\0';
	}

	return (the_input);
}

/**
 * the_loop_shell 
 * @directory_data: data 
 * Return: null
 */
void the_loop_shell(data_shell *directory_data)
{
	int boucle, end_of_line;
	char *the_input_var;

	boucle = 1;
	while (boucle == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		the_input_var = the_read_line(&end_of_line);
		if (end_of_line != -1)
		{
			the_input_var = no_comment_fun(the_input_var);
			if (the_input_var == NULL)
				continue;

			if (check_erreur_s(directory_data, the_input_var) == 1)
			{
				directory_data->the_status = 2;
				free(the_input_var);
				continue;
			}
			the_input_var = the_rep_var(the_input_var, directory_data);
			boucle = the_split_commands(directory_data, the_input_var);
			directory_data->nums += 1;
			free(the_input_var);
		}
		else
		{
			boucle = 0;
			free(the_input_var);
		}
	}
}
