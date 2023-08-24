#include "main.h"

/**
 * compare_envirement_name 
 * @name_envirement: variable
 * @the_name: the_name 
 *
 * Return: 0 
 */
int compare_envirement_name(const char *name_envirement, const char *the_name)
{
	int x;

	for (x = 0; name_envirement[x] != '='; x++)
	{
		if (name_envirement[x] != the_name[x])
		{
			return (0);
		}
	}

	return (x + 1);
}

/**
 * the_envirement_type 
 * @the_name: variable
 * @the_environ: variable
 *
 * Return: value or NULL.
 */
char *the_envirement_type(const char *the_name, char **the_environ)
{
	char *pointer_envirement;
	int x, move;

	/* Initialize pointer_envirement value */
	pointer_envirement = NULL;
	move = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (x = 0; the_environ[x]; x++)
	{
		/* If the_name and env are equal */
		move = compare_envirement_name(the_environ[x], the_name);
		if (move)
		{
			pointer_envirement = the_environ[x];
			break;
		}
	}

	return (pointer_envirement + move);
}

/**
 * the__envirement_ - 
 *
 * @directory_data: data.
 * Return: 1
 */
int the__envirement_(data_shell *directory_data)
{
	int x, y;

	for (x = 0; directory_data->the_env[x]; x++)
	{

		for (y = 0; directory_data->the_env[x][y]; y++)
			;

		write(STDOUT_FILENO, directory_data->the_env[x], y);
		write(STDOUT_FILENO, "\n", 1);
	}
	directory_data->the_status = 0;

	return (1);
}
/**
 * information_copy -
 * @the_name: the the_name
 * @the_value: the the_value
 *
 * Return: string
 */
char *information_copy(char *the_name, char *the_value)
{
	char *_n_v;
	int size_name, size_value, size;

	size_name = lenght_string(the_name);
	size_value = lenght_string(the_value);
	size = size_name + size_value + 2;
	_n_v = malloc(sizeof(char) * (size));
	string_copy(_n_v, the_name);
	concat_string(_n_v, "=");
	concat_string(_n_v, the_value);
	concat_string(_n_v, "\0");

	return (_n_v);
}

/**
 * change_envirement 
 * @the_name: the name
 * @the_value: the value
 * @directory_data: data
 * Return: null
 */
void change_envirement(char *the_name, char *the_value, data_shell *directory_data)
{
	int x;
	char *the_env, *the_name_env;

	for (x = 0; directory_data->the_env[x]; x++)
	{
		the_env = duplicate_string(directory_data->the_env[x]);
		the_name_env = split_by_delimiter(the_env, "=");
		if (compare_strings(the_name_env, the_name) == 0)
		{
			free(directory_data->the_env[x]);
			directory_data->the_env[x] = information_copy(the_name_env, the_value);
			free(the_env);
			return;
		}
		free(the_env);
	}

	directory_data->the_env = the_re_alloc_double(directory_data->the_env, x, sizeof(char *) * (x + 2));
	directory_data->the_env[x] = information_copy(the_name, the_value);
	directory_data->the_env[x + 1] = NULL;
}

/**
 * the_change_envirement 
 * @directory_data: data
 *
 * Return: 1
 */
int the_change_envirement(data_shell *directory_data)
{

	if (directory_data->args[1] == NULL || directory_data->args[2] == NULL)
	{
		the_erreur_function(directory_data, -1);
		return (1);
	}

	change_envirement(directory_data->args[1], directory_data->args[2], directory_data);

	return (1);
}

/**
 * remove_envirement 
 * @directory_data: data
 *
 * Return: 1
 */
int remove_envirement(data_shell *directory_data)
{
	char **realloc_environ;
	char *the_env, *the_name_env;
	int x, j, k;

	if (directory_data->args[1] == NULL)
	{
		the_erreur_function(directory_data, -1);
		return (1);
	}
	k = -1;
	for (x = 0; directory_data->the_env[x]; x++)
	{
		the_env = duplicate_string(directory_data->the_env[x]);
		the_name_env = split_by_delimiter(the_env, "=");
		if (compare_strings(the_name_env, directory_data->args[1]) == 0)
		{
			k = x;
		}
		free(the_env);
	}
	if (k == -1)
	{
		the_erreur_function(directory_data, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (x));
	for (x = j = 0; directory_data->the_env[x]; x++)
	{
		if (x != k)
		{
			realloc_environ[j] = directory_data->the_env[x];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(directory_data->the_env[k]);
	free(directory_data->the_env);
	directory_data->the_env = realloc_environ;
	return (1);
}
