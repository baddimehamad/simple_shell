#include "main.h"

/**
 * parent_directory - parent directory
 *
 * @directory_data: data 
 *
 * Return: null
 */
void parent_directory(data_shell *directory_data)
{
	char password[PATH_MAX];
	char *the_directory, *pawwsord_cpy, *password_split;

	getcwd(password, sizeof(password));
	pawwsord_cpy = duplicate_string(password);
	change_envirement("OLDPWD", pawwsord_cpy, directory_data);
	the_directory = directory_data->args[1];
	if (compare_strings(".", the_directory) == 0)
	{
		change_envirement("PWD", pawwsord_cpy, directory_data);
		free(pawwsord_cpy);
		return;
	}
	if (compare_strings("/", pawwsord_cpy) == 0)
	{
		free(pawwsord_cpy);
		return;
	}
	password_split = pawwsord_cpy;
	string_reverse(password_split);
	password_split = split_by_delimiter(password_split, "/");
	if (password_split != NULL)
	{
		password_split = split_by_delimiter(NULL, "\0");

		if (password_split != NULL)
			string_reverse(password_split);
	}
	if (password_split != NULL)
	{
		chdir(password_split);
		change_envirement("PWD", password_split, directory_data);
	}
	else
	{
		chdir("/");
		change_envirement("PWD", "/", directory_data);
	}
	directory_data->the_status = 0;
	free(pawwsord_cpy);
}

/**
 * enter_to - enter directory
 *
 * @directory_data: data
 * Return: null
 */
void enter_to(data_shell *directory_data)
{
	char password[PATH_MAX];
	char *the_directory, *pawwsord_cpy, *copy_directory;

	getcwd(password, sizeof(password));

	the_directory = directory_data->args[1];
	if (chdir(the_directory) == -1)
	{
		the_erreur_function(directory_data, 2);
		return;
	}

	pawwsord_cpy = duplicate_string(password);
	change_envirement("OLDPWD", pawwsord_cpy, directory_data);

	copy_directory = duplicate_string(the_directory);
	change_envirement("PWD", copy_directory, directory_data);

	free(pawwsord_cpy);
	free(copy_directory);

	directory_data->the_status = 0;

	chdir(the_directory);
}

/**
 * return_to_old_dir - changes to the previous directory
 *
 * @directory_data: data relevant (environ)
 * Return: no return
 */
void return_to_old_dir(data_shell *directory_data)
{
	char password[PATH_MAX];
	char *pointer_password, *pointer_oldpassword, *pawwsord_cpy, *old_password_copy;

	getcwd(password, sizeof(password));
	pawwsord_cpy = duplicate_string(password);

	pointer_oldpassword = the_envirement_type("OLDPWD", directory_data->the_env);

	if (pointer_oldpassword == NULL)
		old_password_copy = pawwsord_cpy;
	else
		old_password_copy = duplicate_string(pointer_oldpassword);

	change_envirement("OLDPWD", pawwsord_cpy, directory_data);

	if (chdir(old_password_copy) == -1)
		change_envirement("PWD", pawwsord_cpy, directory_data);
	else
		change_envirement("PWD", old_password_copy, directory_data);

	pointer_password = the_envirement_type("PWD", directory_data->the_env);

	write(STDOUT_FILENO, pointer_password, lenght_string(pointer_password));
	write(STDOUT_FILENO, "\n", 1);

	free(pawwsord_cpy);
	if (pointer_oldpassword)
		free(old_password_copy);

	directory_data->the_status = 0;

	chdir(pointer_password);
}

/**
 * go_home - changes to home_path directory
 *
 * @directory_data: data relevant (environ)
 * Return: no return
 */
void go_home(data_shell *directory_data)
{
	char *pointer_password, *home_path;
	char password[PATH_MAX];

	getcwd(password, sizeof(password));
	pointer_password = duplicate_string(password);

	home_path = the_envirement_type("HOME", directory_data->the_env);

	if (home_path == NULL)
	{
		change_envirement("OLDPWD", pointer_password, directory_data);
		free(pointer_password);
		return;
	}

	if (chdir(home_path) == -1)
	{
		the_erreur_function(directory_data, 2);
		free(pointer_password);
		return;
	}

	change_envirement("OLDPWD", pointer_password, directory_data);
	change_envirement("PWD", home_path, directory_data);
	free(pointer_password);
	directory_data->the_status = 0;
}
