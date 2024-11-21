#include "data.h"

int	main(void)
{
	int		fd;
	char	*buf;

	fd = open("heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	write(1, "> ", 2);
	while ((buf = get_next_line(0)))
	{
		if (ft_strncmp(buf, "EOF", 3) == 0 && buf[3] == '\n')
		{
			free(buf);
			break ;
		}
		write(fd, buf, ft_strlen(buf));
		free(buf);
		write(1, "> ", 2);
	}
	close(fd);

	fd = open("heredoc", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((buf = get_next_line(fd)))
	{
		write(1, buf, ft_strlen(buf));
		free(buf);
	}
	close (fd);
	unlink("heredoc");
	return (0);
}
