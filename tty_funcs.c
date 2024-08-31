#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
	ISATTY - test whether a file descriptor refers to a terminal

		int	isatty(int fd);

	returns 1 on open terminal or 0 if not (sets errno)

	TTYNAME - return name of a terminal

		char	*ttyname(int fd);

	returns pointer to pathname on success or NULL on failure (sets errno)

	TTYSLOT - returns the index of the current user's entry in some file

		int	ttyslot(void);

	returns slot number or error number(0 or -1, depends on system)

*/

int	main(int ac, char **av)
{
	int tty;	

	if (ac == 1)
	{
		tty = ttyslot();	
		if (isatty(tty))
			printf("%s\n", ttyname(tty));
		else
			printf("Not a terminal\n");
	}
	return (0);
}
