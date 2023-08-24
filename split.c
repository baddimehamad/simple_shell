#include "main.h"

/**
 * change_char_sw 
 * @_the_input: string
 * @check: value
 * Return: string
 */
char *change_char_sw(char *_the_input, int check)
{
	int x;

	if (check == 0)
	{
		for (x = 0; _the_input[x]; x++)
		{
			if (_the_input[x] == '|')
			{
				if (_the_input[x + 1] != '|')
					_the_input[x] = 16;
				else
					x++;
			}

			if (_the_input[x] == '&')
			{
				if (_the_input[x + 1] != '&')
					_the_input[x] = 12;
				else
					x++;
			}
		}
	}
	else
	{
		for (x = 0; _the_input[x]; x++)
		{
			_the_input[x] = (_the_input[x] == 16 ? '|' : _the_input[x]);
			_the_input[x] = (_the_input[x] == 12 ? '&' : _the_input[x]);
		}
	}
	return (_the_input);
}

/**
 * add_separator_cmd - add separators and command lines in the lists
 *
 * @the_head_seperator: the_head of separator list
 * @the_head_line_command: the_head of command lines list
 * @_the_input: string
 * Return: no return
 */
void add_separator_cmd(sep_list **the_head_seperator, line_list **the_head_line_command, char *_the_input)
{
	int x;
	char *ligne;

	_the_input = change_char_sw(_the_input, 0);

	for (x = 0; _the_input[x]; x++)
	{
		if (_the_input[x] == ';')
			separator_add(the_head_seperator, _the_input[x]);

		if (_the_input[x] == '|' || _the_input[x] == '&')
		{
			separator_add(the_head_seperator, _the_input[x]);
			x++;
		}
	}

	ligne = split_by_delimiter(_the_input, ";|&");
	do {
		ligne = change_char_sw(ligne, 1);
		add_line_end(the_head_line_command, ligne);
		ligne = split_by_delimiter(NULL, ";|&");
	} while (ligne != NULL);

}

/**
 * the_go_next 
 * @liste_separator: value
 * @list_line: value
 * @directory_data: data
 * Return: null
 */
void the_go_next(sep_list **liste_separator, line_list **list_line, data_shell *directory_data)
{
	int the_loop_sep;
	sep_list *the_ls_s;
	line_list *the_ls_l;

	the_loop_sep = 1;
	the_ls_s = *liste_separator;
	the_ls_l = *list_line;

	while (the_ls_s != NULL && the_loop_sep)
	{
		if (directory_data->the_status == 0)
		{
			if (the_ls_s->separator == '&' || the_ls_s->separator == ';')
				the_loop_sep = 0;
			if (the_ls_s->separator == '|')
				the_ls_l = the_ls_l->next, the_ls_s = the_ls_s->next;
		}
		else
		{
			if (the_ls_s->separator == '|' || the_ls_s->separator == ';')
				the_loop_sep = 0;
			if (the_ls_s->separator == '&')
				the_ls_l = the_ls_l->next, the_ls_s = the_ls_s->next;
		}
		if (the_ls_s != NULL && !the_loop_sep)
			the_ls_s = the_ls_s->next;
	}

	*liste_separator = the_ls_s;
	*list_line = the_ls_l;
}

/**
 * the_split_commands 
 * @directory_data: data
 * @_the_input: string
 * Return: 0 or 1 
 */
int the_split_commands(data_shell *directory_data, char *_the_input)
{

	sep_list *the_head_seperator, *liste_separator;
	line_list *the_head_line_command, *list_line;
	int the_loop;

	the_head_seperator = NULL;
	the_head_line_command = NULL;

	add_separator_cmd(&the_head_seperator, &the_head_line_command, _the_input);

	liste_separator = the_head_seperator;
	list_line = the_head_line_command;

	while (list_line != NULL)
	{
		directory_data->the_input = list_line->line;
		directory_data->args = the_split_line(directory_data->the_input);
		the_loop = execute_command(directory_data);
		free(directory_data->args);

		if (the_loop == 0)
			break;

		the_go_next(&liste_separator, &list_line, directory_data);

		if (list_line != NULL)
			list_line = list_line->next;
	}

	empty_separator_list(&the_head_seperator);
	empty_list(&the_head_line_command);

	if (the_loop == 0)
		return (0);
	return (1);
}

/**
 * the_split_line 
 * @_the_input: string.
 * Return: string.
 */
char **the_split_line(char *_the_input)
{
	size_t buff_size;
	size_t x;
	char **the_tokens;
	char *the_token;

	buff_size = TOK_BUFSIZE;
	the_tokens = malloc(sizeof(char *) * (buff_size));
	if (the_tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	the_token = split_by_delimiter(_the_input, TOK_DELIM);
	the_tokens[0] = the_token;

	for (x = 1; the_token != NULL; x++)
	{
		if (x == buff_size)
		{
			buff_size += TOK_BUFSIZE;
			the_tokens = the_re_alloc_double(the_tokens, x, sizeof(char *) * buff_size);
			if (the_tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		the_token = split_by_delimiter(NULL, TOK_DELIM);
		the_tokens[x] = the_token;
	}

	return (the_tokens);
}
