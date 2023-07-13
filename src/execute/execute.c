/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:40:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/13 16:11:14 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execute.h"
#include "../../inc/builtin.h"
#include "../../inc/execve.h"
#include "../../inc/pipe_redirect.h"
#include "../../inc/parser.h"
#include "../../inc/env.h"


void	execute_with_child(t_cmd_table *cmd_table, int (*fd)[2], int cmd_index)
{
	int cmd_count = cmd_table->cmd_count;
	if (cmd_index == 0)
		redirect_first_cmd(fd, cmd_count - 1);
	else if (cmd_index != cmd_count - 1)
		redirect_middle_cmd(fd, cmd_index, cmd_count - 1);
	else
		redirect_last_cmd(fd, cmd_count - 1);
	if (is_builtin(cmd_table->cmd_arr[cmd_index].single_cmd[0]) == true)
		execute_builtin(cmd_table, cmd_index);
	else
		ft_execve(cmd_table->cmd_arr[cmd_index].single_cmd, cmd_table->envp);
}

void	execute_multiple_cmd(t_cmd_table *cmd_table)
{
	int i = 0, status, pipe_count, (*fd)[2]; pid_t pid;
	pipe_count = cmd_table->cmd_count - 1;
	fd = malloc(sizeof(int[2]) * pipe_count);
	while (i < pipe_count)
		pipe(fd[i++]);
	i = 0;
	while (i < cmd_table->cmd_count){
		pid = fork();
		if (pid == -1){
			//ERROR
		}
		else if (pid == 0){
			execute_with_child(cmd_table, fd, i);
		}
		i++;
	}
	wait(NULL);
	close_all_pipes(fd, pipe_count);
}

// check if its a builtin with no other commands

void	execute_single_cmd(t_cmd_table *cmd_table)
{
	int	i = 0, status;
	pid_t pid;

	if (is_builtin(cmd_table->cmd_arr[0].single_cmd[0]) == true){
		execute_builtin(cmd_table, 0);
		return ;
	}
	pid = fork();
	if (pid == -1){
		//ERROR
	}
	if (pid == 0){
		ft_execve(cmd_table->cmd_arr[0].single_cmd, cmd_table->envp);
	}
	waitpid(pid, &status, 0);
}

//restoring stdin and stdout after executing one or more command(s)

void	execute(t_cmd_table *cmd_table)
{
	int stdin_holder;
	int stdout_holder;

	stdin_holder = dup(STDIN_FILENO);
	stdout_holder = dup(STDOUT_FILENO);
	cmd_table->env = env_to_linkedlist(cmd_table->envp);
	if (cmd_table->cmd_count == 1)
		execute_single_cmd(cmd_table);
	else
		execute_multiple_cmd(cmd_table);
	dup2(stdin_holder, STDIN_FILENO);
	dup2(stdout_holder, STDOUT_FILENO);
}

// int main(int argc, char **argv, char **envp)
// {
// 	env = envp;
// 	execute();
// 	return (0);
// }
