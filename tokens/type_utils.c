#include "data.h"

/*
	ONLY EXTERNAL FUNCTIONS ALLOWED: 
	readline, rl_clear_history, rl_on_new_line,
	rl_replace_line, rl_redisplay, add_history,
	printf, malloc, free, write, access, open, read,
	close, fork, wait, waitpid, wait3, wait4, signal,
	sigaction, sigemptyset, sigaddset, kill, exit,
	getcwd, chdir, stat, lstat, fstat, unlink, execve,
	dup, dup2, pipe, opendir, readdir, closedir,
	strerror, perror, isatty, ttyname, ttyslot, ioctl,
	getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
	tgetnum, tgetstr, tgoto, tputs ...

	and all the functions in libft
*/

bool is_fd(const char *tk) 
{
	int	i;
	int	fd;

	i = 0;
	if (!tk || tk[0] == '\0')
		return (false);
	while (tk[i])
	{
		if (!isdigit(tk[i]))
			return (false);
		i++;
	}
	fd = atoi(tk);
	return (fd >= 0);
}


bool is_delim(const char *tk) 
{
	if (tk == NULL)	
		return (false);
	return (
		strcmp(tk, ";") == 0 || strcmp(tk, "&&") == 0 ||
		strcmp(tk, "||") == 0 || strcmp(tk, "(") == 0 || strcmp(tk, ")") == 0
	);
}

bool is_filename(const char *tk) 
{
	struct stat	file_stat;

	if (!tk || tk[0] == '\0')
		return (false);
	if (stat(tk, &file_stat) == 0)
	{
		if (S_ISREG(file_stat.st_mode))
			return (true);
	}
	return (false);
}

char	**get_paths()
{
	char	*path_env;
	char	**paths;
	
	path_env = getenv("PATH");
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

bool	is_cmd(const char *tk)
{
	char	*tmp_pathway;
	char	*target_pathway;
	char	**paths;

	paths = get_paths();
	while (*paths)
	{
		tmp_pathway = ft_strjoin(*paths, "/");
		target_pathway = ft_strjoin(tmp_pathway, tk);
		free(tmp_pathway);
		if (access(target_pathway, X_OK) == 0)
			return (true);
		free(target_pathway);
		paths++;
	}
	return (false);
}
