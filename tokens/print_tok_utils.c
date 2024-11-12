#include "data.h" 

void	print_type(int type)
{
	printf(", Type: ");
	if (type == PIPE)
		printf("Pipe");
	else if (type == RDR_IN)
		printf("Redir In");
	else if (type == RDR_OUT)
		printf("Redir Out");
	else if (type == APPEND)
		printf("Append");
	else if (type == CMD)
		printf("Command");
	else if (type == ARG)
		printf("Argument");
	else if (type == FD)
		printf("File Descriptor");
	else if (type == DELIMS)
		printf("Delimiter");
	else if (type == FILENAME)
		printf("File");
	else if (type == CMD_ERR)
		printf("Command not found");
	else
		printf("not found");
	printf("\n");
}

void	print_toks(t_data *d)
{
	t_token	*current;

	current = d->toks;
	while (current != NULL)
	{
		printf("Tok: %s", current->cont);
		print_type(current->type);
		current = current->next;
	}
}
