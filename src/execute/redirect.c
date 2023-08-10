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

void	redirect_input(t_redirect *redirect_arr)
{
	int	fd;

	if (redirect_arr->type == INFILE)
		fd = open(redirect_arr->file_name, O_RDONLY  , 0644);
	dup2(fd, STDIN_FILENO);
}

void	redirect_output(t_redirect *redirect_arr)
{
	int	fd;

	if (redirect_arr->type == OUTFILE)
		fd = open(redirect_arr->file_name, O_WRONLY | O_CREAT | O_TRUNC , 0644);
	else
		fd = open(redirect_arr->file_name, O_WRONLY | O_CREAT | O_APPEND , 0644);
	dup2(fd, STDOUT_FILENO);
}


void	redirect_child(t_cmd_table *cmd_table, int (*fd)[2], int cmd_index)
{
	t_redirect *redirect_arr;

	redirect_arr = cmd_table->cmd_arr[cmd_index].redirect_arr;
	if (redirect_arr)
	{
		if (redirect_arr->type == INFILE)
			redirect_arr_input(redirect_arr);
		if (redirect_arr->type == OUTFILE || redirect_arr->type == APPEND)
			redirect_arr_output(redirect_arr);
		if (redirect_arr->type != INFILE)
			dup2(fd[cmd_index - 1][READ], STDIN_FILENO);
		if (redirect_arr->type != OUTFILE && redirect_arr->type != APPEND)
			dup2(fd[cmd_index][WRITE], STDOUT_FILENO);
		
	}
	else
	{
		dup2(fd[cmd_index - 1][READ], STDIN_FILENO);
		dup2(fd[cmd_index][WRITE], STDOUT_FILENO);
	}
}

