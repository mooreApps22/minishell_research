#include "exec_data.h"

int	count_vector(char **av)
{
	int		size;

	if (!av)
		return (0);
	size = 0;
	while (*av)
	{
		size++;
		av++;
	}
	return (size);
}

char	**init_cmdv(char **av, int size)
{
	char	**cmdv;
	int		i;

	i = 0;
	cmdv = malloc(sizeof(char *) * (size + 1));
	if (!cmdv)
		return (NULL);
	while (i < size)
	{
		cmdv[i] = av[i + 1];
		i++;
	}
	cmdv[i] = NULL;
	return (cmdv);
}

char	**init_execv(t_exe *e)
{
	char	**execv;
	char	*target_path;
	int		i;

	if (!e)
		return (NULL);
	i = 1;
	target_path = searcher(e);
	if (!target_path)
		return (NULL);
	execv = malloc(sizeof(char *) * (e->size + 1));
	execv[0] = target_path;
	while (i < e->size)
	{
		execv[i] = e->cmdv[i];
		i++;
	}
	execv[i] = NULL;
	return (execv);
}

t_exe	*init_exe(char **av, char **envp)
{
	t_exe	*e;
	int		size;

	size = count_vector(av);
	e = malloc(sizeof(t_exe) * (size + 1));
	if (!e)
		return (NULL);
	e->size = size;
	e->envp = envp;
	e->cmdv = init_cmdv(av, size);
	e->paths = get_paths();
	e->execv = init_execv(e);
	return (e);
}

void	free_exe(t_exe *e)
{
	free_paths(e->paths);
	free_paths(e->cmdv);
	free_paths(e->execv);
	free(e);
}
