/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:29:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/06/23 15:45:34 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

void	exec_builtin_if_found(char *arg)
{
	if (ft_strncmp("echo", arg, ft_strlen(arg)) == 0)
		ms_echo();
	else if (ft_strncmp("cd", arg, ft_strlen(arg)) == 0)
		ms_cd();
	else if (ft_strncmp("pwd", arg, ft_strlen(arg)) == 0)
		ms_pwd();
	else if (ft_strncmp("export", arg, ft_strlen(arg)) == 0)
		ms_export();
	else if (ft_strncmp("unset", arg, ft_strlen(arg)) == 0)
		ms_unset();
	else if (ft_strncmp("env", arg, ft_strlen(arg)) == 0)
		ms_env();
	else if (ft_strncmp("exit", arg, ft_strlen(arg)) == 0)
		ms_exit();
}