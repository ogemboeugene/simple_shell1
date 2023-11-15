#include "main.h"

/**
 * Custom shell function declarations
 */

int custom_shell_cd(char **args);
int custom_shell_help(char **args);
int custom_shell_exit(char **argv);
int custom_shell_ctrld(char **args);

char *builtins[] = {"cd", "help", "exit", "^D", "setenv", "unsetenv"};

int (*builtin_func[]) (char **) = {
	&shell_cd, &shell_help,
	&shell_exit, &shell_ctrld, &_setenv, &_unsetenv};

/**
 * Custom shell exit function
 * @param argv: Command-line arguments
 * 
 * @return: 0 to signal exit from the shell
 */
int custom_shell_exit(char **argv)
{
	(void)argv;

	return (0);
}


/**
 * Custom shell cd function - changes the current directory
 * @param args: Command-line arguments
 * @return: 0 on success, -1 on failure
 */
int custom_shell_cd(char **args)
{
	if (args[1])
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (-1);
		}
	}
	else
	{
		chdir(getenv("HOME"));
	}

	return (0);
}

/**
 * Custom shell ctrld function to handle "^D" call
 * @param args: List of arguments
 * @return: Always returns 200
 */
int custom_shell_ctrld(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * Function to return the number of built-in functions
 * @return: Number of built-in functions
 */

int custom_num_builtins(void)
{
	return (sizeof(builtins) / sizeof(char *));
}

/**
 * Custom shell help function
 * @param args: List of arguments
 * @return: Always returns 1 to continue executing
 */
int custom_shell_help(char **args)
{
	int i;

	printf("For help, call 911\n");
	(void)args;
	for (i = 0; i < num_builtins(); i++)
	{
		printf("  %s\n", builtins[i]);
	}

	return (1);
}

/**
 * Custom fork function to create a fork and execute commands
 * @param argc: Command and values path
 * @param argv: Name of the program
 * @param env: Environment variables
 * @param line: Command line for the user
 * @param pd: Process ID
 * @param check: Checker add new test
 * @return: 0 on success
 */

int custom_fork(char **argc, char **argv, char **env, char *line, int pd, int check)
{

	pid_t child;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";

	if (argc[0] == NULL)
		return (1);
	for (i = 0; i < num_builtins(); i++)
	{
		if (_strcmp(argc[0], builtins[i]) == 0)
			return (builtin_func[i](argc));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(argc[0], argc, env) == -1)
		{
			fprintf(stderr, format, argv[0], pd, argc[0]);
			if (!check)
				free(argc[0]);
			free(argc);
			free(line);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
