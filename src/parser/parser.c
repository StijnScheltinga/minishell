/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:49:54 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/13 11:25:33 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/parser.h"

t_cmd_table	*parse_tokens(t_token **head, char **envp)
{
	t_cmd_table	*cmd_table;

	if (grammar_check(head))
		return (NULL);
	cmd_table = init_cmd_table(head, envp);
	return (cmd_table);
}
