#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// int open(const char *pathname, int flags, mode_t mode);

// ./a.out song.txt "all the small things"
// cat song.txt

int main(int ac, char **av)
{
	int fd;

	fd = open(av[1], O_CREAT | O_RDWR, 0660);
	if (fd == -1)
		write(1, "error\n", 6);
	write(fd, av[2], strlen(av[2]));
	close(fd);
	return (0);
}
