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
#include <errno.h>
#include <unistd.h>

static void	redirect_error(char *file)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	if (errno == EACCES)
	{
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	}
}

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
			if (open(redirect_arr[i].file_name, O_RDONLY) == -1)
			{
				redirect_error(redirect_arr[i].file_name);
				return (2);
			}
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

int	redirect_output(t_redirect *red, int red_count)
{
	int		fd;
	int		i;
	int		out_i;
	char	*file;

	i = 0;
	out_i = -1;
	while (i < red_count)
	{
		if (red[i].type == OUTFILE || red[i].type == APPEND)
		{
			out_i = i;
			open(red[i].file_name, O_WRONLY | O_CREAT, 0644);
		}
		i++;
	}
	if (out_i == -1)
		return (1);
	if (red[out_i].type == OUTFILE)
		fd = open(red[out_i].file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(red[out_i].file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	return (0);
}

int	redirect_child(t_cmd_table *cmd_table, int fd[2], int rd, int cmd_i)
{
	t_redirect	*redirect_arr;
	int			redirect_count;
	int			last_command_index;
	int			ret;

	redirect_arr = cmd_table->cmd_arr[cmd_i].redirect_arr;
	redirect_count = cmd_table->cmd_arr[cmd_i].redirect_count;
	last_command_index = cmd_i != cmd_table->cmd_count - 1;
	ret = redirect_input(redirect_arr, redirect_count);
	if (ret == 2)
		return (1);
	else if (ret == 1)
		dup2(rd, STDIN_FILENO);
	if (redirect_output(redirect_arr, redirect_count) && last_command_index)
		dup2(fd[WRITE], STDOUT_FILENO);
	return (0);
}

int	redirect_single_child(t_cmd_table *cmd_table)
{
	t_redirect	*redirect_arr;
	int			redirect_count;
	int			ret;

	redirect_arr = cmd_table->cmd_arr[0].redirect_arr;
	redirect_count = cmd_table->cmd_arr[0].redirect_count;
	if (!redirect_count)
		return (0);
	if (redirect_input(redirect_arr, redirect_count) == 2)
		return (1);
	redirect_output(redirect_arr, redirect_count);
	return (0);
}
