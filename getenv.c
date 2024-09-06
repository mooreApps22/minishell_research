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
	char	*s;

	if (ac == 1)
	{
		while (*envp)
			printf("%s\n", *envp++);
	}
	else if (ac == 2)
	{
		s = getenv(av[1]);
		if (s)
			printf("%s\n", s);
		else
			printf("%s not found\n", s);
	}
	return (0);	
}
