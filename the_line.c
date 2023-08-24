#include "main.h"

/**
 * get_line_fun
 * @pointer_of_line: Buffer
 * @buff: str 
 * @size_line: size
 * @size_buff: size
 */
void get_line_fun(char **pointer_of_line, size_t *size_line, char *buff, size_t size_buff)
{

	if (*pointer_of_line == NULL)
	{
		if  (size_buff > BUFSIZE)
			*size_line = size_buff;

		else
			*size_line = BUFSIZE;
		*pointer_of_line = buff;
	}
	else if (*size_line < size_buff)
	{
		if (size_buff > BUFSIZE)
			*size_line = size_buff;
		else
			*size_line = BUFSIZE;
		*pointer_of_line = buff;
	}
	else
	{
		string_copy(*pointer_of_line, buff);
		free(buff);
	}
}
/**
 * get_line_function_stream 
 * @pointer_of_line: buff 
 * @size_line: size 
 * @the_stream: the_stream
 * Return: bytes
 */
ssize_t get_line_function_stream(char **pointer_of_line, size_t *size_line, FILE *the_stream)
{
	int x;
	static ssize_t the_text;
	ssize_t return_value;
	char *buff;
	char z = 'z';

	if (the_text == 0)
		fflush(the_stream);
	else
		return (-1);
	the_text = 0;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == 0)
		return (-1);
	while (z != '\n')
	{
		x = read(STDIN_FILENO, &z, 1);
		if (x == -1 || (x == 0 && the_text == 0))
		{
			free(buff);
			return (-1);
		}
		if (x == 0 && the_text != 0)
		{
			the_text++;
			break;
		}
		if (the_text >= BUFSIZE)
			buff = the_re_alloc(buff, the_text, the_text + 1);
		buff[the_text] = z;
		the_text++;
	}
	buff[the_text] = '\0';
	get_line_fun(pointer_of_line, size_line, buff, the_text);
	return_value = the_text;
	if (x != 0)
		the_text = 0;
	return (return_value);
}
