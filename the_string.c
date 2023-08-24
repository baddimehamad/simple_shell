#include "main.h"

/**
 * concat_string - concatenate strings
 * @destination:destination
 * @source: source
 * Return: pointer
 */
char *concat_string(char *destination, const char *source)
{
	int x;
	int y;

	for (x = 0; destination[x] != '\0'; x++)
		;

	for (y = 0; source[y] != '\0'; y++)
	{
		destination[x] = source[y];
		x++;
	}

	destination[x] = '\0';
	return (destination);
}
/**
 * *string_copy - Copie string 
 * @destination: destination
 * @source: source
 * Return: pointer
 */
char *string_copy(char *destination, char *source)
{

	size_t vl;

	for (vl = 0; source[vl] != '\0'; vl++)
	{
		destination[vl] = source[vl];
	}
	destination[vl] = '\0';

	return (destination);
}
/**
 * compare_strings - compares strings.
 * @string1: string
 * @string2: string
 * Return: 0.
 */
int compare_strings(char *string1, char *string2)
{
	int x;

	for (x = 0; string1[x] == string2[x] && string1[x]; x++)
		;

	if (string1[x] > string2[x])
		return (1);
	if (string1[x] < string2[x])
		return (-1);
	return (0);
}

/**
 * char_in_string - search character in string,
 * @the_string: string.
 * @the_char: character.
 * Return: pointer.
 */
char *char_in_string(char *the_string, char the_char)
{
	unsigned int x = 0;

	for (; *(the_string + x) != '\0'; x++)
		if (*(the_string + x) == the_char)
			return (the_string + x);
	if (*(the_string + x) == the_char)
		return (the_string + x);
	return ('\0');
}
/**
 * len_p_substring - get lenght.
 * @the_string: string.
 * @the_accept: abytes.
 * Return: the number of accepted bytes.
 */
int len_p_substring(char *the_string, char *the_accept)
{
	int a,x, y;

	for (x = 0; *(the_string + x) != '\0'; x++)
	{
		a = 1;
		for (y = 0; *(the_accept + y) != '\0'; y++)
		{
			if (*(the_string + x) == *(the_accept + y))
			{
				a = 0;
				break;
			}
		}
		if (a == 1)
			break;
	}
	return (x);
}

/**
 * duplicate_string - double string
 * @the_string: pointer 
 * Return: pointer
 */
char *duplicate_string(const char *the_string)
{
	char *_n_v;
	size_t leng;

	leng = lenght_string(the_string);
	_n_v = malloc(sizeof(char) * (leng + 1));
	if (_n_v == NULL)
		return (NULL);
	_copy_memory(_n_v, the_string, leng + 1);
	return (_n_v);
}

/**
 * lenght_string - lenght string.
 * @the_string: pointer
 * Return: 0.
 */
int lenght_string(const char *the_string)
{
	int leng;

	for (leng = 0; the_string[leng] != 0; leng++)
	{
	}
	return (leng);
}

/**
 * compare_characters - compare characters
 * @the_string:  string.
 * @the_delimiter: delimiter.
 *
 * Return: 1 or 0.
 */
int compare_characters(char the_string[], const char *the_delimiter)
{
	unsigned int x, y, z;

	for (x = 0, z = 0; the_string[x]; x++)
	{
		for (y = 0; the_delimiter[y]; y++)
		{
			if (the_string[x] == the_delimiter[y])
			{
				z++;
				break;
			}
		}
	}
	if (x == z)
		return (1);
	return (0);
}

/**
 * split_by_delimiter - split string with delimiter.
 * @the_string: input string.
 * @the_delimiter: delimiter.
 *
 * Return: string splited.
 */
char *split_by_delimiter(char the_string[], const char *the_delimiter)
{
	static char *the_splited_str, *end_of_string;
	char *start_of_string;
	unsigned int x, y;

	if (the_string != NULL)
	{
		if (compare_characters(the_string, the_delimiter))
			return (NULL);
		the_splited_str = the_string; 
		x = lenght_string(the_string);
		end_of_string = &the_string[x]; 
	}
	start_of_string = the_splited_str;
	if (start_of_string == end_of_string)
		return (NULL);

	for (y = 0; *the_splited_str; the_splited_str++)
	{

		if (the_splited_str != start_of_string)
			if (*the_splited_str && *(the_splited_str - 1) == '\0')
				break;
		for (x = 0; the_delimiter[x]; x++)
		{
			if (*the_splited_str == the_delimiter[x])
			{
				*the_splited_str = '\0';
				if (the_splited_str == start_of_string)
					start_of_string++;
				break;
			}
		}
		if (y == 0 && *the_splited_str) 
			y = 1;
	}
	if (y == 0)
		return (NULL);
	return (start_of_string);
}

/**
 * is_number - checks if string is number
 *
 * @the_string: string
 * Return: 1 or 0 .
 */
int is_number(const char *the_string)
{
	unsigned int x;

	for (x = 0; the_string[x]; x++)
	{
		if (the_string[x] < 48 || the_string[x] > 57)
			return (0);
	}
	return (1);
}
/**
 * string_reverse - reverse any string.
 * @the_string: string.
 * Return: null.
 */
void string_reverse(char *the_string)
{
	int count = 0, x, y;
	char *new_string, tmp;

	while (count >= 0)
	{
		if (the_string[count] == '\0')
			break;
		count++;
	}
	new_string = the_string;

	for (x = 0; x < (count - 1); x++)
	{
		for (y = x + 1; y > 0; y--)
		{
			tmp = *(new_string + y);
			*(new_string + y) = *(new_string + (y - 1));
			*(new_string + (y - 1)) = tmp;
		}
	}
}
