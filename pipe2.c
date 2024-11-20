#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
	write = 1, read = 0

	create pipe ends
	fork first process
	close unused read end = close 0
	swap stdout with write end
	exec
	fork next process
	close unused write end = close 1
	swap stdin with read end
	exec
	close 0
	close 1
	wait
	wait
*/


int	main(int ac, char **av)
{
	pid_t 	pid;
	int		status;
	int		pipefds[2];

	pipe(pipefds);
	pid = fork();
	if (pid == 0)
	{
		close(pipefds[0]);
		dup2(pipefds[1], STDOUT_FILENO);
		execlp(av[1], av[1], (char *)NULL);
	}
	pid = fork();
	if (pid == 0)
	{
		close(pipefds[1]);
		dup2(pipefds[0], STDIN_FILENO);
		execlp(av[2], av[2], (char *)NULL);
	}
	close(pipefds[0]);
	close(pipefds[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	exit(0);
}
