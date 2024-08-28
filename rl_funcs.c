# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

// void	rl_clear_history(void);
// cc readline.c -lreadline

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
