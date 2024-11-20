#include <unistd.h> // contains __environ
#include <stdio.h>
#include <stdlib.h>

/*
	EXECVE - execute program

		int execve(const char *path, char *const _Nullable av[], char *const _Nullable envp[])

		returns 0 on success and -1 on failure


	Setup to use program!!!!!!

	create a simple hello_world.c
		cc hello_world.c -o hello_world
		cc execve.c
		./a.out hello_world

  NOTE: the target of the execve.c is an executable, not the .c file
*/

void	handle_error(char *msg)
{
	perror(msg);
	exit(1);
}

void	execute_cmd(char **argv)
{
	if (execve(argv[1], argv, __environ) == -1)
		handle_error("execve");
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		execute_cmd(av);
	printf("\n");
	return (0);
}
