#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>

/*
			RETRIEVING & CHANGING TERMINAL SETTINGS
	
	TCGETATTR - get terminal attributes

		int	tcgetattr(int fd, construct termios *term);

		Gets FD's attributes and put them in TERM.		
			

	TCSETATTR - set terminal attributes

		int	tcsetattr(int fd, int when, construct termios *term);
		
		Sets any changes made to the attributes saved in TERM.
		Specifies WHEN macros.
			-TCSANOW
			-TCSADRAIN
			-TCSAFLUSH
*/

int	main(int ac, char **av)
{
	struct termios	settings;
	int	on;

	if (ac != 2)
	{
		printf("Argument must be on or off\n");
		exit(EXIT_FAILURE);
	}
	on = 0;
	if ((strcmp(av[1], "on")) == 0)
		on = 1;

	if (tcgetattr(0, &settings) == -1)
	{
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
	if (on)
		settings.c_lflag = settings.c_lflag | ECHO;
	else if (!on)
		settings.c_lflag = settings.c_lflag & ~ECHO;
	else
		printf("Error\n");

	if (tcsetattr(0, TCSANOW, &settings) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}

	if ((settings.c_lflag & ECHO))
		printf("Echo on.\n");
	else
		printf("Echo off.\n");	

	return (0);	
}
