#include "simple_shell.h"

/**
 * executioner - starts executing everything
 * @cur_cmd: try to check current token
 * @type_cmd: parse token
 *
 * Return: void function
 */

void executioner(char **cur_cmd, int type_cmd)
{
	pid_t PID;

	if (type_cmd == EXTERNAL_COMMAND || type_cmd == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
			execute_command(cur_cmd, type_cmd);
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(cur_cmd, type_cmd);
}
