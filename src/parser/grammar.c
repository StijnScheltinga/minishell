/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:42:21 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/07 17:11:12 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/error.h"

void	grammar_check(t_token **head)
{
	pipe_check(head);
}

void	pipe_check(t_token **head)
{
	t_token	*iterate;

	iterate = *head;
	if (iterate->type == PIPE)
		syntax_error('|');
	while (iterate != NULL)
	{
		if (iterate->type == PIPE && iterate->next->type == PIPE)
			syntax_error('|');
		iterate = iterate->next;
	}
}
