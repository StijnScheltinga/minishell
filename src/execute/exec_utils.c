/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:44:06 by alex              #+#    #+#             */
/*   Updated: 2023/09/12 13:41:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execute.h"

void	create_pid_array(t_cmd_table *cmd_table)
{
	cmd_table->pids = malloc(sizeof(pid_t) * cmd_table->cmd_count);
	if (!cmd_table->pids)
		exit(EXIT_FAILURE);
}

void	create_pipes(t_cmd_table *cmd_table)
{
	int	i;
	
	i = 0;
	cmd_table->pipes = malloc(sizeof(int) * (cmd_table->cmd_count - 1) * 2);
	while (i < cmd_table->cmd_count - 1)
	{
		if (pipe(cmd_table->pipes[i]) == -1)
			exit(EXIT_FAILURE);
		i++;
	}
}

void	wait_for_children(t_cmd_table *cmd_table)
{
	int	i;
	int	status;

	i = 0;
	while (i < cmd_table->cmd_count)
		waitpid(cmd_table->pids[i++], &status, 0);
	cmd_table->latest_exit_code = WEXITSTATUS(status);
}
