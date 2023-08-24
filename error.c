#include "main.h"

/**
 * string_cat_cd -function
 *
 * @data_direc: data
 * @message: message
 * @erreur: erreur message
 * @c_line: nums lines
 * Return: message
 */
char *string_cat_cd(data_shell *data_direc, char *message, char *erreur, char *c_line)
{
	char *flag;

	string_copy(erreur, data_direc->val_arg[0]);
	concat_string(erreur, ": ");
	concat_string(erreur, c_line);
	concat_string(erreur, ": ");
	concat_string(erreur, data_direc->args[0]);
	concat_string(erreur, message);
	if (data_direc->args[1][0] == '-')
	{
		flag = malloc(3);
		flag[0] = '-';
		flag[1] = data_direc->args[1][1];
		flag[2] = '\0';
		concat_string(erreur, flag);
		free(flag);
	}
	else
	{
		concat_string(erreur, data_direc->args[1]);
	}

	concat_string(erreur, "\n");
	concat_string(erreur, "\0");
	return (erreur);
}

/**
 * cd_erreur - message d'eerur cd
 * @data_direc: data
 * Return: Error message
 */
char *cd_erreur(data_shell *data_direc)
{
	int l, len_id;
	char *erreur, *c_line, *message;

	c_line = convert_int_to_string(data_direc->nums);
	if (data_direc->args[1][0] == '-')
	{
		message = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		message = ": can't cd to ";
		len_id = lenght_string(data_direc->args[1]);
	}

	l = lenght_string(data_direc->val_arg[0]) + lenght_string(data_direc->args[0]);
	l += lenght_string(c_line) + lenght_string(message) + len_id + 5;
	erreur = malloc(sizeof(char) * (l + 1));

	if (erreur == 0)
	{
		free(c_line);
		return (NULL);
	}

	erreur = string_cat_cd(data_direc, message, erreur, c_line);

	free(c_line);

	return (erreur);
}

/**
 * erreur_null - erreur null
 * @data_direc: data
 * Return: Error message
 */
char *erreur_null(data_shell *data_direc)
{
	int l;
	char *erreur;
	char *c_line;

	c_line = convert_int_to_string(data_direc->nums);
	l = lenght_string(data_direc->val_arg[0]) + lenght_string(c_line);
	l += lenght_string(data_direc->args[0]) + 16;
	erreur = malloc(sizeof(char) * (l + 1));
	if (erreur == 0)
	{
		free(erreur);
		free(c_line);
		return (NULL);
	}
	string_copy(erreur, data_direc->val_arg[0]);
	concat_string(erreur, ": ");
	concat_string(erreur, c_line);
	concat_string(erreur, ": ");
	concat_string(erreur, data_direc->args[0]);
	concat_string(erreur, ": not found\n");
	concat_string(erreur, "\0");
	free(c_line);
	return (erreur);
}

/**
 * error_exit_shell - generic erreur message for exit in get_exit
 * @data_direc: data
 *
 * Return: Error message
 */
char *error_exit_shell(data_shell *data_direc)
{
	int l;
	char *erreur;
	char *c_line;

	c_line = convert_int_to_string(data_direc->nums);
	l = lenght_string(data_direc->val_arg[0]) + lenght_string(c_line);
	l += lenght_string(data_direc->args[0]) + lenght_string(data_direc->args[1]) + 23;
	erreur = malloc(sizeof(char) * (l + 1));
	if (erreur == 0)
	{
		free(c_line);
		return (NULL);
	}
	string_copy(erreur, data_direc->val_arg[0]);
	concat_string(erreur, ": ");
	concat_string(erreur, c_line);
	concat_string(erreur, ": ");
	concat_string(erreur, data_direc->args[0]);
	concat_string(erreur, ": Illegal number: ");
	concat_string(erreur, data_direc->args[1]);
	concat_string(erreur, "\n\0");
	free(c_line);

	return (erreur);
}
/**
 * erreur_envirement - message
 * @data_direc: data
 * Return: erreur .
 */
char *erreur_envirement(data_shell *data_direc)
{
	int erreur_envirement;
	char *erreur;
	char *c_line;
	char *message;

	c_line = convert_int_to_string(data_direc->nums);
	message = ": Unable to add/remove from environment\n";
	erreur_envirement = lenght_string(data_direc->val_arg[0]) + lenght_string(c_line);
	erreur_envirement += lenght_string(data_direc->args[0]) + lenght_string(message) + 4;
	erreur = malloc(sizeof(char) * (erreur_envirement + 1));
	if (erreur == 0)
	{
		free(erreur);
		free(c_line);
		return (NULL);
	}

	string_copy(erreur, data_direc->val_arg[0]);
	concat_string(erreur, ": ");
	concat_string(erreur, c_line);
	concat_string(erreur, ": ");
	concat_string(erreur, data_direc->args[0]);
	concat_string(erreur, message);
	concat_string(erreur, "\0");
	free(c_line);

	return (erreur);
}
/**
 * erreur_link_126 -  message
 * @data_direc: data
 *
 * Return: erreur .
 */
char *erreur_link_126(data_shell *data_direc)
{
	int erreur_envirement;
	char *c_line;
	char *erreur;

	c_line = convert_int_to_string(data_direc->nums);
	erreur_envirement = lenght_string(data_direc->val_arg[0]) + lenght_string(c_line);
	erreur_envirement += lenght_string(data_direc->args[0]) + 24;
	erreur = malloc(sizeof(char) * (erreur_envirement + 1));
	if (erreur == 0)
	{
		free(erreur);
		free(c_line);
		return (NULL);
	}
	string_copy(erreur, data_direc->val_arg[0]);
	concat_string(erreur, ": ");
	concat_string(erreur, c_line);
	concat_string(erreur, ": ");
	concat_string(erreur, data_direc->args[0]);
	concat_string(erreur, ": Permission denied\n");
	concat_string(erreur, "\0");
	free(c_line);
	return (erreur);
}
