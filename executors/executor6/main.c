#include "exec_data.h"

/*
typedef struct s_exe
{
	int		size;
	char	**envp;
	char	**cmdv;
	char	**paths;
	char	**execv;
}	t_exe;

*/

// ./a.out ls -l

bool	execute_path(char **execv, char **envp)
{
	if (execve(execv[0], execv, envp) == -1)
	{
		perror("execve");
		return (true);
	}
	return (false);
}

bool	executor(char **av, char **envp)
{
	t_exe	*e;

	if (!av || !envp)
		return (false);
	e = init_exe(av, envp);
	if (!e)
		return (false);
	if (execute_path(e->execv, envp))
	{
		free_exe(e);
		return (true);
	}
	free_exe(e);
	return (false);
}

int	main(int ac, char **av, char **envp)
{
	if (ac < 2 )
		return (99);
	if (executor(av, envp))
		return (0);
	return (1);
}
