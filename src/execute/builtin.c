/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:29:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/06 19:17:41 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/execute.h"
#include "../../libft/libft.h"

bool	is_builtin(char *arg)
{
	if (ft_strncmp("echo", arg, ft_strlen(arg)) == 0)
		return (true);
	if (ft_strncmp("cd", arg, ft_strlen(arg)) == 0)
		return (true);
	if (ft_strncmp("pwd", arg, ft_strlen(arg)) == 0)
		return (true);
	if (ft_strncmp("export", arg, ft_strlen(arg)) == 0)
		return (true);
	if (ft_strncmp("unset", arg, ft_strlen(arg)) == 0)
		return (true);
	if (ft_strncmp("env", arg, ft_strlen(arg)) == 0)
		return (true);
	if (ft_strncmp("exit", arg, ft_strlen(arg)) == 0)
		return (true);
	return (false);
}

void	execute_builtin(char **arg)
{
	if (ft_strncmp("echo", arg[0], ft_strlen(arg[0])) == 0)
		ms_echo(arg[1]);
	// if (ft_strncmp("cd", arg[0], ft_strlen(arg[0])) == 0)
	// 	ms_cd(arg);
	// if (ft_strncmp("pwd", arg[0], ft_strlen(arg[0])) == 0)
	// 	ms_pwd(arg);
	// if (ft_strncmp("export", arg[0], ft_strlen(arg[0])) == 0)
	// 	ms_export(arg);
	// if (ft_strncmp("unset", arg[0], ft_strlen(arg[0])) == 0)
	// 	ms_unset(arg);
	// if (ft_strncmp("env", arg[0], ft_strlen(arg[0])) == 0)
	// 	ms_env(arg);
	// if (ft_strncmp("exit", arg[0], ft_strlen(arg[0])) == 0)
	// 	ms_exit(arg);
}

//ECHO: ARG[0] = "echo", ARG[1] = "-n hello";