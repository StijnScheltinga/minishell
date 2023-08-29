/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:29:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/29 15:38:00 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/execute.h"
#include "../../libft/libft.h"

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
		echo(arg);
	else if (ft_strncmp("cd", arg[0], ft_strlen(arg[0]) + 1) == 0)
		cd(arg[1], &cmd_table->env);
	else if (ft_strncmp("pwd", arg[0], ft_strlen(arg[0]) + 1) == 0)
		pwd();
	else if (ft_strncmp("export", arg[0], ft_strlen(arg[0]) + 1) == 0)
		export(cmd_table, arg);
	else if (ft_strncmp("unset", arg[0], ft_strlen(arg[0]) + 1) == 0)
		unset(cmd_table, arg);
	else if (ft_strncmp("env", arg[0], ft_strlen(arg[0]) + 1) == 0)
		env(&cmd_table->env);
	else if (ft_strncmp("exit", arg[0], ft_strlen(arg[0]) + 1) == 0)
		ms_exit(arg);
	if (cmd_table->cmd_count > 1)
		exit(0);
}

//ECHO: ARG[0] = "echo", ARG[1] = "-n hello";