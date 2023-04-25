#include "simple_shell.h"

/**
 * execute_command_with_fork - executes an external command in a new process
 * @args: an array of strings containing the command and its arguments
 * This function forks a new process and then executes the command given by
 * the array of strings pointed to by `args` in the child process. The parent
 * process waits for the child process to finish and returns the exit status
 * of the child process.
 * Return: the exit status of the child process
 */
int execute_command_with_fork(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (-1);
		}
		return (WEXITSTATUS(status));
	}
}

/**
 * execute_command - executes a command
 * @args: an array of strings containing the command and its arguments
 * This function executes the command given by the array of strings pointed to
 * by `args`. If the command is a built-in command (such as "cd" or "exit"),
 * the function executes the built-in command directly. Otherwise, it calls
 * execute_command_with_fork to execute the command in a new process.
 * Return: the exit status of the command
 */
int execute_command(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);

	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
			return (chdir(getenv("HOME")));
		else
			return (chdir(args[1]));
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else
	{
		return (execute_command_with_fork(args));
	}
}
