/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/15 12:35:04 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"

bool	ft_iswhitespace(char a)
{
	if (a == ' ' || a == '\t' || a == '\n')
		return (true);
	return (false);
}

bool	ismetachar(char a)
{
	if (a == '|' || a == '<' || a == '>')
		return (true);
	return (false);
}

int	count_cmd(t_token **head)
{
	t_token	*iterate;
	int		num_of_cmd;

	iterate = *head;
	num_of_cmd = 1;
	while (iterate != NULL)
	{
		if (iterate->type == PIPE)
			num_of_cmd++;
		iterate = iterate->next;
	}
	return (num_of_cmd);
}


void free_func_token(t_token **head)
{
	t_token *temp;
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
