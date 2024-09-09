#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
	SIGNAL - sets the disposition of the signal signo

	sighandler_t	signal(int signo, sighandler_t handler);

	signal() sets signo to handler or the address of a function
	- if delivered
		- disposition is set to SIG_IGN (it's ignored)
		- set to SIG_DFL (default)
		- or set to a funciton, then SIG_DFL, or blocked
		
	BASICALLY, if signal is caught the handler is called
	SIGKILL or SIGSTOP cannot be caught or ignored

	Return 
		
		returns previous value of the signal handler or on failute SIG_ERR (errno set)
*/

void	handler(int signo)
{
	printf(" Why won't you shut up!\n");
}

int	main(int ac, char **av)
{
	while (1)
	{
		if (signal (SIGINT, handler) == SIG_IGN)
			signal (SIGINT, SIG_IGN);
		printf("Sup.\n");
		usleep(500000);
	}
	return(1);
}

