#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
/*
	FORK - create a new process

		pid_t	fork(void);

			On success both Parent and Child processes return a pid_t
	
			Child returns 0 on success
			Parent returns a positve, non-zero pid_t on success
	
		on failure the parent return -1 (sets errno)
			EAGAIN - too many processes running
			ENOMEN - not enough space 

	Attributes
		- child has its own pid
		- the child knows the parent's pid, this is referred to as the ppid
		- child has a copy of parent's open fildes
		- the elapsed CPU time for child is set to zero
		- no locks are inherited
		- no alarms are set
		- pending signal are cleared
		- sigaction mask is inherited

	WAIT - Causes parent execution to haul until any of the childrens'' execution is finish

		pid_t 	wait(int *wstatus);

			ex: wait(&wstatus);

			WSTATUS is the 

*/

int	main(int ac, char **av)
{
	pid_t	pid;
	int		wstatus;

	if ((pid = fork()) == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid)
	{
		write(1, "Parent: ", 7);
		printf(" can you see me?\n");
		wait(&wstatus);
		printf("Finished\n");
	}
	if (pid == 0)
	{
		write(1, "Child: ", 7);
		printf("can you hear me?\n");
	}
	return (0);
}
