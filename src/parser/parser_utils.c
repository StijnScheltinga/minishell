/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:06:23 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/13 12:07:43 by stijn            ###   ########.fr       */
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
		free(cmd_table->cmd_arr[i].input_file);
		free(cmd_table->cmd_arr[i].output_file);
		j = 0;
		i++;
	}
	free(cmd_table->cmd_arr);
	free(cmd_table);
}

int	num_of_arguments(t_token **head, int i)
{
	t_token *iterate;
	int		num_of_arguments;
	int		cmd_n;

	iterate = *head;
	num_of_arguments = 0;
	cmd_n = 0;
	while (iterate != NULL)
	{
		if (iterate->type == PIPE)
			cmd_n++;
		if (cmd_n == i)
		{
			if (iterate->type == PIPE)
				iterate = iterate->next;
			while (iterate != NULL && iterate->type == WORD)
			{
				num_of_arguments++;
				iterate = iterate->next;
			}
			return (num_of_arguments);
		}
		iterate = iterate->next;
	}
	return (0);
}

t_token	*get_cmd_location(t_token **head, int i)
{
	t_token	*iterate;
	int		cmd_n;

	iterate = *head;
	cmd_n = 0;
	while (iterate != NULL && i != cmd_n)
	{
		if (iterate->type == PIPE)
			cmd_n++;
		iterate = iterate->next;
	}
	return (iterate);
}