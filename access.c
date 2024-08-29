#include <fcntl.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

// int access(const char *pathname, int mode);
// Modes: R_OK, W_OK, X_OK, F_OK (Read, Write, Execute, File)

int main(int ac, char **av)
{
	if (strcmp("check_readable", av[1]) == 0)
	{
		if ((access("./test_read.txt", R_OK)) == 0) // success == 0
			printf("You can read test_read.txt");
	}
	else if (strcmp("check_unreadable", av[1]) == 0)
	{
		if ((access("./test_unread.txt", R_OK)))  // failure == -1 
			printf("You can't read test_unread.txt");
	}
	printf("\n");
	return (0);
}
