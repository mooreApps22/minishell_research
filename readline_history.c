# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// void add_history(const char *prompt);
// cc readline_history.c -lreadline

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
			free(input);
		}
		else
			printf("Nope.\n");
	}
	return (0);
}
