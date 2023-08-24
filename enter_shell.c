#include "main.h"

/**
 * change_directory - change directory
 *
 * @directory_data: data
 * Return: 1 
 */
int change_directory(data_shell *directory_data)
{
	char *dorectory_var;
	int home1, home2, the_dash;

	dorectory_var = directory_data->args[1];

	if (dorectory_var != NULL)
	{
		home1 = compare_strings("$HOME", dorectory_var);
		home2 = compare_strings("~", dorectory_var);
		the_dash = compare_strings("--", dorectory_var);
	}

	if (dorectory_var == NULL || !home1 || !home2 || !the_dash)
	{
		go_home(directory_data);
		return (1);
	}

	if (compare_strings("-", dorectory_var) == 0)
	{
		return_to_old_dir(directory_data);
		return (1);
	}

	if (compare_strings(".", dorectory_var) == 0 || compare_strings("..", dorectory_var) == 0)
	{
		parent_directory(directory_data);
		return (1);
	}

	enter_to(directory_data);

	return (1);
}
