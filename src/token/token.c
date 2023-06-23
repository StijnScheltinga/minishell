/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:38:34 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/23 15:32:40 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"

void	tokenize_string(char *input_string)
{
	int	i;

	i = 0;
	while (input_string[i])
	{
		if (ft_iswhitespace == FALSE)
			i += assign_token(&input_string[i], i);
		else
			i++;
	}
}

int	assign_token(char *str, unsigned int start)
{
	char	*word;
	int		i;

	i = 0;
	if (str[i] == '|')
		create_token(PIPE);
	else if (str[i] == '>' || str[i] == '<')
		create_token(REDIRECT);
	else
	{
		while (ft_iswhitespace(str[i]) == FALSE)
			i++;
		word = ft_substr(str, 0, i);
		create_token(WORD, word);
		return (i);
	}
	return (1);
}

void	create_token(t_type type, char *str)
{
	
}
