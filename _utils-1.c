#include "main.h"

/**
 * _strrealloc - resize the memory block of a string
 * @ptr: pointer to the memory block to be resized
 * @size: new size for the memory block
 * Return: pointer to the resized memory block, or NULL on failure
 */
char *_strrealloc(char *ptr, size_t size)
{
	char *new_ptr;
	size_t i;
	size_t old_size;

	if (ptr == NULL)
	{
		new_ptr = malloc(size);
	}
	else
	{
		old_size = _strlen(ptr);
		new_ptr = malloc(size);
		if (new_ptr != NULL)
		{
			for (i = 0; i < old_size && i < size; i++)
			{
				new_ptr[i] = ptr[i];
			}
			free(ptr);
		}
	}

	return (new_ptr);
}

/**
 * getLastDirectory - Retrieve the last directory from
 *  a given path.
 * @path: A null-terminated string representing
 *  the path.
 *	Return: A pointer to the last directory in
 *  the path, or NULL if the path is empty or
 *  does not contain any directories.
 */

char *getLastDirectory(const char *path)
{
	char *lastDir;
	char *token;
	char *user = NULL;

	if (_getenv0("USER"))
		user = _getenv0("USER");
	else if (_getenv0("HOSTNAME"))
		user = _getenv0("HOSTNAME");
	else
		user = "root";

	lastDir = NULL;
	token = strtok((char *)path, "/");

	while (token != NULL)
	{
		lastDir = token;
		token = strtok(NULL, "/");
	}
	if (_strncmp(user, lastDir, sizeof(lastDir)) == 0)
		return ("~");
	return (lastDir);
}
