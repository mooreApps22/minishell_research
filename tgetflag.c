#include <curses.h>
#include <ncurses.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>

/*
	TGETFLAG - get a boolean value

	int tgetflag (char *name);
	
	name
		return 1 if the capability name is present in the terminal description, 0 if not
				
	
	NOTE:	cc tgetent.c -ltermcap
			infocmp
			./a.out xterm

		"am" (terminal has automatic margins)
		"bw" (cub1 wraps from column 0 to last column)
		"xb" (no_esc_ctlc)
		"xs" (standout not erased by)
		"xn" (newline ignored after 80 cols)
		"eo" (can erase overstrikes w/ a blank)
		"gn" (generic line type)
		"hc" (hard copy terminal)
		"km" (has a meta key, sets 8th-bit)
		"hs" (has extra status line)
		"in" (insert mode distinguishes null)
		"da" (display may be retained above)
		"db" (display may be retained below)
		"mi" (safe to move while in insert)
		"ms" (safe to move while in standout)
		"os" (terminal can overstrike)
		"es" (escape can be used on the status line)
		"xt" (tabs destructive, magic so)
		"hz" (cannot print ~'s (Hazeltine))
		"ul" (unline character)
		"xo" (terminal uses xon/xoff)
		"nx" (padding will not work, xon/xoff required)
		"5i" (printer will not echo on)
		"HC" (hard cursor)
		"NR" (smcup does not reverse rmcup)
		"NP" (pad character does not exist)
		"ND" (scrolling region is non-destructive)
		"cc" (terminal can re-define)
		"ut" (screen erased w/ background)
		"hl" (terminal uses only HLS color)
		"YA" (only positive motion for pha/mhpa caps)
		"YB" (using cr turns off micro mode)
		"YC" (printer needs operator to chang character set)
		"YD" (only positve motion for vpa/mvpa caps)
		"YE" (printing in last column causes cr)
		"YF" (changing character pitch)
		"YG" (changing line pitch changes resolution)

	HINT: re-adjust the window size to see different outputs
*/

#define BUFFER_SIZE 1024

void	print_tgetflags(void);

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
		print_tgetflags();
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

void	print_tgetflags(void)
{
	if (tgetflag("am"))
		printf("terminal has automatic margins\n");
	if (tgetflag("bw"))
		printf("cub1 wraps from column 0 to last column\n");
	if (tgetflag("xb"))
		printf("no escape control-C\n");
	if (tgetflag("xs"))
		printf("standout not erased by\n");
	if (tgetflag("xn"))
		printf("newline ignored after 80 columns\n");
	if (tgetflag("eo"))
		printf("can erase overstrikes with a blank\n");
	if (tgetflag("gn"))
		printf("generic line type\n");
	if (tgetflag("hc"))
		printf("hard copy terminal\n");
	if (tgetflag("km"))
		printf("has a meta key, sets 8th-bit\n");
	if (tgetflag("hs"))
		printf("has extra status line\n");
	if (tgetflag("in"))
		printf("insert mode distinguishes null\n");
	if (tgetflag("da"))
		printf("display may be retained above\n");
	if (tgetflag("db"))
		printf("display may be retained below\n");
	if (tgetflag("mi"))
		printf("safe to move while in insert mode\n");
	if (tgetflag("ms"))
		printf("safe to move while in standout mode\n");
	if (tgetflag("os"))
		printf("terminal can overstrike\n");
	if (tgetflag("es"))
		printf("escape can be used on the status line\n");
	if (tgetflag("xt"))
		printf("tabs are destructive, magic so\n");
	if (tgetflag("hz"))
		printf("cannot print ~'s (Hazeltine)\n");
	if (tgetflag("ul"))
		printf("underline character\n");
	if (tgetflag("xo"))
		printf("terminal uses XON/XOFF flow control\n");
	if (tgetflag("nx"))
		printf("padding will not work, XON/XOFF required\n");
	if (tgetflag("5i"))
		printf("printer will not echo on\n");
	if (tgetflag("HC"))
		printf("hard cursor\n");
	if (tgetflag("NR"))
		printf("smcup does not reverse rmcup\n");
	if (tgetflag("NP"))
		printf("pad character does not exist\n");
	if (tgetflag("ND"))
		printf("scrolling region is non-destructive\n");
	if (tgetflag("cc"))
		printf("terminal can redefine character set\n");
	if (tgetflag("ut"))
		printf("screen erased with background\n");
	if (tgetflag("hl"))
		printf("terminal uses only HLS color\n");
	if (tgetflag("YA"))
		printf("only positive motion for pha/mhpa caps\n");
	if (tgetflag("YB"))
		printf("using CR turns off micro mode\n");
	if (tgetflag("YC"))
		printf("printer needs operator to change character set\n");
	if (tgetflag("YD"))
		printf("only positive motion for vpa/mvpa caps\n");
	if (tgetflag("YE"))
		printf("printing in last column causes CR\n");
	if (tgetflag("YF"))
		printf("changing character pitch\n");
	if (tgetflag("YG"))
		printf("changing line pitch changes resolution\n");
}
