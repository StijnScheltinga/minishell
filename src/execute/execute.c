/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:40:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/06 20:07:08 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execute.h"
#include "../../inc/builtin.h"
#include "../../inc/execve.h"
#include "../../inc/pipe_redirect.h"

char **env;
int	pipe_count=3;
int	cmd_count=4;

char *cmds[][11] = {
    {"find", ".", "-type", "f", "-exec", "ls", "-lS", "{}", "+", NULL},
    {"head", "-n", "10", NULL},
    {"grep", ".c", NULL},
    {"wc", "-l", NULL},
};


void	execute_with_child(int (*fd)[2], int cmd_index)
{
	if (cmd_index == 0)
		redirect_first_cmd(fd);
	else if (cmd_index != cmd_count - 1)
		redirect_middle_cmd(fd, cmd_index);
	else
		redirect_last_cmd(fd);
	ft_execve(cmds[cmd_index], env);
}

void	execute_multiple_cmd()
{
	int i = 0, status, (*fd)[2]; pid_t pid;
	fd = malloc(sizeof(int[2]) * pipe_count);
	while (i < pipe_count)
		pipe(fd[i++]);
	i = 0;
	while (i < cmd_count){
		pid = fork();
		if (pid == 0){
			execute_with_child(fd, i);
		}
		i++;
	}
	waitpid(0, &status, 0);
	close_all_pipes(fd, pipe_count);
}

// check if its a builtin with no other commands

void	execute_single_cmd()
{
	int	i = 0, status;
	pid_t pid;

	if (is_builtin(cmds[0][0]) == true)
		execute_builtin(cmds[0]);
	pid = fork();
	if (pid == 0)
		ft_execve(cmds[0], env);
	waitpid(0, &status, 0);
}

void	execute_commands(void)
{
	if (cmd_count == 1)
		execute_single_cmd();
	else
		execute_multiple_cmd();
}

//restoring stdin and stdout after executing one or more command(s)

void	execute(void)
{
	int stdin_holder;
	int stdout_holder;

	stdin_holder = dup(STDIN_FILENO);
	stdout_holder = dup(STDOUT_FILENO);
	execute_commands();
	dup2(stdin_holder, STDIN_FILENO);
	dup2(stdout_holder, STDOUT_FILENO);
}

int main(int argc, char **argv, char **envp)
{
	env = envp;
	execute();
	return (0);
}
