#include <stdio.h>
#include <stdlib.h>
#include <termcap.h> // must cc <name.c> -ltermcap

/*
		TGETENT - find terminal description

		TGETSTR - get info from  description (uses malloc so must free)

			char *tgetstr (char *name, char **area);

				name is the a two char string id 

				area is also stores the return and will be updated to point past the null-terminator

			returns 1st argument for TPUTS or 0

		TPUTS - compute and perform padding

			int tputs(const char *str, int nlines, int (*f)(int));

				str - TGETSTR return

				nlines - number of lines affected by the operation

				f - a func-pointer called to output each character (putchar)

			returns (no meaningful return)

		TGOTO - handles cursor motion

			char *tgoto(const char *cstring, int hpos, int vpos);		

				cstring - TGETSTR "cm" return

				hpos - horitozal position
				
				vpos - vertical position

			returns string containing terminal control sequence that will move the cursor
*/

#define BUFFER_SIZE 2048

int main(int ac, char **av)
{
	char	buf[BUFFER_SIZE];
	int		result;
	char	*clear_screen;
	char	*move_cursor;
	char	*cursor_pos;


	if (ac != 4)
	{
		printf("<xterm> <width> <height>\n");
		exit(EXIT_FAILURE);
	}
	if ((tgetent(buf, av[1]) != 1))
	{
		perror("tgetent");
		exit(EXIT_FAILURE);
	}
	if ((clear_screen = tgetstr("cl", NULL)) == NULL)
	{
		perror("tgetstr");
		exit(EXIT_FAILURE);
	}
	if ((move_cursor = tgetstr("cm", NULL)) == NULL)
	{
		perror("tgetstr");
		exit(EXIT_FAILURE);
	}
	tputs(clear_screen, 1, putchar);
	if ((cursor_pos = tgoto(move_cursor, atoi(av[2]), atoi(av[3]))) == NULL)
	{
		perror("tgoto");
		exit(EXIT_FAILURE);
	}
	tputs(cursor_pos, 1, putchar);
	printf("x");
	return (EXIT_SUCCESS);
}
