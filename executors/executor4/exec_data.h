#ifndef EXEC_DATA_H
# define EXEC_DATA_H

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "libft/include/libft.h"

//			GET VECTORS
int		count_input_vector(char **input);
char	**get_command_vector(char **input, int input_size);
void	get_executable_vector(char **cmdv, int input_size, char **envp);

//			GET PATHS
char	**get_paths(void);
void	free_paths(char **paths);

//			SEARCH PATHS
char	*search_paths(char *path, char *cmd);

//			REPACE CMD WITH PATH
char	**replace_cmd_with_path(char *target_path, char **cmdv, int size);

//			EXECUTE PATH
void	execute_path(char **execv, char **envp);

#endif
