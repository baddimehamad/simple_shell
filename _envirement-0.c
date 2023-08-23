#include "main.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @key: The key of the environment variable to be retrieved.
 *
 * Return: Pointer to a string representing the value of
 * the environment variable and key and index.
 */

ENV *_getenv(char *key)
{
	int i = 0;
	char *tempkey;
	char *tempvalue;
	ENV *tupele = NULL;

	while (*(environ + i))
	{
		tempkey = strtok(*(environ + i), "=");
		tempvalue = strtok(NULL, "=");
		if (strncmp(tempkey, key, 4UL) == 0)
		{
			tupele->index = i;
			tupele->key = tempkey;
			tupele->value = tempvalue;
			return (tupele);
		}
		i++;
	}
	return (tupele);
}

/**
 * _setenv - set an environment variable
 * @key: The name of the environment variable
 * @value: The value to set
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *key, const char *value)
{
	int i;
	int keyLength = strlen(key);
	char *newEntry;
	const char *strings[3] = {NULL, "=", NULL};

	if (key == NULL)
		return (-1);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], key, keyLength) == 0 && environ[i][keyLength] == '=')
		{
			newEntry = (char *)malloc((keyLength + strlen(value) + 2) * sizeof(char));
			strings[0] = key;
			strings[2] = value;
			_strcpy(newEntry, join_strings(strings, 3));
			environ[i] = newEntry;
			return (0);
		}
	}
	newEntry = (char *)malloc((keyLength + strlen(value) + 2) * sizeof(char));
	strings[0] = key;
	strings[2] = value;
	_strcpy(newEntry, join_strings(strings, 3));
	environ[i] = newEntry;
	environ[i + 1] = NULL;

	return (0);
}
