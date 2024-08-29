#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <unistd.h>

// pid_t wait4(pid_t pid, int *_Nullable wstatus, int options, struct rusage *_Nullable rusage);
// wait4(pid, wstatus, options, rusage) <notice the four arguments>

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
	wait = wait4(pid, &status, 0, &usage);
	if (wait == -1)
	{
		perror("wait4");
		exit(1);
	}
	if (WIFEXITED(status))
		printf("Child %d exiting with status %d\n", wait, WEXITSTATUS(status));
	printf("User CPU used: %ld.%06ld secs \n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec); // utime
	printf("System CPU used: %ld.%06ld secs\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec); // stime
	return (0);
}
