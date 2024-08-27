# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// void	rl_clear_history(void);
// cc readline.c -lreadline

int	main(int ac, char **av)
{
	char *input;

	while (true)
	{
		input = readline("$");
		if (input)
		{
			printf("%s\n", input);
			add_history(input);
			if (strcmp(input, "history -c") == 0)
				rl_clear_history();
			free(input);
		}
		else
			printf("Nope. Input error.\n");
	}
	return (0);
}
