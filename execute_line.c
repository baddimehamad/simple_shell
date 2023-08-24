#include "main.h"

/**
 * execute_command 
 *
 * @directory_data: data
 * Return: 1
 */
int execute_command(data_shell *directory_data)
{
	int (*builtin)(data_shell *directory_data);

	if (directory_data->args[0] == NULL)
		return (1);

	builtin = the_builtin_functions(directory_data->args[0]);

	if (builtin != NULL)
		return (builtin(directory_data));

	return (execute_commande(directory_data));
}
