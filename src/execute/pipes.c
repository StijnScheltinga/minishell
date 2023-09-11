/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:45:11 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/11 16:21:37 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipes.h"
#include "../../inc/redirect.h"
#include "../../inc/delimiter.h"

#define READ 0
#define WRITE 1
#define BOTH 2

#include <unistd.h>
#include <stdlib.h>

void	free_pids_and_pipes(t_cmd_table *cmd_table)
{
	int	i;

	i = 0;
	if (cmd_table->pids)
		free(cmd_table->pids);
	if (cmd_table->pipes)
		free(cmd_table->pipes);
	cmd_table->pids = NULL;
	cmd_table->pipes = NULL;
}

void	close_all_pipes(t_cmd_table *cmd_table)
{
	int	i;

	i = 0;
	while (i < cmd_table->cmd_count - 1)
		close_pipes(cmd_table, i++, BOTH);
}

void	redirect_first_cmd(t_cmd_table *cmd_table, t_command *cmd)
{
	int	i;

	i = 1;
	redirect_input(cmd->redirect_arr, cmd->redirect_count);
	if (redirect_output(cmd->redirect_arr, cmd->redirect_count))
		close_pipes(cmd_table, 0, WRITE);
	else
		dup2(cmd_table->pipes[0][WRITE], STDOUT_FILENO);
	close_pipes(cmd_table, 0, READ);
	while (i < cmd_table->cmd_count - 1)
		close_pipes(cmd_table, i++, BOTH);
}

void	redirect_middle_cmd(t_cmd_table *cmd_table, t_command *cmd, int cmd_index)
{
	int	i;

	i = 0;
	while (i < cmd_table->cmd_count - 1)
	{
		if (i == cmd_index - 1)
		{
			if (redirect_input(cmd->redirect_arr, cmd->redirect_count))
				close_pipes(cmd_table, i, READ);
			else
				dup2(cmd_table->pipes[i][READ], STDIN_FILENO);
			if (redirect_output(cmd->redirect_arr, cmd->redirect_count))
				close_pipes(cmd_table, i + 1, WRITE);
			else
				dup2(cmd_table->pipes[i + 1][WRITE], STDOUT_FILENO);
			close_pipes(cmd_table, i, WRITE);
			close_pipes(cmd_table, i + 1, READ);
			i += 2;
		}
		else
			close_pipes(cmd_table, i++, BOTH);
	}
}

void	redirect_last_cmd(t_cmd_table *cmd_table, t_command *cmd)
{
	int	i;

	i = 0;
	if (redirect_input(cmd->redirect_arr, cmd->redirect_count))
		close_pipes(cmd_table, i, READ);
	else
		dup2(cmd_table->pipes[i][READ], STDIN_FILENO);
	redirect_output(cmd->redirect_arr, cmd->redirect_count);
	while (i < cmd_table->cmd_count - 2)
		close_pipes(cmd_table, i++, BOTH);
	close_pipes(cmd_table, i, WRITE);
}

void	close_pipes(t_cmd_table *cmd_table, int pipe_index, int pipe_to_close)
{
	if (pipe_to_close == READ)
		close(cmd_table->pipes[pipe_index][READ]);
	else if (pipe_to_close == WRITE)
		close(cmd_table->pipes[pipe_index][WRITE]);
	else if (pipe_to_close == BOTH)
	{
		close(cmd_table->pipes[pipe_index][READ]);
		close(cmd_table->pipes[pipe_index][WRITE]);
	}
}
