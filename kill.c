#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/*

	KILL - sends a signal to a process, usually to terminate it

		int	kill(pid_t pid, int sig);
		
		PID 
			> 0		- sig sent to pid
			== 0	- sig sent to all in gpid
			== -1	- sig sent to permissable processes except pid 1
			< -1	- sig sent to all gpid whose is -pid
		sig
			== 0	- no sig is sent, but checks if pid exist & is permissable

		return
			on Success 0 is return, on Failure -1 is returned
			errno is set
*/

volatile sig_atomic_t	g_signal = 0; // to indicate a received signal

void	handler(int sig)
{
	g_signal = 1;
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;
//	sigset_t			sigset;

	pid = fork();
//	sigemptyset(&sigset);
	sa.sa_handler = handler;

	sigaction(SIGUSR1, &sa, NULL);
	if (pid == 0)
	{
		sleep(4);
		printf("child is killing\n");
		kill(pid, SIGUSR1);
		exit(0);
	}
	while (!g_signal)
	{
		printf("parent is running\n");
		usleep(500000);
	}
	printf("parent is exiting\n");
	return (0);
}
