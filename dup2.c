#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
	DUP2 - duplicate a file descriptor

	int dup2(int oldfd, int newfd);

	returns newfd on success and -1 on failure (sets an errno)

*/

int	main(int ac, char **av)
{
	int fd1;	
	int fd2;	

	fd1 = open("test.txt", O_RDWR | O_CREAT, 0664); // no need to make sure the file is in the directory
	fd2 = dup2(fd1, fd2);
	if (!fd2)
		printf("Didn't open dup fd");
	else
		printf("The dup fd was opened");
	close(fd1);
	close(fd2);
	printf("\n");
	return (0);
}
