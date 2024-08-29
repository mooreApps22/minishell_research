#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\nReceived signal[%d]\n666 is SIGINT-ing\n", sig);
		exit(EXIT_SUCCESS);
	}
	else if (sig == SIGSTOP)
		printf("\nReceived signal[%d]\n666 is SIGSTOP-ing\n", sig);
	else if (sig == SIGQUIT)
		printf("\nReceived signal[%d]\n666 is SIGQUIT-ing\n", sig);
	else if (sig == SIGTSTP)
		printf("\nReceived signal[%d]\n666 is SIGTSTP-ing\n", sig);
}

void	check_sigact(struct sigaction *sa, int sig)
{
	if (sigaction(sig, sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	struct sigaction sa;

	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART; // sa_flags now includes SA_RESTART
	check_sigact(&sa, SIGQUIT);
	check_sigact(&sa, SIGINT);
	check_sigact(&sa, SIGTSTP);
	while (true)
	{
		printf("666 is running\n");
		usleep(333334);
	}
	return (EXIT_SUCCESS);
}
