#include "main.h"

/**
 * help_built - get help for builtin
 * Return: null
 */
void help_built(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, lenght_string(help));
	help = "Print enviroment.\n";
	write(STDOUT_FILENO, help, lenght_string(help));

}
/**
 * help_built_set - get help for builtin
 * Return: null
 */
void help_built_set(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, lenght_string(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, lenght_string(help));
	help = "Add  definition to env\n";
	write(STDOUT_FILENO, help, lenght_string(help));
}
/**
 * help_built_unset - get help for builtin
 * Return: no return
 */
void help_built_unset(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, lenght_string(help));
	help = "Remove  entry completely anv\n";
	write(STDOUT_FILENO, help, lenght_string(help));
}


/**
 * help_built_global - get help for builtin
 * Return: null
 */
void help_built_global(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, lenght_string(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, lenght_string(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, lenght_string(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, lenght_string(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, lenght_string(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, lenght_string(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, lenght_string(help));
}
/**
 * help_built_exit - get help for builtin
 * Return: null
 */
void help_built_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, lenght_string(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, lenght_string(help));
	help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, help, lenght_string(help));
}
/**
 * help_built_fun - get help for builtin
 * Return: null
 */
void help_built_fun(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, lenght_string(help));
	help = "\tDisplay information.\n ";
	write(STDOUT_FILENO, help, lenght_string(help));
	help = "Displays brief summaries.\n";
	write(STDOUT_FILENO, help, lenght_string(help));
}
/**
 * help_built_a - get help for builtin
 * Return: null
 */
void help_built_a(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, lenght_string(help));
	help = "\tDefine or display aliase.\n ";
	write(STDOUT_FILENO, help, lenght_string(help));
}
/**
 * help_built_cd - get help for builtin
 * Return: null
 */
void help_built_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, lenght_string(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, lenght_string(help));
}
