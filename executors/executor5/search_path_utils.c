#include "exec_data.h"

bool	check_access(char *target_path)
{
	if (access(target_path, X_OK) == -1)
	{
		perror("access");
		return (false);
	}
	return (true);
}

static char	*join_path_and_cmd(char *path, char *cmd)
{
	char	*tmp_path;
	char	*target_path;

	tmp_path = ft_strjoin(path, "/");
	target_path = ft_strjoin(tmp_path, cmd);
	free(tmp_path);
	if (!target_path)
		return (NULL);
	return (target_path);
}

char	*check_entry(char *entry, char *path, char *cmd)
{
	char	*target_path;

	if (strcmp(entry, cmd) == 0)
	{
		target_path = join_path_and_cmd(path, cmd);
		if (!target_path)
			return (NULL);
		if (check_access(target_path))
			return (target_path);
	}
	return (NULL);
}
