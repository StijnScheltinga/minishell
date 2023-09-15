/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/14 22:20:20 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"
#include "../../inc/error.h"

int	ft_iswhitespace(char a)
{
	if (a == ' ' || a == '\t' || a == '\n')
		return (1);
	return (0);
}

int	ismetachar(char a)
{
	if (a == '|' || a == '<' || a == '>' || a == '$' || a == '\'' || a == '"')
		return (1);
	return (0);
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

void	create_token(t_type type, char *text, t_cmd_table *cmd_table)
{
	t_token	*new_token;

	new_token = ft_lstnew(type, text);
	ft_lstadd_back(cmd_table->token_head, new_token);
}
