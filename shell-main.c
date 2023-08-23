#include "main.h"

/**
 * find_command_path - a function that takes a command as input,
 * searches for the command in the directories specified in the
 * PATH environment variable, and returns the full
 * path of the command if found
 * @buffer: ...
 * Return: void.
 */

char *find_command_path(char *buffer)
{
	char *path = _getenv0("PATH");
	char *copy_path = _strdup(path);
	char *token;
	char *cmd = strtok(buffer, " ");
	char full_path[BUFFER_SIZE];

	if (_strchr(buffer, '/') != NULL)
		return (cmd);
	token = strtok(copy_path, ":");
	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, cmd);
		if (access(full_path, X_OK) == 0)
		{
			return (_strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	free(copy_path);
	return (cmd);
}

/**
 * change_directory - change current directory.
 * @path: ...
 * Return: int.
 */

int change_directory(char *path)
{
	char *dir = path;
	char *HOME = _getenv0("HOME");
	size_t len;

	if (dir == ((void *)0) || *dir == '~')
		dir = HOME;
	len = _strlen(dir);
	if (len > 0 && dir[len - 1] == '\n')
		dir[len - 1] = '\0';
	if (chdir(dir) != 0 || _setenv("PWD", dir) == -1)
		return (-1);
	return (0);
}

/**
 * run - constract comand from buffer and execute it,
 * @buffer: ...
 * @history: ...
 * Return: void.
 */

void run(char *buffer, CommandHistory *history)
{
	int i, status = 0;
	char *cmds[64] = {NULL};
	pid_t pid;

	cmds[0] = strtok(buffer, " ");
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (pid == 0)
		{
			for (i = 1; i < 64; i++)
			{
				cmds[i] = strtok(NULL, " ");
				if (cmds[i] == NULL)
					break;
			}
			if (switch_builtin_command(cmds) == 0)
				return;
			add_to_history(history, cmds[0]);
			cmds[0] = find_command_path(buffer);
			execve(cmds[0], cmds, environ);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
}

/**
 * main - simple shell
 * @ac: arg count.
 * @av: arg array.
 * Return: int()status.
 */

int main(int ac, char **av)
{
	char current_directory[BUFFER_SIZE];

	char *lineptr = NULL;
	char *user = NULL;
	size_t len = 0;
	ssize_t read;
	size_t n = 64;
	CommandHistory *history = create_history();

	if (_getenv0("USER"))
		user = _getenv0("USER");
	else if (_getenv0("HOSTNAME"))
		user = _getenv0("HOSTNAME");
	else
		user = "root";
	(void)user;
	clear_screen();
	handle_exec(ac, av, history);
	while (1)
	{
		getcwd(current_directory, sizeof(current_directory));
		_putstr("#cisfun$ ");
		fflush(stdout);
		lineptr = (char *)malloc(n);
		read = getline(&lineptr, &n, stdin);
		if (read == -1)
			break;
		len = _strlen(lineptr);
		if (len > 0 && lineptr[len - 1] == '\n')
			lineptr[len - 1] = '\0';
		if (_strncmp(lineptr, "exit", 5UL) == 0)
			break;
		run(lineptr, history);
		free(lineptr);
	}

	return (EXIT_SUCCESS);
}
