#include "main.h"

/**
 * the_builtin_functions 
 * @command: command
 * Return: pointer
 */
int (*the_builtin_functions(char *command))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", the__envirement_ },
		{ "exit", out_of_shell },
		{ "setenv", the_change_envirement },
		{ "unsetenv", remove_envirement },
		{ "cd", change_directory },
		{ "help", print_help_function },
		{ NULL, NULL }
	};
	int x;

	for (x = 0; builtin[x].name; x++)
	{
		if (compare_strings(builtin[x].name, command) == 0)
			break;
	}

	return (builtin[x].f);
}
