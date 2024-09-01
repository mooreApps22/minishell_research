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

		struct winsize
		{
			unsigned short	ws_row;
			unsigned short	ws_col;
			unsigned short	ws_xpixel;
			unsigned short	ws_ypixel;
		}
*/

int	main(int ac, char **av)
{
	struct winsize		ws;
	int					fd;

	fd = STDOUT_FILENO;
	if (ioctl(fd, TIOCGWINSZ, &ws) == -1)
	{
		perror("ioctl");
		return (EXIT_FAILURE);
	}
	printf("___Terminal Size_____________\n");
	printf("\tRows:\t\t%d\n", ws.ws_row);
	printf("\tCols:\t\t%d\n", ws.ws_col);
	printf("\tX Pixels:\t%d\n", ws.ws_xpixel);
	printf("\tY Pixels:\t%d\n", ws.ws_ypixel);
	printf("____________________________\n");
	return (0);	
}
