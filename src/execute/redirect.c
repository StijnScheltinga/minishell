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
#include "../../inc/delimiter.h"
#include "../../inc/pipes.h"
#include "../../inc/execute.h"

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>

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
	exit(1);
}

int	redirect_input(t_redirect *redirect_arr, int redirect_count)
{
	int	in_file;
	int	i;

	in_file = 0;
	i = 0;
	while (i < redirect_count)
	{
		if (redirect_arr[i].type == INFILE)
		{
			in_file = open(redirect_arr[i].file_name, O_RDONLY);
			if (in_file == -1)
				redirect_error(redirect_arr[i].file_name);
		}
		i++;
	}
	if (in_file == 0 && !del_is_input(redirect_arr, redirect_count))
		return (0);
	if (!del_is_input(redirect_arr, redirect_count))
		dup2(in_file, STDIN_FILENO);
	return (1);
}

int	redirect_output(t_redirect *red, int red_count)
{
	int	out_fd;
	int	out_count;
	int	i;

	out_fd = 0;
	i = -1;
	out_count = count_red(red, red_count, OUTFILE, APPEND);
	if (!out_count)
		return (0);
	while (++i < red_count)
	{
		if (red[i].type == OUTFILE)
			out_fd = open(red[i].file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (red[i].type == APPEND)
			out_fd = open(red[i].file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (out_fd == -1)
			redirect_error(red[i].file_name);
		if (out_fd && --out_count > 0)
		{
			close(out_fd);
			out_fd = 0;
		}
	}
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	return (1);
}

void	redirect_child(t_cmd_table *cmd_table, int cmd_i)
{
	t_redirect	*red;
	int			fd_delimiter;
	int			red_count;

	red = cmd_table->cmd_arr[cmd_i].redirect_arr;
	red_count = cmd_table->cmd_arr[cmd_i].redirect_count;
	fd_delimiter = delimiter(red, red_count, cmd_table);
	if (fd_delimiter > 0)
		dup2(fd_delimiter, STDIN_FILENO);
	if (cmd_i == 0)
		redirect_first_cmd(cmd_table, &cmd_table->cmd_arr[cmd_i]);
	else if (cmd_i != cmd_table->cmd_count - 1)
		redirect_middle_cmd(cmd_table, &cmd_table->cmd_arr[cmd_i], cmd_i);
	else
		redirect_last_cmd(cmd_table, &cmd_table->cmd_arr[cmd_i]);
}

void	redirect_single_child(t_cmd_table *cmd_table)
{
	t_redirect	*redirect_arr;
	int			redirect_count;
	int			fd_delimiter;

	redirect_arr = cmd_table->cmd_arr[0].redirect_arr;
	redirect_count = cmd_table->cmd_arr[0].redirect_count;
	if (!redirect_count)
		return ;
	fd_delimiter = delimiter(redirect_arr, redirect_count, cmd_table);
	if (fd_delimiter > 0)
		dup2(fd_delimiter, STDIN_FILENO);
	redirect_input(redirect_arr, redirect_count);
	redirect_output(redirect_arr, redirect_count);
}
