#include "main.h"

/**
 * print_help_function 
 * @directory_data: data
 * Return: Return 0
*/
int print_help_function(data_shell *directory_data)
{

	if (directory_data->args[1] == 0)
		help_built_global();
	else if (compare_strings(directory_data->args[1], "setenv") == 0)
		help_built_set();
	else if (compare_strings(directory_data->args[1], "env") == 0)
		help_built();
	else if (compare_strings(directory_data->args[1], "unsetenv") == 0)
		help_built_unset();
	else if (compare_strings(directory_data->args[1], "help") == 0)
		help_built_fun();
	else if (compare_strings(directory_data->args[1], "exit") == 0)
		help_built_exit();
	else if (compare_strings(directory_data->args[1], "cd") == 0)
		help_built_cd();
	else if (compare_strings(directory_data->args[1], "alias") == 0)
		help_built_a();
	else
		write(STDERR_FILENO, directory_data->args[0],
		      lenght_string(directory_data->args[0]));

	directory_data->the_status = 0;
	return (1);
}
