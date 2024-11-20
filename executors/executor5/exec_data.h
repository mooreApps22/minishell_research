#ifndef EXEC_DATA_H
# define EXEC_DATA_H

#include <sys/types.h>
#include <dirent.h>
#include "exec_data.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "libft/include/libft.h"

typedef struct s_exe	t_exe;

typedef struct s_exe
{
	int		size;
	char	**envp;
	char	**cmdv;
	char	**paths;
	char	**execv;

}	t_exe;

//		GET PATHS
char	**get_paths(void);
void	free_paths(char **paths);

//		INITS
int		count_vector(char **av);
char	**init_cmdv(char **av, int size);
char	**init_execv(t_exe *e);
t_exe	*init_exe(char **av, char **envp);
void	free_exe(t_exe *e);

//		SEARCHER
char	*search_path(char *path, char *cmd);
char	*search_file_system(char **paths, char *cmd);
char	*searcher(t_exe *e);

//		SEARCH PATH UTILS
char	*check_entry(char *entry, char *path, char *cmd);

//
bool	check_access(char *target_path);

#endif
