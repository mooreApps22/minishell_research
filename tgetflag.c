#include <curses.h>
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

		"am" (auto_right_margin)
		"bw" (auto_left_margin)
		"xsb" (no_esc_ctlc)
		"xhp" (ceol_standout_glitch)
		"xenl" (eat_newline_glitch)
		"eo" (erase_overstrike)
		"gn" (generic_type)
		"hc" (hard_copy)
		"km" (has_meta_key)
		"hs" (has_status_line)

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
		printf("auto right margin\n");
	if (tgetflag("bw"))
		printf("auto left margin\n");
	if (tgetflag("xsb"))
		printf("no esc-cntl\n");
	if (tgetflag("xhp"))
		printf("ceol standout glitch\n");
	if (tgetflag("xenl"))
		printf("eat newline glitch\n");
	if (tgetflag("eo"))
		printf("erase overstrike\n");
	if (tgetflag("gn"))
		printf("generic type\n");
	if (tgetflag("hc"))
		printf("hard copy\n");
	if (tgetflag("km"))
		printf("has meta key\n");
	if (tgetflag("hs"))
		printf("has status line\n");
}
