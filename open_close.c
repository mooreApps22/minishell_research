#include <fcntl.h>
#include <unistd.h>
#include <string.h>


// int open(const char *pathname, int flags, mode_t mode);

// ./a.out song.txt "all the small things"
// cat song.txt

void	open_file(char *name, char *content)
{
	int fd;

	fd = open(name, O_CREAT | O_RDWR, 0660);
	if (fd == -1)
		write(1, "error\n", 6);
	write(fd, content, strlen(content));
	close(fd);
}

int main(int ac, char **av)
{
	open_file(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
