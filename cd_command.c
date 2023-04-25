#include <stdio.h>
#include <unistd.h>

/**
 * main- the entry point of the program
 * @argc:the nomber of command line arguments
 * @argv:number of array strings
 *return: always 0 (success)
 */
int main(int argc, char *argv[])
{
	char cwd[1024];

	if (argc == 1)
	{
		chdir(getenv("HOME"));
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		chdir(getenv("OLDPWD));
	}
	else
	{
		chdir(argv[1]);
	}
	getcwd(cwd, sizeof(cwd));
	setenv("PWD", cwd, 1);
	printf(" % s\n", cwd);
	return (0);
}
