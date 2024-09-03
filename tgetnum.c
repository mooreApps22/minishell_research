#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>

/*
	TGETNUM - get numeric capability value 

	int tgetnum (char *name);
	
	name

		"co" (number of columns in a line)
		"it" (tabs initially every # spaces)
		"li" (number of lines on screen or page)
		"lm" (lines of memory if > line. 0 means varies)
		"sg" (number of blank characters left by smso or rmso)
		"pb" (lowest baud rate where padding needed)
		"vt" (virtual terminal number (CB/unix))
		"ws" (number of columns in status line)
		"Nl" (number of labels on screen)
		"lh" (rows in each label)
		"lw" (columns in each label)
		"ma" (maximum combined attributes terminal can handle)
		"MW" (maximum number of definable windows)
		"Co" (maximum number of colors on screen)
		"pa" (maximum number of color-pairs on the screen)
		"NC" (video attributes that cannot be used with colors)

	return value or -1 on not mention in terminal description 
	
	NOTE:	cc tgetnum.c -ltermcap
			infocmp
			./a.out xterm

	HINT: readjust the window size to see different outputs
*/

#define BUFFER_SIZE 1024

void print_tgetnums(void);

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
		print_tgetnums();
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

void print_tgetnums(void)
{
    printf("Columns: %d\n", tgetnum("co"));
    printf("Init Tabs: %d\n", tgetnum("it"));
    printf("Lines: %d\n", tgetnum("li"));
    printf("Lines of Memory: %d\n", tgetnum("lm"));
    printf("Magic Cookie Glitch: %d\n", tgetnum("sg"));
    printf("Padding Baud Rate: %d\n", tgetnum("pb"));
    printf("Virtual Terminal: %d\n", tgetnum("vt"));
    printf("Width Status Line: %d\n", tgetnum("ws"));
    printf("Num Labels: %d\n", tgetnum("Nl"));
    printf("Label Height: %d\n", tgetnum("lh"));
    printf("Label Width: %d\n", tgetnum("lw"));
    printf("Max Attributes: %d\n", tgetnum("ma"));
    printf("Maximum Windows: %d\n", tgetnum("MW"));
    printf("Max Colors: %d\n", tgetnum("Co"));
    printf("Max Pairs: %d\n", tgetnum("pa"));
    printf("No Color Video: %d\n", tgetnum("NC"));
}
