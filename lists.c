#include "main.h"

/**
 * separator_add - add a separator
 * @the_head: the_head 
 * @the_separator: separator 
 * Return: address.
 */
sep_list *separator_add(sep_list **the_head, char the_separator)
{
	sep_list *the_n_v, *tmp;

	the_n_v = malloc(sizeof(sep_list));
	if (the_n_v == NULL)
		return (NULL);

	the_n_v->separator = the_separator;
	the_n_v->next = NULL;
	tmp = *the_head;

	if (tmp == NULL)
	{
		*the_head = the_n_v;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = the_n_v;
	}

	return (*the_head);
}

/**
 * empty_separator_list - empty list
 * @the_head: the_head.
 * Return: null.
 */
void empty_separator_list(sep_list **the_head)
{
	sep_list *tmp;
	sep_list *current_v;

	if (the_head != NULL)
	{
		current_v = *the_head;
		while ((tmp = current_v) != NULL)
		{
			current_v = current_v->next;
			free(tmp);
		}
		*the_head = NULL;
	}
}

/**
 * add_line_end - add line at the end 
 * @the_head: the_head
 * @the_line: command
 * Return: address of the the_head.
 */
line_list *add_line_end(line_list **the_head, char *the_line)
{
	line_list *the_n_v, *tmp;

	the_n_v = malloc(sizeof(line_list));
	if (the_n_v == NULL)
		return (NULL);

	the_n_v->line = the_line;
	the_n_v->next = NULL;
	tmp = *the_head;

	if (tmp == NULL)
	{
		*the_head = the_n_v;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = the_n_v;
	}

	return (*the_head);
}

/**
 * empty_list - empty list
 * @the_head: the_head.
 * Return: no return.
 */
void empty_list(line_list **the_head)
{
	line_list *tmp;
	line_list *current_v;

	if (the_head != NULL)
	{
		current_v = *the_head;
		while ((tmp = current_v) != NULL)
		{
			current_v = current_v->next;
			free(tmp);
		}
		*the_head = NULL;
	}
}

/**
 * add_var - add variable
 * @the_head: the_head of the linked list.
 * @len_var: variable length.
 * @val_var: variable value.
 * @len_val: value length.
 * Return: address.
 */
r_var *add_var(r_var **the_head, int len_var, char *val_var, int len_val)
{
	r_var *_n_v, *tmp;

	_n_v = malloc(sizeof(r_var));
	if (_n_v == NULL)
		return (NULL);

	_n_v->len_var = len_var;
	_n_v->val = val_var;
	_n_v->len_val = len_val;

	_n_v->next = NULL;
	tmp = *the_head;

	if (tmp == NULL)
	{
		*the_head = _n_v;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = _n_v;
	}

	return (*the_head);
}

/**
 * empty_var_list - empty list
 * @the_head: the_head of the linked list.
 * Return: no return.
 */
void empty_var_list(r_var **the_head)
{
	r_var *tmp;
	r_var *current_val;

	if (the_head != NULL)
	{
		current_val = *the_head;
		while ((tmp = current_val) != NULL)
		{
			current_val = current_val->next;
			free(tmp);
		}
		*the_head = NULL;
	}
}
