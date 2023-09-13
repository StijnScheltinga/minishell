/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:29:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/13 14:00:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/execute.h"
#include "../../inc/redirect.h"
#include "../../inc/delimiter.h"
#include "../../libft/libft.h"

#include <readline/readline.h>

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

void	execute_builtin(t_cmd_table *cmd_table, int cmd_index)
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
		ms_exit(arg, cmd_table);
	if (cmd_table->cmd_count > 1)
		exit(0);
}

void	builtin_single_cmd(t_cmd_table *cmd_table)
{
	t_redirect	*redirect_arr;
	int			redirect_count;
	pid_t		pid;

	redirect_arr = cmd_table->cmd_arr[0].redirect_arr;
	redirect_count = cmd_table->cmd_arr[0].redirect_count;
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		delimiter_single_builtin(cmd_table);
	wait(NULL);
	redirect_input(redirect_arr, redirect_count);
	redirect_output(redirect_arr, redirect_count);
	execute_builtin(cmd_table, 0);
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
