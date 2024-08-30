#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
		PIPE - creates a one way pipe with a write end and a read end

		int	pipe(int pipefd[2]);

		pipefd[0]	- read end
		pipefd[1]	- write end

		the point is to read data from process 1 && write that data to process 2

		return 0 on success and -1 on failure (errno is set)
*/

void	child_process(int *pipefd, char **av)
{
	dup2(pipefd[1], 0);
	close(pipefd[0]);
	printf("PID %d: %s\n", getpid(), av[1]); // will work with '\n'
//	printf("PID %d: %s", getpid(), av[1]); // will work with '\n'
	close(pipefd[0]);
	_exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int		pipefd[2];
	pid_t	child_pid;

	if (ac == 2)
	{
		if (pipe(pipefd) == -1)	
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		child_pid = fork();
		if (child_pid == 0)
			child_process(pipefd, av);
	}
	else
		printf("Enter 1 argument, no more, no less");
//	waitpid(child_pid, NULL, 0);
}
