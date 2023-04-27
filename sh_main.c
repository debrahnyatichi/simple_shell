#include "simple_shell.h"

/**
 * main - the main shell code
 * @argc: number of arguments passed
 * @argv: program arguments to be parsed
 *
 * applies the functions in utils and helpers
 * implements EOF
 * Prints error on Failure
 * Return: 0 on success
 */


int main(int argc __attribute__((unused)), char **argv)
{
	char **cmds = NULL;
	char *line = NULL;
	char *sh_name = NULL;
	int stats = 0;
	char **cur_cmd = NULL;
	int i, type_cmd = 0;
	size_t n = 0;

	signal(SIGINT, ctrl_c_handler);
	sh_name = argv[0];
	while (1)
	{
		handle_non_interactive();
		print(" ($) ", STDOUT_FILENO);
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			_rm_newline(line);
			rm_comment(line);
			cmds = split_string(line, ";");
		for (i = 0; commands[i] != NULL; i++)
		{
			current_command = split_string(commands[i], " ");
			if (current_command[0] == NULL)
			{
				free(current_command);
				break;
			}
			type_command = identify_command_type(current_command[0]);
			executioner(current_command, type_command);
			free(current_command);
		}
		free(commands);
	}
	free(line);
	return (status);
}
