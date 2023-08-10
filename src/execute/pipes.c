/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:45:11 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/10 15:32:47 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipes.h"
#include "../../inc/execute.h"

#include <unistd.h>

void	close_unused_pipes(t_cmd_table *cmd_table, int (*fd)[2], int cmd_index)
{
	int	pipe_index;

	pipe_index = 0;
	while (pipe_index < cmd_table->cmd_count - 1)
	{
		if (pipe_index != cmd_index - 1)
			close(fd[pipe_index][READ]);
		if (pipe_index != cmd_index)
			close(fd[pipe_index][WRITE]);
		pipe_index++;
	}
}

void	close_all_pipes(int (*fd)[2], int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		close(fd[i][READ]);
		close(fd[i][WRITE]);
		i++;
	}
}
