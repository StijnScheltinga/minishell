/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:58:35 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/20 16:45:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pipes.h"
#include "../../inc/redirect.h"

#define READ 0
#define WRITE 1
#define BOTH 2

#include <unistd.h>
#include <stdlib.h>

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

int	dup_and_close(int fd[2])
{
	int	rd;

	rd = dup(fd[READ]);
	close(fd[READ]);
	close(fd[WRITE]);
	return (rd);
}

int	close_one_pipe(int fd[2])
{
	close(fd[READ]);
	close(fd[WRITE]);
	return (0);
}
