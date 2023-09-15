/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:06:50 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/15 16:32:41 by sschelti         ###   ########.fr       */
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

int	is_valid_var_name_char(char a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')
		|| (a >= '0' && a <= 9) || a == '_' || a == '?')
		return (1);
	return (0);
}

void	create_token(t_type type, char *text, t_cmd_table *cmd_table)
{
	t_token	*new_token;

	new_token = ft_lstnew(type, text);
	ft_lstadd_back(cmd_table->token_head, new_token);
}
