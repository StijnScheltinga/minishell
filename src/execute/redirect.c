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
#include "../../inc/delimiter.h"
#include "../../inc/pipes.h"

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

int	 redirect_input(t_redirect *redirect_arr, int redirect_count)
{
	int		in_file;
	int		i;

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
	if (in_file == 0)
		return (0);
	if (in_file != 0 && !del_is_input(redirect_arr, redirect_count))
		dup2(in_file, STDIN_FILENO);
	return (1);
}

int	redirect_output(t_redirect *red, int red_count)
{
	int		out_file;
	int		i;
	char	*file;

	out_file = 0;
	i = 0;
	while (i < red_count)
	{
		file = red[i].file_name;
		if (red[i].type == OUTFILE)
			out_file = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (red[i].type == APPEND)
			out_file = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		i++;
	}
	if (out_file == 0)
		return (0);
	dup2(out_file, STDOUT_FILENO);
	return (1);
}

int	redirect_child(t_cmd_table *cmd_table, int cmd_i)
{
	t_redirect *red;
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
	return (0);
}

int	redirect_single_child(t_cmd_table *cmd_table)
{
	t_redirect	*redirect_arr;
	int			redirect_count;
	int			fd_delimiter;

	redirect_arr = cmd_table->cmd_arr[0].redirect_arr;
	redirect_count = cmd_table->cmd_arr[0].redirect_count;
	if (!redirect_count)
		return (0);
	fd_delimiter = delimiter(redirect_arr, redirect_count, cmd_table);
	if (fd_delimiter > 0)
		dup2(fd_delimiter, STDIN_FILENO);
	redirect_input(redirect_arr, redirect_count);
	redirect_output(redirect_arr, redirect_count);
	return (0);
}
