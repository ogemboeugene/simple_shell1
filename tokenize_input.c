#include "main.h"
/**
 * Tokenizes a string into an array of pointers to tokens
 * 
 * input: The user input string
 * Return: Pointer to an array of pointers to tokens
 * 
 */

char **tokenize_input(char *lptr)
{
	char **tokens = NULL;
	char *token = NULL;
	size_t i = 0;
	int s = 0;

	if (lptr == NULL)
		return (NULL);

	for (i = 0; lptr[i]; i++)
	{
		if (lptr[i] == ' ')
			s++;
	}
	if ((s + 1) == _strlen(lptr))
		return (NULL);
	tokens = malloc(sizeof(char *) * (s + 2));
	if (tokens == NULL)
		return (NULL);

	token = strtok(lptr, " \n\t\r");

	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t\r");
	}
	tokens[i] = NULL;
	return (tokens);
}
