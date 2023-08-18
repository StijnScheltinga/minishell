/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:27:04 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/18 12:09:00 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"

#include <errno.h>

void	execve_error(char *cmd)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		if (ft_strchr(cmd, '/'))
			ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		else
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit(127);
	}
	if (errno == EACCES)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		exit(126);
	}
	exit(1);
}