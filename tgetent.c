#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>

/*
	TGETENT - loads the entry for name

		int	tgetent(char *buffer_pointer, const char *name);

		returns 1 on success, 0 no entry, -1 termifo database not found

	NOTE:	cc tgetent.c -ltermcap
			infocmp
			./a.out xterm
*/

#define BUFFER_SIZE 1024

int main(int ac, char **av)
{
	char	buf[BUFFER_SIZE];
	int		result;

	if (ac != 2)
	{
		printf("Must input terminal name.\n");
		exit(EXIT_FAILURE);
	}
	result = tgetent(buf, av[1]);
	if (result == 1)
	{
		printf("Terminal %s: found\n", av[1]);
	}
	else if (result == 0)
	{
		printf("Terminal %s: not found in database\n", av[1]);
		exit(EXIT_FAILURE);
	}
	else if (result == -1)
	{
		perror("tgetent");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
