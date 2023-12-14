#include "shell.h"

/**
 * _strdup - Duplicates a string
 * @s: The null-terminated string to duplicate.
 * Return: A newly allocated null-terminated copy of the string, or NULL on failure.
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Gets the length of a null-terminated string
 * @s: The null-terminated string to measure.
 * Return: The length of the string (excluding the null terminator).
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - Checks if characters in a string match any in a delimiter
 * @str: The null-terminated string to compare.
 * @delim: The null-terminated delimiter characters to check against.
 *
 * Return: 1 if all characters in 'str' are present in 'delim', 0 otherwise.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - Tokenizes a string based on a delimiter (stateful)
 * @str: The null-terminated string to tokenize (initially or subsequently).
 * @delim: The null-terminated delimiter characters
 *
 * Return: A pointer to the first token, or NULL if no more tokens or invalid input.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; 
		i = _strlen(str);
		str_end = &str[i]; 
	}
	str_start = splitted;
	if (str_start == str_end) 
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) 
			bool = 1;
	}
	if (bool == 0) 
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - Checks if all characters in a string are digits
 *
 * @s: The null-terminated string to analyze
 * Return:  1 if all characters are digits, 0 otherwise.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
