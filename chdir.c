#include <stdio.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	CHANGE DIRECTORY - change working directory

		int	chdir(const char *path);

			Changes the CWD of the calling process to directory PATH

			return 0 on success and -1 on failure (sets errno)
*/

int	main(int ac, char **av)
{
	char	*input;

	while (true)
	{
		input = readline("$> cd ");
		if (chdir(input))
			printf("No such directory\n");
		else
			printf("You are now in directory %s\n", input);
		free(input);
	}
	return (0);
}
