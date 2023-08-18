/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:40:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/18 12:46:44 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execute.h"
#include "../../inc/builtin.h"
#include "../../inc/execve.h"
#include "../../inc/pipes.h"
#include "../../inc/parser.h"
#include "../../inc/redirect.h"

#include <fcntl.h>

void	execute_with_child(t_cmd_table *cmd_table, int fd[2], int rd, int cmd_index)
{
	redirect_child(cmd_table, fd, rd, cmd_index);
	if (is_builtin(cmd_table->cmd_arr[cmd_index].single_cmd[0]) == true)
		execute_builtin(cmd_table, cmd_index);
	else
		ft_execve(cmd_table->cmd_arr[cmd_index].single_cmd, &cmd_table->env);
}

void	execute_multiple_cmd(t_cmd_table *cmd_table)
{
	int		i, status;
	int		fd[2];
	int		read;
	pid_t	pid;

	i = 0;
	read = STDIN_FILENO;
	while (i < cmd_table->cmd_count)
	{
		if (pipe(fd) == -1)
			exit(EXIT_FAILURE);
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		if (pid == 0)
			execute_with_child(cmd_table, fd, read, i);
		waitpid(pid, &status, 0);
		read = dup(fd[0]);
		close_pipes(fd);
		i++;
	}
}

// check if its a builtin with no other commands

void	execute_single_cmd(t_cmd_table *cmd_table)
{
	int		status;
	pid_t	pid;

	redirect_single_child(cmd_table);
	if (is_builtin(cmd_table->cmd_arr[0].single_cmd[0]) == true)
	{
		execute_builtin(cmd_table, 0);
		return ;
	}
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		ft_execve(cmd_table->cmd_arr[0].single_cmd, &cmd_table->env);
	waitpid(pid, &status, 0);
}

//restoring stdin and stdout after executing one or more command(s)

void	execute(t_cmd_table *cmd_table)
{
	int	stdin;
	int	stdout;

	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	if (cmd_table->cmd_count == 1)
		execute_single_cmd(cmd_table);
	else
		execute_multiple_cmd(cmd_table);
	dup2(stdin, STDIN_FILENO);
	dup2(stdout, STDOUT_FILENO);
}

// int main(int argc, char **argv, char **envp)
// {
// 	env = envp;
// 	execute();
// 	return (0);
// }
