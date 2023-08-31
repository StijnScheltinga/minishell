/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:59:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/30 23:31:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/delimiter.h"
#include "../../inc/redirect.h"
#include "../../inc/signals.h"
#include "../../inc/token.h"

#include <readline/readline.h>
#include <stdbool.h>

static int	delimiter_count(t_redirect *redirect_arr, int redirect_count)
{
	int	i;
	int	del_count;

	i = 0;
	del_count = 0;
	while (i < redirect_count)
	{
		if (redirect_arr[i++].type == DELIMITER)
			del_count++;
	}
	return (del_count);
}

bool	check_if_del_is_input(t_redirect *redirect_arr, int redirect_count)
{
	t_type	type;

	while (redirect_count > 0)
	{
		type = redirect_arr[redirect_count - 1].type;
		if (type == DELIMITER)
			return (true);
		else if (type == INFILE)
			return (false);
		redirect_count--;
	}
	return (false);
}

static void	exec_delim(char *eof, int del_count, int fd[2], bool is_input)
{
	char	*input_string;

	input_string = NULL;
	while (1)
	{
		input_string = readline("> ");
		if (!input_string)
			exit(130);
		if (!ft_strncmp(input_string, eof, ft_strlen(eof) + 1))
			break ;
		if (del_count == 0 && is_input == true)
		{
			ft_putstr_fd(input_string, fd[1]);
			ft_putstr_fd("\n", fd[1]);
		}
		free(input_string);
	}
	free(input_string);
}

static int	dup_and_close(int fd[2])
{
	int	rd;

	rd = dup(fd[0]);
	close(fd[0]);
	close(fd[1]);
	return (rd);
}

int	delimiter(t_redirect *redirect_arr, int redirect_count)
{
	int		i;
	int		rd;
	int		fd[2];
	int		del_count;
	bool	is_input;

	del_count = delimiter_count(redirect_arr, redirect_count);
	if (del_count == 0)
		return (0);
	is_input = check_if_del_is_input(redirect_arr, redirect_count);
	pipe(fd);
	i = 0;
	sign_delimiter();
	while (del_count > 0)
	{
		if (redirect_arr[i].type == DELIMITER)
		{
			del_count--;
			exec_delim(redirect_arr[i].file_name, del_count, fd, is_input);
		}
		i++;
	}
	if (is_input == false)
		return (0);
	return (dup_and_close(fd));
}
