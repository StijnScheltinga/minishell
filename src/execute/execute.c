/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:40:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/30 23:17:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execute.h"
#include "../../inc/builtin.h"
#include "../../inc/execve.h"
#include "../../inc/parser.h"
#include "../../inc/redirect.h"
#include "../../inc/signals.h"

#include <fcntl.h>

void	execute_with_child(t_cmd_table *cmd_table, int fd[2], int rd, int cmd_i)
{
	sign_child();
	close(fd[READ]);
	if (redirect_child(cmd_table, fd, rd, cmd_i))
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
		cmd_table->latest_exit_code = WEXITSTATUS(status);
		read = dup(fd[0]); 
		close(fd[0]);
		close(fd[1]);
		i++;
	}
}

// check if its a builtin with no other commands

void	execute_single_cmd(t_cmd_table *cmd_table)
{
	int		status;
	pid_t	pid;

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
		if (redirect_single_child(cmd_table))
			exit(1);
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
