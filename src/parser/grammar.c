/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:42:21 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/12 14:37:36 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/error.h"

int	grammar_check(t_token **head, t_cmd_table *cmd_table)
{
	if (double_metachar_check(head, cmd_table))
		return (1);
	return (0);
}

int	double_metachar_check(t_token **head, t_cmd_table *cmd_table)
{
	t_token	*iterate;

	iterate = *head;
	if (iterate && iterate->type == PIPE)
		return (syntax_error(iterate->text, cmd_table));
	while (iterate != NULL)
	{
		if ((iterate->type == PIPE || iterate->type == REDIRECT)
			&& iterate->next == NULL)
			return (syntax_error("newline", cmd_table));
		else if ((iterate->type == PIPE || iterate->type == REDIRECT)
			&& iterate->next->type == PIPE)
			return (syntax_error(iterate->next->text, cmd_table));
		iterate = iterate->next;
	}
	return (0);
}
