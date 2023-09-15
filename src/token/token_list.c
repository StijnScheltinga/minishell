/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:23:43 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/15 16:07:48 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"

t_token	*ft_lstnew(t_type type, char *text)
{
	t_token	*new;

	new = ft_malloc(sizeof(t_token));
	new->type = type;
	new->text = text;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_token **head, t_token *new)
{
	t_token	*last;

	if (!*head)
		*head = new;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	free_func_token(t_token **head)
{
	t_token	*temp;
	t_token	*first;

	while (*head != NULL)
	{
		first = *head;
		temp = first->next;
		free(first->text);
		free(first);
		*head = temp;
	}
}
