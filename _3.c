#include "main.h"
int compare_strings(const char *first_string, const char *second_string, size_t n)
{
	if (n == 0)
		return (0);

	while (*first_string && *second_string && (*first_string == *second_string) && (n > 1))
	{
		first_string++;
		second_string++;
		n--;
	}

	return (*(unsigned char *)first_string - *(unsigned char *)second_string);
}
int lenght_string(const char *x)
{
	unsigned int y = 0;

	while (*(x + y))
		y++;

	return ((int)y);
}
char *string_dump(const char *string_text)
{
	size_t l;
	char *c;
	size_t i;

	if (string_text == NULL)
		return (NULL);
	l = lenght_string(string_text);
	c = (char *)malloc((l + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	for (i = 0; i <= l; i++)
		c[i] = string_text[i];

	return (c);
}
char *env_0(const char *x)
{
	char **env;
	size_t l;

	if (x == NULL || *x == '\0')
		return (NULL);
	l = lenght_string(x);

	for (env = environ; *env != NULL; env++)
		if (compare_strings(*env, x, l) == 0 && (*env)[l] == '=')
			return (&((*env)[l + 1]));

	return (NULL);
}

char *string_to_chars(const char *text, int x)
{
	if (text == NULL)
	{
		return (NULL);
	}

	while (*text != '\0')
	{
		if (*text == x)
		{
			return ((char *)text);
		}
		text++;
	}

	if (x == '\0')
	{
		return ((char *)text);
	}

	return (NULL);
}
