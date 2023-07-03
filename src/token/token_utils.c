/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/03 15:39:29 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"

bool	ft_iswhitespace(char a)
{
	if (a == ' ' || a == '\t' || a == '\n')
		return (true);
	return (false);
}

int	count_cmd(t_token **head)
{
	t_token	*iterate;
	int		num_of_cmd;
	bool	next_cmd;

	iterate = *head;
	num_of_cmd = 0;
	next_cmd = true;
	while (iterate != NULL)
	{
		if (iterate->type == WORD && next_cmd == true)
		{
			num_of_cmd++;
			next_cmd = false;
		}
		else if (iterate->type == PIPE)
			next_cmd = true;
		else if (iterate->type == REDIRECT)
			next_cmd = false;
		iterate = iterate->next;
	}
	return (num_of_cmd);
}

void free_func(t_token **head)
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
