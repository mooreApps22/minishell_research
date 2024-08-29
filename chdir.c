#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
	CHANGE DIRECTORY

		int	chdir(const char *path);
		return 0 on sucess and -1 on failure (sets errno)
*/

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (chdir(av[1]) == 0)
		{
			while (1)
			{
				printf("I'm in %s\n", av[1]);
			}
			exit(EXIT_SUCCESS); // you will exit back into the directory you started
		}
		else
		{
			perror("Failed to change directory");
			exit(EXIT_FAILURE);
		}
	}
}
