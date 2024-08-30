#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
	UNLINK - deletes a file from the filesystem

	int unlink(const char *path);
	
	the file specified by path is unlinked from the process:
		- if it's not linked to any other processs && not open in any other process
			then it is deleted


	on success return is 0 and on failure the return is -1
*/

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if ((unlink(av[1])) == 0)
			printf("%s is deleted", av[1]);
		else
			printf("There is no file called %s", av[1]);
	}
	printf("\n");
}
