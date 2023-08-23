#include "main.h"

/**
 * clear_screen - constract comand from buffer and execute it,
 * Return: void.
 */

int clear_screen(void)
{
	_putstr("\033[2J\033[H");
	return (0);
}

/**
 * switch_builtin_command - Execute actions based on input command.
 *
 * This function takes an input command as a string and uses a switch
 * statement to determine the appropriate action based on the command.
 * It compares the command with different built-in commands and executes
 * the corresponding code block for the matching command.
 *
 * @cmds: The input command and args to switch.
 * Return: int.
 */
int switch_builtin_command(char *cmds[64])
{
	if (_strncmp(cmds[0], "cd", 3UL) == 0)
		return (change_directory(cmds[1]));
	if (_strncmp(cmds[0], "clear", 6UL) == 0)
		return (clear_screen());
	if (_strncmp(cmds[0], "env", 6UL) == 0)
		return (print_environment());
	if (_strncmp(cmds[0], "exit", 6UL) == 0 || _strncmp(cmds[0], "^C", 3UL) == 0)
		exit(0);
	return (-1);
}

/**
 * handle_exec - find if args and exec the comand.
 * @ac: args count
 * @av: args values
 * @history: passed linked list
 * Return: void.
 */

void handle_exec(int ac, char **av, CommandHistory *history)
{
	size_t total_length = 0;
	int k, j, n = 0;
	char *lineptr;

	if (ac > 0 && av != NULL)
	{
		for (k = 1; k < ac; k++)
			total_length += strlen(av[k]) + 1;
		lineptr = (char *)malloc(total_length);
		for (k = 1; k < ac; k++)
		{
			j = 0;
			while (av[k][j] != '\0')
			{
				lineptr[n] = av[k][j];
				n++;
				j++;
			}
			lineptr[n] = ' ';
			n++;
		}
		lineptr[n - 1] = '\0';
		run(lineptr, history);
		free(lineptr);
	}
}

/**
 * print_environment - function that prints the environment
 * variables.
 * Return: void.
 */

int print_environment()
{
	char **env = environ;

	while (*env != NULL)
	{
		_putstr(*env);
		_putstr("\n");
		env++;
	}
	return (0);
}
