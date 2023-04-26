#include "simple_shell.h"

/**
 * str_tokr - tokenizes a string
 * @str: string to be tokenized
 * @delim: delimiter to be used to tokenize the string
 * @save_ptr: pointer to be used to keep track of the next token
 *
 * Return: The next available token
 */
char *str_tokr(char *str, char *delim, char **save_ptr)
{
	char *end;

	if (str == NULL)
		str = *save_ptr;

	if (*str == '\0')
	{
		*save_ptr = str;
		return (NULL);
	}

	str += str_spn(str, delim);
	if (*str == '\0')
	{
		*save_ptr = str;
		return (NULL);
	}

	end = str + str_c_spn(str, delim);
	if (*finish == '\0')
	{
		*save_ptr = end;
		return (str);
	}

	*end = '\0';
	*save_ptr = end + 1;
	return (str);
}

/**
 * convert_to_int - changes a string to an integer
 * @s: the string to be changed
 *
 * Return: the converted int
 */
int convert_to_int(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			n = (n * 10) + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n);
}

/**
 * realloc_mem - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size of ptr
 * @new_size: size of the new memory to be allocated
 *
 * Return: pointer to the address of the new memory block
 */
void *realloc_mem(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *tmp;
	unsigned int i;

	if (ptr == NULL)
	{
		tmp = malloc(new_size);
		return (tmp);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		tmp = malloc(new_size);
		if (tmp != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)tmp + i) = *((char *)ptr + i);
			free(ptr);
			return (tmp);
		}
		else
			return (NULL);

	}
}

/**
 * ctrl_c_handler - handles the signal raised by CTRL-C
 * @sig_num: signal number
 *
 * Return: void
 */
void ctrl_c_handler(int sig_num)
{
	if (sig_num == SIGINT)
		print("\n($) ", STDIN_FILENO);
}

/**
 * rm_comment - removes/ignores everything after a '#' char
 * @input: input to be used
 *
 * Return: void
 */
void rm_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
}
	input[i] = '\0';
}
