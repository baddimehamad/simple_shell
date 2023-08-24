#include "main.h"

/**
 * the_envirement_c 
 * @het: list
 * @the_text:  string
 * @the_data: the_data 
 * Return: null
 */
void the_envirement_c(r_var **het, char *the_text, data_shell *the_data)
{
	int horis, characters, x, line_val;
	char **the_envir;

	the_envir = the_data->the_env;
	for (horis = 0; the_envir[horis]; horis++)
	{
		for (x = 1, characters = 0; the_envir[horis][characters]; characters++)
		{
			if (the_envir[horis][characters] == '=')
			{
				line_val = lenght_string(the_envir[horis] + characters + 1);
				add_var(het, x, the_envir[horis] + characters + 1, line_val);
				return;
			}

			if (the_text[x] == the_envir[horis][characters])
				x++;
			else
				break;
		}
	}

	for (x = 0; the_text[x]; x++)
	{
		if (the_text[x] == ' ' || the_text[x] == '\t' || the_text[x] == ';' || the_text[x] == '\n')
			break;
	}

	add_var(het, x, NULL, 0);
}

/**
 * the_v_cks 
 *
 * @het: list
 * @the_text: string
 * @the_status: the_status
 * @the_data: data 
 * Return: null
 */
int the_v_cks(r_var **het, char *the_text, char *the_status, data_shell *the_data)
{
	int x, last, last_pointer;

	last = lenght_string(the_status);
	last_pointer = lenght_string(the_data->pere_id);

	for (x = 0; the_text[x]; x++)
	{
		if (the_text[x] == '$')
		{
			if (the_text[x + 1] == '?')
				add_var(het, 2, the_status, last), x++;
			else if (the_text[x + 1] == '$')
				add_var(het, 2, the_data->pere_id, last_pointer), x++;
			else if (the_text[x + 1] == '\n')
				add_var(het, 0, NULL, 0);
			else if (the_text[x + 1] == '\0')
				add_var(het, 0, NULL, 0);
			else if (the_text[x + 1] == ' ')
				add_var(het, 0, NULL, 0);
			else if (the_text[x + 1] == '\t')
				add_var(het, 0, NULL, 0);
			else if (the_text[x + 1] == ';')
				add_var(het, 0, NULL, 0);
			else
				the_envirement_c(het, the_text + x, the_data);
		}
	}

	return (x);
}

/**
 * the_text_replaced 
 * @the_head: list
 * @the_text: string
 * @new_input:string
 * @the_size: length
 * Return: string
 */
char *the_text_replaced(r_var **the_head, char *the_text, char *new_input, int the_size)
{
	r_var *the_ind;
	int x, y, z;

	the_ind = *the_head;
	for (y = x = 0; x < the_size; x++)
	{
		if (the_text[y] == '$')
		{
			if (!(the_ind->len_var) && !(the_ind->len_val))
			{
				new_input[x] = the_text[y];
				y++;
			}
			else if (the_ind->len_var && !(the_ind->len_val))
			{
				for (z = 0; z < the_ind->len_var; z++)
					y++;
				x--;
			}
			else
			{
				for (z = 0; z < the_ind->len_val; z++)
				{
					new_input[x] = the_ind->val[z];
					x++;
				}
				y += (the_ind->len_var);
				x--;
			}
			the_ind = the_ind->next;
		}
		else
		{
			new_input[x] = the_text[y];
			y++;
		}
	}

	return (new_input);
}

/**
 * the_rep_var 
 *
 * @the_text: string
 * @directory_data: data 
 * Return: string
 */
char *the_rep_var(char *the_text, data_shell *directory_data)
{
	r_var *the_head, *the_ind;
	char *the_status, *new_in;
	int o_size, the_size;

	the_status = convert_int_to_string(directory_data->the_status);
	the_head = NULL;

	o_size = the_v_cks(&the_head, the_text, the_status, directory_data);

	if (the_head == NULL)
	{
		free(the_status);
		return (the_text);
	}

	the_ind = the_head;
	the_size = 0;

	while (the_ind != NULL)
	{
		the_size += (the_ind->len_val - the_ind->len_var);
		the_ind = the_ind->next;
	}

	the_size += o_size;

	new_in = malloc(sizeof(char) * (the_size + 1));
	new_in[the_size] = '\0';

	new_in = the_text_replaced(&the_head, the_text, new_in, the_size);

	free(the_text);
	free(the_status);
	empty_var_list(&the_head);

	return (new_in);
}
