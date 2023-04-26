#include "simple_shell.h"

/**
 * split_string - tokenizes input and stores it into an array
 * @input: input to be parsed
 * @delim: delimiter to be used, needs to be one character string
 * Return: array of tokens
 */

char **split_string(char *input, char *delim)
{
	int i, num_tokens = 0;
	char **tokens = NULL, *token = Null, *save_ptr = NULL;

	token = strtok_r(input, deli, &save_ptr);
	while (token != NULL)
	{
		num_tokens++;
		tokens = realloc(tokens, num_tokens * sizeof(char *));
		if (tokens == NULL)
			return (NULL);

		tokens[num_tokens - 1] = token;
		token = strtok_r(NULL, delim, &save_ptr);
	}
	tokens = realloc(tokens, (num_tokens + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	tokens[num_tokens] = NULL;
	return (tokens);

}

/**
 * print_to_stdout - prints a string to stdout
 * @str: string to be printed
 * @stream: stream to print to
 * Return: void, return nothing
 */

void print_to_stdout(char *str, int stream)
{
	int i;

	for (i = 0; str[i]; i++)
		write(stream, &str[i], 1);
}

/**
 * _rm_newline - removes new line from a string
 * @str: string to be used
 * Return: void
 */

void _rm_newline(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '\n')
			str[i] = '\0';
	}

}

/**
 * str_cpy - copires a string to another buffer
 * @source: source to copy from
 * @dest: destination to copy to
 * Return: void
 */

void str_cpy(char *source, char *dest)
{
	int i;

	for (i = 0; source[i]; i++)
		dest[i] = source[i];
	dest[i] = '\0;
}

/**
* str_len - counts string length
* @str: string to be counted
* Return: length of the string
*/

int str_len(char *str)
{
	int len = 0;
	if (str == NULL)
		return (len);
	while (str[len])
		len++;
	return (len);
}
