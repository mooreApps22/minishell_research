#include "exec_data.h"

char	*search_path(char *path, char *cmd)
{
	char			*target_path;
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(path);
	if (dir)
	{
		while ((entry = readdir(dir)))
		{
			target_path = check_entry(entry->d_name, path, cmd);
			if (target_path)
			{
				closedir(dir);
				return (target_path);
			}
		}
	}
	closedir(dir);
	return (NULL);
}

char	*search_file_system(char **paths, char **cmdv, char **envp)
{
	char	*target;
	
	//target = search_path(".", cmd); // this is an issue. script don't get exec. unless start w/ ./
	if (cmdv[0][0] == '.' && cmdv[0][1] == '/')
	{
		if (execute_path(cmdv, envp))
			return (NULL);
	}
	if (target)
		return (target);
	while (*paths)
	{
		target = search_path(*paths, cmdv[0]);
		if (target)
			return (target);
		paths++;
	}
}

char	*searcher(t_exe *e)
{
	char	*target;

	if (!e)
		return (NULL);
	target = search_file_system(e->paths, e->cmdv, e->envp);
	if (target)
		return (target);
	return (NULL);
}
