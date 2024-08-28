#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <unistd.h>

//pid_t   wait3(int *stat_loc, int options, struct rusage *resource_usage)
// wait3 allows the call process to obtain status info for a specified child process

void	child(void)
{
	printf("Child %d running...\n", getpid());
	sleep(4);
	exit(0);
}

int	main(int ac, char **av)
{
	pid_t			pid;
	pid_t			wait;
	int				status;
	struct rusage	usage;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
		child();
	printf("Parent %d running...\n", getpid());
	wait = wait3(&status, 0, &usage);
	if (wait == -1)
	{
		perror("wait3");
		exit(1);
	}
	if (WIFEXITED(status))
		printf("Child %d exiting with status %d\n", wait, WEXITSTATUS(status));
	printf("User CPU used: %ld.%06ld secs \n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec); // utime
	printf("System CPU used: %ld.%06ld secs\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec); // stime
	return (0);
}
