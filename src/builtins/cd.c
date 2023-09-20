/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/20 01:27:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/error.h"
#include "../../inc/env_utils.h"

#include <errno.h>
#include <string.h>

char	*get_home(t_env **env_head, t_cmd_table *cmd_table)
{
	char	*ret;
	t_env	*iter;

	ret = NULL;
	iter = *env_head;
	while (iter)
	{
		if (ft_strncmp(iter->variable, "HOME", 5) == 0)
			break ;
		iter = iter->next;
	}
	if (!iter)
	{
		write(STDERR_FILENO, "cd: HOME not set\n", 17);
		cmd_table->latest_exit_code = 1;
	}
	else
		ret = iter->value;
	return (ret);
}

static char	*find_right_path(char **arg, t_env **env_head, t_cmd_table *cmd_tab)
{
	char	*path;

	path = NULL;
	if (arg[1] == NULL)
		path = get_home(env_head, cmd_tab);
	else if (arg[1][0] == '~')
		path = ft_strjoin(cmd_tab->home, arg[1] + 1);
	else
		path = arg[1];
	return (path);
}

void	change_env_pwd(t_env **env_head, char *pwd)
{
	t_env	*iter;
	char	buffer[FILENAME_MAX];

	iter = *env_head;
	getcwd(buffer, FILENAME_MAX);
	while (iter)
	{
		if (!ft_strncmp(iter->variable, pwd, ft_strlen(pwd) + 1))
			break ;
		iter = iter->next;
	}
	if (!iter && !ft_strncmp(pwd, "PWD", 4))
		lst_delone(env_head, "OLDPWD");
	if (iter)
	{
		free(iter->value);
		iter->value = ft_strdup(buffer);
	}
}

void	cd(char **arg, t_env **env_head, t_cmd_table *cmd_table)
{
	char	*path;

	path = NULL;
	if (arg[1] && arg[2])
	{
		cd_error_msg(cmd_table, arg[0], "too many arguments");
		return ;
	}
	path = find_right_path(arg, env_head, cmd_table);
	change_env_pwd(env_head, "OLDPWD");
	if (chdir(path))
		cd_error_msg(cmd_table, arg[1], strerror(errno));
	else
	{
		change_env_pwd(env_head, "PWD");
		cmd_table->latest_exit_code = 0;
	}
	if (arg[1] && arg[1][0] == '~')
		free(path);
}
