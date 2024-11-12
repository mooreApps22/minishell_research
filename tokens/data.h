#ifndef TOKEN_H
# define TOKEN_H

# include "libft/include/libft.h" 
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct s_data	t_data;
typedef	struct s_token	t_token;

enum e_type
{
	PIPE,
	RDR_IN,
	RDR_OUT,
	APPEND,
	CMD,
	CMD_ERR,
	ARG,
	FD,
	DELIMS,
	FILENAME
};

typedef	struct s_data
{
	char	*input;
	int		tok_ct;
	t_token	*toks;
}	t_data;

typedef	struct s_token
{
	char			*cont;
	t_token			*next;
	int				type;
}	t_token;


void	assign_one_type(t_token *tok, int *type);
void	assign_multiple_type(char *tk, int *type);
void	tok_type_assigner(t_token *head);

bool	is_fd(const char *tk);
bool	is_delim(const char *tk);
bool	is_filename(const char *tk);
char	**get_paths(void);
bool	is_cmd(const char *tk);

t_token	*tok_lstnew(char *word);
void	tok_lstadd_back(t_token **head, t_token *new); // new_tok
int		tok_lstsize(t_token *tok);
t_token	*tok_lstlast(t_token *tok);
void	tok_lstclear(t_token **tok);

void	print_toks(t_data *d);
void	print_type(int type);

#endif
