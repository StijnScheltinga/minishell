/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:54:07 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/18 12:45:35 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"
#include "../../inc/error.h"

//return amount of char within quote
int	handle_quotes(char *str, t_token **head, t_env **env_list)
{
	int		i;
	char	*text;

	i = 1;
	while (str[i] && str[i] != str[0])
		i++;
	text = ft_substr(str, 1, i - 1);
	if (str[0] == '"')
		text = expand_var_quotes(text, env_list);
	create_token(WORD, text, head);
	return (i + 1);
}

void	create_io_file_tokens(t_token **head)
{
	t_token	*iterate;

	iterate = *head;
	while (iterate != NULL)
	{	
		if (iterate->type == REDIRECT && iterate->next != NULL)
		{
			if (!ft_strncmp(iterate->text, ">>", 2) && iterate->next != NULL)
				iterate->next->type = APPEND;
			else if (!ft_strncmp(iterate->text, "<", 1) && iterate->next != NULL)
				iterate->next->type = INFILE;
			else if (!ft_strncmp(iterate->text, ">", 1) && iterate->next != NULL)
				iterate->next->type = OUTFILE;
		}
		iterate = iterate->next;
	}
}

int	create_redirection_token(char *str, t_token **head)
{
	char	*text;
	int		i;

	i = 0;
	while (str[i] && !ft_iswhitespace(str[i]))
	{
		if ((str[i] != '>' && str[i] != '<') || i >= 2)
			break ;
		i++;
	}
	text = ft_substr(str, 0, i);
	create_token(REDIRECT, text, head);
	return (i);
}
