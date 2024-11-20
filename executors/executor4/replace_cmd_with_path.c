#include "exec_data.h"

char	**replace_cmd_with_path(char *target_path, char **cmdv, int size)
{
	char	**execv;
	int		i;

	i = 1;
	execv = malloc(sizeof(char *) * (size + 1));
	if (!execv)
		return (NULL);
	execv[0] = target_path;
	while (i < size)
	{
		execv[i] = cmdv[i];
		i++;
	}
	execv[i] = NULL;
	return (execv);
}
