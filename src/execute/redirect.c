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

int	 redirect_input(int rd, t_redirect *redirect_arr, int redirect_count)
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
			{
				redirect_error(redirect_arr[i].file_name);
				return (1);
			}
		}
		i++;
	}
	if (in_file != 0 && !check_if_del_is_input(redirect_arr, redirect_count))
		dup2(in_file, STDIN_FILENO);
	else if (!check_if_del_is_input(redirect_arr, redirect_count))
		dup2(rd, STDIN_FILENO);
	return (0);
}

int	redirect_output(int fd[2], t_redirect *red, int red_count, int is_last_cmd)
{
	int		out_file;
	int		i;
	char	*file;

	out_file = 0;
	i = 0;
	while (i < red_count)
	{
		if (red[i].type == OUTFILE)
			out_file = open(red[i].file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (red[i].type == APPEND)
			out_file = open(red[i].file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		i++;
	}
	if (out_file == 0 && !is_last_cmd)
	{
		dup2(fd[WRITE], STDOUT_FILENO);
		return (0);
	}
	else if (out_file > 0)
		dup2(out_file, STDOUT_FILENO);
	close(fd[WRITE]);
	return (0);
}

int	redirect_output_single_cmd(t_redirect *red, int red_count)
{
	int		out_file;
	int		i;

	out_file = 0;
	i = 0;
	while (i < red_count)
	{
		if (red[i].type == OUTFILE)
			out_file = open(red[i].file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (red[i].type == APPEND)
			out_file = open(red[i].file_name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		i++;
	}
	if (out_file > 0)
		dup2(out_file, STDOUT_FILENO);
	return (0);
}

int	redirect_child(t_cmd_table *cmd_table, int fd[2], int rd, int cmd_i)
{
	t_redirect	*redirect_arr;
	int			redirect_count;
	int			is_last_cmd;
	int			fd_delimiter;


	redirect_arr = cmd_table->cmd_arr[cmd_i].redirect_arr;
	redirect_count = cmd_table->cmd_arr[cmd_i].redirect_count;
	is_last_cmd = cmd_i == cmd_table->cmd_count - 1;
	fd_delimiter = delimiter(redirect_arr, redirect_count);
	if (fd_delimiter > 0)
		dup2(fd_delimiter, STDIN_FILENO);
	redirect_input(rd, redirect_arr, redirect_count);
	redirect_output(fd, redirect_arr, redirect_count, is_last_cmd);
	return (0);
}

int	redirect_single_child(t_cmd_table *cmd_table)
{
	t_redirect	*redirect_arr;
	int			redirect_count;
	int			fd;

	redirect_arr = cmd_table->cmd_arr[0].redirect_arr;
	redirect_count = cmd_table->cmd_arr[0].redirect_count;
	if (!redirect_count)
		return (0);
	fd = delimiter(redirect_arr, redirect_count);
	if (fd > 0)
		dup2(fd, STDIN_FILENO);
	if (redirect_input(STDIN_FILENO, redirect_arr, redirect_count))
		exit(1);
	if (redirect_output_single_cmd(redirect_arr, redirect_count))
		exit(1);
	return (0);
}
