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

int	redirect_output(t_redirect *red_arr, int red_count)
{
	int	fd;
	int	i;
	int	out_i;

	i = 0;
	out_i = -1;
	while (i < red_count)
	{
		if (red_arr[i].type == OUTFILE || red_arr[i].type == APPEND)
		{
			out_i = i;
			open(red_arr[i].file_name, O_WRONLY | O_CREAT, 0644);
		}
		i++;
	}
	if (out_i == -1)
		return (1);
	if (red_arr[out_i].type == OUTFILE)
		fd = open(red_arr[out_i].file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(red_arr[out_i].file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	return (0);
}

void	redirect_child(t_cmd_table *cmd_table, int fd[2], int rd, int cmd_index)
{
	t_redirect *redirect_arr;
	int			redirect_count;

	redirect_arr = cmd_table->cmd_arr[cmd_index].redirect_arr;
	redirect_count = cmd_table->cmd_arr[cmd_index].redirect_count;
	if (redirect_input(redirect_arr, redirect_count))
		dup2(rd, STDIN_FILENO);
	if (redirect_output(redirect_arr, redirect_count) && cmd_index != cmd_table->cmd_count -1)
		dup2(fd[WRITE], STDOUT_FILENO);
}

void	redirect_single_child(t_cmd_table *cmd_table)
{
	t_redirect *redirect_arr;
	int			redirect_count;

	redirect_arr = cmd_table->cmd_arr[0].redirect_arr;
	redirect_count = cmd_table->cmd_arr[0].redirect_count;
	if (!redirect_count)
		return ;
	redirect_input(redirect_arr, redirect_count);
	redirect_output(redirect_arr, redirect_count);
}
