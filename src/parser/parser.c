/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:49:54 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/17 15:22:32 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/parser.h"

int	parse_tokens(t_cmd_table *cmd_table, t_token **head)
{
	if (grammar_check(head))
		return (1);
	init_cmd_table(cmd_table, head);
	return (0);
}
