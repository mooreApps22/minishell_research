#include <error.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
	PERROR - print a system error message

	void	perror(const char *s);

	prints a standard error message when a system call encounters an error

	NOTE: try to open a file that doesn't exist to see perror work
*/

int	main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		printf("%s was opened\n", av[1]);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
