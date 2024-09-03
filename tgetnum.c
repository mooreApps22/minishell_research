#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>

/*
	TGETNUM - get numeric capability value 

	int tgetnum (char *name);
	
	name

		"li" - height
		"co" - width 
		"it" - intial spacing between hardware tab stop columns
		"kn" - number of numbered function keys
		"lm" - lines of display memory
		"pb" - lowest baud rate which padding is actually needed
		"sg" - width of magic standout cookie
		"ug" - width of underlining  magic standout cookie
		"ws" - width of status line 

		"colors" - number of colors

	return value or -1 on not mention in terminal description 
	
	NOTE:	cc tgetnum.c -ltermcap
			infocmp
			./a.out xterm

	HINT: readjust the window size to see different outputs
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
		int height;
		int	width;
		height = tgetnum("li");
		width = tgetnum("co");
		printf("%s Height: %d\n", av[1], height);
		printf("%s Width: %d\n", av[1], width);
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
