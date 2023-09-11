/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:06:23 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/11 16:16:06 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/pipes.h"

void	free_func_cmd_table(t_cmd_table *cmd_table, t_token **head)
{
	int	i;

	i = 0;
	while (i != count_cmd(head))
	{
		free_double_array(cmd_table->cmd_arr[i].single_cmd);
		if (cmd_table->cmd_arr[i].redirect_arr)
			free_redirect_array(cmd_table->cmd_arr[i].redirect_arr, cmd_table->cmd_arr[i].redirect_count);
		i++;
	}
	free(cmd_table->cmd_arr);
	free_pids_and_pipes(cmd_table);
}

void	free_redirect_array(t_redirect *redirect_arr, unsigned int redirect_count)
{
	int	i;

	i = 0;
	while (i < redirect_count)
	{
		free(redirect_arr[i].file_name);
		i++;
	}
	free(redirect_arr);
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