/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:36:53 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/05 12:46:46 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execve.h"
#include "../../inc/env_utils.h"
#include "../../inc/error.h"
#include "../../inc/signals.h"
#include "../../libft/libft.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

char	*get_right_path(char **paths, char **cmd)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (paths[i])
	{
		ret = ft_strjoin_with_char(paths[i], cmd[0], '/');
		if (access(ret, X_OK | F_OK) == 0)
			return (ret);
		free(ret);
		i++;
	}
	ret = ft_strdup(cmd[0]);
	if (!ret)
		exit(EXIT_FAILURE);
	return (ret);
}

char	*get_paths(char **envp)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (envp[i])
	{
		ret = ft_strnstr(envp[i], "PATH=", 5);
		if (ret)
			break ;
		i++;
	}
	return (ret);
}

static void	free_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
}

static void	path_not_found(char *cmd)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	exit(127);
}

void	ft_execve(char **cmd, t_env **env_head)
{
	char	**envp;
	char	*path;
	char	**paths;
	char	*cmdpath;

	if (!cmd[0])
		exit(0);
	envp = linked_list_to_double_array(env_head);
	path = get_paths(envp);
	if (!path)
		path_not_found(cmd[0]);
	paths = ft_split(path + 5, ':');
	cmdpath = get_right_path(paths, cmd);
	execve(cmdpath, cmd, envp);
	free(cmdpath);
	free_envp(envp);
	execve_error(cmd[0]);
}
