#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

// pid_t	fork(void);

void	child1(void)
{
	int i;
	
	i = 0;
	while (i < 1000000)
	{
		i++;
	}
	exit(1);
}

void	child2(void)
{
	int i;
	
	i = 0;
	while (i < 100)
	{
		i++;	
	}
	exit(1);
}

int	main(int ac, char **av)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == 0)
		child1();
	pid2 = fork();
	if (pid2 == 0)
		child2();
	if (waitpid(pid1, NULL, 0))
		printf("waitpid(&pid1)\n");
	if (waitpid(pid2, NULL, 0))
		printf("waitpid(&pid2)\n");
	return (0);
}
