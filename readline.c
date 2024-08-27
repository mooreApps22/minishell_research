# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

// char *readline(const char *prompt);
// cc readline.c -lreadline

int	main(int ac, char **av)
{
	char *input;

	input = readline("$");
	if (input)
	{
		printf("%s\n", input);
		free(input);
	}
	else
		printf("Nope.\n");
	return (0);
}
