#include "main.h"

historique_c *the_history_create()
{
	historique_c *h = (historique_c *)malloc(sizeof(historique_c));

	h->head = NULL;
	h->tail = NULL;
	return (h);
}

void print_h(const historique_c *x)
{
	the_node *y = x->head;

	while (y != NULL)
	{
		string_put(y->command);
		y = y->next;
	}
}
void clear_h(historique_c *x)
{
	the_node *y = x->head;
	the_node *temp;

	while (y != NULL)
	{
		temp = y;
		y = y->next;
		free(temp);
	}
	x->head = NULL;
	x->tail = NULL;
}
void history_add(historique_c *x, const char *y)
{
	the_node *n = (the_node *)malloc(sizeof(the_node));

	string_copy(n->command, y);
	n->next = NULL;

	if (x->head == NULL)
	{
		x->head = n;
		x->tail = n;
	}
	else
	{
		x->tail->next = n;
		x->tail = n;
	}
}