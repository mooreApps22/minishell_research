# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/*

	ADD_HISTORY - Keeps a history of readline inputs

	void add_history(const char *str);

		Places STR at the end of a the history list

	Necessary Compile Options:
		cc readline_history.c -lreadline

*/

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
			printf("Error.\n");
	}
	return (0);
}
