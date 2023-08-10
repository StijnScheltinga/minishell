/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:06:23 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/10 16:12:22 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

//freeing double array input and output file needs to be implemented
void	free_func_cmd_table(t_cmd_table *cmd_table, t_token **head)
{
	int	i;

	i = 0;
	while (i != count_cmd(head))
	{
		free_double_array(cmd_table->cmd_arr[i].single_cmd);
		i++;
	}
	free(cmd_table->cmd_arr);
}

void	free_double_array(char	**double_array)
{
	int	i;
	
	i = 0;
	while (double_array[i])
	{
		free(double_array[i]);
		i++;
	}
	free(double_array);
}

int	num_of_arguments(t_token **head, int i)
{
	t_token	*iterate;
	int		num_of_arguments;

	iterate = get_cmd_location(head, i);
	num_of_arguments = 0;
	while (iterate != NULL && iterate->type != PIPE)
	{
		if (iterate->type == WORD)
			num_of_arguments++;
		iterate = iterate->next;
	}
	return (num_of_arguments);
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