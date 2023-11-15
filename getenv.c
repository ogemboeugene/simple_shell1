#include "main.h"


/**
 * Function to print environment variables to stdout
 * 
 * @param env: Array of environment variables
 * 
 * Return: void
 */

void _getenv(char **env)
{
	size_t i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
