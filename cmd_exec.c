#include "main.h"

/**
 * if_char_current 
 * @link: char pointer.
 * @the_index: the index.
 * Return: 1 or 0 .
 */
int if_char_current(char *link, int *the_index)
{
	if (link[*the_index] == ':')
		return (1);

	while (link[*the_index] != ':' && link[*the_index])
	{
		*the_index += 1;
	}

	if (link[*the_index])
		*the_index += 1;

	return (0);
}

/**
 * _the_cmd_location 
 *
 * @command: command
 * @_the_env: environment
 * Return: pointer.
 */
char *_the_cmd_location(char *command, char **_the_env)
{
	char *link, *pointer_link, *t_link, *the_directory;
	int length_d, length_c, the_index;
	struct stat status;

	link = the_envirement_type("PATH", _the_env);
	if (link)
	{
		pointer_link = duplicate_string(link);
		length_c = lenght_string(command);
		t_link = split_by_delimiter(pointer_link, ":");
		the_index = 0;
		while (t_link != NULL)
		{
			if (if_char_current(link, &the_index))
				if (stat(command, &status) == 0)
					return (command);
			length_d = lenght_string(t_link);
			the_directory = malloc(length_d + length_c + 2);
			string_copy(the_directory, t_link);
			concat_string(the_directory, "/");
			concat_string(the_directory, command);
			concat_string(the_directory, "\0");
			if (stat(the_directory, &status) == 0)
			{
				free(pointer_link);
				return (the_directory);
			}
			free(the_directory);
			t_link = split_by_delimiter(NULL, ":");
		}
		free(pointer_link);
		if (stat(command, &status) == 0)
			return (command);
		return (NULL);
	}
	if (command[0] == '/')
		if (stat(command, &status) == 0)
			return (command);
	return (NULL);
}

/**
 * if_exec - 
 *
 * @directory_data: data
 * Return: 0 
 */
int if_exec(data_shell *directory_data)
{
	struct stat status;
	int the_index;
	char *the_input;

	the_input = directory_data->args[0];
	for (the_index = 0; the_input[the_index]; the_index++)
	{
		if (the_input[the_index] == '.')
		{
			if (the_input[the_index + 1] == '.')
				return (0);
			if (the_input[the_index + 1] == '/')
				continue;
			else
				break;
		}
		else if (the_input[the_index] == '/' && the_index != 0)
		{
			if (the_input[the_index + 1] == '.')
				continue;
			the_index++;
			break;
		}
		else
			break;
	}
	if (the_index == 0)
		return (0);

	if (stat(the_input + the_index, &status) == 0)
	{
		return (the_index);
	}
	the_erreur_function(directory_data, 127);
	return (-1);
}

/**
 * erreur_command_check 
 *
 * @the_directory: destination
 * @directory_data: data
 * Return: 1 or 0
 */
int erreur_command_check(char *the_directory, data_shell *directory_data)
{
	if (the_directory == NULL)
	{
		the_erreur_function(directory_data, 127);
		return (1);
	}

	if (compare_strings(directory_data->args[0], the_directory) != 0)
	{
		if (access(the_directory, X_OK) == -1)
		{
			the_erreur_function(directory_data, 126);
			free(the_directory);
			return (1);
		}
		free(the_directory);
	}
	else
	{
		if (access(directory_data->args[0], X_OK) == -1)
		{
			the_erreur_function(directory_data, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * execute_commande 
 *
 * @directory_data: data 
 * Return: 1
 */
int execute_commande(data_shell *directory_data)
{
	pid_t pere_id;
	pid_t pere_id_t;
	int the_state;
	int the_execution;
	char *the_directory;
	(void) pere_id_t;

	the_execution = if_exec(directory_data);
	if (the_execution == -1)
		return (1);
	if (the_execution == 0)
	{
		the_directory = _the_cmd_location(directory_data->args[0], directory_data->the_env);
		if (erreur_command_check(the_directory, directory_data) == 1)
			return (1);
	}

	pere_id = fork();
	if (pere_id == 0)
	{
		if (the_execution == 0)
			the_directory = _the_cmd_location(directory_data->args[0], directory_data->the_env);
		else
			the_directory = directory_data->args[0];
		execve(the_directory + the_execution, directory_data->args, directory_data->the_env);
	}
	else if (pere_id < 0)
	{
		perror(directory_data->val_arg[0]);
		return (1);
	}
	else
	{
		do {
			pere_id_t = waitpid(pere_id, &the_state, WUNTRACED);
		} while (!WIFEXITED(the_state) && !WIFSIGNALED(the_state));
	}

	directory_data->the_status = the_state / 256;
	return (1);
}
