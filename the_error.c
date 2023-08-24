#include "main.h"

/**
 * the_erreur_function 
 * @directory_data: data
 * @erreur_value: err
 * Return: value
 */
int the_erreur_function(data_shell *directory_data, int erreur_value)
{
	char *err;

	switch (erreur_value)
	{
	case -1:
		err = erreur_envirement(directory_data);
		break;
	case 126:
		err = erreur_link_126(directory_data);
		break;
	case 127:
		err = erreur_null(directory_data);
		break;
	case 2:
		if (compare_strings("exit", directory_data->args[0]) == 0)
			err = error_exit_shell(directory_data);
		else if (compare_strings("cd", directory_data->args[0]) == 0)
			err = cd_erreur(directory_data);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, lenght_string(err));
		free(err);
	}

	directory_data->the_status = erreur_value;
	return (erreur_value);
}
