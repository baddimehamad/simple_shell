#include "main.h"
/**
 * _strcpy - copy the string pointed by src to dest
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (dest_start);
}

/**
 * _putchar - print char in stdout
 * @c: one char
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - print str in stdout
 * @c: char*
 *
 * Return: ...
 */

int _putstr(char *c)
{
	int i = 0;

	if (c == NULL)
		return (0UL);
	while (*(c + i))
	{
		_putchar(*(c + i));
		i++;
	}

	return (sizeof(char) * _strlen(c));
}

/**
 * splitString - Splits a string based on a delimiter.
 * @str: The original string to be split.
 * @delimiter: The delimiter character.
 * @numTokens: Pointer to an integer to store the number of tokens.
 *
 * Return: Pointer to an array of strings representing the tokens.
 */

char **splitString(const char *str, char delimiter, int *numTokens)
{
	char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
	int strLength = 0;
	int tokenIndex = 0;
	int tokenStart = 0;
	int i, j, tokenLength;

	while (str[strLength] != '\0')
		strLength++;

	for (i = 0; i <= strLength; i++)
	{
		if (str[i] == delimiter || str[i] == '\0')
		{
			tokenLength = i - tokenStart;
			tokens[tokenIndex] = (char *)malloc((tokenLength + 1) * sizeof(char));
			for (j = 0; j < tokenLength; j++)
				tokens[tokenIndex][j] = str[tokenStart + j];
			tokens[tokenIndex][j] = '\0';
			tokenIndex++;
			tokenStart = i + 1;
			if (tokenIndex >= MAX_TOKENS)
				break;
		}
	}
	*numTokens = tokenIndex;
	tokens = (char **)realloc(tokens, tokenIndex * sizeof(char *));

	return (tokens);
}

/**
 * join_strings - join a list of string based on order.
 * @strings: array of strings to join.
 * @count: strings count.
 *
 * Return: Pointer to string representing joined strings.
 */

char *join_strings(const char **strings, int count)
{
	int total_length = 0, i, position;
	char *joined_string;

	for (i = 0; i < count; i++)
	{
		total_length += strlen(strings[i]);
	}
	joined_string = (char *)malloc((total_length + 1) * sizeof(char));
	if (joined_string == NULL)
	{
		_putstr("Failed to allocate memory.\n");
		return (NULL);
	}
	position = 0;
	for (i = 0; i < count; i++)
	{
		_strcpy(joined_string + position, strings[i]);
		position += strlen(strings[i]);
	}
	joined_string[total_length] = '\0';

	return (joined_string);
}
