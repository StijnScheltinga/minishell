/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:49:54 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/07 13:52:52 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/parser.h"

t_cmd_table	*parse_tokens(t_token **head, char **envp)
{
	t_cmd_table	*cmd_table;

	// grammar_error(head);
	cmd_table = init_cmd_table(head, envp);
	return (cmd_table);
}
