#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
	STRERROR - print a system error message

	char	*strerror(int errnum);

	returns a pointer to string with error code selected by errnum

	NOTE: try to open a file that doesn't exist to see strerror work
*/

int	main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			printf("%s", strerror(errno));
			exit(EXIT_FAILURE);
		}
		printf("%s was opened\n", av[1]);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
