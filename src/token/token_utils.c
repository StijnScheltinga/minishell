/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/29 17:34:37 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"

bool	ft_iswhitespace(char a)
{
	if (a == ' ' || a == '\t' || a == '\n')
		return (true);
	return (false);
}

t_token	*ft_lstnew(t_type type, char *text)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
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
