/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:40:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/11 16:19:48 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execute.h"
#include "../../inc/builtin.h"
#include "../../inc/execve.h"
#include "../../inc/parser.h"
#include "../../inc/redirect.h"
#include "../../inc/signals.h"
#include "../../inc/pipes.h"

#include <fcntl.h>

void	execute_with_child(t_cmd_table *cmd_table, int cmd_i)
{
	sign_child();
	redirect_child(cmd_table, cmd_i);
	if (is_builtin(cmd_table->cmd_arr[cmd_i].single_cmd[0]))
		execute_builtin(cmd_table, cmd_i);
	ft_execve(cmd_table->cmd_arr[cmd_i].single_cmd, &cmd_table->env, cmd_table->pipes);
}

void	execute_multiple_cmd(t_cmd_table *cmd_table)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < cmd_table->cmd_count)
	{
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		if (pid == 0)
			execute_with_child(cmd_table, i);
		cmd_table->pids[i] = pid;
		i++;
	}
	close_all_pipes(cmd_table);
	wait_for_children(cmd_table);
}

void	execute_single_cmd(t_cmd_table *cmd_table)
{
	int		status;
	pid_t	pid;

	redirect_single_child(cmd_table);
	if (is_builtin(cmd_table->cmd_arr[0].single_cmd[0]))
	{
		execute_builtin(cmd_table, 0);
		return ;
	}
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		sign_child();
		ft_execve(cmd_table->cmd_arr[0].single_cmd, &cmd_table->env, NULL);
	}
	waitpid(pid, &status, 0);
	cmd_table->latest_exit_code = WEXITSTATUS(status);
}

void	execute(t_cmd_table *cmd_table)
{
	int	stdin;
	int	stdout;

	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	sign_ignore();
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
