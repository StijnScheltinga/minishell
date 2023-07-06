/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:06:23 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/06 13:26:32 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	free_func_cmd_table(t_cmd_table *cmd_table, t_token **head)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i != count_cmd(head))
	{
		while(cmd_table->cmd_arr[i].single_cmd[j])
		{
			free(cmd_table->cmd_arr[i].single_cmd[j]);
			j++;
		}
		free(cmd_table->cmd_arr[i].single_cmd);
		j = 0;
		i++;
	}
	free(cmd_table->cmd_arr);
	free(cmd_table);
}
