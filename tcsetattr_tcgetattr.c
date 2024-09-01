#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>

/*
		TCGETATTR - get the parameters associated with the terminal

		int	tcgetattr(int fd, const struct termios *term);

		Returns 0 on success or -1 on failure (sets errno)
***
***
		TCSETATTR - set parameters associated with the terminal

		int	tcsetattr(int fd, int opt, const struct termios *term);

		fd - terminal's file descriptor 

		opt - TCSANOW | TCSADRAIN | TCSAFLUSH

		term - output baud rate (BIT PER SEC) stored in termios struct pointer

		Returns 0 on success or -1 on failure (sets errno)

		STD BAUD RATES:
			
			4800, 9600, 19200, 38400, 57600, 115200, 230400 460800, 921600
		
			#include <termios.h>

		struct termios
		{
			tcflag_t c_iflag; // control chars
			tcflag_t c_oflag; // control modes
			tcflag_t c_cflag; // input modes
			tcflag_t c_lflag; // local modes
			cc_t c_cc[NCCS];  // output modes
			speed_t c_ispeed; // input  baud rate
			speed_t c_ospeed; // output baud rate
		};
*/

void print_iflags(tcflag_t iflag)
{
    if (iflag & IGNBRK)
        printf("IGNBRK is set (ignore Ctrl-BREAK)\n");
    if (iflag & BRKINT)
        printf("BRKINT is set (Generate SIGINT on Ctrl-BREAK)\n");
    if (iflag & IGNPAR)
        printf("IGNPAR is set (ignored)\n");
    if (iflag & PARMRK)
        printf("PARMRK is set (ignored)\n");
    if (iflag & INPCK)
        printf("INPCK is set (ignored)\n");
    if (iflag & ISTRIP)
        printf("ISTRIP is set (strip the 8th bit from input)\n");
    if (iflag & INLCR)
        printf("INLCR is set (Map NL to CR in input)\n");
    if (iflag & IGNCR)
        printf("IGNCR is set (Ignore CR characters)\n");
    if (iflag & ICRNL)
        printf("ICRNL is set (Map CR to NL on input)\n");
    if (iflag & IXON)
        printf("IXON is set (ignored)\n");
    if (iflag & IXOFF)
        printf("IXOFF is set (Enable start/stop input control)\n");
    if (iflag & IMAXBEL)
        printf("IMAXBEL is set (Ring the bell if input line too long)\n");
}

void print_oflags(tcflag_t oflag)
{
    if (oflag & OPOST)
        printf("OPOST is set (If not set, output character verbatim)\n");
    if (oflag & ONLCR)
        printf("ONLCR is set (Map NL to CR-NL on output)\n");
    if (oflag & OCRNL)
        printf("OCRNL is set (Map CR to NL on output)\n");
    if (oflag & ONOCR)
        printf("ONOCR is set (No CR output at column 0)\n");
    if (oflag & ONLRET)
        printf("ONLRET is set (NL performs CR function)\n");
    // Add other flags as needed
}

void print_cflags(tcflag_t cflag)
{
    if (cflag & CSIZE)
        printf("CSIZE is set (Character size mask)\n");
    if (cflag & PARENB)
        printf("PARENB is set (Enable parity generation on output and parity checking for input)\n");
    if (cflag & PARODD)
        printf("PARODD is set (Odd parity instead of even)\n");
    if (cflag & CSTOPB)
        printf("CSTOPB is set (Send two stop bits, else one)\n");
    if (cflag & CREAD)
        printf("CREAD is set (Enable receiver)\n");
    // Add other flags as needed
}

void print_lflags(tcflag_t lflag)
{
    if (lflag & ISIG)
        printf("ISIG is set (Enable signals)\n");
    if (lflag & ICANON)
        printf("ICANON is set (Canonical mode)\n");
    if (lflag & ECHO)
        printf("ECHO is set (Enable echo)\n");
    if (lflag & ECHOE)
        printf("ECHOE is set (Echo ERASE as BS-SP-BS)\n");
    if (lflag & ECHOK)
        printf("ECHOK is set (Echo NL after kill)\n");
    // Add other flags as needed
}

void	print_termios(struct termios term)
{
	printf("Iflag: %d\n", term.c_iflag);
	printf("Oflag: %d\n", term.c_oflag);
	printf("Cflag: %d\n", term.c_cflag);
	printf("Lflag: %d\n", term.c_lflag);
	printf("CC: %s\n", term.c_cc);
	printf("Ispeed: %d\n", term.c_ispeed);
	printf("Ospeed: %d\n", term.c_ospeed);
}

int	main(int ac, char **av)
{
	int				fd;	
	struct	termios	term;

	fd = STDOUT_FILENO;
	if (tcgetattr(fd, &term) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
//	print_termios(term);
	printf("________________Iflag: %d____________________\n", term.c_iflag);
    print_iflags(term.c_iflag);
	printf("________________Oflag: %d____________________\n", term.c_oflag);
    print_oflags(term.c_oflag);
	printf("________________Cflag: %d____________________\n", term.c_cflag);
    print_cflags(term.c_cflag);
	printf("________________Lflag: %d____________________\n", term.c_lflag);
    print_lflags(term.c_lflag);
	if (ac == 1)
	{
		if (tcsetattr(fd, TCSANOW, &term) == -1)
		{
			perror("tcsetattr");
			exit(EXIT_FAILURE);
		}
	}
	//print_termios(term);
	return (0);
}
