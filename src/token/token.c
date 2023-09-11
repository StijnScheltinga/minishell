/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:38:34 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/11 13:39:36 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"
#include "../../inc/parser.h"
#include "../../inc/expansions.h"

int	tokenize_string(char *input_string, t_token **head, t_cmd_table *cmd_table)
{
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	while (input_string[i])
	{
		if (input_string[i] && !ft_iswhitespace(input_string[i]))
		{
			temp = assign_token(&input_string[i], head, cmd_table);
			if (temp == -1)
				return (1);
			i += temp;
		}
		else
			i++;
		if (i >= ft_strlen(input_string))
			break;
	}
	if (grammar_check(head, cmd_table))
		return (1);
	create_io_file_tokens(head);
	return (0);
}

int	assign_token(char *str, t_token **head, t_cmd_table *cmd_table)
{
	if (*str == '|')
		create_token(PIPE, ft_strdup("|"), cmd_table, head);
	else if (*str == '>' || *str == '<')
		return (create_redirection_token(str, head, cmd_table));
	else if (*str == '"' || *str == '\'')
		return (handle_quotes(str, head, cmd_table));
	else if (*str == '$' && *(str + 1) == '?')
		return (expand_exit_status(str, head, cmd_table));
	else if (*str == '$')
		return (expand_env_var(str, head, cmd_table));
	else
		return (create_word_token(str, head, cmd_table));
	return (1);
}
