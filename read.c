#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// ssize_t	read(int fd, void buf[.count], size_t count);
// ./a.out <file name>

int main(int ac, char **av)
{
	int		fd;
	ssize_t	nb;
	char	*buf;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		write(1, "File not found\n", 6);
	while (1)
	{
		buf = malloc(2);
		if (!buf)
			return (1);
		nb = read(fd, buf, 1);
		if (!nb)
		{
			free(buf);
			return (2);
		}
		buf[nb] = '\0';
		write(1, buf, 1);
		// do stuff to buf
		free(buf);
	}
	close(fd);
	return (0);
}
