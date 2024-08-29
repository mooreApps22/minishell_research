#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

//int sigaction(int signum, const struct sigaction *_Nullable restrict act, struct sigaction *_Nullable restrict oldact);
//int sigemptyset(sigset_t *set);

// signum	- specifies the signal (except SIGKILL & SIGSTOP)
// act		- the new action for signum (non-NULL)
// oldact	- the previous action is saved here (non-NULL)
// RETURN	- 0 on SUCCESS, -1 on error (errno is set)
/*
		struct sigaction {
            void     (*sa_handler)(int);
            void     (*sa_sigaction)(int, siginfo_t *, void *);
            sigset_t   sa_mask;
            int        sa_flags;
            void     (*sa_restorer)(void); // not intented for app use!!
        };

*/

void	sigint_handler(int signum)
{
	printf("\nReceived signal(%d)\n666 is exiting\n", signum);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	struct sigaction sa;

	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	while (true)
	{
		printf("666 is running\n");
		usleep(333334);
	}
	return (0);
}
