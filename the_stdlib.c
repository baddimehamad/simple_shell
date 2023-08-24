#include "main.h"

/**
 * length_get - Get l
 * @val: number.
 * Return: number.
 */
int length_get(int val)
{
	unsigned int number_1;
	int l = 1;

	if (val < 0)
	{
		l++;
		number_1 = val * -1;
	}
	else
	{
		number_1 = val;
	}
	while (number_1 > 9)
	{
		l++;
		number_1 = number_1 / 10;
	}

	return (l);
}
/**
 * convert_int_to_string - convert int to string.
 * @val: number
 * Return: String.
 */
char *convert_int_to_string(int val)
{
	unsigned int number_1;
	int l = length_get(val);
	char *buff;

	buff = malloc(sizeof(char) * (l + 1));
	if (buff == 0)
		return (NULL);

	*(buff + l) = '\0';

	if (val < 0)
	{
		number_1 = val * -1;
		buff[0] = '-';
	}
	else
	{
		number_1 = val;
	}

	l--;
	do {
		*(buff + l) = (number_1 % 10) + '0';
		number_1 = number_1 / 10;
		l--;
	}
	while (number_1 > 0)
		;
	return (buff);
}

/**
 * string_to_int - convert  string to integer.
 * @str_text: string.
 * Return: integer.
 */
int string_to_int(char *str_text)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(str_text + count) != '\0')
	{
		if (size > 0 && (*(str_text + count) < '0' || *(str_text + count) > '9'))
			break;

		if (*(str_text + count) == '-')
			pn *= -1;

		if ((*(str_text + count) >= '0') && (*(str_text + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(str_text + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
