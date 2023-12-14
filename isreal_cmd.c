#include "shell.h"

/**
 * read_line - Reads a line of input from stdin.
 *
 * @i_eof: Pointer to an integer flag. Set to 1 if EOF encountered, 0 otherwise.
 * Return: Pointer to the allocated buffer containing the read line, including the newline character.
 * Frees the buffer on subsequent calls.
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
