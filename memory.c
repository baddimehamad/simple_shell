#include "main.h"

/**
 * _copy_memory - copies data  pointers.
 * @new_pointer: destination .
 * @pointer: source .
 * @the_size: the_size.
 *
 * Return: null.
 */
void _copy_memory(void *new_pointer, const void *pointer, unsigned int the_size)
{
	char *pointer_char = (char *)pointer;
	char *new_pointer_char = (char *)new_pointer;
	unsigned int x;

	for (x = 0; x < the_size; x++)
		new_pointer_char[x] = pointer_char[x];
}

/**
 * the_re_alloc - reallocate the memory .
 * @pointer: pointer
 * @the_old_size: the_size
 * @the_new_size: the new size
 *
 * Return: pointer.
 */
void *the_re_alloc(void *pointer, unsigned int the_old_size, unsigned int the_new_size)
{
	void *new_pointer;

	if (pointer == NULL)
		return (malloc(the_new_size));

	if (the_new_size == 0)
	{
		free(pointer);
		return (NULL);
	}

	if (the_new_size == the_old_size)
		return (pointer);

	new_pointer = malloc(the_new_size);
	if (new_pointer == NULL)
		return (NULL);

	if (the_new_size < the_old_size)
		_copy_memory(new_pointer, pointer, the_new_size);
	else
		_copy_memory(new_pointer, pointer, the_old_size);

	free(pointer);
	return (new_pointer);
}

/**
 * the_re_alloc_double - double pointer.
 * @pointer: pointer
 * @the_old_size: old size
 * @the_new_size: new size
 *
 * Return: pointer.
 */
char **the_re_alloc_double(char **pointer, unsigned int the_old_size, unsigned int the_new_size)
{
	char **new_pointer;
	unsigned int x;

	if (pointer == NULL)
		return (malloc(sizeof(char *) * the_new_size));

	if (the_new_size == the_old_size)
		return (pointer);

	new_pointer = malloc(sizeof(char *) * the_new_size);
	if (new_pointer == NULL)
		return (NULL);

	for (x = 0; x < the_old_size; x++)
		new_pointer[x] = pointer[x];

	free(pointer);

	return (new_pointer);
}
