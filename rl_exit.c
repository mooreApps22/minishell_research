# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

// you have to use the -lreadline flag when you compile

int	main(int ac, char **av)
{
	char *input;

	while (1)
	{
		input = readline(""); // input = readline ((char *)NULL);
		if (!input)
			break ;
		printf("$%s\n", input);
		if (strcmp(input, "exit") == 0)
			break ;
		free(input);
	}
	exit (0);
}
