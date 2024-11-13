#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
	DUP - duplicate a file descriptor

		int dup(int oldfd);

		returns fd on success and -1 on failure (sets an errno)

	Usage:
		./a.out <filename>
*/

{
}

int	main(int ac, char **av)
{
	int fd1;	
	int fd2;	

	fd1 = open(av[1], O_RDONLY);
	fd2 = dup(fd1);
	if (fd2 == -1)
		printf("Didn't open dup fd");
	else
		printf("The dup fd was opened");
	close(fd1);
	close(fd2);
	printf("\n");
	return (0);
}
