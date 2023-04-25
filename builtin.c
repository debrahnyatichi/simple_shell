#include "simple_shell.h"

/**
 * print_environment_variables - Prints the current environment variables
 * @comn_args: Unused argument
 * Return: Void
 */

void print_environment_variables(char **comn_args __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

/**
 * exit_shell - Exits the shell program
 * @comn_args: Array of command arguments
 * Return: Void
 */

void exit_shell(char **comn_args)
{
	int num_args = 0, exit_status;

	for (comn_args[num_args] != NULL; num_args++)

	if (num_args == 1)
	{
		free(comn_args);
		free(line);
		free(commands);
		exit(status);
	}
	else if (num_args == 2)
	{
		exit_status = _atoi(comn_args[1]);

		if (exit_status == -1)
		{
			print(shell_program_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(comn_args[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(comn_args);
			free(commands);
			exit(exit_status);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
