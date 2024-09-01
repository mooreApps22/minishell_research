#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

/*
		IOCTL - control device

		int	ioctl(int fd, unsigned long op, ...) // glibc, BSD

		this system call controls parameters of terminals

		returns 0 on sucess and -1 on error (sets errno)
*/

int	main(int ac, char **av)
{
	int				tty;
	struct termios	term;

	if (ac == 1)
	{
		tty = ttyslot();	
		if (tty > 0 && isatty(tty))
		{
			printf("TTY: %s\n", ttyname(tty));
			if ((ioctl(tty, TCGETS, &term)) == -1) // for macOS you'll have to use the TIOCGETA macro
			{
				perror("ioctl TCGETS");
				exit(EXIT_FAILURE);
			}
			term.c_lflag &= ~ECHO;
			if ((ioctl(tty, TCGETS, &term)) == -1)
			{
				perror("ioctl TCGETS");
				exit(EXIT_FAILURE);
			}
			printf("TTY: %s settings modified successfull.\n", ttyname(tty));
		}
		else
			printf("Not a terminal\n");
	}
	return (0);	
}
