/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:42:21 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/13 11:24:58 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/error.h"

int	grammar_check(t_token **head)
{
	if (pipe_check(head))
		return (1);
	return (0);
}

int	pipe_check(t_token **head)
{
	t_token	*iterate;

	iterate = *head;
	if (iterate->type == PIPE)
		return (syntax_error('|'));
	while (iterate != NULL)
	{
		if (iterate->type == PIPE && iterate->next->type == PIPE)
			return (syntax_error('|'));
		iterate = iterate->next;
	}
	return (0);
}
