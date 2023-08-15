/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:38:34 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/15 16:10:20 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"
#include "../../inc/parser.h"

int	tokenize_string(char *input_string, t_token **head, t_env **env_list)
{
	int		i;

	i = 0;
	while (input_string[i])
	{
		if (input_string[i] && !ft_iswhitespace(input_string[i]))
			i += assign_token(&input_string[i], head, env_list);
		else
			i++;
		if (i >= ft_strlen(input_string))
			break;
	}
	if (grammar_check(head))
		return (1);
	create_io_file_tokens(head);
	return (0);
}

int	assign_token(char *str, t_token **head, t_env **env_list)
{
	char	*text;
	int		i;

	i = 0;
	if (*str == '|')
		create_token(PIPE, ft_strdup("|"), head);
	else if (*str == '>' || *str == '<')
		return (create_redirection_token(str, head));
	else if (*str == '"' || *str == '\'')
		return (handle_quotes(str, head));
	else if (*str == '$')
		return (expand_env_var(str, head, env_list));
	else
	{
		while (str[i] && !ft_iswhitespace(str[i]) && !ismetachar(str[i]))
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
