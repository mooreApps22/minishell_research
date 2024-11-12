# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

/*
	READLINE UTILITY FUNCTIONS

	void	rl_replace_line(const char *text, int clear_undo);
		
		Replaces the readline buffer with TEXT

		If CLEAR_UNDO == non-zero, the undo list is cleared

	void	rl_clear_history(void);

		Clears all saved history

	int		rl_on_new_line(void);

		Tell update functions, there is a newline

	void	rl_redisplay(void);

		Change output to current contents of rl_line_buffer.

	 Necessary Compile Option:
		 cc readline.c -lreadline
*/

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		write(1, "\n$", 2);
	}
}

int	main(int ac, char **av)
{
	char *input;

	while (true)
	{
		signal(SIGINT, handler);
		input = readline("$");
		if (input)
		{
			printf("%s\n", input);
			add_history(input);
			if (strcmp(input, "history -c") == 0)
				rl_clear_history();
			if (strcmp(input, "exit") == 0)
				break ;
			free(input);
		}
		else
			break ;
	}
	return (0);
}
