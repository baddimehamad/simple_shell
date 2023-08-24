#include "main.h"

/**
 * the_empty_data_function - empty data
 *
 * @directory_data: data
 * Return: null
 */
void the_empty_data_function(data_shell *directory_data)
{
	unsigned int x;

	for (x = 0; directory_data->the_env[x]; x++)
	{
		free(directory_data->the_env[x]);
	}

	free(directory_data->the_env);
	free(directory_data->pere_id);
}

/**
 * init_the_data - init data
 *
 * @directory_data: data
 * @val_arg: value
 * Return: null
 */
void init_the_data(data_shell *directory_data, char **val_arg)
{
	unsigned int x;

	directory_data->val_arg = val_arg;
	directory_data->the_input = NULL;
	directory_data->args = NULL;
	directory_data->the_status = 0;
	directory_data->nums = 1;

	for (x = 0; environ[x]; x++)
		;

	directory_data->the_env = malloc(sizeof(char *) * (x + 1));

	for (x = 0; environ[x]; x++)
	{
		directory_data->the_env[x] = duplicate_string(environ[x]);
	}

	directory_data->the_env[x] = NULL;
	directory_data->pere_id = convert_int_to_string(getpid());
}

/**
 * main - Entry point
 *
 * @val_num: value number
 * @val_arg: value argumantes
 *
 * Return: 0
 */
int main(int val_num, char **val_arg)
{
	data_shell directory_data;
	(void) val_num;

	signal(SIGINT, handler_fun);
	init_the_data(&directory_data, val_arg);
	the_loop_shell(&directory_data);
	the_empty_data_function(&directory_data);
	if (directory_data.the_status < 0)
		return (255);
	return (directory_data.the_status);
}
