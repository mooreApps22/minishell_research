#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
	CURRENT WORKING DIRECTING (CWD)
	
	char	*getcwd(char buf[.size], size_t size);

	This function returns a complete string of the absolute pathname of cwd of the calling process

	The cwd is both returned and written to BUF 
*/

int	main(int ac, char **av)
{
	char	buf[256];

	if (getcwd(buf, sizeof(buf)) == NULL)
	{
		perror("cwd");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", buf);
	return (EXIT_SUCCESS);
}
