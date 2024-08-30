#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/*
		SIGADDSET - add a signal to a signal set

		int	sigaddset(sigset_t *set, int signo);

		prior to any use of a sigset_t object, one must use sigemptyset() or sigaddset() or the results of sigaddset() is undefined
*/

void	hand(int signo)
{
	printf("hand() has %d\n", signo);
}

int	main(void)
{
	struct sigaction		sa;
	sigset_t				sigset;
	pid_t					pid;

	sigemptyset(&sa.sa_mask); 
	sigaddset(&sigset, SIGUSR1);
	sa.sa_handler = hand;
	sa.sa_mask = sigset;
	sa.sa_flags = 0; // MACROs
	sigaction(SIGUSR1, &sa, NULL); // defines/re-defines SIGUSR1 w/ sigaction object data
	pid = getpid();
	printf("%d is running\n", pid);
	printf("%d is killing\n", pid);
	kill(pid, SIGUSR1); // runs sa.sa_handler
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR1);
	return (0);
}
