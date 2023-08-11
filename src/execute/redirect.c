/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:32:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/10 15:55:06 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/redirect.h"
#include "../../inc/parser.h"

#include <fcntl.h>

int	redirect_input(t_redirect *redirect_arr, int redirect_count)
{
	int	fd;
	int	i;
	int	last_input;

	i = 0;
	last_input = -1;
	while (i < redirect_count)
	{
		if (redirect_arr[i].type == INFILE)
		{
			last_input = i;
			open(redirect_arr[i].file_name, O_RDONLY);
		}
		i++;
	}
	if (last_input == -1)
		return (1);
	if (redirect_arr[last_input].type == INFILE)
		fd = open(redirect_arr[last_input].file_name, O_RDONLY);
	dup2(fd, STDIN_FILENO);
	return (0);
}

int	redirect_output(t_redirect *redirect_arr, int redirect_count)
{
	int	fd;
	int	i;
	int	last_output;

	i = 0;
	last_output = -1;
	while (i < redirect_count)
	{
		if (redirect_arr[i].type == OUTFILE || redirect_arr[i].type == APPEND)
		{
			last_output = i;
			open(redirect_arr[i].file_name, O_WRONLY | O_CREAT, 0644);
		}
		i++;
	}
	if (last_output == -1)
		return (1);
	if (redirect_arr[last_output].type == OUTFILE)
		fd = open(redirect_arr[last_output].file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(redirect_arr[last_output].file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	return (0);
}


void	redirect_child(t_cmd_table *cmd_table, int (*fd)[2], int cmd_index)
{
	t_redirect *redirect_arr;
	int			redirect_count;

	redirect_arr = cmd_table->cmd_arr[cmd_index].redirect_arr;
	redirect_count = cmd_table->cmd_arr[cmd_index].redirect_count;
	if (redirect_count != 0)
	{
		if (redirect_input(redirect_arr, redirect_count) && cmd_index != 0)
			dup2(fd[cmd_index - 1][READ], STDIN_FILENO);
		if (redirect_output(redirect_arr, redirect_count) && cmd_index != cmd_table->cmd_count -1)
			dup2(fd[cmd_index][WRITE], STDOUT_FILENO);
	}
	else
	{
		if (cmd_index != 0)
			dup2(fd[cmd_index - 1][READ], STDIN_FILENO);
		if (cmd_index != cmd_table->cmd_count -1)
			dup2(fd[cmd_index][WRITE], STDOUT_FILENO);
	}
}

void	redirect_single_child(t_cmd_table *cmd_table)
{
	t_redirect *redirect_arr;
	int			redirect_count;

	redirect_arr = cmd_table->cmd_arr[0].redirect_arr;
	redirect_count = cmd_table->cmd_arr[0].redirect_count;
	if (redirect_count != 0)
	{
		redirect_input(redirect_arr, redirect_count);
		redirect_output(redirect_arr, redirect_count);
	}
}