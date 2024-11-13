#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/*
	DUP2 - duplicate a file descriptor

		int dup2(int oldfd, int newfd);

		NEWFD now refers to OLDFD

		returns newfd on success and -1 on failure (sets an errno)

	Usage:
	./a.out <filename> <message to write to filename>
*/

void	create_new_file(char *filename, char *msg)
{
	int oldfd;	
	int newfd;	

	oldfd = open(filename, O_RDWR | O_CREAT, 0664); // no need to make sure the file is in the directory
	newfd = dup2(oldfd, newfd);
	if (newfd == -1)
		printf("Didn't open dup fd");
	else
	{
		write(newfd, msg, strlen(msg));
		write(newfd, "\n", 1);
	}
	close(newfd);
	close(oldfd);
}

int	main(int ac, char **av)
{
	create_new_file(av[1], av[2]);
	printf("\n");
	return (0);
}
