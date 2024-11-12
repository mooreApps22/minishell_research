# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

/*
	READLINE - get a line from a user with editing
	
	char *readline(const char *prompt);

		Gets a line from the terminal using PROMPT as the prompt

		The return is allocated, so you must free it after done using

		If PROMPT is NULL or an empty string, no prompt is seen by the user

	Necessary Compile Option:
		 cc readline.c -lreadline
*/
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
