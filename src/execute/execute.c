/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:40:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/05 18:07:09 by aolde-mo         ###   ########.fr       */
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

void	execute_with_child(t_cmd_table *cmd_table, int (*fd)[2], int cmd_i)
{
	sign_child();
	if (redirect_child(cmd_table, fd, cmd_i))
		exit(1);
	if (!cmd_table->cmd_arr[cmd_i].single_cmd[0])
		exit(1);
	if (is_builtin(cmd_table->cmd_arr[cmd_i].single_cmd[0]) == true)
		execute_builtin(cmd_table, cmd_i);
	else
		ft_execve(cmd_table->cmd_arr[cmd_i].single_cmd, &cmd_table->env);
}

void	execute_multiple_cmd(t_cmd_table *cmd_table)
{
	int		i;
	int		status;
	int		(*fd)[2];
	pid_t	pid;
	pid_t	*pids[cmd_table->cmd_count];

	i = 0;
	fd = malloc(sizeof(int[2]) * (cmd_table->cmd_count - 1));
	for (size_t j = 0; j < cmd_table->cmd_count - 1; j++)
		pipe(fd[j]);
	while (i < cmd_table->cmd_count)
	{
		pid = fork();
		if (pid < 0)
			exit(EXIT_FAILURE);
		if (pid == 0)
			execute_with_child(cmd_table, fd, i);
		pids[i] = pid;
		i++;
	}
	close_all_pipes(fd, cmd_table->cmd_count - 1);
	for (size_t i = 0; i < cmd_table->cmd_count; i++)
		waitpid(pids[i], &status, 0);
	cmd_table->latest_exit_code = WEXITSTATUS(status);
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
	{
		sign_child();
		ft_execve(cmd_table->cmd_arr[0].single_cmd, &cmd_table->env);
	}
	waitpid(pid, &status, 0);
	cmd_table->latest_exit_code = WEXITSTATUS(status);
}

//restoring stdin and stdout after executing one or more command(s)

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
