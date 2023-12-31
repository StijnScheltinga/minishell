/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:29:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/22 14:05:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/redirect.h"
#include "../../inc/delimiter.h"
#include "../../inc/execute.h"

#include <readline/readline.h>
#include <sys/types.h>
#include <sys/wait.h>

char	*get_home_cmd_table(t_env **env_head)
{
	t_env	*iter;

	iter = *env_head;
	while (iter)
	{
		if (ft_strncmp(iter->variable, "HOME", 5) == 0)
			break ;
		iter = iter->next;
	}
	return (ft_strdup(iter->value));
}

bool	is_builtin(char *arg)
{
	if (!arg)
		return (false);
	if (ft_strncmp("echo", arg, ft_strlen(arg) + 1) == 0)
		return (true);
	if (ft_strncmp("cd", arg, ft_strlen(arg) + 1) == 0)
		return (true);
	if (ft_strncmp("pwd", arg, ft_strlen(arg) + 1) == 0)
		return (true);
	if (ft_strncmp("export", arg, ft_strlen(arg) + 1) == 0)
		return (true);
	if (ft_strncmp("unset", arg, ft_strlen(arg) + 1) == 0)
		return (true);
	if (ft_strncmp("env", arg, ft_strlen(arg) + 1) == 0)
		return (true);
	if (ft_strncmp("exit", arg, ft_strlen(arg) + 1) == 0)
		return (true);
	return (false);
}

void	execute_builtin(t_cmd_table *cmd_table, int cmd_index, int io[2])
{
	char	**arg;

	arg = cmd_table->cmd_arr[cmd_index].single_cmd;
	if (ft_strncmp("echo", arg[0], ft_strlen(arg[0]) + 1) == 0)
		echo(cmd_table, arg);
	else if (ft_strncmp("cd", arg[0], ft_strlen(arg[0]) + 1) == 0)
		cd(arg, &cmd_table->env, cmd_table);
	else if (ft_strncmp("pwd", arg[0], ft_strlen(arg[0]) + 1) == 0)
		pwd(cmd_table);
	else if (ft_strncmp("export", arg[0], ft_strlen(arg[0]) + 1) == 0)
		export(cmd_table, arg);
	else if (ft_strncmp("unset", arg[0], ft_strlen(arg[0]) + 1) == 0)
		unset(cmd_table, arg);
	else if (ft_strncmp("env", arg[0], ft_strlen(arg[0]) + 1) == 0)
		env(cmd_table, &cmd_table->env);
	else if (ft_strncmp("exit", arg[0], ft_strlen(arg[0]) + 1) == 0)
		ms_exit(arg, cmd_table, io);
	if (cmd_table->cmd_count == 1)
		reset_stdin_stdout(io);
	if (cmd_table->cmd_count > 1)
		exit(0);
}

void	builtin_single_cmd(t_cmd_table *cmd_table)
{
	t_redirect	*redirect_arr;
	int			redirect_count;
	pid_t		pid;
	int			io[2];

	redirect_arr = cmd_table->cmd_arr[0].redirect_arr;
	redirect_count = cmd_table->cmd_arr[0].redirect_count;
	io[0] = dup(STDIN_FILENO);
	io[1] = dup(STDOUT_FILENO);
	if (delimiter_count(redirect_arr, redirect_count) > 0)
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			delimiter_single_builtin(cmd_table, io);
		wait(NULL);
	}
	redirect_input(cmd_table, redirect_arr, redirect_count);
	redirect_output(cmd_table, redirect_arr, redirect_count);
	execute_builtin(cmd_table, 0, io);
}

void	exec_delimiter_single_builtin(char *eof)
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
		free(input_string);
	}
	free(input_string);
}
