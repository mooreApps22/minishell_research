#include <fcntl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "tokens/libft/include/libft.h"

/*
	ACCESS - check user's permissions for a file'

	int access(const char *pathname, int mode);

		Checks a MODE of permission of a file located at PATHNAME

		Returns 0 if granted permission and -1 on Failure or denied permission

	Modes: R_OK, W_OK, X_OK, F_OK (Read, Write, Execute, File)

	Necessary Compile Archive for ft_strjoin:

	cc access.c libft.a

	Testing Info:

		This program takes av[1] and will test if it's in the execuable or not
*/

int main(int ac, char **av)
{
	if (ac == 2)
	{
		if ((access(av[1], X_OK)))
			printf("%s: command not found", av[1]);
		else
			printf("%s is valid command", av[1]);
	}
	printf("\n");
	return (0);
}
