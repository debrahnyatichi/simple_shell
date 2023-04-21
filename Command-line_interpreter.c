#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *buffer;

	size_t bufsize = BUFFER_SIZE
		buffer = (char *) malloc(bufsize * sizeof(char));
	if (!buffer)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("simple_shell$");
		getline(&buffer, &bufsize, stdin);

		buffer[strcspn(buffer, "\n")] = 0;
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(buffer, buffer, NULL) < 0)
			{
				printf("ls: command not found\n");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

