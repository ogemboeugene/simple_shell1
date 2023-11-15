#include "main.h"
#define BUFFER_SIZE 1024

char *custom_getline(void)
char *custom_read_input(void);
int custom_find_newline(char *buffer, int size);
char *custom_copy_line(char *buffer, int len, char *line);
void custom_shift_buffer(char *buffer, int size, int pos);
/**
 * Function _custom_getline - prompts for input and returns a line
 * Return: char pointer to the read line
 */

char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int pos;
	static int size;
	int newline_pos;
	int len;
	char *line = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	while (1)
	{
		if (pos >= size)
		{
			size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (size <= 0)
			{
				return (NULL);
			}
			pos = 0;
		}

		newline_pos = find_newline(buffer + pos, size - pos);
		if (newline_pos == -1)
		{
			newline_pos = size - pos;
		}
		else
		{
			newline_pos += 1;
		}

		len = newline_pos;
		line = copy_line(buffer + pos, len, line);

		shift_buffer(buffer, size, pos + len);
		size -= pos + len;
		pos = 0;

		return (line);
	}
}
/**
 * Function custom_read_input - reads input from stdin
 * Return: char pointer to the read input
 */
char *custom_read_input(void)
{
	static char buffer[BUFFER_SIZE];
	static int size;

	size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (size <= 0)
	{
		return (NULL);
	}

	return (buffer);
}
/**
 * Function custom_find_newline - finds newline character in the buffer
 * @buffer: input buffer
 * @size: size of the buffer
 * Return: index of the newline character or -1 if not found
 */

int custom_find_newline(char *buffer, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (buffer[i] == '\n')
		{
			return (i);
		}
	}
	return (-1);
}

/**
 * Function custom_copy_line - copies a line from buffer to line pointer
 * @buffer: input buffer containing the line
 * @len: length of the line
 * @line: pointer to the line
 * Return: char pointer to the copied line
 */

char *custom_copy_line(char *buffer, int len, char *line)
{
	char *temp;
	int i;

	temp = realloc(line, len + 1);
	if (temp == NULL)
	{
		free(line);
		return (NULL);
	}
	line = temp;
	for (i = 0; i < len; i++)
	{
		line[i] = buffer[i];
	}
	line[len] = '\0';

	return (line);
}

/**
 * Function custom_shift_buffer - shifts the buffer after processing a line
 * @buffer: buffer to shift
 * @size: size of the buffer
 * @pos: position to shift the buffer
 * Return: void
 */

void custom_shift_buffer(char *buffer, int size, int pos)
{
	int i;

	for (i = 0; i < size - pos; i++)
	{
		buffer[i] = buffer[pos + i];
	}
}
