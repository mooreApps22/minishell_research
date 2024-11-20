#include "exec_data.h"

void	execute_path(char **execv, char **envp)
{
	if (execve(execv[0], execv, envp) == -1)
		perror("execve");
}
