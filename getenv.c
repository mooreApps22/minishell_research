#include <unistd.h> // contains __environ
#include <stdio.h>

/*
	EXECVE - execute program

		int execve(const char *path, char *const _Nullable av[], char *const _Nullable envp[])

		returns 0 on sucess and -1 on failure


	Setup to use program!!!!!!

	create a simple hello_world.c
		cc hello_world.c -o hello_world
		cc execve.c
		./a.out hello_world

  NOTE: the target of the execve.c is an executable, not the .c file
*/

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (execve(av[1], av, __environ))
			printf("%s: was not found", av[1]);
	}
	printf("\n");
	return (0);
}
