#include "exec_data.h"

char	**get_paths(void)
{
	char	*path;
	char	**paths;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

void	free_paths(char **paths)
{
	while (*paths)
	{
		free(paths);
		paths++;
	}
	free(paths);
}
