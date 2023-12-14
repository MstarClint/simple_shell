#include "shell.h"

/**
 * cmp_env_name - Compares environment variable names up to the first "=".
 *
 * @nenv: Pointer to the environment variable name to compare.
 * @name: Pointer to the name to compare against.
 *
 * Return: 0 if names differ before the first "=" in nenv, otherwise the length of the matching part + 1.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - Searches for an environment variable in the provided environment list.
 *
 * @name: Pointer to the name of the environment variable to search for.
 * @_environ: Pointer to the list of environment variables.
 *
 * Return: Pointer to the environment variable string if found, or NULL if not found.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Init ptr_env val */
	ptr_env = NULL;
	mov = 0;
	/* */
	/*  */
	for (i = 0; _environ[i]; i++)
	{
		/* comments here */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - Prints all environment variables stored in the shell data structure.
 *
 * @datash: Pointer to the shell data structure containing the environment.
 *
 * Return: 1 on success, 0 on error.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
