#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main- entry point of the program
 * @argc: number of command line arguments
 * @argv:array of string containing number of line arguments
 * Return: Always 0(success);
 */

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s <command> [args]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Command: %s\n", argv[1]);

	printf("Arguments:\n");
	for (int a = 2; a < argc; a++)
	{
		printf("%d: %s\n", a - 1, argv[a]);
	}
	return (0);
}
