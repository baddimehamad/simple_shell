#include "main.h"
char *link_find(char *b)
{
	char *link = env_0("PATH");
	char *link_copy = string_dump(link);
	char *the_token;
	char *the_command = strtok(b, " ");
	char all_link[BUFFER_SIZE];

	if (string_to_chars(b, '/') != NULL)
		return (the_command);
	the_token = strtok(link_copy, ":");
	while (the_token != NULL)
	{
		snprintf(all_link, sizeof(all_link), "%s/%s", the_token, the_command);
		if (access(all_link, X_OK) == 0)
		{
			return (string_dump(all_link));
		}
		the_token = strtok(NULL, ":");
	}
	free(link_copy);
	return (the_command);
}


int change_folder(char *link)
{
	char *the_directory = link;
	char *the_home = env_0("HOME");
	size_t lenght;

	if (the_directory == ((void *)0) || *the_directory == '~')
		the_directory = the_home;
	lenght = lenght_string(the_directory);
	if (lenght > 0 && the_directory[lenght - 1] == '\n')
		the_directory[lenght - 1] = '\0';
	if (chdir(the_directory) != 0 || envirement_set("PWD", the_directory) == -1)
		return (-1);
	return (0);
}


void the_exec_run(char *x, historique_c *the_history)
{
	int i, the_status = 0;
	char *commands[64] = {NULL};
	pid_t pere_id;

	commands[0] = strtok(x, " ");
	pere_id = fork();
	if (pere_id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (pere_id == 0)
		{
			for (i = 1; i < 64; i++)
			{
				commands[i] = strtok(NULL, " ");
				if (commands[i] == NULL)
					break;
			}
			if (commands_builtin(commands) == 0)
				return;
			history_add(the_history, commands[0]);
			commands[0] = link_find(x);
			execve(commands[0], commands, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&the_status);
		}
	}
}


int main(int x, char **y)
{
	char current_directory[BUFFER_SIZE];

	char *the_line_pointer = NULL;
	char *user_type = NULL;
	size_t lenght = 0;
	ssize_t z;
	size_t n = 64;
	historique_c *the_history = the_history_create();

	if (env_0("USER"))
		user_type = env_0("USER");
	else if (env_0("HOSTNAME"))
		user_type = env_0("HOSTNAME");
	else
		user_type = "root";
	(void)user_type;
	clear_console();
	execution(x, y, the_history);
	while (1)
	{
		getcwd(current_directory, sizeof(current_directory));
		string_put("#cisfun$ ");
		fflush(stdout);
		the_line_pointer = (char *)malloc(n);
		z = getline(&the_line_pointer, &n, stdin);
		if (z == -1)
			break;
		lenght = lenght_string(the_line_pointer);
		if (lenght > 0 && the_line_pointer[lenght - 1] == '\n')
			the_line_pointer[lenght - 1] = '\0';
		if (compare_strings(the_line_pointer, "exit", 5UL) == 0)
			break;
		the_exec_run(the_line_pointer, the_history);
		free(the_line_pointer);
	}

	return (EXIT_SUCCESS);
}
