#include "main.h"

char **split_text(const char *x, char y, int *z)
{
	char **w = (char **)malloc(MAX_TOKENS * sizeof(char *));
	int l = 0;
	int d = 0;
	int s = 0;
	int i, j, lt;

	while (x[l] != '\0')
		l++;

	for (i = 0; i <= l; i++)
	{
		if (x[i] == y || x[i] == '\0')
		{
			lt = i - s;
			w[d] = (char *)malloc((lt + 1) * sizeof(char));
			for (j = 0; j < lt; j++)
				w[d][j] = x[s + j];
			w[d][j] = '\0';
			d++;
			s = i + 1;
			if (d >= MAX_TOKENS)
				break;
		}
	}
	*z = d;
	w = (char **)realloc(w, d * sizeof(char *));

	return (w);
}
char *string_copy(char *x, const char *y)
{
	char *res = x;

	while (*y != '\0')
	{
		*x = *y;
		x++;
		y++;
	}

	*x = '\0';

	return (res);
}
int string_p(char ch)
{
	return (write(1, &ch, 1));
}

int string_put(char *ch)
{
	int i = 0;

	if (ch == NULL)
		return (0UL);
	while (*(ch + i))
	{
		string_p(*(ch + i));
		i++;
	}

	return (sizeof(char) * lenght_string(ch));
}
char *concat_string(const char **x, int y)
{
	int z = 0, i, p;
	char *j;

	for (i = 0; i < y; i++)
	{
		z += strlen(x[i]);
	}
	j = (char *)malloc((z + 1) * sizeof(char));
	if (j == NULL)
	{
		string_put("error memory.\n");
		return (NULL);
	}
	p = 0;
	for (i = 0; i < y; i++)
	{
		string_copy(j + p, x[i]);
		p += strlen(x[i]);
	}
	j[z] = '\0';

	return (j);
}
