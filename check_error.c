#include "main.h"

/**
 * char_doubles - doubles of characters
 *
 * @the_input: string
 * @the_index: the index
 * Return: pointer
 */
int char_doubles(char *the_input, int the_index)
{
	if (*(the_input - 1) == *the_input)
		return (char_doubles(the_input - 1, the_index + 1));

	return (the_index);
}

/**
 * find_errurs_s - erreurs
 *
 * @the_input: string
 * @the_index: the index
 * @end_char: char
 * Return: 0 
 */
int find_errurs_s(char *the_input, int the_index, char end_char)
{
	int num;

	num = 0;
	if (*the_input == '\0')
		return (0);

	if (*the_input == ' ' || *the_input == '\t')
		return (find_errurs_s(the_input + 1, the_index + 1, end_char));

	if (*the_input == ';')
		if (end_char == '|' || end_char == '&' || end_char == ';')
			return (the_index);

	if (*the_input == '|')
	{
		if (end_char == ';' || end_char == '&')
			return (the_index);

		if (end_char == '|')
		{
			num = char_doubles(the_input, 0);
			if (num == 0 || num > 1)
				return (the_index);
		}
	}

	if (*the_input == '&')
	{
		if (end_char == ';' || end_char == '|')
			return (the_index);

		if (end_char == '&')
		{
			num = char_doubles(the_input, 0);
			if (num == 0 || num > 1)
				return (the_index);
		}
	}

	return (find_errurs_s(the_input + 1, the_index + 1, *the_input));
}

/**
 * the_char_1 - first character
 *
 * @the_input: string
 * @the_index: the index
 * Return: 1 or 0
 */
int the_char_1(char *the_input, int *the_index)
{

	for (*the_index = 0; the_input[*the_index]; *the_index += 1)
	{
		if (the_input[*the_index] == ' ' || the_input[*the_index] == '\t')
			continue;

		if (the_input[*the_index] == ';' || the_input[*the_index] == '|' || the_input[*the_index] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * echo_erreur_s - echo the erreur
 *
 * @directory_data: data
 * @the_input: string
 * @the_index: the index
 * @if_erreur: erreur
 * Return: no return
 */
void echo_erreur_s(data_shell *directory_data, char *the_input, int the_index, int if_erreur)
{
	char *message1, *message2, *message3, *err, *num;
	int length;

	if (the_input[the_index] == ';')
	{
		if (if_erreur == 0)
			message1 = (the_input[the_index + 1] == ';' ? ";;" : ";");
		else
			message1 = (the_input[the_index - 1] == ';' ? ";;" : ";");
	}

	if (the_input[the_index] == '|')
		message1 = (the_input[the_index + 1] == '|' ? "||" : "|");

	if (the_input[the_index] == '&')
		message1 = (the_input[the_index + 1] == '&' ? "&&" : "&");

	message2 = ": Syntax err: \"";
	message3 = "\" unexpected\n";
	num = convert_int_to_string(directory_data->nums);
	length = lenght_string(directory_data->val_arg[0]) + lenght_string(num);
	length += lenght_string(message1) + lenght_string(message2) + lenght_string(message3) + 2;

	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(num);
		return;
	}
	string_copy(err, directory_data->val_arg[0]);
	concat_string(err, ": ");
	concat_string(err, num);
	concat_string(err, message2);
	concat_string(err, message1);
	concat_string(err, message3);
	concat_string(err, "\0");

	write(STDERR_FILENO, err, length);
	free(err);
	free(num);
}

/**
 * check_erreur_s - function
 *
 * @directory_data: data
 * @the_input: string
 * Return: 1 or 0 
 */
int check_erreur_s(data_shell *directory_data, char *the_input)
{
	int first = 0;
	int first_character = 0;
	int the_index = 0;

	first_character = the_char_1(the_input, &first);
	if (first_character == -1)
	{
		echo_erreur_s(directory_data, the_input, first, 0);
		return (1);
	}

	the_index = find_errurs_s(the_input + first, 0, *(the_input + first));
	if (the_index != 0)
	{
		echo_erreur_s(directory_data, the_input, first + the_index, 1);
		return (1);
	}

	return (0);
}
