/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:45:11 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 14:09:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipes.h"
#include "../../inc/redirect.h"

#define READ 0
#define WRITE 1
#define BOTH 2

#include <unistd.h>
#include <stdlib.h>

void	free_pids_and_pipes(t_cmd_table *cmd_table)
{
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
	t_redirect	*red;
	int			red_count;
	int			i;

	red = cmd->redirect_arr;
	red_count = cmd->redirect_count;
	i = 0;
	redirect_input(cmd_table, red, red_count);
	if (!redirect_output(cmd_table, red, red_count))
		dup2(cmd_table->pipes[0][WRITE], STDOUT_FILENO);
	close_pipes(cmd_table, 0, BOTH);
	while (i < cmd_table->cmd_count - 1)
		close_pipes(cmd_table, i++, BOTH);
}

void	redirect_middle_cmd(t_cmd_table *cmd_table, t_command *cmd, int cmd_i)
{
	t_redirect	*red;
	int			red_count;
	int			i;

	red = cmd->redirect_arr;
	red_count = cmd->redirect_count;
	i = 0;
	while (i < cmd_table->cmd_count - 1)
	{
		if (i == cmd_i - 1)
		{
			if (!redirect_input(cmd_table, red, red_count))
				dup2(cmd_table->pipes[i][READ], STDIN_FILENO);
			if (!redirect_output(cmd_table, red, red_count))
				dup2(cmd_table->pipes[i + 1][WRITE], STDOUT_FILENO);
			close_pipes(cmd_table, i, BOTH);
			close_pipes(cmd_table, i + 1, BOTH);
			i += 2;
		}
		else
			close_pipes(cmd_table, i++, BOTH);
	}
}

void	redirect_last_cmd(t_cmd_table *cmd_table, t_command *cmd)
{
	t_redirect	*red;
	int			red_count;
	int			pipe_i;
	int			i;

	red = cmd->redirect_arr;
	red_count = cmd->redirect_count;
	pipe_i = cmd_table->cmd_count - 2;
	i = 0;
	if (!redirect_input(cmd_table, red, red_count))
		dup2(cmd_table->pipes[pipe_i][READ], STDIN_FILENO);
	redirect_output(cmd_table, red, red_count);
	while (i < pipe_i + 1)
		close_pipes(cmd_table, i++, BOTH);
}
