#include "exec_data.h"

int	count_input_vector(char **input)
{
	int	ct;

	ct = 0;
	while (*input)
	{
		ct++;
		input++;
	}
	return (ct);
}

char	**get_command_vector(char **input, int input_size)
{
	char	**cmdv;
	int		i;

	i = 0;
	cmdv = malloc(sizeof(char *) * (input_size + 1));
	if (!cmdv)
		return (NULL);
	while (i < input_size)
	{
		cmdv[i]	= input[i + 1];
		i++;
	}
	cmdv[i] = NULL;
	return (cmdv);
}

void	get_executable_vector(char **cmdv, int input_size, char **envp)
{
	char	**paths;
	char	*target_path;
	char	**execv;

	paths = get_paths();
	if (!paths)
		return ;
	while (*paths)
	{
		target_path = search_paths(*paths, cmdv[0]);
		if (target_path)
		{
			execv = replace_cmd_with_path(target_path, cmdv, input_size);
			execute_path(execv, envp);
			free(target_path);
			free_paths(paths);
			free_paths(execv);
		}
		paths++;
	}
	free_paths(paths);
}

//		./a.out ls -l	==> /usr/bin/ls -l

int	main(int ac, char **av, char **envp)
{
	char	**cmdv;
	int		input_size;


	if (ac < 2)
		return (1);
	input_size = count_input_vector(av);
	cmdv = get_command_vector(av, input_size); // 			ls, -l
	get_executable_vector(cmdv, input_size, envp); //		/usr/bin/ls, -l
	free(cmdv);
	return (0);
}
