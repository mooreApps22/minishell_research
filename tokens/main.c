#include "data.h"

void	free_split(char **toks)
{
	char	**tmp;

	tmp = toks;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(toks);
}

t_token	*tokenizer(t_data *d)
{
	char	**toks;
//	char	**saved;;
	t_token	*head;
	t_token	*new_tok;

	toks = ft_split(d->input, ' ');
//	saved = toks;
	head = NULL;
	while (*toks)
	{
		new_tok = tok_lstnew(*toks);
		tok_lstadd_back(&head, new_tok);
		toks++;		
	}
	tok_type_assigner(head);
//	free_split(saved);
	return (head);
}

int	main(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (1);
	while (1)
	{
		d->input = readline("$$$> ");
		if (!d->input)
			break ;
		d->toks = tokenizer(d);
		print_toks(d);
		
		tok_lstclear(&d->toks);
		d->toks = NULL;
		free(d->input);
		d->input = NULL;
	}
	free(d);
	return (0);
}

	/*
int	main(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (1);
	d->input = readline("$$$> ");
	d->toks = tokenizer(d);
	print_toks(d);
	return (0);
}
	*/
