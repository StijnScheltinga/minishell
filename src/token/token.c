/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:38:34 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/30 15:01:16 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"

void	tokenize_string(char *input_string, t_token **head)
{
	int		i;

	i = 0;
	while (input_string[i])
	{
		if (input_string[i] && ft_iswhitespace(input_string[i]) == false)
			i += assign_token(&input_string[i], head);
		else
			i++;
		if (i >= ft_strlen(input_string))
			break;
	}
}

int	assign_token(char *str, t_token **head)
{
	char	*text;
	int		i;

	i = 0;
	if (str[i] == '|')
		create_token(PIPE, NULL, head);
	else if (str[i] == '>' || str[i] == '<')
		create_token(REDIRECT, NULL, head);
	else
	{
		while (str[i] && ft_iswhitespace(str[i]) == false)
			i++;
		text = ft_substr(str, 0, i);
		create_token(WORD, text, head);
		return (i);
	}
	return (1);
}

void	create_token(t_type type, char *text, t_token **head)
{
	t_token	*new_token;

	new_token = ft_lstnew(type, text);
	if (!new_token)	
		exit(EXIT_FAILURE);
	ft_lstadd_back(head, new_token);
}
