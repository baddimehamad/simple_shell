#include "main.h"

ENV *get_envirement(char *k)
{
	int i = 0;
	char *tmp_k;
	char *tmp_v;
	ENV *t = NULL;

	while (*(environ + i))
	{
		tmp_k = strtok(*(environ + i), "=");
		tmp_v = strtok(NULL, "=");
		if (strncmp(tmp_k, k, 4UL) == 0)
		{
			t ->index = i;
			t ->key = tmp_k;
			t ->value = tmp_v;
			return (t );
		}
		i++;
	}
	return (t );
}

int envirement_set(const char *k, const char *v)
{
	int i;
	int leng = strlen(k);
	char *n;
	const char *strings[3] = {NULL, "=", NULL};

	if (k == NULL)
		return (-1);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], k, leng) == 0 && environ[i][leng] == '=')
		{
			n = (char *)malloc((leng + strlen(v) + 2) * sizeof(char));
			strings[0] = k;
			strings[2] = v;
			string_copy(n, concat_string(strings, 3));
			environ[i] = n;
			return (0);
		}
	}
	n = (char *)malloc((leng + strlen(v) + 2) * sizeof(char));
	strings[0] = k;
	strings[2] = v;
	string_copy(n, concat_string(strings, 3));
	environ[i] = n;
	environ[i + 1] = NULL;

	return (0);
}
