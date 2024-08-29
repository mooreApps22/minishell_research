# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

// void exit(int status);
// status: EXIT_SUCCESS = 0, EXIT_FAILURE = 1
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
