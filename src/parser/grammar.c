/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:42:21 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/31 17:23:31 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/error.h"

int	grammar_check(t_token **head)
{
	if (double_metachar_check(head))
		return (1);
	return (0);
}

int	double_metachar_check(t_token **head)
{
	t_token	*iterate;

	iterate = *head;
	if (iterate && iterate->type == PIPE)
		return (syntax_error(iterate->text));
	while (iterate != NULL)
	{
		if ((iterate->type == PIPE || iterate->type == REDIRECT)
			&& iterate->next == NULL)
			return (syntax_error("newline"));
		else if ((iterate->type == PIPE || iterate->type == REDIRECT) 
			&& (iterate->next->type == PIPE || iterate->next->type == REDIRECT))
			return (syntax_error(iterate->next->text));
		iterate = iterate->next;
	}
	return (0);
}
