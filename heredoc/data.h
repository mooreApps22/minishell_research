#ifndef DATA_H
# define DATA_H

# include "libft/include/libft.h" 
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct s_data	t_data;

typedef	struct s_data
{
	int		fd;
	char	*eof;
	int		pipefd[2];
}	t_data;



#endif
