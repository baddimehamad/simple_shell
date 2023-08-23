#include "main.h"

/**
 * create_history - Creates a new command history.
 *
 * This function allocates memory for a new CommandHistory structure,
 * initializes its head and tail pointers to NULL, and returns the
 * newly created history.
 *
 * Return: A pointer to the newly created CommandHistory structure.
 */

CommandHistory *create_history()
{
	CommandHistory *history = (CommandHistory *)malloc(sizeof(CommandHistory));

	history->head = NULL;
	history->tail = NULL;
	return (history);
}

/**
 * add_to_history - Adds a command to the command history.
 * @history: A pointer to the CommandHistory structure.
 * @command: The command to be added to the history.
 *
 * This function creates a new CommandNode with the given command,
 * and adds it to the end of the command history. If the history
 * is empty, the new node becomes the head and the tail. Otherwise,
 * the new node is linked to the tail and becomes the new tail.
 *
 * Return: void.
 */

void add_to_history(CommandHistory *history, const char *command)
{
	CommandNode *newNode = (CommandNode *)malloc(sizeof(CommandNode));

	strcpy(newNode->command, command);
	newNode->next = NULL;

	if (history->head == NULL)
	{
		history->head = newNode;
		history->tail = newNode;
	}
	else
	{
		history->tail->next = newNode;
		history->tail = newNode;
	}
}

/**
 * print_history - Prints the command history.
 * @history: A pointer to the CommandHistory structure.
 *
 * This function traverses the command history linked list and prints
 * each command in the history, one per line.
 *
 * Return: void.
 */

void print_history(const CommandHistory *history)
{
	CommandNode *current = history->head;

	while (current != NULL)
	{
		_putstr(current->command);
		current = current->next;
	}
}

/**
 * clear_history - Clears the command history.
 * @history: A pointer to the CommandHistory structure.
 *
 * This function deallocates the memory used by the command history.
 * It iterates through the linked list, frees each node, and sets
 * the head and tail pointers to NULL.
 *
 * Return: void.
 */

void clear_history(CommandHistory *history)
{
	CommandNode *current = history->head;
	CommandNode *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	history->head = NULL;
	history->tail = NULL;
}
