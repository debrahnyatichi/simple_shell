#include "simple_shell.h"

/**
 * handle_non_interactive - reads input from standard input and
 * executes commands in non-interactive mode.
 * Return: void
 */

void handle_non_interactive(void)
{
	char **commands = NULL;
	char **current_command = NULL;
	int i, command_type = 0;
	size_t buffer_size = 0;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &buffer_size, stdin) != -1)
		{
			remove_newlines(line);
			remove_comments(line);
			commands = tokenize(line, ";");
			for (i = 0; commands[i] != NULL; i++)
			{
				current_command = tokenize(commands[i], " ");
				if (current_command[0] == NULL)
				{
					free(current_command);
					break;
				}
				command_type = parse_command_type(current_command[0]);
				execute_command(current_command, command_type);
				free(current_command);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
