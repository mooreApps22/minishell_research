#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "tokens/libft/include/libft.h"

/*
	OPENDIR - open a directory

		DIR	*opendir(const char *name);

		returns a pointer the directory stream

	CLOSERDIR - close a directory

		int	closedir(DIR *dirp);

		returns a 0 on success and -1 on failure (sets errno)

	READDIR - read a directory

	struct dirent	*readdir(DIR *dirp);

	struct direct
	{
		ino_t			d_ino;				// inode number
		off_t			d_off;				// returns current location in directory stream
		unsigned short	d_reclen;			// length of this record
		unsigned char	d_type;				// type of file, not support in all filesystems
		char			d_name[256];		// null-term filename
	};
*/

char	**get_paths(void)
{
	char	*path_env;
	char	**paths;

	path_env = getenv("PATH");
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

void	free_all_paths(char **paths)
{
	int i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

bool	check_access(char *cmd)
{
	if (access(cmd, X_OK))
		return (false);
	return (true);
}

char	*join_path_and_cmd(char **paths, char *cmd)
{
	char	*target_path;
	char	*tmp_path;

	tmp_path = ft_strjoin(*paths, "/");
	target_path = ft_strjoin(tmp_path, cmd);
	free(tmp_path);
	if (!target_path)
		return (NULL);
	return (target_path);
	
}

bool	check_entry(char *entry, char **paths, char *cmd)
{
	char			*target_path;

	if (strcmp(entry, cmd) == 0)
	{
		target_path = join_path_and_cmd(paths, cmd);
		if (check_access(target_path))
		{
			free(target_path);
			return (true);
		}
		free(target_path);
	}
	return (false);
}

bool	search_dirs(char **paths, char *cmd)
{
	DIR				*dir;
	struct dirent	*entry;

	while (*paths)
	{
		dir = opendir(*paths);
		if (dir)
		{
			while ((entry = readdir(dir)))
				if (check_entry(entry->d_name, paths, cmd))
				{
					closedir(dir);
					return (true);
				}
		}
		closedir(dir);
		paths++;
	}
	return (false);
}

int	main(int ac, char **av)
{
	char			**paths;

	paths = get_paths();
	if (!paths)
		return (1);
	if (search_dirs(paths, av[1]))
		printf("Found: You can exec %s\n", av[1]);
	else
		printf("%s: command not found\n", av[1]);
	free_all_paths(paths);
	return (0);
}
