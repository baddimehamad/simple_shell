#include "main.h"

/**
 * out_of_shell 
 * @directory_data: data 
 * Return: 0 
 */
int out_of_shell(data_shell *directory_data)
{
	unsigned int the_status;
	int the_number;
	int string_size;
	int size_number_b;

	if (directory_data->args[1] != NULL)
	{
		the_status = string_to_int(directory_data->args[1]);
		the_number = is_number(directory_data->args[1]);
		string_size = lenght_string(directory_data->args[1]);
		size_number_b = the_status > (unsigned int)INT_MAX;
		if (!the_number || string_size > 10 || size_number_b)
		{
			the_erreur_function(directory_data, 2);
			directory_data->the_status = 2;
			return (1);
		}
		directory_data->the_status = (the_status % 256);
	}
	return (0);
}
