/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:36:53 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/06 15:53:10 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execve.h"
#include "../../libft/libft.h"

char	*get_path(char **envp)
{
	int		i;
	char	*ret;

	i = 0;
	while (envp[i])
	{
		ret = ft_strnstr(envp[i], "PATH=", 5);
		if (ret)
			break ;
		i++;
	}
	return (ret);
}

void	ft_execve(char **cmd, char **envp)
{
	char *path = get_path(envp);
	char **paths = ft_split(path + 5, ':');
	char *cmdpath = NULL;
	int i = 0;
	while (paths[i])
	{
		cmdpath = ft_strjoin_with_slash(paths[i], cmd[0]);
		execve(cmdpath, cmd, envp);
		free(cmdpath);
		i++;
	}
}
