/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:45:11 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/05 18:00:16 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execute.h"

#define READ 0
#define WRITE 1

#include <unistd.h>

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

void	redirect_first_cmd(int (*fd)[2], int pipe_count)
{
	int	i;

	i = 1;
	dup2(fd[0][WRITE], STDOUT_FILENO);
	close(fd[0][READ]);
	while (i < pipe_count)
	{
		close(fd[i][READ]);
		close(fd[i][WRITE]);
		i++;
	}
}

void	redirect_middle_cmd(int (*fd)[2], int cmd_index, int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		if (i == cmd_index - 1)
		{
			dup2(fd[i][READ], STDIN_FILENO);
			dup2(fd[i + 1][WRITE], STDOUT_FILENO);
			close(fd[i][WRITE]);
			close(fd[i + 1][READ]);
			i += 2;
		}
		else
		{
			close(fd[i][READ]);
			close(fd[i][WRITE]);
			i++;
		}
	}
}

void	redirect_last_cmd(int (*fd)[2], int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count - 1)
	{
		close(fd[i][READ]);
		close(fd[i][WRITE]);
		i++;
	}
	dup2(fd[i][READ], STDIN_FILENO);
	close(fd[i][WRITE]);
}
