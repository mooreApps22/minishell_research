#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
	GETENV - get an environment variable

	char	*getenv(const char *name);

	return pointer to value in the environment or NULL if no match

	NOTE: add a Command line argument(any string) to output the environmenvariables separated by a newline
*/

int	main(int ac, char **av, char **envp)
{
	if (ac == 1 || ac == 2)
	{
		char	*env;

		while ((env = getenv(*envp)) != NULL)
		{
			if (ac == 1)
				printf("%s", env);
			else if (ac == 2)
				printf("%s\n", env);
			envp++;
		}
	}
	printf("\n");
	return (0);	
}
