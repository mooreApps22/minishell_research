# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// char *readline(const char *prompt);
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
			free(input);
		}
		else
			printf("Nope.\n");
	}
	return (0);
}
