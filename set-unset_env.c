#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * setenv_command- initializes a new environment variable
 * Command syntax: setenv VARIABLE VALUE
 * @args: contains command line arguments
 * return: 0 on success and -1 on failure
 */

int setenv_command(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable\n");
		return (1);
	}
	return (0);
}
/**
 * unsetenv_command- removes environment variable
 * Command Syntax: unsetenv VARIABLE
 * @args: command line argument
 * return: 0 on success and -1 on failure
 */

int unsetenv_command(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}
	if (unsetenv(args[1]) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable\n");
	return (1);
	}
return (0);
}
