#include "main.h"

/**
 * _strlen - strlen clone
 * @f: char's pointers
 * Return:...
 */
int _strlen(const char *f)
{
	unsigned int i = 0;

	while (*(f + i))
		i++;

	return ((int)i);
}

/**
 * _strncmp - _strncmp clone
 * @str1: char's pointers
 * @str2: char's pointers
 * @n: char's pointers
 * Return:...
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);

	while (*str1 && *str2 && (*str1 == *str2) && (n > 1))
	{
		str1++;
		str2++;
		n--;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * _getenv0 - _getenv clone
 * @name: char's pointers
 * Return:...
 */

char *_getenv0(const char *name)
{
	char **env;
	size_t nameLength;

	if (name == NULL || *name == '\0')
		return (NULL);
	nameLength = _strlen(name);

	for (env = environ; *env != NULL; env++)
		if (_strncmp(*env, name, nameLength) == 0 && (*env)[nameLength] == '=')
			return (&((*env)[nameLength + 1]));

	return (NULL);
}

/**
 * _strdup - _strdup clone
 * @str: char's pointers
 * Return:...
 */

char *_strdup(const char *str)
{
	size_t length;
	char *copy;
	size_t i;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	copy = (char *)malloc((length + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		copy[i] = str[i];

	return (copy);
}

/**
 * _strchr - _strchr clone
 * @str: char's pointers
 * @character: char int
 * Return:...
 */

char *_strchr(const char *str, int character)
{
	if (str == NULL)
	{
		return (NULL);
	}

	while (*str != '\0')
	{
		if (*str == character)
		{
			return ((char *)str);
		}
		str++;
	}

	if (character == '\0')
	{
		return ((char *)str);
	}

	return (NULL);
}
