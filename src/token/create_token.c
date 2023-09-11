/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:54:07 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/11 18:01:54 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"
#include "../../inc/error.h"
#include "../../inc/expansions.h"

//return amount of char within quote
int	handle_quotes(char *str, t_token **head, t_cmd_table *cmd_table)
{
	char	*text;

	text = get_quote_text(str, cmd_table);
	if (!text)
		return (-1);
	create_token(WORD, text, cmd_table, head);
	printf("text: %s, first char: %c\n", text, str[0]);
	return (ft_strlen(text) + 2);
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
			else if (!ft_strncmp(iterate->text, "<<", 2) && iterate->next != NULL)
				iterate->next->type = DELIMITER;	
			else if (!ft_strncmp(iterate->text, "<", 1) && iterate->next != NULL)
				iterate->next->type = INFILE;
			else if (!ft_strncmp(iterate->text, ">", 1) && iterate->next != NULL)
				iterate->next->type = OUTFILE;
		}
		iterate = iterate->next;
	}
}

int	create_redirection_token(char *str, t_token **head, t_cmd_table *cmd_table)
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
	if (!text)
		malloc_error(NULL, NULL, cmd_table);
	create_token(REDIRECT, text, cmd_table, head);
	return (i);
}

int	create_word_token(char *str, t_token **head, t_cmd_table *cmd_table)
{
	char	*text;
	int		i;

	i = 0;
	while (str[i] && !ft_iswhitespace(str[i]) && !ismetachar(str[i]))
		i++;
	text = ft_substr(str, 0, i);
	if (!text)
		malloc_error(NULL, NULL, cmd_table);
	create_token(WORD, text, cmd_table, head);
	return (i);
}
