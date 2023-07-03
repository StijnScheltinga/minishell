/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:49:54 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/03 17:18:15 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/parser.h"

void	parse_tokens(t_token **head)
{
	t_cmd_table	*cmd_table;

	cmd_table = NULL;
	init_cmd_table(cmd_table, head);
	check_redirection(head);	
}

void	check_redirection(t_token **head)
{
	t_token	*iterate;

	iterate = *head;
	// while (iterate != NULL)
	// {
	// 	if (iterate->type == REDIRECT)
	// 	{
	// 		if (ft_strncmp(iterate->text, "<", 1) == 0)

	// 		else if (ft_strncmp(iterate->text, "<", 1) == 0)
			
	// 	}
	// 	iterate = iterate->next;
	// }
}
