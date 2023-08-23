#include "main.h"

int clear_console(void)
{
	string_put("\033[2J\033[H");
	return (0);
}

int commands_builtin(char *commands[64])
{
	if (compare_strings(commands[0], "cd", 3UL) == 0)
		return (change_folder(commands[1]));
	if (compare_strings(commands[0], "clear", 6UL) == 0)
		return (clear_console());
	if (compare_strings(commands[0], "env", 6UL) == 0)
		return (get_env());
	if (compare_strings(commands[0], "exit", 6UL) == 0 || compare_strings(commands[0], "^C", 3UL) == 0)
		exit(0);
	return (-1);
}
int get_env()
{
	char **env = environ;

	while (*env != NULL)
	{
		string_put(*env);
		string_put("\n");
		env++;
	}
	return (0);
}

void execution(int x, char **y, historique_c *the_historique)
{
	size_t t_len = 0;
	int i, u, num = 0;
	char *p;

	if (x > 0 && y != NULL)
	{
		for (i = 1; i < x; i++)
			t_len += strlen(y[i]) + 1;
		p = (char *)malloc(t_len);
		for (i = 1; i < x; i++)
		{
			u = 0;
			while (y[i][u] != '\0')
			{
				p[num] = y[i][u];
				num++;
				u++;
			}
			p[num] = ' ';
			num++;
		}
		p[num - 1] = '\0';
		the_exec_run(p, the_historique);
		free(p);
	}
}
