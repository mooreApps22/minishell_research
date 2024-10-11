#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

/*
		TCGETATTR - get terminal attributes/parameters

			int tcgetattr(int fd, const struct termios *term);
		
		TCSETATTR - set terminal atributes/parameters

			int tcsetattr(int fd, int opt, const struct termios *term);

		fd - the terminal fd
		opt - TCSANOW | TCSADRIAN | TCSAFLUSH
		term - struct w/ flags

		both return 0 on success and -1 on failure (sets errno)

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

  		ECHO 	= Enables echo of input characters
    		ICANON 	= Enables canonical mode (process line by line)
      		ISIG 	= Enables signal generation for control character/signals
*/

void	output_terminal_attr(struct termios term);
void	print_iflags(tcflag_t iflag);
void	print_oflags(tcflag_t oflag);
void	print_cflags(tcflag_t cflag);
void	print_lflags(tcflag_t lflag);
void	print_ccflags(struct termios term);
void	print_ispeed(speed_t ispeed);
void	print_ospeed(speed_t ospeed);

int	main(int ac, char **av)
{
	int				fd;
	struct termios	term;

	fd = STDOUT_FILENO;
	if (tcgetattr(fd, &term) == -1) // you now have terminal attributes
	{
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
	output_terminal_attr(term);
	printf("\n\n");
	term.c_iflag |= (INLCR);
	if (tcsetattr(fd, TCSANOW ,&term) == -1) // you now have terminal attributes
	{
		perror("tcgetattr");
		exit(EXIT_FAILURE);
	}
	output_terminal_attr(term);
	printf("\n_____________Important Note_____________\n");
	printf("See termios Linux man page for more on flags!!\nResult may vary on different systems!!\n");
	return (EXIT_SUCCESS);
}

void	output_terminal_attr(struct termios term)
{
	print_iflags(term.c_iflag);
	print_oflags(term.c_oflag);
	print_cflags(term.c_cflag);
	print_lflags(term.c_lflag);
	print_ispeed(term.c_ispeed);
	print_ospeed(term.c_ospeed);


}

void	print_iflags(tcflag_t iflag)
{
	printf("_____________Print I Flags_____________\n");
	if (iflag & IGNBRK) //BRKINT?
		printf("IGNBRK: Ignor Break on input\n");
	if (iflag & IGNPAR) // PARMRK?
		printf("IGNPAR: Ignore framing errors and parity errors\n");
	if (iflag & INPCK) 
		printf("INPCK: Enable input parity checking\n");
	if (iflag & ISTRIP)
		printf("ISTRIP: Strip off eigth bit\n");
	if (iflag & INLCR)
		printf("INLCR: Translate NL to CR on input\n");
	if (iflag & IGNCR)
		printf("IGNCR: Ignore carriage return on input\n");
	if (iflag & ICRNL)
		printf("ICRNL: Translate carriage return to newline on input (unless IGNCR is set)\n");
	if (iflag & IXON)
		printf("IXON: Enable XON/XOFF flow control on output\n");
	if (iflag & IXANY)
		printf("IXANY: (XSI) Typing any character will restart stopped output.\n");
	if (iflag & IXOFF)
		printf("IXOFF: Enable XON/XOFF flow control on input\n");
}

void	print_oflags(tcflag_t oflag)
{
	printf("_____________Print O Flags_____________\n");
	if (oflag & OPOST)
		printf("OPOST: Enable implementation-define output processing\n");
	if (oflag & ONLCR)
		printf("ONLCR: (XSI) Map NL to CR-NL on output\n");
	if (oflag & OCRNL)
		printf("OCRNL: Map CR to NL on output\n");
	if (oflag & ONOCR)
		printf("ONOCR: Don't output CR at column 0\n");
	if (oflag & ONLRET)
		printf("ONLRET: The NL char is assumed to do the carriage-return function\nThe kernel's set the current column to 0 after both NL and CR\n");
	if (oflag & OFILL)
		printf("OFILL: Send fill chars for a delay, rather than using a timed delay\n");
	if (oflag & OFDEL)
		printf("OFDEL: Fill character is ASCII DEL, else NULL\n");
	if (oflag & NLDLY)
		printf("NLDLY: Newline delay mask. Values are NL0 and NL1\n");
	if (oflag & TABDLY)
		printf("TABDLY: Horizontal tab delay mask.\n");
	if (oflag & BSDLY)
		printf("BSDLY: Backspace delay mask.\n");
	if (oflag & VTDLY)
		printf("VTDLY: Vertical tab delay mask.\n");
	if (oflag & FFDLY)
		printf("FFDLY: Form feed delay mask.\n");
}

void	print_cflags(tcflag_t cflag)
{
	printf("_____________Print C Flags_____________\n");
	if (cflag & CSIZE)
		printf("CSIZE: Character size mask. Values: CS5, CS6, CS7, CS8\n");
	if (cflag & CSTOPB)
		printf("CSTOP: BSet two stop bits, rather than one.\n");
	if (cflag & CREAD)
		printf("CREAD: Enable receiver\n");
	if (cflag & PARENB)
		printf("PARENB: Enable parity generation on output and parity check for input.\n");
	if (cflag & PARODD)
		printf("PARODD: If set, then parity for input and output is odd; else even\n");
	if (cflag & HUPCL)
		printf("HUPCL: Lower modem control lines after last process closes the device (hang up).\n");
	if (cflag & CLOCAL)
		printf("CLOCAL: Ignore modem control lines.\n");
}

void	print_lflags(tcflag_t lflag)
{
	printf("_____________Print L Flags_____________\n");
	if (lflag & ISIG)
		printf("ISIG: When any of the characters INTR, QUIT, SUSP, or DSUSP are received, generate the corresponding signal\n");
	if (lflag & ICANON)
		printf("ICANON: Enable canonical mode (see man termios)\n");
	if (lflag & ECHO)
		printf("ECHO: Echo input characters.\n");
	if (lflag & ECHOE)
		printf("ECHOE: IF ICANON is set, ERASE erases last input char, WERASE erases last word.\n");
	if (lflag & ECHOK)
		printf("ECHOK: If ICANON is set, KILL erases the current line.\n");
	if (lflag & ECHONL)
		printf("ECHONL: If ICANON is set, echo NL even if ECHO not set.\n");
	if (lflag & NOFLSH)
		printf("NOFLSH: Disable flush of input and output queues when generating signals: INT, QUIT, SUSP characters.\n");
	if (lflag & IEXTEN)
		printf("IEXTEN: Enable implementation-defined input processing.\n");
}

void	print_ccflags(struct termios term)
{
	int i;
	printf("_______________Control Characters Flags____________\n");
	i = 0;
	while (i < 11)
	{
	
		//printf("c_cc: %hhu\n", term.c_cc[i]);
		if (term.c_cc[i] & VEOF)
			printf("VEOF: Signal End-Of-Input (Ctrl-D)\n");
		if (term.c_cc[i] & VEOL)
			printf("VEOL: Signal End-Of_Line [Disabled]\n");
		if (term.c_cc[i] & VERASE)
			printf("VERASE: Delete previous character (Backspace)\n");
		if (term.c_cc[i] & VINTR)
			printf("VINTR: Generate SIGINT (Ctrl-C)\n");
		if (term.c_cc[i] & VKILL)
			printf("VKILL: Erase current line (Ctrl-U)\n");
		if (term.c_cc[i] & VMIN)
			printf("VMIN: The MIN value (1)\n");
		if (term.c_cc[i] & VQUIT)
			printf("VQUIT: Generate SIGQUIT (Ctrl-\\)\n");
		if (term.c_cc[i] & VSTART)
			printf("VSTART: Resume output (Ctrl-Q)\n");
		if (term.c_cc[i] & VSTOP)
			printf("VSTOP: Suspend output (Ctrl-S)\n");
		if (term.c_cc[i] & VSUSP)
			printf("VSUSP: Suspend program (Ctrl-Z)\n");
		if (term.c_cc[i] & VTIME)
			printf("VTIME: (0)\n");
		i++;
	}
}

void	print_ispeed(speed_t ispeed)
{
	printf("_______________Baud Rate____________\n");
	if (ispeed)
		printf("Input Speed: %d bits per sec\n", ispeed);
}

void	print_ospeed(speed_t ospeed)
{
	if (ospeed)
		printf("Output Speed: %d bits per sec\n", ospeed);
}
