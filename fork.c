#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

// pid_t	fork(void);

int	main(int ac, char **av)
{
	pid_t	pid;

	pid = fork();
	if (pid)
		printf("Parent: %d\n", getpid());
	if (pid == 0)
		printf("Child:  %d\n", getpid());
	wait(&pid);
	return (0);
}
