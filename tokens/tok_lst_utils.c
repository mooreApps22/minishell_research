#include "data.h"

t_token	*tok_lstnew(char *word)
{
	t_token	*new_tok;

	new_tok = malloc(sizeof(t_token)); if (!new_tok) return (NULL);
	new_tok->cont = word;
	new_tok->next = NULL;
	return (new_tok);
}

void	tok_lstadd_back(t_token **head, t_token *new)
{
	t_token	*current;

	if (!new)
		return ;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

int	tok_lstsize(t_token *tok)
{
	int	i;

	i = 0;
	while (tok != NULL)
	{
		i++;
		tok = tok->next;
	}
	return (i);
}

t_token	*tok_lstlast(t_token *tok)
{
	if (tok == NULL)
		return (0);
	while (tok)
	{
		if (tok->next == NULL)
			return (tok);
		tok = tok->next;
	}
	return (tok);
}

void	tok_lstclear(t_token **tok)
{
	t_token	*current;
	t_token	*temp;

	if (*tok == NULL)
		return ;
	current = *tok;
	while (current != NULL)
	{
		temp = current->next;
		free(current->cont);
		free(current);
		current = temp;
	}
	*tok = NULL;
}
