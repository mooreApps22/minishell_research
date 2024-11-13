#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "tokens/libft/include/libft.h" 

//#include <.h>

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

void	free_paths(char **paths)
{
	int i;

	i = 0;
	if (paths)
	{
		while (paths[i])
			free(paths[i++]);
		free(paths);
	}
}


int	main(int ac, char **av)
{
	char			**paths;
	char			*target_path;
	char			*tmp_path;
	DIR				*dir;
	struct dirent	*entry;

	paths = get_paths();
	if (!paths)
		return (1);
	while (*paths)
	{
		dir = opendir(*paths);
		if (dir)
		{
			while ((entry = readdir(dir)))
			{
				if (strcmp(entry->d_name, av[1]) == 0)
				{
					tmp_path = ft_strjoin(*paths, "/");
					target_path = ft_strjoin(tmp_path, av[1]);
					free(tmp_path);
					if (access(target_path, X_OK) == 0)
					{
						free(target_path);
						closedir(dir);
						free_paths(paths); //
						printf("Found\n");
						return (0);
					}
					free(target_path);
				}
			}
			closedir(dir);
		}
		paths++;
	}
	free_paths(paths); //
	printf("Not Found\n");
	return (1);
}
